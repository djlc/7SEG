// _7SEGLib].h

#ifndef _7SEGLIB_h
#define _7SEGLIB_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

class ShiftRegister;

class _7SEG {
private:
	ShiftRegister* SR;
	void init();
	char convertNum(const int num);
public:
	_7SEG(ShiftRegister* SR);
	void showNum(const unsigned int num, const char dp, const bool zeroFill, const int radix);
	void slotMachine(const unsigned int num);
};

#endif
