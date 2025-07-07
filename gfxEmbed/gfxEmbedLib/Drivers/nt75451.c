//----------------------------------------------------------------------------------------------------------------------------------------
//
//      Filename: nt75451.c
//      Driver for Novatek NT75451 LCD display controller LSI in SERIAL (SPI) interface mode
//      Version 1.0
//      Author: Sonic2k
//      Date: 6 Jul 2025
//
//----------------------------------------------------------------------------------------------------------------------------------------

#include <stdint.h>             // Use standardized types
#include "gfxdriver.h"          // Include common display header


// Functions
//---------------------------

// Name: reset_timer
// Function: Rough software timer to generate a small delay (few uS) for the RESET signal
// Parameters: void
// Returns: void
//---------------------------------------------------------------------------------------------------------
void reset_timer(void){
    uint16_t count;
    for(count = 0; count < 10; count++){
        ;
    }
}

// Name: InitDriver
// Function: Initialise the driver to a known state, including the GPIO port pins as defined in the header
//           This does not initialise the display, only the interfacing to it
// Parameters: void
// Returns: void
//----------------------------------------------------------------------------------------------------------
void InitDriver(void){
    CS(set, CS_PORT);                       // Chip Select = high
    CMD_DATA(clear, CMD_DATA_PORT);         // C/D = low
    RST(clear, RST_PORT);                   // Pull RESET low
    SCLK(clear, SCLK_PORT);                 // SCLK pulled low
    SDATA(clear, SDATA_PORT);               // SDATA pulled low

    // Hold reset low for 10uS max
    reset_timer();
    RST(set, RST_PORT);                     // Raise RESET
    reset_timer();      

}



// Name: sendSPICmd
// Function: Sends the byte over the SPI bus as a command (C/D = 0)
// Parameters: Data byte to send
// Returns: void
//----------------------------------------------------------------------------------------------------------
void sendSPICmd(uint8_t data){

    uint8_t bitcount = 0;


    // Loop to shift out the data bits, MSB first
    for (bitcount = 0; bitcount < 8; bitcount++){
        if((data & 0x80) == 0x80){
            SDATA(set, SDATA_PORT);     // SDATA line = H
        } else {
            SDATA(clear, SDATA_PORT);   // SDATA line = L
        }
        data <<= 1;     // left shift 1
        SCLK(set, SCLK_PORT);
        asm (" nop");
        asm (" nop");
        asm (" nop");
        asm (" nop");
        SCLK(clear, SCLK_PORT);
    }
}




//--------------------------------------------------------------------------------------------------------------
// Name: InitDisplay
// Function: Initialise the display module
// Parameters: void
// Returns: void
//--------------------------------------------------------------------------------------------------------------
void InitDisplay(void){
    sendSPICmd(0xAA);
}






