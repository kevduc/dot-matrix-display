/*
	ASCII_PixelFont.cpp
	Copyright (c) 2018 Kev Duc. All right reserved.
*/

#include "ASCII_PixelFont.h"

#include <stdint.h>

const uint8_t pixelfont[PIXELFONT_NB_CHARS][PIXELFONT_CHAR_WIDTH] = {
   {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, 
   {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, 
   {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, 
   {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, 
   {0x00, 0x00, 0x00, 0x00, 0x00}, //  
   {0x00, 0x00, 0xDE, 0x00, 0x00}, // !
   {0x00, 0x06, 0x00, 0x06, 0x00}, // "
   {0x28, 0xFE, 0x28, 0xFE, 0x28}, // #
   {0x48, 0x54, 0xFE, 0x54, 0x24}, // $
   {0x46, 0x26, 0x10, 0xC8, 0xC4}, // %
   {0x6C, 0x92, 0xAC, 0x40, 0xA0}, // &
   {0x00, 0x00, 0x00, 0x06, 0x00}, // '
   {0x00, 0x38, 0x44, 0x82, 0x00}, // (
   {0x00, 0x82, 0x44, 0x38, 0x00}, // )
   {0x28, 0x10, 0x7C, 0x10, 0x28}, // *
   {0x10, 0x10, 0x7C, 0x10, 0x10}, // +
   {0x00, 0xA0, 0x60, 0x00, 0x00}, // ,
   {0x10, 0x10, 0x10, 0x10, 0x10}, // -
   {0x00, 0xC0, 0xC0, 0x00, 0x00}, // .
   {0x40, 0x20, 0x10, 0x08, 0x04}, // /
   {0x7C, 0xA2, 0x92, 0x8A, 0x7C}, // 0
   {0x00, 0x84, 0xFE, 0x80, 0x00}, // 1
   {0x84, 0xC2, 0xA2, 0x92, 0x8C}, // 2
   {0x42, 0x82, 0x8A, 0x96, 0x62}, // 3
   {0x30, 0x28, 0x24, 0xFE, 0x20}, // 4
   {0x4E, 0x8A, 0x8A, 0x8A, 0x72}, // 5
   {0x78, 0x94, 0x92, 0x92, 0x60}, // 6
   {0x02, 0xE2, 0x12, 0x0A, 0x06}, // 7
   {0x6C, 0x92, 0x92, 0x92, 0x6C}, // 8
   {0x0C, 0x92, 0x92, 0x52, 0x3C}, // 9
   {0x00, 0x6C, 0x6C, 0x00, 0x00}, // :
   {0x00, 0xAC, 0x6C, 0x00, 0x00}, // ;
   {0x10, 0x28, 0x44, 0x82, 0x00}, // <
   {0x28, 0x28, 0x28, 0x28, 0x28}, // =
   {0x00, 0x82, 0x44, 0x28, 0x10}, // >
   {0x04, 0x02, 0xA2, 0x12, 0x0C}, // ?
   {0x7C, 0x82, 0xBA, 0x92, 0x1C}, // @
   {0xFC, 0x12, 0x12, 0x12, 0xFC}, // A
   {0xFE, 0x92, 0x92, 0x92, 0x6C}, // B
   {0x7C, 0x82, 0x82, 0x82, 0x44}, // C
   {0xFE, 0x82, 0x82, 0x82, 0x7C}, // D
   {0xFE, 0x92, 0x92, 0x92, 0x82}, // E
   {0xFE, 0x12, 0x12, 0x12, 0x02}, // F
   {0x7C, 0x82, 0x92, 0x92, 0xF4}, // G
   {0xFE, 0x10, 0x10, 0x10, 0xFE}, // H
   {0x82, 0x82, 0xFE, 0x82, 0x82}, // I
   {0x40, 0x80, 0x82, 0x7E, 0x02}, // J
   {0xFE, 0x10, 0x28, 0x44, 0x82}, // K
   {0xFE, 0x80, 0x80, 0x80, 0x80}, // L
   {0xFE, 0x04, 0x18, 0x04, 0xFE}, // M
   {0xFE, 0x08, 0x10, 0x20, 0xFE}, // N
   {0x7C, 0x82, 0x82, 0x82, 0x7C}, // O
   {0xFE, 0x12, 0x12, 0x12, 0x0C}, // P
   {0x7C, 0x82, 0xA2, 0x42, 0xBC}, // Q
   {0xFE, 0x12, 0x32, 0x52, 0x8C}, // R
   {0x8C, 0x92, 0x92, 0x92, 0x62}, // S
   {0x02, 0x02, 0xFE, 0x02, 0x02}, // T
   {0x7E, 0x80, 0x80, 0x80, 0x7E}, // U
   {0x1E, 0x60, 0x80, 0x60, 0x1E}, // V
   {0x7E, 0x80, 0x70, 0x80, 0x7E}, // W
   {0xC6, 0x28, 0x10, 0x28, 0xC6}, // X
   {0x0E, 0x10, 0xE0, 0x10, 0x0E}, // Y
   {0xC2, 0xA2, 0x92, 0x8A, 0x86}, // Z
   {0x00, 0xFE, 0x82, 0x00, 0x00}, // [
   {0x04, 0x08, 0x10, 0x20, 0x40}, // \ //
   {0x00, 0x00, 0x82, 0xFE, 0x00}, // ]
   {0x08, 0x04, 0x02, 0x04, 0x08}, // ^
   {0x80, 0x80, 0x80, 0x80, 0x80}, // _
   {0x02, 0x04, 0x08, 0x00, 0x00}, // `
   {0x40, 0xA8, 0xA8, 0xA8, 0xF0}, // a
   {0xFE, 0x90, 0x88, 0x88, 0x70}, // b
   {0x70, 0x88, 0x88, 0x88, 0x40}, // c
   {0x70, 0x88, 0x88, 0x90, 0xFE}, // d
   {0x70, 0xA8, 0xA8, 0xA8, 0x30}, // e
   {0x10, 0xFC, 0x12, 0x02, 0x04}, // f
   {0x18, 0xA4, 0xA4, 0xA4, 0x7C}, // g
   {0xFE, 0x10, 0x08, 0x08, 0xF0}, // h
   {0x00, 0x88, 0xFA, 0x80, 0x00}, // i
   {0x40, 0x80, 0x88, 0x7A, 0x00}, // j
   {0xFE, 0x20, 0x50, 0x88, 0x00}, // k
   {0x00, 0x82, 0xFE, 0x80, 0x00}, // l
   {0xF8, 0x08, 0x30, 0x08, 0xF0}, // m
   {0xF8, 0x10, 0x08, 0x08, 0xF0}, // n
   {0x70, 0x88, 0x88, 0x88, 0x70}, // o
   {0xF8, 0x28, 0x28, 0x28, 0x10}, // p
   {0x10, 0x28, 0x28, 0x30, 0xF8}, // q
   {0xF8, 0x10, 0x08, 0x08, 0x10}, // r
   {0x90, 0xA8, 0xA8, 0xA8, 0x40}, // s
   {0x08, 0x7E, 0x88, 0x80, 0x40}, // t
   {0x78, 0x80, 0x80, 0x40, 0xF8}, // u
   {0x38, 0x40, 0x80, 0x40, 0x38}, // v
   {0x78, 0x80, 0x60, 0x80, 0x78}, // w
   {0x88, 0x50, 0x20, 0x50, 0x88}, // x
   {0x18, 0xA0, 0xA0, 0xA0, 0x78}, // y
   {0x88, 0xC8, 0xA8, 0x98, 0x88}, // z
   {0x10, 0x6C, 0x82, 0x82, 0x00}, // {
   {0x00, 0x00, 0xFE, 0x00, 0x00}, // |
   {0x00, 0x82, 0x82, 0x6C, 0x10}, // }
   {0x04, 0x02, 0x04, 0x08, 0x04}, // ~
   {0},
};

// Public Methods //////////////////////////////////////////////////////////////

uint8_t ASCII_PixelFont(char c, unsigned int col) {
  return pixelfont[(unsigned int)c][col];
}

uint8_t ASCII_PixelFont(const char s[], unsigned int col) {
  return ASCII_PixelFont(s[col / PIXELFONT_CHAR_WIDTH], col % PIXELFONT_CHAR_WIDTH);
}

// Private Methods /////////////////////////////////////////////////////////////

