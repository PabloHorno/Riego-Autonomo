// 
// 
// 

#include "Riego.h"

Riego::Riego(const unsigned pin_valvula[])
{
	for (unsigned i = 0; i < NUM_VALVULAS; i++)
		valvulas[i] = Valvula(pin_valvula[i]);
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
	for (unsigned i = 0; i < NUM_VALVULAS; i++)
		valvulas[i].cerrar();
}

void Riego::loop()
{
	DateTime tiempo = clock.now();
	for (unsigned i = 0; i < condiciones_activas; i++)
	{
		if (condiciones[i].first(tiempo)) {
			valvulas[condiciones[i].second].abrir();
		}
		else {
			valvulas[condiciones[i].second].cerrar();
		}
	}
}

String Riego::get_fecha()
{
	DateTime fecha = clock.now();
	String fecha_str = String(nombre_dias[fecha.dayOfTheWeek()] + ' ' + fecha.hour() + ':' + fecha.minute() + ':' + fecha.second() + ' ' + fecha.year() + '/' + fecha.month() + '/' + fecha.day());

	return fecha_str;
}

void Riego::set_condicion(const Condicion condicion, const unsigned valvula)
{
	set_condicion(Pair<Condicion, unsigned>(condicion, valvula));
}

void Riego::set_condicion(const Pair<Condicion, unsigned> condicion)
{
	if (condiciones_activas < NUM_CONDICIONES)
		if (condicion.second < NUM_VALVULAS)
			condiciones[condiciones_activas++] = condicion;
		else
			Serial.println("Se ha introducido una condicion para una valvula que no existe. Revise NUM_VALVULAS");
	else
		Serial.println("Se ha superado el numero de condiciones. Aumente NUM_CONDICIONES");
}

void Riego::set_condicion(const Pair<Condicion, unsigned> condiciones[])
{
	for (unsigned i = 0; i < sizeof(condiciones); i++)
		set_condicion(condiciones[i]);
}


Condicion::Condicion()
{
}

Condicion::Condicion(const Tiempo fecha)
{
	this->hora = fecha;
}

Condicion::Condicion(const Tiempo fecha, const char dias[], const Tiempo duracion)
{
	this->hora = fecha;
	set_dias_semanas(dias);
	this->duracion = duracion;
}

bool Condicion::se_cumple_condicion(const DateTime fecha)
{
	return this->operator()(fecha);
}
bool Condicion::operator()(const DateTime tiempo)
{
	if (dias_semana[tiempo.dayOfTheWeek()])
	{
		Tiempo hora = Tiempo(tiempo.hour(), tiempo.minute(), tiempo.second());
		return (hora > this->hora && hora < (this->hora + duracion));
	}
	return false;
}

void Condicion::set_dias_semanas(const char dias_semana[])
{
	for (unsigned i = 0; i < sizeof(dias_semana); i++)
	{
		int index_dia = -1;
		switch (dias_semana[i])
		{
		case 'L': case 'l':
			index_dia = 1;
			break;
		case 'M': case 'm':
			index_dia = 2;
			break;
		case 'X': case 'x':
			index_dia = 3;
			break;
		case 'J': case 'j':
			index_dia = 4;
			break;
		case 'V': case 'v':
			index_dia = 5;
			break;
		case 'S': case 's':
			index_dia = 6;
			break;
		case 'D': case 'd':
			index_dia = 0;
			break;
		default:break;
		}
		if (index_dia >= 0);
		this->dias_semana[index_dia] = true;
	}
}

void Condicion::set_hora(const unsigned hora, const  unsigned minuto = 0, const  unsigned segundo = 0)
{
	this->hora = Tiempo(hora, minuto, segundo);
}

void Condicion::set_duracion(const Tiempo duracion)
{
	this->duracion = duracion;
}

void Valvula::abrir()
{
	if (estado != estado_enum::ABIERTO)
	{
		Serial.print("Valvula con pin ");Serial.print(pin_valvula);Serial.println(" estaba cerrada y se ha ABIERTO");
		digitalWrite(pin_valvula, HIGH);
		estado = estado_enum::ABIERTO;
	}
}

void Valvula::cerrar()
{
	if (estado != estado_enum::CERRADO)
	{
		Serial.print("Valvula con pin "); Serial.print(pin_valvula); Serial.println(" estaba abierta y se ha CERRADO");
		digitalWrite(pin_valvula, LOW);
		estado = estado_enum::CERRADO;
	}
}
