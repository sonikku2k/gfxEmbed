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







// Name: Init_gfx
// Function: Top-down initialisation of the embedded graphics library
// Parameters: void
// Returns: void
//---------------------------------------------------------------------- 
void Init_gfx(void){
    InitDriver();           // Call init in driver
    InitDisplay();          // Initialize the display attached
    ClearDisplay();         // Clear display memory
}
