// Ethernet.h

#ifndef _ETHERNET_h
#define _ETHERNET_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include <SPI.h>
#include <Ethernet.h>
#include "Tiempo.h"

class Ethernet_web
{
 private:
	 byte mac[6] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
	 IPAddress ip = IPAddress(192, 168, 1, 177);
	 EthernetServer server = EthernetServer(80);
 public:
	 void init();
	 void loop(double, double, String);
};



#endif




