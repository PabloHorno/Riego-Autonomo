// Valvula.h

#ifndef _VALVULA_h
#define _VALVULA_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

class Valvula
{
public:
	Valvula(unsigned pin) { pin_valvula = pin; }
	Valvula() {};
	enum class estado_enum { ABIERTO, CERRADO, DESCONOCIDO };
	estado_enum estado = estado_enum::DESCONOCIDO;
	void init();
	void abrir();
	void cerrar();
private:
	unsigned pin_valvula = 0;
};

#endif

