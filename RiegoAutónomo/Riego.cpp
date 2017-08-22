#include "Riego.h"



Riego::Riego(unsigned valvula1, unsigned valvula2)
{
	this->valvula1.attach(valvula1);
	this->valvula2.attach(valvula2);
}

void Riego::begin()
{
}

Riego::~Riego()
{
}
