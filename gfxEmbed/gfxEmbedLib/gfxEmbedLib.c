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





// Name: Put_graphic
// Function: Fill entire LCD with graphics using a function exposed by the library
// Parameters: Pointer to array that contains bitmap data
// Returns: void
//---------------------------------------------------------------------------------
void Put_graphic(uint8_t *bmp){
    WriteFSGraphic(bmp);
}


// Name: Init_gfx
// Function: Top-down initialisation of the embedded graphics library
// Parameters: void
// Returns: void
//---------------------------------------------------------------------- 
void Init_gfx(void){
    InitDriver(160, 32);     // Call init in driver
    InitDisplay();                          // Initialize the display attached
    ClearDisplay();                         // Clear display memory
}
