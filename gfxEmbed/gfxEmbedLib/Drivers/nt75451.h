//
//  nt75451.h
//  Header file for Display Controller Driver NT75451.c
//  Author: Sonic2k
//  Date: 1 Jul 2025
//----------------------------------------------------------------------------
#include <msp430.h>

#ifndef NT75451_H_
#define NT75451_H_

// Commands
#define DISPLAY_ON 0xAF
#define DISPLAY_OFF 0xAE
#define DISPLAY_START_LINE_SET 0x40
#define PAGE_ADDRESS_SET 0xB0
#define COLUMN_ADDRESS_SET 0x10
#define ADC_SELECT_NORMAL 0xA0
#define ADC_SELECT_REVERSE 0xA1
#define NORMAL_DISPLAY 0xA6
#define REVERSE_DISPLAY 0xA7
#define ENTIRE_DISPLAY_ON 0xA4
#define ENTIRE_DISPLAY_OFF 0xA5
#define LCD_BIAS_SET_1_6_BIAS 0xA2
#define LCD_BIAS_SET_1_5_BIAS 0xA3
#define SET_READ_MODIFY_WRITE 0xE0
#define CANCEL_READ_MODIFY_WRITE 0xEE
#define RESET 0xE2
#define OUTPUT_STATUS_SELECT 0xC0
#define POWER_CONTROL_SET 0x28
#define POWER_CONTROL_SET_ALL_ON 0x2F
#define RESET_POWER_SAVING 0xE1
#define VOLTAGE_REGULATOR_RATIO_SET 0x20
#define E_VOLUME_SET 0x81
#define STATIC_INDICATOR_OFF 0xAC
#define STATIC_INDICATOR_ON 0xAD
#define NOP 0xE3
#define OSCILLATOR_FREQ_SET_31KHZ 0xE4
#define OSCILLATOR_FREQ_SET_26KHZ 0xE5
#define PARTIAL_DISPLAY_MODE_OFF 0x82
#define PARTIAL_DISPLAY_MODE_ON 0x83
#define PARTIAL_DISPLAY_DUTY 0x30
#define PARTIAL_START_LINE 0xD3
#define N_LINE_INVERSION 0x85
#define RELEASE_N_LINE_INVERSION 0x84
#define SELECT_DC_DC_SETUP 0x89
#define OTP_PROGRAMMING_SET 0xDF
#define OTP_E_VOLUME_SET 0xD2
#define TEST_COMMAND 0xF0



#endif /* NT75451_H_ */
// end of code  
  
