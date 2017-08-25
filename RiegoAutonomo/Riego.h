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

class Riego
{
 protected:
	 RTC_DS3231 clock;
	 String const nombre_dias[7] = { "Domingo", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado" };
	 String const nombre_meses[12] = { "Enero", "Febrero", "Marzo", "Abril", "Mayo",  "Junio", "Julio","Agosto","Septiembre","Octubre","Noviembre","Diciembre" };

 public:
	void init();
	String get_fecha();
};

class Condicion
{
public:
	Condicion();
	Condicion(const DateTime);
	Condicion(const DateTime,const unsigned);

	bool se_cumple_condicion(DateTime);
	bool operator()(DateTime);
private:
	DateTime fecha;
	unsigned duracion;
};

#endif

