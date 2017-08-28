/*
 Name:		RiegoAutónomo.ino
 Created:	8/22/2017 5:47:38 PM
 Author:	Pablo Horno
*/
#include "Riego.h"
Condicion condiciones[] = { Condicion(Tiempo(9,30),"lxv", Tiempo(1)),
							Condicion(Tiempo(15,30),"lxv", Tiempo(1)),
							Condicion(Tiempo(21,30),"lxv", Tiempo(1)) };
unsigned pins[] = { 2,3 };
Riego riego(pins);

void setup() {
	Serial.begin(9600);
	Serial.setTimeout(20);
	Serial.println("Iniciando..");
	riego.init();
}

void loop() {
	Serial.println(riego.get_fecha());
	delay(5000);
}