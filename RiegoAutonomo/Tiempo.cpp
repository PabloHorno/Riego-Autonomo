// 
// 
// 

#include "Tiempo.h"

void Tiempo::actualizar_hora()
{
	unsigned segundos = (millis() - millis_inicial)/1000;
	hora += segundos / 3600;
	minutos += segundos / 60;
	while(hora >= 24)
		hora = hora/24;
	while (minutos >= 60)
		minutos = minutos / 60;
}

void Tiempo::init()
{
	while (hora < 0 || hora >= 24) {
		Serial.println("Introduzca hora:");
		while (true)
		{
			if (Serial.available())
			{
				hora = Serial.readString().toInt();
				break;
			}
		}
	}
	while (minutos < 0 || minutos >= 60) {
		Serial.println("Introduzca minutos:");
		while (true)
		{
			if (Serial.available())
			{
				minutos = Serial.readString().toInt();
				break;
			}
		}
	}
	millis_inicial = millis();
	
	Serial.print("Hora: " + get_hora_str());
}

String Tiempo::get_hora_str()
{
	actualizar_hora();
	String hora="";
	hora += this->hora;
	hora += ":";
	hora += this->minutos;
	return hora;
}
