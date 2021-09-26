/*
	DMD.cpp - Dot-matrix display library
	For A-1088BS_led-matrix + SN74HC595
	Copyright (c) 2018 Kev Duc. All right reserved.
*/

#include "DMD.h"

#include "Arduino.h"

DMD::DMD(unsigned long rowModules, unsigned long colModules, int rowDataPin, int rowClockPin, int colDataPin, int colClockPin, int latchPin, int outputEnablePin, int resetPin = -1) : 
    _rM(rowModules), _cM(colModules), 
		_rowDataPin(rowDataPin), _rowClockPin(rowClockPin), _colDataPin(colDataPin), _colClockPin(colClockPin), _latchPin(latchPin), _outputEnablePin(outputEnablePin), _resetPin(resetPin) {}

    
// Public Methods //////////////////////////////////////////////////////////////

void DMD::init() {
  pinInit();
  clocksInit();
  shiftRegsInit();
}

void DMD::clear() {
  if (_resetPin != -1) {
    digitalWrite(_resetPin, LOW); // clear
    digitalWrite(_resetPin, HIGH);
    push();
  }
}

void DMD::dispOn() {
	digitalWrite(_outputEnablePin, LOW); // enable output
}

void DMD::dispOff() {
	digitalWrite(_outputEnablePin, HIGH); // disable output
}

void DMD::dispCol(byte data[]) {
  for (unsigned int r = 0; r < _rM; ++r)
    shiftOut(_rowDataPin, _rowClockPin, LSBFIRST, data[r]);
  push();
  nextCol();
}

void DMD::dispMat(byte *data[]) {
  for (unsigned int c = 0; c < _cM; ++c)
    dispCol(data[c]);
}

unsigned long DMD::getNbCols() {
  return MODULE_SIZE*_cM;
}

// Private Methods /////////////////////////////////////////////////////////////


void DMD::nextCol() {
  // shift column
  digitalWrite(_colClockPin, HIGH);
  digitalWrite(_colClockPin, LOW);
}

void DMD::push() {
  // push data
  digitalWrite(_latchPin, HIGH);
  digitalWrite(_latchPin, LOW);
}


void DMD::pinInit() {
  pinMode(_outputEnablePin, OUTPUT);
  pinMode(_latchPin, OUTPUT);
  if (_resetPin != -1) pinMode(_resetPin, OUTPUT);

  pinMode(_colClockPin, OUTPUT);
  pinMode(_colDataPin, OUTPUT);

  pinMode(_rowClockPin, OUTPUT);
  pinMode(_rowDataPin, OUTPUT);
}

void DMD::clocksInit() {
  // lower the clocks
	digitalWrite(_latchPin, LOW);
	digitalWrite(_rowClockPin, LOW);
	digitalWrite(_colClockPin, LOW);
}

void DMD::shiftRegsInit() {
  dispOff();
  clear();
  colShiftRegsInit();
  dispOn();
}

void DMD::colShiftRegsInit() {
  // prepare col shift registers (turns all LEDs off)
	for (unsigned int c = 0; c < _cM; ++c)
    shiftOut(_colDataPin, _colClockPin, MSBFIRST, 0xFF);

	push();

	// shift a 0 to enable a column
	digitalWrite(_colDataPin, LOW);
	digitalWrite(_colClockPin, HIGH);
	digitalWrite(_colClockPin, LOW);
  
  // [optional] adjust col offset
	shiftOut(_colDataPin, _colClockPin, MSBFIRST, 0xFF);

	// disable _colDataPin to allow looping
	pinMode(_colDataPin, INPUT);
}