#pragma once
#include <Servo\src\Servo.h>
class Riego
{
public:
	Riego(unsigned, unsigned );
	void begin();
	~Riego();

private:
	Servo valvula1;
	Servo valvula2;
};

