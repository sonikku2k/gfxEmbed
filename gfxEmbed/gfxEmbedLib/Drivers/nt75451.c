//----------------------------------------------------------------------------------------------------------------------------------------
//
//      Filename: nt75451.c
//      Driver for Novatek NT75451 LCD display controller LSI in SERIAL (SPI) interface mode
//      Version 1.0
//      Author: Sonic2k
//      Date: 6 Jul 2025
//
//----------------------------------------------------------------------------------------------------------------------------------------

#include "gfxdriver.h"          // Include common display header



// Functions
//---------------------------

// Name: Init
// Function: Initialise the driver to a known state, including the GPIO port pins as defined in the header
//           This does not initialise the display, only the interfacing to it
// Parameters: void
// Returns: void
//----------------------------------------------------------------------------------------------------------
void initDriver(void){
    CS(set, CS_PORT);

}



