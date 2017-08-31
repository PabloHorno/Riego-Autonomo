// 
// 
// 

#include "Tiempo_Riego.h"


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

