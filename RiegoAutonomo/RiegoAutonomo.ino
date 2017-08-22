/*
 Name:		RiegoAutónomo.ino
 Created:	8/22/2017 5:47:38 PM
 Author:	Pablo Horno
*/
#include "Riego.h"

unsigned lastmilis = 0;

void setup() {
	Serial.begin(9600);
}

void loop() {
	unsigned milis = millis() / 10;
	if (lastmilis != milis)
	{
		Serial.println(milis);
		lastmilis = milis;
	}
}
