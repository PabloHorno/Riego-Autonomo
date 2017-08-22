/*
 Name:		RiegoAutónomo.ino
 Created:	8/22/2017 5:47:38 PM
 Author:	Pablo Horno
*/
#include "Riego.h"
#include <Servo.h>
#include <LiquidCrystal.h>

LiquidCrystal pantalla(12, 11, 5, 4, 3, 2);

void setup() {
	pantalla.begin(16, 2);
	pantalla.print("Iniciando...");
}

void loop() {
	pantalla.clear();
	pantalla.setCursor(0, 1);
	pantalla.print(millis() / 1000);
}
