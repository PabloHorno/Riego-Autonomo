﻿/*
 Name:		RiegoAutónomo.ino
 Created:	8/22/2017 5:47:38 PM
 Author:	Pablo Horno
*/

//#include "Servidor_HTTP.h"
#include "Riego.h"
Pair<unsigned, Riego::Valvula_t> pines[] = { {3, Riego::Valvula_t::NORMAL},
											 {6, Riego::Valvula_t::ADITIVA} };
Riego riego(pines);

//byte Ethernet::buffer[TAM_BUFFER];
//Servidor_HTTP web;
void setup() {
	Serial.begin(9600);
	Serial.println("Iniciando..");
	riego.init();
	riego.set_condicion(Tiempo_Riego(Tiempo(14, 18), "lmj", Tiempo(0, 1)), Riego::Valvula_t::NORMAL);
	riego.set_condicion(Tiempo_Riego(Tiempo(14, 19), "lmj", Tiempo(0, 1)), Riego::Valvula_t::ADITIVA);

//	web.init(Servidor_HTTP::tipo_ip::ESTATICA);
}

void loop() {
	//riego.loop();
	
	Serial.println(riego.get_fecha_str());
	riego.valvulas[(unsigned)Riego::Valvula_t::ADITIVA].abrir();
	delay(10000);
	riego.valvulas[(unsigned)Riego::Valvula_t::ADITIVA].cerrar();
	delay(10000);
//	web.loop(riego.get_fecha_str().c_str(), riego.get_temperatura(), riego.get_humedad());
}