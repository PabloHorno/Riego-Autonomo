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


class Condicion
{
public:
	Condicion();
	Condicion(const DateTime);
	Condicion(const DateTime, const char[], const DateTime);

	bool se_cumple_condicion(const DateTime);
	bool operator()(const DateTime);
	void set_dias_semanas(const char[]);
	void set_hora(const unsigned, const unsigned, const unsigned);
	void set_duracion(const DateTime);
	void loop();

private:
	bool dias_semana[7] = { false,false,false,false,false,false,false };
	DateTime fecha;
	DateTime duracion;
};

class Riego
{
private:
	RTC_DS3231 clock;
	String const nombre_dias[7] = { "Domingo", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado" };
	String const nombre_meses[12] = { "Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre" };
	enum class estado{ ABIERTA, CERRADA, DESCONOCIDA};
	Condicion condiciones[20];
	unsigned pin_valvula[10];
public:
	Riego(const unsigned[]);
	void init();
	String get_fecha();
};
#endif

