//
//  gfxdriver.h
//  Common header for display drivers
//  Author: Sonic2k
//  Date: 6 Jul 2025
//----------------------------------------------------------------------------
#include <msp430.h>

#ifndef GFXDRIVER_H_
#define GFXDRIVER_H_

// Definitions for BIT-BANG SPI interface
//----------------------------------------

#define INTERFACE_CS_PIN BIT0               // Bit position on the port where CS is located
#define INTERFACE_RST_PIN BIT1              // Bit position on the port where RST is located
#define INTERFACE_CMD_DATA_PIN BIT2         // Bit position on the port where C/D is located
#define INTEFRACE_SCLK_PIN BIT3             // Bit positon on the port where SCLK is located
#define INTERFACE_SDATA_PIN BIT4            // Bit position on the port where SDATA is located


#define CS_PORT P1OUT                       // Port register that allows writing to the port where CS is located
#define RST_PORT P1OUT                      // Port register that allows writing to the port where RST is located
#define CMD_DATA_PORT P1OUT                 // Port register that allows writing to the port where C/D is located
#define SCLK_PORT P1OUT                     // Port register that allows writing to the port where SCLK is located
#define SDATA_PORT P1OUT                    // Port register that allows writing to the port where SDATA is located


// Macros
//--------

#define toggle ^=
#define clear &= ~
#define set |=

// GPIO interface macros for SERIALLY INTERFACED displays
// Set the port macro and port pin macro above before compiling

#define RST(y, x) (x y INTERFACE_RST_PIN)
#define CMD_DATA(y, x) (x y INTERFACE_CMD_DATA_PIN)
#define SCLK(y, x) (x y INTEFRACE_SCLK_PIN)
#define SDATA(y, x) (x y INTERFACE_SDATA_PIN)
#define CS(y, x)  (x y INTERFACE_CS_PIN)        // macro writes  out a line of C code so P1OUT |= BIT0
                                                    //                                          ^  ^
                                                    //                                          |  |
                                                    //                                          |  "&=~" is parameter y as string     
                                                    //                                        "OUT" is parameter X as string

// Function Prototypes
//--------------------
void InitDriver(uint16_t x_size, uint16_t y_size);
void InitDisplay(void);
void ClearDisplay(void);
void WriteFSGraphic(uint8_t *bmpdata);
void SetFont(int *fontName);
void PutChar(unsigned char c);


#endif /* GFXDRIVER_H_ */
