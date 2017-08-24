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
	 unsigned _millis = 0;
	 int _hora = -1;
	 int _minutos = -1;
	 int _segundos = -1;
	 void actualizar_hora();

 public:
	 int hora;
	 int minutos;
	 int segundos;
	 void init();
	 void init(unsigned, unsigned, unsigned);
	 String get_hora_str();
};

#endif

