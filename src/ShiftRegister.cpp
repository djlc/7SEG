// 
// 
// 

#include "ShiftRegister.h"

ShiftRegister::ShiftRegister(const int SER, const int RCLK, const int SRCLK)
	: SER(SER), RCLK(RCLK), SRCLK(SRCLK) {

	pinMode(this->SER, OUTPUT);
	digitalWrite(this->SER, LOW);
	pinMode(this->RCLK, OUTPUT);
	digitalWrite(this->RCLK, LOW);
	pinMode(this->SRCLK, OUTPUT);
	digitalWrite(this->SRCLK, LOW);

	send8bitData(B00000000);
}

ShiftRegister::~ShiftRegister() {
}

void ShiftRegister::send8bitData(const char data) {
	digitalWrite(RCLK, HIGH);
	shiftOut(SER, SRCLK, LSBFIRST, data);
	digitalWrite(RCLK, LOW);
}

void ShiftRegister::sendData(const char * data, const int num) {
	digitalWrite(RCLK, HIGH);
	for (int i = 1; i <= num; i++) shiftOut(SER, SRCLK, LSBFIRST, data[num - i]);
	digitalWrite(RCLK, LOW);
}
