/*
	DMD_TextDisplay.h - Dot-matrix text display library
	Copyright (c) 2018 Kev Duc. All right reserved.
*/

#ifndef DMD_TEXTDISPLAY_H
#define DMD_TEXTDISPLAY_H

#include "Arduino.h"
#include "DMD.h"

class DMD_TextDisplay {
	public:
		DMD_TextDisplay(DMD* dmd, String txt);
    void setText(String txt);
    void setSpeed(unsigned int speed); // speed between 0 - 100
    void dispFrame();

	private:
    DMD* _dmd;
    String _txt;
    unsigned long _txtNbCols;
    unsigned long _frameRepeatNb;
    unsigned long _frameCnt;
    unsigned long _currCol;
    
		void update();
};

#endif // DMD_TEXTDISPLAY_H

