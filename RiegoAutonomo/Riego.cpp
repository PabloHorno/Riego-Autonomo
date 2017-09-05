// 
// 
// 

#include "Riego.h"

Riego::Riego(const Pair<unsigned, Riego::Valvula_t> pin_valvula[])
{
	for (unsigned i = 0; i < sizeof(pin_valvula); i++)
		valvulas[(unsigned)pin_valvula[i].second] = Valvula(pin_valvula[(unsigned)pin_valvula[i].second].first);
}

void Riego::init()
{
	if (!clock.begin())
	{
		Serial.println("No se ha encontrado el modulo RTC");
		while (true);
	}
	else
		if (clock.lostPower()) {
			clock.adjust(DateTime(F(__DATE__), F(__TIME__)));
			//clock.adjust(DateTime(2017, 8, 28, 15, 8));
		}
		else
			Serial.println("Reloj RTC:  OK");
	sensor_temperatura.begin();
	Serial.println("Iniciando sensor tempertura...");

	for (unsigned i = 0; i < (unsigned)Riego::Valvula_t::NUM_VALVULAS; i++)
		valvulas[i].cerrar();
}

void Riego::loop()
{
	DateTime tiempo = clock.now();
	for (unsigned i = 0; i < condiciones_activas; i++)
	{
		if (condiciones[i].first(tiempo)) {
			valvulas[(unsigned)condiciones[i].second].abrir();
		}
		else {
			valvulas[(unsigned)condiciones[i].second].cerrar();
		}
	}
}

DateTime Riego::get_fecha()
{
	return clock.now();
}
String Riego::get_fecha_str()
{
	DateTime fecha = clock.now();
	String fecha_str = String(nombre_dias[fecha.dayOfTheWeek()] + ' ' + fecha.hour() + ':' + fecha.minute() + ':' + fecha.second() + ' ' + fecha.year() + '/' + fecha.month() + '/' + fecha.day());

	return fecha_str;
}

void Riego::set_condicion(const Tiempo_Riego condicion, const Riego::Valvula_t valvula)
{
	set_condicion(Pair<Tiempo_Riego, Valvula_t>(condicion, valvula));
}

void Riego::set_condicion(const Pair<Tiempo_Riego, Valvula_t> condicion)
{
	if (condiciones_activas < NUM_CONDICIONES)
			condiciones[condiciones_activas++] = condicion;
	else
		Serial.println("Se ha superado el numero de condiciones. Aumente NUM_CONDICIONES");
}

void Riego::set_condicion(const Pair<Tiempo_Riego, Valvula_t> condiciones[])
{
	for (unsigned i = 0; i < sizeof(condiciones); i++)
		set_condicion(condiciones[i]);
}

double Riego::get_temperatura()
{
	double temp = sensor_temperatura.readTemperature();
	if (isnan(temp))
		return Serial.println("Error al leer temperatura.");
	return temp;
}

double Riego::get_humedad()
{
	double hum = sensor_temperatura.readTemperature();
	if (isnan(hum))
		return Serial.println("Error al leer humedad.");
	return hum;
}
