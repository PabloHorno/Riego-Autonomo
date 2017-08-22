// Riego.h

#ifndef _RIEGO_h
#define _RIEGO_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

class RiegoClass
{
 protected:


 public:
	void init();
};

extern RiegoClass Riego;

#endif

