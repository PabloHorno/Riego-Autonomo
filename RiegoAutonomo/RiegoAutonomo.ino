﻿/*
 Name:		RiegoAutónomo.ino
 Created:	8/22/2017 5:47:38 PM
 Author:	Pablo Horno
*/
#include "Tiempo.h"
#include "Riego.h"

Tiempo tiempo;
String hora;

void setup() {
	Serial.begin(9600);
	Serial.setTimeout(20);
	Serial.println("Iniciando..");
	delay(3000);
	tiempo.init();
}

void loop() {
	Serial.println(tiempo.get_hora_str());
	delay(30000);
}