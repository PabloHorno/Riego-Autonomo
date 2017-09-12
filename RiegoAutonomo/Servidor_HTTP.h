// Ethernet.h

#ifndef _ETHERNET_WEB_h
#define _ETHERNET_WEB_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include <net.h>
#include <EtherCard.h>
#include <enc28j60.h>
#include <time.h>
#define TAM_BUFFER 300

class Servidor_HTTP
{
public:
	enum class tipo_ip
	{
		ESTATICA,
		DHCP
	};
	Servidor_HTTP() {};
	void init(tipo_ip);
	void loop(DateTime);
private:
	const byte mac[6] = { 0x74,0x69,0x69,0x2D,0x30,0x31 };
	const byte ip[4] = { 192, 168, 1, 10 };
	const byte get_way_ip[4] = {192, 168, 1, 1};
};


#endif




