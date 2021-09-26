/*
	DMD.h - Dot-matrix display library
	For A-1088BS_led-matrix + SN74HC595
	Copyright (c) 2018 Kev Duc. All right reserved.
*/

#ifndef DMD_H
#define DMD_H

#include "Arduino.h"

#define MODULE_SIZE 8

class DMD {
	public:
		DMD(unsigned long rowlModules, unsigned long colModules, int rowDataPin, int rowClockPin, int colDataPin, int colClockPin, int latchPin, int outputEnablePin, int resetPin);
		void init();
		void clear();
    void dispOn();
    void dispOff();
    void dispCol(byte data[]);
    void dispMat(byte *data[]);
    unsigned long getNbCols();

	private:
    unsigned long _rM;
    unsigned long _cM;
		int _rowDataPin;		int _rowClockPin;		int _colDataPin;		int _colClockPin;		int _latchPin;		int _outputEnablePin;		int _resetPin;
    
    void nextCol();
    void push();
    void pinInit();
    void clocksInit();
    void shiftRegsInit();
    void colShiftRegsInit();
};

#endif // DMD_H

