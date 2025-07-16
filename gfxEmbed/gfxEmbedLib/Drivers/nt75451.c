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
#include <stdbool.h>
#include "gfxdriver.h"          // Include common display header
#include "timer.h"
#include "nt75451.h"
#include "gfxconfig.h"


// Variables
//--------------------------------------------------------------------------------------------------------
uint8_t column = 0;
uint8_t row = 0;

uint16_t display_x_size = DISPLAY_HORIZONTAL_SIZE;
uint16_t display_y_size = DISPLAY_VERTICAL_SIZE;

int *font_data_ptr;

uint8_t debug_var = 0;
uint8_t debug_var_2 = 0;
uint8_t BaselineShift = 0;
uint8_t masking;
bool Inverted;


// Functions
//---------------------------

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
// Function: Select Display Page (row) to access in the LCD controller
// Parameter: Row number (0 is uppermost row)
// Returns: void
//----------------------------------------------------------------------------------
void setPageAddress(uint8_t page){
    uint8_t tmp = PAGE_ADDRESS_SET;         // Command's four least significant bits are the page address
    tmp |= (page & 0x0F);
    sendSPICmd(tmp);
}

// Name: setColumnAddress
// Function: Set the column of pixels to access in the LCD controller
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



void SetInverseMode(uint8_t mask){
    Inverted = true;
    masking = mask;
}

void ClearInverseMode(){
    Inverted = false;
}

void SetBaselineShift(uint8_t shift){
    BaselineShift = shift;
}

// Name: SetFont
// Function: Set the font pointer to reference memory where the font in use lives
// Parameters: Pointer (address) to location in memory (or FLASH) of font glyph tables
// Returns: void
//---------------------------------------------------------------------------------------------------------
void SetFont(int *fontName){
    font_data_ptr = fontName;
}


// Name: putPixels
// Function: Places a column (or row) of pixels on the LCD by writing to the LCD
//           it auto-increments the row and column, and also handles quirks of wide LCD displays
// Parameters: column or row of pixel data (8 bits = 8 pixels)
// Returns: void
//---------------------------------------------------------------------------------------------------------
void putPixels(uint8_t pixels){

    uint8_t offset;
    // With this type of controller, if the display is wider than 128 pixels, special handling is required
    // Majority of displays using this controller (and clones) are 128 pixels wide
    if (display_x_size > 128){
        if (column >= 128){
            //159
            offset = (uint8_t)(display_x_size - 1) - column;      // (160 - 128 = 32)
            offset += 0x60; 
            setPageAddress(row + (display_y_size / 8));
            setColumnAddress(offset);

        }
        
    }
    sendSPIData(pixels);
    column++;
}


// Name: PutChar
// Function: Put a character at the current location on the display with the currently selected font
// Parameters: Character code (ASCII)
// Returns: void
void PutChar(unsigned char c){

    unsigned char *px;                      // Declare pointer variable 
    unsigned int font_ptr;                  // Font array address storage
    unsigned char rcnt;
    unsigned char run_length;
    unsigned char char_height;
    unsigned char ref_height;
    unsigned char glyph;
    px = 0;                                 // Reset pointer at runtime 
    
    
    font_ptr = font_data_ptr[c];
    px = (px + (font_ptr));                 // Set pointer to point to font data

    // Process character's header information 
    debug_var = *px;                        // Get the header as it stands so we can evaluate in the debugger
    run_length = (*px & 0x1F);              // Extract run-length value 
    char_height = (*px & 0xC0);             // Extract cell height bits 
    char_height = ((char_height >> 6) & 0x03);
    ref_height = char_height;
    char_height++;                          // Offset by 1 
    px++;                                   // Increment to next address 
    debug_var_2 = *px;

    // Render character at current location
    while(char_height != 0){
        for (rcnt = 0; rcnt < run_length; rcnt++){

            glyph = *px;

            // Process baseline shift, if any
            if(BaselineShift > 0){
                glyph = glyph >> BaselineShift;
            }

            // Process masking, if any
            if(Inverted == true){
                glyph = ~glyph & masking;
            }
            putPixels(glyph);             // Put glyph data on display
            px++;                         // Increment pointer
        }
                              
        if(Inverted == true){
            putPixels(0xFF & masking);
        } else {
            putPixels(0x00);           // Inter-character whitespace
        }
        char_height--;
        if (char_height != 0){
            row++;      /* If more than 1 row high, switch to next line */
            column = column - run_length;
            column--;
            setPageAddress(row);
            setColumnAddress(column);
        }
    }
    // Restore original display row
    row = (row - ref_height);
    setPageAddress(row);
    setColumnAddress(column);
}

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


// Name: PrintText
// Function: Basic text print function in the absence of printf() on constrained systems. Does NOT provide escape sequences or any format specifiers
// Parameters: Pointer to text string (array of bytes)
// Returns: void
//---------------------------------------------------------------------------------------------------------------------------------------------------
void PrintText(char * string){

    char c = 0;
    int x = 0;

    for(;;){
        c = string[x];
        if(c == 0){
            return;
        } else {
            PutChar(c);
        }
        x++;
    }

}


// Name: gotoxy
// Function: Set current location on the LCD display
// Parameters: X location in pixels from top left corner, Y location in lines from top left corner
// Returns: void
//-----------------------------------------------------------------------------------------------------------------------------------------------
void gotoxy(uint8_t x, uint8_t y){
    column = x;
    row = y;
    setColumnAddress(column);
    setPageAddress(row);
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

    column = 0;
    row = 0;


    setPageAddress(row);
    setColumnAddress(column);

    for (j = 0; j < (display_y_size / 8); j++){
        for (i = 0; i < display_x_size; i++){

            putPixels(0x00);

        }
        
        row++;
        column = 0;
        setColumnAddress(column);
        setPageAddress(row);
    }

    column = 0;
    row = 0;
    setPageAddress(row);
    setColumnAddress(column);
}


// Name: WriteFSGraphic
// Function: Fill entire LCD with graphics from a source
// Parameters: Pointer to source of bitmap data
// Returns: void
//-----------------------------------------------------------------------------
void WriteFSGraphic(uint8_t *bmpdata){
    uint16_t i, j, k = 0;

    column = 0;
    row = 0;


    setPageAddress(row);
    setColumnAddress(column);

    for (j = 0; j < (display_y_size / 8); j++){
        for (i = 0; i < display_x_size; i++){

            putPixels(bmpdata[k]);
            k++;
        }
        
        row++;
        column = 0;
        setColumnAddress(column);
        setPageAddress(row);
    }

    column = 0;
    row = 0;
    setPageAddress(row);
    setColumnAddress(column);
}
