// Hora.h

#ifndef _HORA_h
#define _HORA_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

class Tiempo
{
 private:
	 unsigned millis_inicial = 0;
	 int hora = -1;
	 int minutos = -1;
	 int segundos = -1;
	 void actualizar_hora();

 public:
	 void init();
	 String get_hora_str();
};

#endif

