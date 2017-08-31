// Tiempo_Riego.h

#ifndef _TIEMPO_RIEGO_h
#define _TIEMPO_RIEGO_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include <RTClib.h>
#include "Tiempo.h"

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

#endif

