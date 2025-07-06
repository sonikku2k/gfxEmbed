# gfxEmbed
Embedded Graphics Library for Microcontrollers

## Introduction
This is a common Graphics Library for Microcontrollers. This brings together all the code written as far back as 1999
for microcontrollers of all kinds from PIC to ARM. Formerly this code project was known as GraphLCD, but due to version hell
I have decided to create a new version and ensure all new applications reference this single Git repository.

## Why yet another library?
I wrote much of this software in the late 1990s, long before libraries were available from others online. Indeed I might have influenced many of those
libraries available nowadays, or maybe not, but much of my work here is derived from personal interests going back to 1999, where I was quite fascinated
with one of the first mobile phones to have a GUI, the Nokia 5110. Of course this library supports the "5110 LCD" as it's called in the trade and has for years.

Some of the work in this library was developed at the time for the SEGA Dreamcast, particularly the Visual Memory Unit. At least one font in this library
was specifically created for downloadable mini-games and animations that were run on the Dreamcast VMU.

I also have a good eye for design, and with this library you will not get that "generic Chinese" look that one sees on so many LCD/OLED displays of various kinds
of gadgets these days. Most of the fonts I created here were influenced by proper continental typefaces, NOT the generic codepage Roman fonts seen on
computers set to the Asian locale. The bulk of this work was done at a time when Windows XP was my main OS, and therefore at least one font is based on the 
default Windows XP system font (Trebuchet)

## Features
Provides a one-stop shop library compatible with all the fonts, drivers and legacy code I wrote for Graphics LCD displays, 
thermal printers, OLED displays, and TFT displays over the years. With the recent introduction of e-Paper displays it has become
necessary to modernize this software.

## Supported Microcontrollers
At a minimum, without the use of a frame buffer, this software should compile for any mid-range PIC microcontroller.
At a bare minimum, with a single font, you can estimate that this code will consume around 8Kbytes of FLASH space. This increases dramatically
the moment you hook printf() into this library. 

The main determining factor of how many features are supported and how many fonts are available is the available FLASH space. 
Microcontrollers generally have very limited FLASH ROM and even more limited RAM.

## Asian language Support
I am currently developing a means to add Shift-JIS to this library. Much of this work is done, but the testing thereof requires time and at a minimum a processor
with sufficient resources as one JIS font consumes at least 200K of FLASH (and that's just coverage of the Joyo Kanji, Hiragana, and Katakana).
Japanese language support will be diffcult, and only usable on large, 32 bit embedded processors, such as the ARM Cortex M3 series or embedded Linux SoCs.

## Testing
Much of this code is tested on a TI MSP430G2553 microcontroller. This particular platform is chosen as a bare minimum as it compares favourably to the midrange PICMicro and other cheap microcontrollers such as the AVR. In addition, the MSP430 is probably the lowest upfront cost, as the other platforms' programmers/ISP units are quite expensive, whereas a complete MSP430 board with integrated MSP-FET debugger can be had
for less than 1/3 of the price.



