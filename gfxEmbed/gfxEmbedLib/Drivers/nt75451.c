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

uint16_t display_x_size = 0;
uint16_t display_y_size = 0;

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
void InitDriver(uint16_t x_size, uint16_t y_size){

    display_x_size = x_size;
    display_y_size = y_size;

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


// Name: setPageAddress
// Function: Select Display Page (row) to access 
// Parameter: Row number (0 is uppermost row)
// Returns: void
//----------------------------------------------------------------------------------
void setPageAddress(uint8_t page){
    uint8_t tmp = PAGE_ADDRESS_SET;         // Command's four least significant bits are the page address
    tmp |= (page & 0x0F);
    sendSPICmd(tmp);
}

// Name: setColumnAddress
// Function: Set the column of pixels to access
// Parameter: Column number (0 = left top corner if row = 0)
// Returns: void
//----------------------------------------------------------------------------------
void setColumnAddress(uint8_t column){
    uint8_t tmp = column;
    tmp = tmp >> 4;
    tmp |= COLUMN_ADDRESS_SET;
    sendSPICmd(tmp);            // Command bits and upper nibble of column number
    tmp = column & 0x0F;
    sendSPICmd(tmp);            // Lower nibble of column number
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
    uint16_t i, j = 0;
    uint8_t offset = 0;

    column = 0;
    row = 0;


    setPageAddress(row);
    setColumnAddress(column);

    for (j = 0; j < (display_y_size / 8); j++){
        for (i = 0; i < display_x_size; i++){

            // With this type of controller, if the display is wider than 128 pixels, special handling is required
            // Majority of displays using this controller (and clones) are 128 pixels wide
            if (display_x_size > 128){
                if (i >= 128){
                    //159
                    offset = (uint8_t)(display_x_size - 1) - column;      // (160 - 128 = 32)
                    offset += 0x60; 
                    setPageAddress(row + (display_y_size / 8));
                    setColumnAddress(offset);

                }
        
            }
            sendSPIData(0x00);
            column++;
        }
        
        row++;
        column = 0;
        setColumnAddress(column);
        setPageAddress(row);
    }
}


// Name: WriteFSGraphic
// Function: Fill entire LCD with graphics from a source
// Parameters: Pointer to source of bitmap data
// Returns: void
//-----------------------------------------------------------------------------
void WriteFSGraphic(uint8_t *bmpdata){
    uint16_t i, j, k = 0;
    uint8_t offset = 0;

    column = 0;
    row = 0;


    setPageAddress(row);
    setColumnAddress(column);

    for (j = 0; j < (display_y_size / 8); j++){
        for (i = 0; i < display_x_size; i++){

            // With this type of controller, if the display is wider than 128 pixels, special handling is required
            // Majority of displays using this controller (and clones) are 128 pixels wide
            if (display_x_size > 128){
                if (i >= 128){
                    //159
                    offset = (uint8_t)(display_x_size - 1) - column;      // (160 - 128 = 32)
                    offset += 0x60; 
                    setPageAddress(row + (display_y_size / 8));
                    setColumnAddress(offset);

                }
        
            }
            sendSPIData(bmpdata[k]);
            k++;
            column++;
        }
        
        row++;
        column = 0;
        setColumnAddress(column);
        setPageAddress(row);
    }
}
