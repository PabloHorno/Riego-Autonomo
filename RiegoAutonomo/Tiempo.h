#pragma once

class Tiempo
{
public:
	Tiempo(unsigned hora = 0, unsigned minuto = 0, unsigned segundo = 0);

	friend bool operator<(const Tiempo, const Tiempo);
	friend bool operator>(const Tiempo, const Tiempo);
	friend Tiempo operator+(const Tiempo, const Tiempo);
	Tiempo& operator+=( const Tiempo&);
private:
	unsigned hora, minuto, segundo;
};
