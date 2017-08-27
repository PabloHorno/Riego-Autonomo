/*
 Name:		RiegoAutónomo.ino
 Created:	8/22/2017 5:47:38 PM
 Author:	Pablo Horno
*/
#include "Riego.h"
Condicion condiciones[] = { Condicion(Tiempo(9,30),"lxv", Tiempo(1)),
							Condicion(Tiempo(15,30),"lxv", Tiempo(1)),
							Condicion(Tiempo(21,30),"lxv", Tiempo(1)),
};
Riego riego(2);

void setup() {
	Serial.begin(9600);
	Serial.setTimeout(20);
	Serial.println("Iniciando..");
	riego.init();
}

void loop() {
	Tiempo a(9, 30), b(13,10),ans;
	ans = a + b;
	Serial.print(ans.hora);
	Serial.print(':');
	Serial.print(ans.minuto);
	Serial.print(':');
	Serial.println(ans.segundo);
	Serial.println(bool( a < b));
	while (1) {};
}