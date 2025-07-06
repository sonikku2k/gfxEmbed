//
//                main.c - Main Code File
//                Project: gfxEmbed
//
//                Main test application that implements tests for the gfxEmbed library
//                This application runs tests against the library on a MSP-EXP430G2ET Launchpad
//
//----------------------------------------------------------------------------------------------------------------------

#include <msp430.h>
#include "timer.h"


//------------------------------------------- Main Function -----------------------------------------------------------------------------------------
int main(void){
  
  
  WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer

    // Configure and calibrate system clock
    //--------------------------------------
    DCOCTL = 0;                                  // Select lowest DCOx and MODx settings
    BCSCTL1 = CALBC1_1MHZ;                       // Set range
    DCOCTL = CALDCO_1MHZ;                        // Set DCO step + modulation */
    BCSCTL2 = 0x00;



    // Configure ports
    //------------------
    P1DIR = 0x41;                               // P1.0 is connected to the leftmost green LED
    P1OUT = 0x00;


    // Configure WDT as systick timer
    //--------------------------------

    WDTCTL = WDT_MDLY_0_5 ;                     // Enable WDT with period of 500uS
    IE1 |= WDTIE;                               // Enable WDT interrupt
    __enable_interrupt();                       // Enable System interrupts
    InitTimerSystem();

    for(;;){
      Delay(1000);
      P1OUT ^= 0x01;                        // Toggle P1.0 using exclusive-OR
    }
}


// Watchdog Timer interrupt service routine
// Used here as a system timer
// Period is 65.6 uS
//---------------------------------------------------
#pragma vector=WDT_VECTOR
__interrupt void watchdog_timer(void){

    CallInISR();

}
