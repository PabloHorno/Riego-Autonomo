// 
// 
// 

#include "Tiempo.h"

void Tiempo::actualizar_hora()
{
	unsigned segundos = (millis() - _millis)/1000 + _segundos;
	hora = segundos / 3600 + _hora;
	minutos = segundos / 60 + _minutos;
	this->segundos = segundos;

	while(hora >= 24)
		hora -= 24;
	while (minutos >= 60)
		minutos -= 60;
	while (this->segundos >= 60)
		this->segundos -= 60;
	
}

void Tiempo::init()
{
	while (_hora < 0 || _hora >= 24) {
		Serial.println("Introduzca hora:");
		while (true)
		{
			if (Serial.available())
			{
				_hora = Serial.readString().toInt();
				break;
			}
		}
	}
	while (_minutos < 0 || _minutos >= 60) {
		Serial.println("Introduzca minutos:");
		while (true)
		{
			if (Serial.available())
			{
				_minutos = Serial.readString().toInt();
				break;
			}
		}
	}
	while (_segundos < 0 || _segundos >= 60) {
		Serial.println("Introduzca segundos:");
		while (true)
		{
			if (Serial.available())
			{
				_segundos = Serial.readString().toInt();
				break;
			}
		}
	}
	_millis = millis();
	
	Serial.println("Hora: " + get_hora_str());
}

void Tiempo::init(unsigned hora, unsigned minutos = 0, unsigned segundos = 0)
{
	_hora = hora; _minutos = minutos; _segundos = segundos;
	_millis = millis();

	Serial.println("Hora: " + get_hora_str());
}

String Tiempo::get_hora_str()
{
	actualizar_hora();
	String hora="";
	hora += this->hora;
	hora += ":";
	hora += this->minutos;
	hora += ":";
	hora += this->segundos;
	return hora;
}
