#pragma once

class chrono {
public:
	chrono() {}
	unsigned long resultado;
	void start()
	{
		if(time == 0)
			time = millis();
	}
	unsigned long getTime()
	{
		return millis() - time;
	}
	void end()
	{
		resultado = millis() - time;
		time = 0;
	}
	void delay(unsigned long time, void (*callback_func)()) {
		this->start();
		if (this->getTime() > time)
		{
			Serial.print("Resultado ");
			Serial.println(this->getTime());
			this->end();
			callback_func();
		}
	}
private:
	unsigned long time;
};