//----------------------------------------------------------------------------------------------------------------------------------------------------
//
//                                  gfxEmbedLib
//                           Embedded Graphics Display Library
//                                (C) 1999 - 2025 Sonic2k
//
//----------------------------------------------------------------------------------------------------------------------------------------------------

#include <stdint.h>             // Use standardized types
#include "gfxEmbedLib.h"
#include "Drivers/gfxdriver.h"
#include "gfxconfig.h"


// Name: Set_Font
// Function: Select font by name for character mode
// Parameter: Pointer to font definition table, usually a header file that contains a table
//            with matching array name(s)
//--------------------------------------------------------------------------------------------
void Set_Font(int * fontName){
    SetFont(fontName);
}

// Name: Put_Character
// Function: Place a character of the specified font at the specified location on the display
//--------------------------------------------------------------------------------------------
void Put_Char(unsigned char c){
    PutChar(c);
}

// Name: Put_graphic
// Function: Fill entire LCD with graphics using a function exposed by the library
// Parameters: Pointer to array that contains bitmap data
// Returns: void
//---------------------------------------------------------------------------------
void Put_graphic(uint8_t *bmp){
    WriteFSGraphic(bmp);
}

// Name: Clear_Display
// Function: Clears display contents
// Parameters: void
// Returns: void
//---------------------------------------------------------------------------------
void Clear_Display(void){
    ClearDisplay();
}


// Name: Init_gfx
// Function: Top-down initialisation of the embedded graphics library
// Parameters: void
// Returns: void
//---------------------------------------------------------------------- 
void Init_gfx(void){
    InitDriver();                           // Call init in driver
    InitDisplay();                          // Initialize the display attached
    ClearDisplay();                         // Clear display memory
}
