/*
 Name:		RiegoAutónomo.ino
 Created:	8/22/2017 5:47:38 PM
 Author:	Pablo Horno
*/
#include "Hora.h"
#include "Riego.h"

Hora hora;

void setup() {
	Serial.begin(9600);
	Serial.setTimeout(20);
	Serial.println("Iniciando..");
	delay(3000);
	hora.init();
}

void loop() {
}