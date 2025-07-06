//
//  gfxdriver.h
//  Common header for display drivers
//  Author: Sonic2k
//  Date: 6 Jul 2025
//----------------------------------------------------------------------------
#include <msp430.h>

#ifndef GFXDRIVER_H_
#define GFXDRIVER_H_

// Definitions
//------------

#define INTERFACE_CS_PIN BIT0               // Bit position on the port where CS is located
#define CS_PORT P1OUT                       // Port register that allows writing to the port where CS is located


// Macros
//--------

#define toggle ^=
#define clear &= ~
#define set |=

// GPIO interface macros for SERIALLY INTERFACED displays
// Set the port macro and port pin macro above before compiling

#define CS(y, x)  (x y INTERFACE_CS_PIN)        // macro writes  out a line of C code so P1OUT |= BIT0
                                                    //                                          ^  ^
                                                    //                                          |  |
                                                    //                                          |  "&=~" is parameter y as string     
                                                    //                                        "OUT" is parameter X as string

// Function Prototypes
//--------------------
void initDriver(void);



#endif /* GFXDRIVER_H_ */
