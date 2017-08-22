#include "Riego.h"



Riego::Riego(unsigned valvula0, unsigned valvula1)
{
	valvula_pin[0] = valvula0;
	valvula_pin[1] = valvula1;
}

void Riego::begin()
{
	valvula[0].attach(valvula_pin[0]);
	valvula[1].attach(valvula_pin[1]);
}

Riego::~Riego()
{
}
