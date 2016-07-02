// ShiftRegister.h

#ifndef _SHIFTREGISTER_h
#define _SHIFTREGISTER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

class ShiftRegister {
	const int SER, RCLK, SRCLK;
public:
	ShiftRegister(const int SER, const int RCLK, const int SRCCK);
	~ShiftRegister();
	void send8bitData(const char data);
	void sendData(const char* data, const int num);
};

#endif
