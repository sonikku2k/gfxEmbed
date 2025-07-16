//
//  gfxEmbedLib.h
//
//  Header file for gfxEmbedLib.c
//  Author: Sonic2k
//  Date: 06 Jul 2025
//
//----------------------------------------------------------------------------

#ifndef GFXEMBEDLIB_H_
#define GFXEMBEDLIB_H_

#include <stdint.h>             // Use standardized types

// Definitions
//--------------------



// Function Prototypes
//--------------------
void Init_gfx(void);
void Put_graphic(uint8_t *bmp);
void Set_Font(int * fontName);
void Put_Char(unsigned char c);
void Clear_Display(void);
void Print_Text(char *string);
void Set_Location(uint8_t x, uint8_t y);



#endif /* GFXEMBEDLIB_H_ */
