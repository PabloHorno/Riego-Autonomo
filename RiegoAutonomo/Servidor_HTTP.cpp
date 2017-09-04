#include "Servidor_HTTP.h"

void Servidor_HTTP::init(tipo_ip ip)
{

	if (ether.begin(sizeof Ethernet::buffer, mac) == 0)
		Serial.println("Failed to access Ethernet controller");
	if(ip == tipo_ip::ESTATICA)
		ether.staticSetup(this->ip, this->get_way_ip);
	else if (!ether.dhcpSetup())
		Serial.println("DHCP failed");

	ether.printIp("IP:  ", ether.myip);
	ether.printIp("GW:  ", ether.gwip);
	ether.printIp("DNS: ", ether.dnsip);
}

void Servidor_HTTP::loop()
{
	word len = ether.packetReceive();
	word pos = ether.packetLoop(len);

	if (pos)
	{
		if (strstr((char *)Ethernet::buffer + pos, "GET /?data1=0") != 0) {
			Serial.println("Led1 OFF");
		}

		if (strstr((char *)Ethernet::buffer + pos, "GET /?data1=1") != 0) {
			Serial.println("Led1 ON");
		}

		if (strstr((char *)Ethernet::buffer + pos, "GET /?data2=0") != 0) {
			Serial.println("Led2 OFF recieved");
		}

		if (strstr((char *)Ethernet::buffer + pos, "GET /?data2=1") != 0) {
			Serial.println("Led2 ON");
		}


		ether.httpServerReply(mainPage());
	}
}

word Servidor_HTTP::mainPage()
{
	BufferFiller bfill = ether.tcpOffset();
	bfill.emit_p(PSTR("HTTP/1.0 200 OKrn"
		"Content-Type: text/htmlrnPragma: no-cachernRefresh: 5rnrn"
		"<html><head><title>Luis Llamas</title></head>"
		"<body>"
		"<div style='text-align:center;'>"
		"<h1>Salidas digitales</h1>"
		"<br /><br />Estado LED 1 = $S<br />"
		"<a href='./?data1=0'><input type='button' value='OFF'></a>"
		"<a href='./?data1=1'><input type='button' value='ON'></a>"
		"<br /><br />Estado LED 2 = $S<br />"
		"<a href='./?data2=0'><input type='button' value='OFF'></a>"
		"<a href='./?data2=1'><input type='button' value='ON'></a>"
		"<br /></div>\n</body></html>"), 1, 2);

	return bfill.position();
}