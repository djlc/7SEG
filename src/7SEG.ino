#include <Arduino.h>

/*
 Name:		_7SEG.ino
 Created:	2016/02/18 23:11:55
 Author:	djlc
*/

// the setup function runs once when you press reset or power the board
#include "7SEGLib.h"
#include "ShiftRegister.h"

_7SEG display(new ShiftRegister(2, 3, 4));

void setup() {

}

// the loop function runs over and over again until power down or reset
void loop() {
	static int i = 0;
	for (int j = 0; j < 256; j++) display.showNum(i, 0, false, 10);
	i++;
}
