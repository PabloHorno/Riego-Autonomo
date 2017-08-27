#include "Tiempo.h"




Tiempo::Tiempo(unsigned hora, unsigned minuto, unsigned segundo)
{
	this->hora = hora;
	this->minuto = minuto;
	this->segundo = segundo;

	while (this->segundo > 60)
	{
		this->segundo -= 60;
		this->minuto++;
	}
	while (this->minuto > 60)
	{
		this->minuto -= 60;
		this->hora++;
	}
}

bool operator<(const Tiempo a, const Tiempo b)
{
	return (a.hora < b.hora && a.minuto < b.minuto &&  a.segundo < b.segundo);
}

bool operator>(const Tiempo a, const Tiempo b)
{
	return (a.hora > b.hora && a.minuto > b.minuto &&  a.segundo > b.segundo);
}

Tiempo operator+(const Tiempo a, const Tiempo b)
{
	return Tiempo(a.hora + b.hora, a.minuto + b.minuto, a.segundo + b.segundo);
}

Tiempo& Tiempo::operator+=(const Tiempo& b)
{
	this->hora += b.hora;
	this->minuto += b.minuto;
	this->segundo += b.segundo;
	return *this;
}