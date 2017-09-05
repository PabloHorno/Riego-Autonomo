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

void Servidor_HTTP::loop()
{
	word len = ether.packetReceive();
	word pos = ether.packetLoop(len);

	if (pos)
	{
		Serial.println("Un cliente");
		ether.httpServerReply(mainPage());
	}
}

word Servidor_HTTP::mainPage()
{
	BufferFiller bfill;
	bfill = ether.tcpOffset();
	bfill.emit_p(PSTR("<html><body>"
		/*"<link rel='stylesheet' href='https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css'>"
		"<script src='https://ajax.googleapis.com/ajax/libs/jquery/3.2.1/jquery.min.js'></script>"
		"<script src='https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js'></script>"
		"</head> <body><h1>High</h1>"*/
		"<iframe src='http://192.241.236.31/themes/preview/smartadmin/1.8.x/ajax/index.html#ajax/dashboard.html?v=1.8.7.3' width='100%' height='100%' frameborder='0'>"
		"Alternative text for browsers that do not understand IFrames."
		"</iframe>"
		"</body> </html> "));
	return bfill.position();
}

