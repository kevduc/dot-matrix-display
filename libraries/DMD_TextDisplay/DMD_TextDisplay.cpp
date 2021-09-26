/*
	DMD_TextDisplay.cpp - Dot-matrix text display library
	Copyright (c) 2018 Kev Duc. All right reserved.
*/

#include "DMD_TextDisplay.h"

#include "ASCII_PixelFont.h"
#include "DMD.h"

#include "Arduino.h"

#define MAX_FRAME_CNT 100

DMD_TextDisplay::DMD_TextDisplay(DMD* dmd, String txt) : _dmd(dmd) {
  _frameRepeatNb = 15;
  setText(txt);
}

// Public Methods //////////////////////////////////////////////////////////////

void DMD_TextDisplay::setText(String txt) {
  if (txt.length() == 0)
    _txt = " ";
  else
    _txt = txt;
  
  update();
}

// speed between 0 - 100
void DMD_TextDisplay::setSpeed(unsigned int speed) {
  if (speed >= MAX_FRAME_CNT)
    _frameRepeatNb = 0;
  else
    _frameRepeatNb = MAX_FRAME_CNT - speed;
}

void DMD_TextDisplay::dispFrame() {
  unsigned long tempCol;
  uint8_t data;

  _dmd->dispOn();
  
  for (unsigned long i = 0; i < _dmd->getNbCols(); i++) {
    tempCol = (_currCol + _txtNbCols - i) % _txtNbCols;
    data = ASCII_PixelFont(_txt.c_str(), tempCol);
    _dmd->dispCol(&data);
  }

  _dmd->dispOff();

  if (_frameRepeatNb != MAX_FRAME_CNT && ++_frameCnt >= _frameRepeatNb) {
    _currCol = (_currCol + 1) % _txtNbCols;
    _frameCnt = 0;
  }
}

// Private Methods /////////////////////////////////////////////////////////////

void DMD_TextDisplay::update() {
  _currCol = 0;
  _frameCnt = 0;
  _txtNbCols = (_txt.length()-1)*PIXELFONT_CHAR_WIDTH;
}
