/*
	ASCII_PixelFont.h
	Copyright (c) 2018 Kev Duc. All right reserved.
*/

#ifndef ASCII_PIXELFONT_H
#define ASCII_PIXELFONT_H

#include <stdint.h>

#define PIXELFONT_NB_CHARS 128
#define PIXELFONT_CHAR_WIDTH 6

uint8_t ASCII_PixelFont(char c, unsigned int col);
uint8_t ASCII_PixelFont(const char s[], unsigned int col);

#endif // ASCII_PIXELFONT_H

