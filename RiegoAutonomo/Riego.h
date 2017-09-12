// Riego.h

#ifndef _RIEGO_h
#define _RIEGO_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include <Time.h>
#include <Wire.h>
#include <RTClib.h>
#include <DHT.h>
#include "Pair.h"
#include "Tiempo.h"
#include "Valvula.h"
#include "Tiempo_Riego.h"

#define NUM_CONDICIONES 5
#define PIN_TEMPERATURA 20


class Riego
{
public:
	enum class Valvula_t
	{
		NORMAL,
		ADITIVA,

		//Añadir valvulas por encima
		NUM_VALVULAS
	};
private:
	RTC_DS3231 clock;
	const String nombre_dias[7] PROGMEM = { "Domingo", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado" };
	const String nombre_meses[12] PROGMEM = { "Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre" };
	Pair<Tiempo_Riego, Valvula_t> condiciones[NUM_CONDICIONES];
	unsigned condiciones_activas = 0;
	Valvula valvulas[(unsigned)Riego::Valvula_t::NUM_VALVULAS];
	DHT sensor_temperatura = DHT(PIN_TEMPERATURA, DHT22);
public:
	Riego(const Pair<unsigned, Riego::Valvula_t>[]);
	void init();
	void loop();
	const DateTime get_fecha() PROGMEM;
	String get_fecha_str();
	void set_condicion(const Tiempo_Riego, const Valvula_t);
	void set_condicion(const Pair<Tiempo_Riego, Valvula_t>);
	void set_condicion(const Pair<Tiempo_Riego, Valvula_t>[]);
	double get_temperatura();
	double get_humedad();
};
#endif

