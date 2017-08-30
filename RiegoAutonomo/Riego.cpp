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
	for (unsigned i = 0; i < (unsigned)Riego::Valvula_t::NUM_VALVULAS; i++) {
		valvulas[i].cerrar();
	}
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

String Riego::get_fecha()
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


Tiempo_Riego::Tiempo_Riego()
{
}

Tiempo_Riego::Tiempo_Riego(const Tiempo fecha)
{
	this->hora = fecha;
}

Tiempo_Riego::Tiempo_Riego(const Tiempo fecha, const char dias[], const Tiempo duracion)
{
	this->hora = fecha;
	set_dias_semanas(dias);
	this->duracion = duracion;
}

bool Tiempo_Riego::se_cumple_condicion(const DateTime fecha)
{
	return this->operator()(fecha);
}
bool Tiempo_Riego::operator()(const DateTime tiempo)
{
	if (dias_semana[tiempo.dayOfTheWeek()])
	{
		Tiempo hora = Tiempo(tiempo.hour(), tiempo.minute(), tiempo.second());
		return (hora > this->hora && hora < (this->hora + duracion));
	}
	return false;
}

void Tiempo_Riego::set_dias_semanas(const char dias_semana[])
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

void Tiempo_Riego::set_hora(const unsigned hora, const  unsigned minuto = 0, const  unsigned segundo = 0)
{
	this->hora = Tiempo(hora, minuto, segundo);
}

void Tiempo_Riego::set_duracion(const Tiempo duracion)
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
