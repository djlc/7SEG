//
//
//

#include "7SEGLib.h"
#include "ShiftRegister.h"

_7SEG::_7SEG(ShiftRegister* SR) {
	this->SR = SR;
	init();
}

void _7SEG::init() {
	const char temp[2] = { 0b11111111 , ~0b00001000 };
	SR->sendData(temp, 2);
}

char _7SEG::convertNum(const int num) {
	switch (num) {
	case 0x0:
		return 0b11111100;
	case 0x1:
		return 0b01100000;
	case 0x2:
		return 0b11011010;
	case 0x3:
		return 0b11110010;
	case 0x4:
		return 0b01100110;
	case 0x5:
		return 0b10110110;
	case 0x6:
		return 0b10111110;
	case 0x7:
		return 0b11100000;
	case 0x8:
		return 0b11111110;
	case 0x9:
		return 0b11110110;
	case 0xA:
		return 0b11101110;
	case 0xB:
		return 0b00111110;
	case 0xC:
		return 0b10011100;
	case 0xD:
		return 0b01111010;
	case 0xE:
		return 0b10011110;
	case 0xF:
		return 0b10001110;
	case 0xFF:
		return 0b00000000;
	default:
		return 0b00000000;
	}
}

void _7SEG::showNum(const unsigned int num, const char dp, const bool zeroFill, const int radix) {

	char buf = 0;
	char temp[2] = { 0, 0 };

	// X000
	if (num >= radix*radix*radix) {
		buf = num / (radix*radix*radix);
	}
	else {
		buf = (zeroFill) ? 0 : 0xFF;
	}
	temp[0] = convertNum(buf) | ((dp & 0b00001000) >> 3);
	temp[1] = ~0b00001000;
	SR->sendData(temp, 2);

	// 0X00
	if (num >= radix*radix) {
		buf = (num % (radix*radix*radix)) / (radix*radix);
	}
	else {
		buf = (zeroFill) ? 0 : 0xFF;
	}
	temp[0] = convertNum(buf) | ((dp & 0b00000100) >> 2);
	temp[1] = ~0b00000100;
	SR->sendData(temp, 2);

	// 00X0
	if (num >= radix) {
		buf = (num % (radix*radix)) / radix;
	}
	else {
		buf = (zeroFill) ? 0 : 0xFF;
	}
	temp[0] = convertNum(buf) | ((dp & 0b00000010) >> 1);
	temp[1] = ~0b00000010;
	SR->sendData(temp, 2);

	// 000X
	buf = num % radix;
	temp[0] = convertNum(buf) | (dp & 0b00000001);
	temp[1] = ~0b00000001;
	SR->sendData(temp, 2);
}

void _7SEG::slotMachine(const unsigned int num) {
	for (int i = 0; i < 4; i++) {

	}
}
