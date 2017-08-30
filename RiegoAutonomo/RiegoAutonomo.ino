/*
 Name:		RiegoAutónomo.ino
 Created:	8/22/2017 5:47:38 PM
 Author:	Pablo Horno
*/
#include "Riego.h"
Pair<unsigned, Riego::Valvula_t> pines[] = { {3, Riego::Valvula_t::NORMAL},
											 {4, Riego::Valvula_t::ADITIVA} };
Riego riego(pines);
void setup() {
	Serial.begin(9600);
	Serial.setTimeout(20);
	Serial.println("Iniciando..");
	riego.init();
	riego.set_condicion(Tiempo_Riego(Tiempo(14, 18), "lmj", Tiempo(0, 1)), Riego::Valvula_t::NORMAL);
	riego.set_condicion(Tiempo_Riego(Tiempo(14, 19), "lmj", Tiempo(0, 1)), Riego::Valvula_t::ADITIVA);
}

void loop() {
	riego.loop();
}