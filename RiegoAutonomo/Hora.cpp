// 
// 
// 

#include "Hora.h"

void Hora::actualizar_hora()
{
}

void Hora::init()
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

String Hora::get_hora_str()
{
	actualizar_hora();
	String hora="";
	hora += this->hora;
	hora += ":";
	hora += this->minutos;
	return hora;
}
