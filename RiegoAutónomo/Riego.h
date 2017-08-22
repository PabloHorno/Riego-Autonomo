#pragma once
#include <Servo\src\Servo.h>
class Riego
{
public:
	Riego(unsigned, unsigned );
	void begin();
	~Riego();

private:
	Servo valvula[2];
	unsigned valvula_pin[2];
};

