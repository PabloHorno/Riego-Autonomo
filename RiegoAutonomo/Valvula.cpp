// 
// 
// 

#include "Valvula.h"



void Valvula::init()
{
	pinMode(this->pin_valvula, OUTPUT);
	this->cerrar();
}

void Valvula::abrir()
{
	if (estado != estado_enum::ABIERTO)
	{
		Serial.print("Valvula con pin "); Serial.print(pin_valvula); Serial.println(" estaba cerrada y se ha ABIERTO");
		analogWrite(pin_valvula, 255);
		estado = estado_enum::ABIERTO;
	}
}

void Valvula::cerrar()
{
	if (estado != estado_enum::CERRADO)
	{
		Serial.print("Valvula con pin "); Serial.print(pin_valvula); Serial.println(" estaba abierta y se ha CERRADO");
		analogWrite(pin_valvula, 0);
		estado = estado_enum::CERRADO;
	}
}


