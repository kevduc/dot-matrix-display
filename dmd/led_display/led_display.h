#ifndef __LED_DISPLAY_H__
#define __LED_DISPLAY_H__

#include "stdint.h"

#define ASCII_NB_CHARS 128
#define CHAR_WIDTH 6

void LED_Display_Config(char * string, unsigned int length, uint16_t period); // period in units 100us, period > 1
void LED_Display_Set_String(char * string, unsigned int length);              // sets the string to display

void LED_Display_Start(void); // starts displaying
void LED_Display_Stop(void);  // stops displaying

#endif // __LED_DISPLAY_H__
