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
#include "Tiempo.h"
#include "Pair.h"

#define NUM_CONDICIONES 20

class Tiempo_Riego
{
public:
	Tiempo_Riego();
	Tiempo_Riego(const Tiempo);
	Tiempo_Riego(const Tiempo, const char[], const Tiempo);

	bool se_cumple_condicion(const DateTime);
	bool operator()(const DateTime);
	void set_dias_semanas(const char[]);
	void set_hora(const unsigned, const unsigned, const unsigned);
	void set_duracion(const Tiempo);

private:
	bool dias_semana[7] = { false,false,false,false,false,false,false };
	Tiempo hora;
	Tiempo duracion;
};

class Valvula
{
public:
	Valvula(unsigned pin) { pin_valvula = pin; }
	Valvula() {};
	enum class estado_enum { ABIERTO, CERRADO, DESCONOCIDO };
	estado_enum estado = estado_enum::DESCONOCIDO;
	void abrir();
	void cerrar();
private:
	unsigned pin_valvula = 0;
};

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
	String const nombre_dias[7] = { "Domingo", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado" };
	String const nombre_meses[12] = { "Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre" };
	Pair<Tiempo_Riego, Valvula_t> condiciones[NUM_CONDICIONES];
	unsigned condiciones_activas = 0;
	Valvula valvulas[(unsigned)Riego::Valvula_t::NUM_VALVULAS];
public:
	Riego(const Pair<unsigned, Riego::Valvula_t>[]);
	void init();
	void loop();
	String get_fecha();
	void set_condicion(const Tiempo_Riego, const Valvula_t);
	void set_condicion(const Pair<Tiempo_Riego, Valvula_t>);
	void set_condicion(const Pair<Tiempo_Riego, Valvula_t>[]);
};
#endif

