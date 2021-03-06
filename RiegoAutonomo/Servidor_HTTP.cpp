#include "Servidor_HTTP.h"

void Servidor_HTTP::init(tipo_ip ip)
{

	if (ether.begin(TAM_BUFFER, mac) == 0)
		Serial.println("Failed to access Ethernet controller");
	if (ip == tipo_ip::ESTATICA)
		ether.staticSetup(this->ip, this->get_way_ip);
	else if (!ether.dhcpSetup())
		Serial.println("DHCP failed");

	ether.printIp("IP:  ", ether.myip);
	ether.printIp("GW:  ", ether.gwip);
	ether.printIp("DNS: ", ether.dnsip);
}


void Servidor_HTTP::loop(const char hora[] = "--:--:-- --/--/----", const double temperatura = 0, const double humedad = 0)
{
	word len = ether.packetReceive();
	word pos = ether.packetLoop(len);

	if (pos)
	{
		Serial.println("Un cliente");
		if (strstr((char *)Ethernet::buffer + pos, PSTR("GET /?data1=0")) != 0) {
			Serial.println("Led1 OFF");
		}

		if (strstr((char *)Ethernet::buffer + pos, PSTR("GET /?data1=1")) != 0) {
			Serial.println("Led1 ON");
		}

		if (strstr((char *)Ethernet::buffer + pos, PSTR("GET /?data2=0")) != 0) {
			Serial.println("Led2 OFF recieved");
		}

		if (strstr((char *)Ethernet::buffer + pos, PSTR("GET /?data2=1")) != 0) {
			Serial.println("Led2 ON");
		}

		BufferFiller bfill;
		bfill = ether.tcpOffset();
		bfill.emit_p(PSTR("<html><body>"
			"<link rel='stylesheet' href='https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css'>"
			"</head><body>"
			"<div><h1>$F</h1>"
			"<h2>Temperatura:$T</h2>"
			"<h2>Humedad:$T</h2>"
			"</body></html>"), hora, temperatura, humedad);
		ether.httpServerReply(bfill.position());
	}
}


