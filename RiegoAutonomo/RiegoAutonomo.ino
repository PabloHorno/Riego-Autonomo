/*
 Name:		RiegoAutónomo.ino
 Created:	8/22/2017 5:47:38 PM
 Author:	Pablo Horno
*/
#include "Riego.h"
unsigned pins[] = { 4, 5 };
Riego riego(pins);
void setup() {
	Serial.begin(9600);
	Serial.setTimeout(20);
	Serial.println("Iniciando..");
	riego.init();
	riego.set_condicion(Condicion(Tiempo(12, 50), "lmj", Tiempo(0, 5)), 1);
	riego.set_condicion(Condicion(Tiempo(12, 56), "lmj", Tiempo(0, 5)), 0);
}

void loop() {
	riego.loop();
}