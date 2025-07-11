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
#include "timer.h"
#include "nt75451.h"


// Variables
uint8_t column = 0;
uint8_t row = 0;

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




// Name: sendSPI
// SPI transmit function
// By default this is the bit-banger or you can call a routine to use SPI hardware in your MCU
//---------------------------------------------------------------------------------------------
void sendSPI(uint8_t data){

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

// Name: sendSPICmd
// Function: Sends the byte over the SPI bus as a command (C/D = 0)
// Parameters: Data byte to send
// Returns: void
//----------------------------------------------------------------------------------------------------------
void sendSPICmd(uint8_t cmdbyte){

    CMD_DATA(clear, CMD_DATA_PORT);     // C/D = 0
    CS(clear, CS_PORT);                 // Lower CS
    sendSPI(cmdbyte);                   // tx command
    CS(set, CS_PORT);                   // Raise CS
}

// Name: sendSPIData
// Function: Sends the byte over the SPI bus as data (C/D = 1)
// Parameters: Data byte to send
// Returns: void
//----------------------------------------------------------------------------------------------------------
void sendSPIData(uint8_t databyte){

    CMD_DATA(set, CMD_DATA_PORT);       // C/D = 1
    CS(clear, CS_PORT);                 // Lower CS
    sendSPI(databyte);            // tx data
    CS(set, CS_PORT);                   // Raise CS
}

//--------------------------------------------------------------------------------------------------------------
// Name: InitDisplay
// Function: Initialise the display module
// Parameters: void
// Returns: void
//--------------------------------------------------------------------------------------------------------------
void InitDisplay(void){
    sendSPICmd(STATIC_INDICATOR_OFF);                   // Static indicator off
    sendSPICmd(ADC_SELECT_NORMAL);                      // ADC SELECT
    sendSPICmd(OUTPUT_STATUS_SELECT);                   // SHL SELECT
    sendSPICmd(DISPLAY_START_LINE_SET);                 // Initial Display Line
    sendSPICmd(0x00);                                   // Column address LSB
    sendSPICmd(NORMAL_DISPLAY);                         // Reverse display OFF
    sendSPICmd(VOLTAGE_REGULATOR_RATIO_SET + 4);        // Set Ratio = 4
    sendSPICmd(E_VOLUME_SET);                           // Set Electronic volume
    sendSPICmd(0x17);                                   // E-Volume <= 0x17
    sendSPICmd(RESET_POWER_SAVING);                     // Reset Power Save modes (if available)
    sendSPICmd(POWER_CONTROL_SET_ALL_ON);               // Turn power ON
    sendSPICmd(DISPLAY_ON);                             // Turn display ON
}


//--------------------------------------------------------------------------------------------------------------
// Name: ClearDisplay
// Function: Clears display memory i.e. 0x00 is written, all pixels per byte = OFF
// Parameters: void
// Returns: void
//--------------------------------------------------------------------------------------------------------------
void ClearDisplay(void){
    int i = 0;
    uint8_t offset, tmp, tg = 0;

    sendSPICmd(0xB0);
    sendSPICmd(0x10);
    sendSPICmd(0x00);
    column = 0;
    row = 0;
    for (i = 0; i < 160; i++){

        if (i >= 128){

            offset = 159 - column;      // (160 - 128 = 32)
            offset += 0x60; 
            //offset = 0x60;
            sendSPICmd(0xB4);
            tmp = offset;
            tmp = tmp >> 4;
            tmp |= 0x10;
            sendSPICmd(tmp);
            tmp = offset & 0x0F;
            sendSPICmd(tmp);
            

        }
        tg ^= 0x01;
        if (tg == 0x01){
            sendSPIData(0x55);   
        } else {
            sendSPIData(0xAA); 
        }
        column++;
    }

 /*   offset = 0x60;
    sendSPICmd(0xB4);
    tmp = offset;
    tmp = tmp >> 4;
    tmp |= 0x10;
    sendSPICmd(tmp);
    tmp = offset & 0x0F;
    sendSPICmd(tmp);
    sendSPIData(0x55); */

    
    // Select Next page and column to get the rest of the line.. 
/*    sendSPICmd(0xB4);
    sendSPICmd(0x16);
    sendSPICmd(0x00);

   // Here the buffer is reverse read to fill the rest of the display WTAF
    for (i = 0; i < 32; i++){
        sendSPIData(0xFF);      
    }

    */



}



