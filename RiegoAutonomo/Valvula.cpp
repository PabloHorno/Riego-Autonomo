// 
// 
// 

#include "Valvula.h"



void Valvula::abrir()
{
	if (estado != estado_enum::ABIERTO)
	{
		Serial.print("Valvula con pin "); Serial.print(pin_valvula); Serial.println(" estaba cerrada y se ha ABIERTO");
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


