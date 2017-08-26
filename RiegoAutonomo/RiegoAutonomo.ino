/*
 Name:		RiegoAutónomo.ino
 Created:	8/22/2017 5:47:38 PM
 Author:	Pablo Horno
*/
#include <RTClib.h>
#include <Wire.h>
#include "Riego.h"
Condicion condiciones[] = { Condicion(DateTime(0,0,0,9,30,0),"lxv", DateTime(0,0,0,1,0,0)),
							Condicion(DateTime(0,0,0,15,30,0),"lxv", DateTime(0,0,0,1,0,0)),
							Condicion(DateTime(0,0,0,21,30,0),"lxv", DateTime(0,0,0,1,0,0)),
};
Riego riego(2);

void setup() {
	Serial.begin(9600);
	Serial.setTimeout(20);
	Serial.println("Iniciando..");
	riego.init();
}

void loop() {
	Serial.println(riego.get_fecha());
	delay(1000);
	Serial.println("test");

}