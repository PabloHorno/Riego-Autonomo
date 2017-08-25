// 
// 
// 

#include "Riego.h"

void Riego::init()
{
	if (!clock.begin())
	{
		Serial.println("No se ha encontrado el modulo RTC");
		while (true);
	}
	else
		if (clock.lostPower())
			clock.adjust(DateTime(F(__DATE__), F(__TIME__)));
	//clock.adjust(DateTime(2017, 8, 25, 3, 0));
}

String Riego::get_fecha()
{
	DateTime fecha = clock.now();
	String fecha_str = String(nombre_dias[fecha.dayOfTheWeek()] + ' ' + fecha.hour() + ':' + fecha.minute() + ':' + fecha.second() + ' ' + fecha.year() + '/' + fecha.month() + '/' + fecha.day());

	return fecha_str;
}

Condicion::Condicion()
{
}

Condicion::Condicion(const DateTime fecha)
{
	this->fecha = fecha.hour();
}

Condicion::Condicion(const DateTime fecha, const unsigned dias_semana[], const unsigned duracion)
{
	Condicion(fecha);
	//for()
	this->duracion = duracion;
}
bool Condicion::operator()(DateTime now)
{
	if (duracion > 0)
	{
		if (dias_semana[now.dayOfTheWeek()])
		{
			
		}
	}
	else
		return false;
}
