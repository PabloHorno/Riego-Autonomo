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
#include "Tiempo.h"
#include "Pair.h"

#define NUM_CONDICIONES 20
#define NUM_VALVULAS 2

class Condicion
{
public:
	Condicion();
	Condicion(const Tiempo);
	Condicion(const Tiempo, const char[], const Tiempo);

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
private:
	RTC_DS3231 clock;
	String const nombre_dias[7] = { "Domingo", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado" };
	String const nombre_meses[12] = { "Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre" };
	Pair<Condicion, unsigned> condiciones[NUM_CONDICIONES];
	unsigned condiciones_activas = 0;
	Valvula valvulas[NUM_VALVULAS];
public:
	Riego(const unsigned[]);
	void init();
	void loop();
	String get_fecha();
	void set_condicion(const Condicion, const unsigned);
	void set_condicion(const Pair<Condicion, unsigned>);
	void set_condicion(const Pair<Condicion, unsigned>[]);
};
#endif

