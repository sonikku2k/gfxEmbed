//----------------------------------------------------------------------------------------------------------------------------------------------
//                  Filename: hitachi5x7.h
//              Font Header file for gfxEmbed
//              Copyright (C) 1999 - 2025 Sonikku
//
//              This font is taken from the Hitachi HD44780 LCD controller which is an industry standard
//              Since Hitachi Semiconductor no longer exists, this is considered to be in the public domain
//              
//              Not all the characters are defined, and some of the lower code tables have custom characters I added
//              for specific projects
//
//----------------------------------------------------------------------------------------------------------------------------------------------
#include "gfxconfig.h"

#ifndef HITACHI5X7_H
#define HITACHI5X7_H

#ifdef VERTICAL_ORIENTATION
const char h5x7_00 [] = {
                        0x05,
                        0x55, 0xAA, 0x55, 0xAA, 0x55
};

const char h5x7_01 [] = {
                         0x05,
                         0x7F, 0x7F, 0x7F, 0x7F, 0x7F
};
const char h5x7_02 [] = {
                         0x07,                                                  // Number 1, inverse in square with rounded corners
                         0x3E, 0x7F, 0x7B, 0x41, 0x7F, 0x7F, 0x3E
};
const char h5x7_03 [] = {
                         0x12,
                         0x1C, 0x14, 0x7F, 0x41, 0x71, 0x7D, 0x5F, 0x47,
                         0x71, 0x7D, 0x5F, 0x47, 0x71, 0x7D, 0x5F, 0x47, 0x41, 0x7F
};
const char h5x7_04 [] = {
                         0x0C,
                         0x12, 0x12, 0x3F, 0x21, 0x21, 0x21, 0x1E, 0x1C, 0x6C, 0x6C, 0x7C, 0x38
};
const char h5x7_05 [] = {
                         0x0A,
                         0x7F, 0x43, 0x45, 0x45, 0x49, 0x49, 0x45, 0x45, 0x43, 0x7F
};
const char h5x7_06 [] = {
                         0x13,
                         0x3E, 0x7F, 0x41, 0x7B, 0x77, 0x7B, 0x41, 0x7F, 0x41,
                         0x55, 0x5D, 0x7F, 0x41, 0x7B, 0x77, 0x7B, 0x41, 0x7F, 0x3E
};
const char h5x7_07 [] = {
                         0x07,
                         0x1C, 0x1C, 0x7F, 0x7F, 0x7F, 0x1C, 0x1C
};
const char h5x7_08 [] = {
                         0x0E,
                         0x06, 0x09, 0x06, 0x09, 0x40, 0x66, 0x7F, 0x7F, 0x66,
                         0x40, 0x09, 0x06, 0x09, 0x06
};
const char h5x7_09 [] = {
                         0x07,
                         0xDE, 0x57, 0x53, 0x51, 0x53, 0x57, 0xDE
};
const char h5x7_10 [] = {
                         0x07,
                         0x7B, 0xEA, 0xCA, 0x8A, 0xCA, 0xEA, 0x7B
};
const char h5x7_11 [] = {
                         0x07,
                         0xFF, 0x03, 0x03, 0x03, 0x03, 0x03, 0xFF
};
const char h5x7_12 [] = {
                         0x07,
                         0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF
};
const char h5x7_13 [] = {
                         0x12,
                         0x1C, 0x14, 0x7F, 0x41, 0x41, 0x41, 0x41, 0x41,
                         0x71, 0x7D, 0x5F, 0x47, 0x71, 0x7D, 0x5F, 0x47, 0x41, 0x7F
};
const char h5x7_14 [] = {
                         0x1D,
                         0xFE, 0xB6, 0x9A, 0xAA, 0xB6, 0xFE, 0xDE, 0xCE,
                         0xD6, 0x82, 0xDE, 0xFE, 0x9E, 0xEE, 0xF2, 0xFE, 0xF6, 0x82,            // 24/192 indicator
                         0xFE, 0xF6, 0xAA, 0xAA, 0xC6, 0xFE, 0xB6, 0x9A, 0xAA, 0xB6, 0xFE

};
const char h5x7_15 [] = {
                         0x1D,
                         0x7F, 0x41, 0x7F, 0x41, 0x7B, 0x77, 0x41, 0x7F,                        // INPUT 2 indicator
                         0x41, 0x75, 0x75, 0x7B, 0x7F, 0x61, 0x5F, 0x5F,
                         0x61, 0x7F, 0x7D, 0x41, 0x7D, 0x7F, 0x7F, 0x7F,
                         0x5B, 0x4D, 0x55, 0x5B, 0x7F

};
const char h5x7_16 [] = {
                         0x1D,
                         0x7F, 0x41, 0x7F, 0x41, 0x7B, 0x77, 0x41, 0x7F,                        // INPUT 1 indicator
                         0x41, 0x75, 0x75, 0x7B, 0x7F, 0x61, 0x5F, 0x5F,
                         0x61, 0x7F, 0x7D, 0x41, 0x7D, 0x7F, 0x7F, 0x7F,
                         0x7B, 0x41, 0x7F, 0x7F, 0x7F
};
const char h5x7_17 [] = {
                         0x1D,
                         0x7F, 0x41, 0x7F, 0x41, 0x7B, 0x77, 0x41, 0x7F,                        // INPUT 3 indicator
                         0x41, 0x75, 0x75, 0x7B, 0x7F, 0x61, 0x5F, 0x5F,
                         0x61, 0x7F, 0x7D, 0x41, 0x7D, 0x7F, 0x7F, 0x7F,
                         0x5D, 0x55, 0x69, 0x7F, 0x7F


};
const char h5x7_18 [] = {
                         0x08,
                         0xFE, 0x82, 0xFE, 0x82, 0xEA, 0xCA, 0xB6, 0xFE                         // IR ON indicator
};


const char h5x7_19 [] = {
                         0x08,
                         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00                         // Clear IR indicator
};


const char h5x7_20 [] = {
                         0x1D,
                         0xFE, 0xB6, 0x9A, 0xAA, 0xB6, 0xFE, 0xDE, 0xCE,
                         0xD6, 0x82, 0xDE, 0xFE, 0x9E, 0xEE, 0xF2, 0xFE,                        // 24/48 icon
                         0xDE, 0xCE, 0xD6, 0x82, 0xDE, 0xFE, 0xD6, 0xAA,
                         0xAA, 0xD6, 0xFE, 0xFE, 0xFE
};
const char h5x7_21 [] = {
                         0x1D,                                                                  // 24/44 icon
                         0xFE, 0xB6, 0x9A, 0xAA, 0xB6, 0xFE, 0xDE, 0xCE,
                         0xD6, 0x82, 0xDE, 0xFE, 0x9E, 0xEE, 0xF2, 0xDE,
                         0xCE, 0xD6, 0x82, 0xDE, 0xFE, 0xDE, 0xCE, 0xD6,
                         0x82, 0xDE, 0xFE, 0xFE, 0xFE
};
const char h5x7_22 [] = {
                         0x1D,
                         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                         0x00, 0x00, 0x00, 0x00, 0x00
};
const char h5x7_23 [] = {
                         0x05,
                         0x10, 0x38, 0x54, 0x10, 0x1F
};
const char h5x7_24 [] = {
                         0x05,
                         0x04, 0x02, 0x7F, 0x02, 0x04
};
const char h5x7_25 [] = {
                         0x05,
                         0x10, 0x20, 0x7F, 0x20, 0x10
};
const char h5x7_26 [] = {
                         0x05,
                         0x08, 0x08, 0x2A, 0x1C, 0x08
};
const char h5x7_27 [] = {
                         0x05,
                         0x08, 0x1C, 0x2A, 0x08, 0x08
};
const char h5x7_28 [] = {
                         0x05,
                         0x40, 0x44, 0x4A, 0x51, 0x40
};
const char h5x7_29 [] = {
                         0x05,
                         0x40, 0x51, 0x4A, 0x44, 0x40
};
const char h5x7_30 [] = {
                         0x05,
                         0x20, 0x38, 0x3E, 0x38, 0x20
};
const char h5x7_31 [] = {
                         0x05,
                         0x02, 0x0E, 0x3E, 0x0E, 0x02
};
//=====================================================================================
const char h5x7_32 [] = {
                         0x05,
                         0x00, 0x00, 0x00, 0x00, 0x00
};
const char h5x7_33 [] = {
                         0x05,
                         0x00, 0x00, 0x4F, 0x00, 0x00
};
const char h5x7_34 [] = {
                         0x05,
                         0x00, 0x07, 0x00, 0x07, 0x00
};
const char h5x7_35 [] = {
                         0x05,
                         0x14, 0x7F, 0x14, 0x7F, 0x14
};
const char h5x7_36 [] = {
                         0x05,
                         0x24, 0x2A, 0x7F, 0x2A, 0x12
};
const char h5x7_37 [] = {
                         0x05,
                         0x23, 0x13, 0x08, 0x64, 0x62
};
const char h5x7_38 [] = {
                         0x05,
                         0x36, 0x49, 0x55, 0x22, 0x50
};
const char h5x7_39 [] = {
                         0x05,
                         0x00, 0x05, 0x03, 0x00, 0x00
};
const char h5x7_40 [] = {
                         0x05,
                         0x00, 0x1C, 0x22, 0x41, 0x00
};
const char h5x7_41 [] = {
                         0x05,
                         0x00, 0x41, 0x22, 0x1C, 0x00
};
const char h5x7_42 [] = {
                         0x05,
                         0x14, 0x08, 0x3E, 0x08, 0x14
};
const char h5x7_43 [] = {
                         0x05,
                         0x08, 0x08, 0x3E, 0x08, 0x08
};
const char h5x7_44 [] = {
                         0x05,
                         0x00, 0x50, 0x30, 0x00, 0x00
};
const char h5x7_45 [] = {
                         0x05,
                         0x08, 0x08, 0x08, 0x08, 0x08
};
const char h5x7_46 [] = {
                         0x05,
                         0x00, 0x60, 0x60, 0x00, 0x00
};
const char h5x7_47 [] = {
                         0x05,
                         0x20, 0x10, 0x08, 0x04, 0x02
};
const char h5x7_48 [] = {
                         0x05,
                         0x3E, 0x51, 0x49, 0x45, 0x3E
};
const char h5x7_49 [] = {
                         0x05,
                         0x00, 0x42, 0x7F, 0x40, 0x00
};
const char h5x7_50 [] = {
                         0x05,
                         0x42, 0x61, 0x51, 0x49, 0x46
};
const char h5x7_51 [] = {
                         0x05,
                         0x21, 0x41, 0x45, 0x4B, 0x31
};
const char h5x7_52 [] = {
                         0x05,
                         0x18, 0x14, 0x12, 0x7F, 0x10
};
const char h5x7_53 [] = {
                         0x05,
                         0x27, 0x45, 0x45, 0x45, 0x39
};
const char h5x7_54 [] = {
                         0x05,
                         0x3C, 0x4A, 0x49, 0x49, 0x30
};
const char h5x7_55 [] = {
                         0x05,
                         0x03, 0x01, 0x71, 0x09, 0x07
};
const char h5x7_56 [] = {
                         0x05,
                         0x36, 0x49, 0x49, 0x49, 0x36
};
const char h5x7_57 [] = {
                         0x05,
                         0x06, 0x49, 0x49, 0x29, 0x1E
};
const char h5x7_58 [] = {
                         0x05,
                         0x00, 0x36, 0x36, 0x00, 0x00
};
const char h5x7_59 [] = {
                         0x05,
                         0x00, 0x56, 0x36, 0x00, 0x00
};
const char h5x7_60 [] = {
                         0x05,
                         0x08, 0x14, 0x22, 0x41, 0x00
};
const char h5x7_61 [] = {
                         0x05,
                         0x14, 0x14, 0x14, 0x14, 0x14
};
const char h5x7_62 [] = {
                         0x05,
                         0x00, 0x41, 0x22, 0x14, 0x08
};
const char h5x7_63 [] = {
                         0x05,
                         0x02, 0x01, 0x51, 0x09, 0x06
};
const char h5x7_64 [] = {
                         0x05,
                         0x32, 0x49, 0x79, 0x41, 0x3E
};
const char h5x7_65 [] = {
                         0x05,
                         0x7C, 0x12, 0x11, 0x12, 0x7C
};

const char h5x7_66 [] = {
                         0x05,
                         0x7F, 0x49, 0x49, 0x49, 0x36
};
const char h5x7_67 [] = {
                         0x05,
                         0x3E, 0x41, 0x41, 0x41, 0x22
};
const char h5x7_68 [] = {
                         0x05,
                         0x7F, 0x41, 0x41, 0x22, 0x1C
};
const char h5x7_69 [] = {
                         0x05,
                         0x7F, 0x49, 0x49, 0x49, 0x41
};
const char h5x7_70 [] = {
                         0x05,
                         0x7F, 0x09, 0x09, 0x09, 0x01
};
const char h5x7_71 [] = {
                         0x05,
                         0x3E, 0x41, 0x49, 0x49, 0x7A
};
const char h5x7_72 [] = {
                         0x05,
                         0x7F, 0x08, 0x08, 0x08, 0x7F
};
const char h5x7_73 [] = {
                         0x05,
                         0x00, 0x41, 0x7F, 0x41, 0x00
};
const char h5x7_74 [] = {
                         0x05,
                         0x20, 0x40, 0x41, 0x3F, 0x01
};
const char h5x7_75 [] = {
                         0x05,
                         0x7F, 0x08, 0x14, 0x22, 0x41
};
const char h5x7_76 [] = {
                         0x05,
                         0x7F, 0x40, 0x40, 0x40, 0x40
};
const char h5x7_77 [] = {
                         0x05,
                         0x7F, 0x02, 0x0C, 0x02, 0x7F
};
const char h5x7_78 [] = {
                         0x05,
                         0x7F, 0x04, 0x08, 0x10, 0x7F
};
const char h5x7_79 [] = {
                         0x05,
                         0x3E, 0x41, 0x41, 0x41, 0x3E
};
const char h5x7_80 [] = {
                         0x05,
                         0x7F, 0x09, 0x09, 0x09, 0x06
};
const char h5x7_81 [] = {
                         0x05,
                         0x3E, 0x41, 0x51, 0x21, 0x5E
};
const char h5x7_82 [] = {
                         0x05,
                         0x7F, 0x09, 0x19, 0x29, 0x46
};
const char h5x7_83 [] = {
                         0x05,
                         0x26, 0x49, 0x49, 0x49, 0x32
};
const char h5x7_84 [] = {
                         0x05,
                         0x01, 0x01, 0x7F, 0x01, 0x01
};
const char h5x7_85 [] = {
                         0x05,
                         0x3F, 0x40, 0x40, 0x40, 0x3F
};
const char h5x7_86 [] = {
                         0x05,
                         0x1F, 0x20, 0x40, 0x20, 0x1F
};
const char h5x7_87 [] = {
                         0x05,
                         0x3F, 0x40, 0x38, 0x40, 0x3F
};
const char h5x7_88 [] = {
                         0x05,
                         0x63, 0x14, 0x08, 0x14, 0x63
};
const char h5x7_89 [] = {
                         0x05,
                         0x07, 0x08, 0x70, 0x08, 0x07
};
const char h5x7_90 [] = {
                         0x05,
                         0x61, 0x51, 0x49, 0x45, 0x43
};
const char h5x7_91 [] = {
                         0x05,
                         0x00, 0x7F, 0x41, 0x41, 0x00
};
const char h5x7_92 [] = {
                         0x05,
                         0x02, 0x04, 0x08, 0x10, 0x20
};
const char h5x7_93 [] = {
                         0x05,
                         0x00, 0x41, 0x41, 0x7F, 0x00
};
const char h5x7_94 [] = {
                         0x05,
                         0x04, 0x02, 0x01, 0x02, 0x04
};
const char h5x7_95 [] = {
                         0x05,
                         0x40, 0x40, 0x40, 0x40, 0x40
};
const char h5x7_96 [] = {
                         0x05,
                         0x00, 0x01, 0x02, 0x04, 0x00
};
const char h5x7_97 [] = {
                         0x05,
                         0x20, 0x54, 0x54, 0x54, 0x78
};
const char h5x7_98 [] = {
                         0x05,
                         0x7F, 0x48, 0x44, 0x44, 0x38
};
const char h5x7_99 [] = {
                         0x05,
                         0x38, 0x44, 0x44, 0x44, 0x20
};
const char h5x7_100 [] = {
                         0x05,
                         0x38, 0x44, 0x44, 0x48, 0x7F
};
const char h5x7_101 [] = {
                         0x05,
                         0x38, 0x54, 0x54, 0x54, 0x18
};
const char h5x7_102 [] = {
                         0x05,
                         0x08, 0x7E, 0x09, 0x09, 0x02
};
const char h5x7_103 [] = {
                         0x05,
                         0x08, 0x54, 0x54, 0x54, 0x3C
};
const char h5x7_104 [] = {
                         0x05,
                         0x7F, 0x08, 0x04, 0x04, 0x78
};
const char h5x7_105 [] = {
                         0x05,
                         0x00, 0x48, 0x7D, 0x40, 0x00
};
const char h5x7_106 [] = {
                         0x05,
                         0x20, 0x40, 0x44, 0x3D, 0x00
};
const char h5x7_107 [] = {
                         0x05,
                         0x7F, 0x10, 0x28, 0x44, 0x00
};
const char h5x7_108 [] = {
                         0x05,
                         0x00, 0x41, 0x7F, 0x40, 0x00
};
const char h5x7_109 [] = {
                         0x05,
                         0x7C, 0x04, 0x78, 0x04, 0x78
};
const char h5x7_110 [] = {
                         0x05,
                         0x7C, 0x08, 0x04, 0x04, 0x78
};
const char h5x7_111 [] = {
                         0x05,
                         0x38, 0x44, 0x44, 0x44, 0x38
};
const char h5x7_112 [] = {
                         0x05,
                         0x7C, 0x14, 0x14, 0x14, 0x08
};
const char h5x7_113 [] = {
                         0x05,
                         0x08, 0x14, 0x14, 0x18, 0x7C
};
const char h5x7_114 [] = {
                         0x05,
                         0x7C, 0x08, 0x04, 0x04, 0x08
};
const char h5x7_115 [] = {
                         0x05,
                         0x48, 0x54, 0x54, 0x54, 0x20,
};
const char h5x7_116 [] = {
                         0x05,
                         0x04, 0x3F, 0x44, 0x40, 0x20
};
const char h5x7_117 [] = {
                         0x05,
                         0x3C, 0x40, 0x40, 0x20, 0x7C
};
const char h5x7_118 [] = {
                         0x05,
                         0x1C, 0x20, 0x40, 0x20, 0x1C
};
const char h5x7_119 [] = {
                         0x05,
                         0x3C, 0x40, 0x30, 0x40, 0x3C
};

const char h5x7_120 [] = {
                         0x05,
                         0x44, 0x28, 0x10, 0x28, 0x44
};
const char h5x7_121 [] = {
                         0x05,
                         0x0C, 0x50, 0x50, 0x50, 0x3C
};
const char h5x7_122 [] = {
                         0x05,
                         0x44, 0x64, 0x54, 0x4C, 0x44
};
const char h5x7_123 [] = {
                         0x05,
                         0x00, 0x08, 0x36, 0x41, 0x00
};
const char h5x7_124 [] = {
                         0x05,
                         0x00, 0x00, 0x7F, 0x00, 0x00
};
const char h5x7_125 [] = {
                         0x05,
                         0x00, 0x41, 0x36, 0x08, 0x00
};
const char h5x7_126 [] = {
                         0x05,
                         0x10, 0x08, 0x08, 0x10, 0x08
};
const char h5x7_127 [] = {
                         0x05,
                         0x3C, 0x22, 0x21, 0x22, 0x3C
};
const char h5x7_128 [] = {
                         0x05,
                         0x7F, 0x49, 0x49, 0x49, 0x33
};
const char h5x7_129 [] = {
                         0x05,
                         0x70, 0x29, 0x27, 0x21, 0x7F
};
const char h5x7_130 [] = {
                         0x05,
                         0x77, 0x08, 0x7F, 0x08, 0x77
};
const char h5x7_131 [] = {
                         0x05,
                         0x41, 0x41, 0x49, 0x49, 0x36
};
const char h5x7_132 [] = {
                         0x05,
                         0x7F, 0x10, 0x08, 0x04, 0x7F
};
const char h5x7_133 [] = {
                         0x05,
                         0x7C, 0x21, 0x12, 0x09, 0x7C
};
const char h5x7_134 [] = {
                         0x05,
                         0x20, 0x41, 0x3F, 0x01, 0x7F
};
const char h5x7_135 [] = {
                         0x05,
                         0x7F, 0x01, 0x01, 0x01, 0x7F
};
const char h5x7_136 [] = {
                         0x05,
                         0x47, 0x28, 0x10, 0x08, 0x07
};
const char h5x7_137 [] = {
                         0x05,
                         0x3F, 0x20, 0x20, 0x20, 0x7F
};
const char h5x7_138 [] = {
                         0x05,
                         0x07, 0x08, 0x08, 0x08, 0x7F
};
const char h5x7_139 [] = {
                         0x05,
                         0x7E, 0x40, 0x7E, 0x40, 0x7E
};
const char h5x7_140 [] = {
                         0x05,
                         0x3F, 0x20, 0x3F, 0x20, 0x7F
};
const char h5x7_141 [] = {
                         0x05,
                         0x01, 0x7F, 0x48, 0x48, 0x30
};
const char h5x7_142 [] = {
                         0x05,
                         0x7F, 0x48, 0x30, 0x00, 0x7F
};
const char h5x7_143 [] = {
                         0x05,
                         0x22, 0x49, 0x45, 0x49, 0x3E
};
const char h5x7_144 [] = {
                         0x05,
                         0x38, 0x44, 0x48, 0x30, 0x4C
};
const char h5x7_145 [] = {
                         0x05,
                         0x60, 0x60, 0x7F, 0x02, 0x0C
};
const char h5x7_146 [] = {
                         0x05,
                         0x7F, 0x01, 0x01, 0x01, 0x03
};
const char h5x7_147 [] = {
                         0x05,
                         0x44, 0x3C, 0x04, 0x7C, 0x44
};
const char h5x7_148 [] = {
                         0x05,
                         0x63, 0x55, 0x49, 0x41, 0x41
};
const char h5x7_149 [] = {
                         0x05,
                         0x38, 0x44, 0x44, 0x3C, 0x04
};
const char h5x7_150 [] = {
                         0x05,
                         0x30, 0x30, 0x1F, 0x65, 0x7F
};
const char h5x7_151 [] = {
                         0x05,
                         0x08, 0x04, 0x3C, 0x44, 0x02
};
const char h5x7_152 [] = {
                         0x05,
                         0x10, 0x1E, 0x3F, 0x1E, 0x10
};
const char h5x7_153 [] = {
                         0x05,
                         0x3E, 0x49, 0x49, 0x49, 0x3E
};
const char h5x7_154 [] = {
                         0x05,
                         0x5C, 0x62, 0x02, 0x62, 0x5C
};
const char h5x7_155 [] = {
                         0x05,
                         0x30, 0x4A, 0x45, 0x49, 0x32
};
const char h5x7_156 [] = {
                         0x05,
                         0x18, 0x14, 0x08, 0x14, 0x0C
};
const char h5x7_157 [] = {
                         0x05,
                         0x1C, 0x3E, 0x7C, 0x3E, 0x1C
};
const char h5x7_158 [] = {
                         0x05,
                         0x28, 0x54, 0x54, 0x44, 0x20
};
const char h5x7_159 [] = {
                         0x05,
                         0x7E, 0x01, 0x01, 0x01, 0x7E
};
const char h5x7_160 [] = {
                         0x05,
                         0x7F, 0x7F, 0x00, 0x7F, 0x7F
};
const char h5x7_161 [] = {
                         0x05,
                         0x00, 0x00, 0x79, 0x00, 0x00
};
const char h5x7_162 [] = {
                         0x05,
                         0x1C, 0x22, 0x7F, 0x22, 0x10
};
const char h5x7_163 [] = {
                         0x05,
                         0x48, 0x3E, 0x49, 0x41, 0x20
};
const char h5x7_164 [] = {
                         0x05,
                         0x22, 0x1C, 0x14, 0x1C, 0x22
};
const char h5x7_165 [] = {
                         0x05,
                         0x15, 0x16, 0x7C, 0x16, 0x15
};
const char h5x7_166 [] = {
                         0x05,
                         0x00, 0x00, 0x77, 0x00, 0x00
};
const char h5x7_167 [] = {
                         0x05,
                         0x20, 0x4A, 0x55, 0x29, 0x02
};
const char h5x7_168 [] = {
                         0x05,
                         0x28, 0x48, 0x3E, 0x09, 0x0A
};
const char h5x7_169 [] = {
                         0x05,
                         0x7F, 0x41, 0x5D, 0x49, 0x7F
};
const char h5x7_170 [] = {
                         0x05,
                         0x48, 0x55, 0x55, 0x55, 0x5E
};
const char h5x7_171 [] = {
                         0x05,
                         0x08, 0x14, 0x2A, 0x14, 0x22
};
const char h5x7_172 [] = {
                         0x05,
                         0x7F, 0x08, 0x3E, 0x41, 0x3E
};
const char h5x7_173 [] = {
                         0x05,
                         0x46, 0x29, 0x19, 0x09, 0x7F
};
const char h5x7_174 [] = {
                         0x05,
                         0x7F, 0x41, 0x65, 0x51, 0x7F
};
const char h5x7_175 [] = {
                         0x05,
                         0x00, 0x06, 0x05, 0x00, 0x00
};
const char h5x7_176 [] = {
                         0x05,
                         0x0E, 0x11, 0x11, 0x0E, 0x00
};
const char h5x7_177 [] = {
                         0x05,
                         0x44, 0x44, 0x5F, 0x44, 0x44
};
const char h5x7_178 [] = {
                         0x05,
                         0x12, 0x19, 0x15, 0x12, 0x00
};
const char h5x7_179 [] = {
                         0x05,
                         0x11, 0x15, 0x15, 0x0A, 0x00
};
const char h5x7_180 [] = {
                         0x05,
                         0x7F, 0x05, 0x15, 0x7A, 0x50
};
const char h5x7_181 [] = {
                         0x05,
                         0x7F, 0x10, 0x10, 0x08, 0x1F
};
const char h5x7_182 [] = {
                         0x05,
                         0x06, 0x09, 0x09, 0x7F, 0x7F
};
const char h5x7_183 [] = {
                         0x05,
                         0x00, 0x18, 0x18, 0x00, 0x00
};
const char h5x7_184 [] = {
                         0x05,
                         0x38, 0x44, 0x30, 0x44, 0x38
};
const char h5x7_185 [] = {
                         0x05,
                         0x12, 0x1F, 0x10, 0x00, 0x00
};
const char h5x7_186 [] = {
                         0x05,
                         0x4E, 0x51, 0x51, 0x51, 0x4E
};
const char h5x7_187 [] = {
                         0x05,
                         0x22, 0x14, 0x2A, 0x14, 0x08
};
const char h5x7_188 [] = {
                         0x05,
                         0x17, 0x68, 0x54, 0xFA, 0x41
};
const char h5x7_189 [] = {
                         0x05,
                         0x17, 0x08, 0x94, 0xCA, 0xB1
};
const char h5x7_190 [] = {
                         0x05,
                         0x15, 0x1F, 0x60, 0x50, 0xF8
};
const char h5x7_191 [] = {
                         0x05,
                         0x30, 0x48, 0x45, 0x40, 0x20
};
const char h5x7_192 [] = {
                         0x05,
                         0x70, 0x29, 0x26, 0x28, 0x70
};
const char h5x7_193 [] = {
                         0x05,
                         0x70, 0x28, 0x26, 0x29, 0x70
};
const char h5x7_194 [] = {
                         0x05,
                         0x70, 0x2A, 0x29, 0x2A, 0x70
};
const char h5x7_195 [] = {
                         0x05,
                         0x72, 0x29, 0x29, 0x2A, 0x71
};
const char h5x7_196 [] = {
                         0x05,
                         0x70, 0x29, 0x24, 0x29, 0x70
};
const char h5x7_197 [] = {
                         0x05,
                         0x70, 0x2A, 0x2D, 0x2A, 0x70
};
const char h5x7_198 [] = {
                         0x05,
                         0x7C, 0x12, 0x7F, 0x49, 0x49
};
const char h5x7_199 [] = {
                         0x05,
                         0x0E, 0x51, 0x51, 0x71, 0x0A
};
const char h5x7_200 [] = {
                         0x05,
                         0x7C, 0x55, 0x56, 0x54, 0x44
};
const char h5x7_201 [] = {
                         0x05,
                         0x7C, 0x54, 0x56, 0x55, 0x44
};
const char h5x7_202 [] = {
                         0x05,
                         0x7C, 0x56, 0x55, 0x56, 0x44
};
const char h5x7_203 [] = {
                         0x05,
                         0x7C, 0x55, 0x54, 0x55, 0x44
};
const char h5x7_204 [] = {
                         0x05,
                         0x00, 0x49, 0x7A, 0x48, 0x00
};
const char h5x7_205 [] = {
                         0x05,
                         0x00, 0x48, 0x7A, 0x49, 0x00
};
const char h5x7_206 [] = {
                         0x05,
                         0x00, 0x4A, 0x79, 0x4A, 0x00
};
const char h5x7_207 [] = {
                         0x05,
                         0x00, 0x45, 0x7C, 0x45, 0x00
};
const char h5x7_208 [] = {
                         0x05,
                         0x08, 0x7F, 0x49, 0x41, 0x3E
};
const char h5x7_209 [] = {
                         0x05,
                         0x7A, 0x09, 0x11, 0x22, 0x79
};
const char h5x7_210 [] = {
                         0x05,
                         0x38, 0x45, 0x46, 0x44, 0x38
};
const char h5x7_211 [] = {
                         0x05,
                         0x38, 0x44, 0x46, 0x45, 0x38
};
const char h5x7_212 [] = {
                         0x05,
                         0x38, 0x46, 0x45, 0x46, 0x38
};
const char h5x7_213 [] = {
                         0x05,
                         0x72, 0x89, 0x89, 0x8A, 0x71
};
const char h5x7_214 [] = {
                         0x05,
                         0x38, 0x45, 0x44, 0x45, 0x38
};
const char h5x7_215 [] = {
                         0x05,
                         0x22, 0x14, 0x08, 0x14, 0x22
};
const char h5x7_216 [] = {
                         0x05,
                         0x08, 0x55, 0x7F, 0x55, 0x08
};
const char h5x7_217 [] = {
                         0x05,
                         0x3C, 0x41, 0x42, 0x40, 0x3C
};
const char h5x7_218 [] = {
                         0x05,
                         0x3C, 0x40, 0x42, 0x41, 0x3C
};
const char h5x7_219 [] = {
                         0x05,
                         0x38, 0x42, 0x41, 0x42, 0x38
};
const char h5x7_220 [] = {
                         0x05,
                         0x3C, 0x41, 0x40, 0x41, 0x3C
};
const char h5x7_221 [] = {
                         0x05,
                         0x04, 0x08, 0x72, 0x09, 0x04
};
const char h5x7_222 [] = {
                         0x05,
                         0x41, 0x7F, 0x52, 0x12, 0x0C
};
const char h5x7_223 [] = {
                         0x05,
                         0x40, 0x3E, 0x49, 0x49, 0x36
};
const char h5x7_224 [] = {
                         0x05,
                         0x40, 0xA9, 0xAA, 0xA8, 0xF0
};
const char h5x7_225 [] = {
                         0x05,
                         0x20, 0x54, 0x56, 0x55, 0x78
};
const char h5x7_226 [] = {
                         0x05,
                         0x20, 0x56, 0x55, 0x56, 0x78
};
const char h5x7_227 [] = {
                         0x05,
                         0x42, 0xA9, 0xA9, 0xAA, 0xF1
};
const char h5x7_228 [] = {
                         0x05,
                         0x20, 0x55, 0x54, 0x55, 0x78
};
const char h5x7_229 [] = {
                         0x05,
                         0x40, 0xAA, 0xAD, 0xAA, 0xF0
};
const char h5x7_230 [] = {
                         0x05,
                         0x32, 0x4A, 0x3C, 0x4A, 0x2C
};
const char h5x7_231 [] = {
                         0x05,
                         0x0C, 0x52, 0x72, 0x12, 0x08
};
const char h5x7_232 [] = {
                         0x05,
                         0x38, 0x55, 0x56, 0x54, 0x18
};
const char h5x7_233 [] = {
                         0x05,
                         0x38, 0x54, 0x56, 0x55, 0x18
};
const char h5x7_234 [] = {
                         0x05,
                         0x38, 0x56, 0x55, 0x56, 0x18
};
const char h5x7_235 [] = {
                         0x05,
                         0x38, 0x55, 0x54, 0x55, 0x18
};
const char h5x7_236 [] = {
                         0x05,
                         0x00, 0x51, 0x7A, 0x40, 0x00
};
const char h5x7_237 [] = {
                         0x05,
                         0x00, 0x50, 0x7A, 0x41, 0x00
};
const char h5x7_238 [] = {
                         0x05,
                         0x00, 0x92, 0xF9, 0x82, 0x00
};
const char h5x7_239 [] = {
                         0x05,
                         0x00, 0x49, 0x7C, 0x41, 0x00
};
const char h5x7_240 [] = {
                         0x05,
                         0x25, 0x52, 0x55, 0x58, 0x30
};
const char h5x7_241 [] = {
                         0x05,
                         0x7A, 0x11, 0x09, 0x0A, 0x71
};
const char h5x7_242 [] = {
                         0x05,
                         0x38, 0x45, 0x46, 0x44, 0x38
};
const char h5x7_243 [] = {
                         0x05,
                         0x38, 0x44, 0x46, 0x45, 0x38
};
const char h5x7_244 [] = {
                         0x05,
                         0x30, 0x4A, 0x49, 0x4A, 0x30
};
const char h5x7_245 [] = {
                         0x05,
                         0x32, 0x49, 0x49, 0x4A, 0x31
};
const char h5x7_246 [] = {
                         0x05,
                         0x38, 0x45, 0x44, 0x45, 0x38
};
const char h5x7_247 [] = {
                         0x05,
                         0x08, 0x08, 0x2A, 0x08, 0x08
};
const char h5x7_248 [] = {
                         0x05,
                         0x08, 0x54, 0x3E, 0x15, 0x08
};
const char h5x7_249 [] = {
                         0x05,
                         0x3C, 0x41, 0x42, 0x20, 0x7C
};
const char h5x7_250 [] = {
                         0x05,
                         0x38, 0x40, 0x42, 0x21, 0x78
};
const char h5x7_251 [] = {
                         0x05,
                         0x38, 0x42, 0x41, 0x22, 0x78
};
const char h5x7_252 [] = {
                         0x05,
                         0x3C, 0x41, 0x40, 0x21, 0x7C
};
const char h5x7_253 [] = {
                         0x05,
                         0x0C, 0x50, 0x52, 0x51, 0x3C
};
const char h5x7_254 [] = {
                         0x05,
                         0x00, 0x41, 0x7F, 0x54, 0x08
};
const char h5x7_255 [] = {
                         0x05,
                         0x0C, 0x51, 0x50, 0x51, 0x3C
};

#endif
/* Font indexing table */
const int Hitachi [] = {
          (int) &h5x7_00,
          (int) &h5x7_01,
          (int) &h5x7_02,
          (int) &h5x7_03,
          (int) &h5x7_04,
          (int) &h5x7_05,
          (int) &h5x7_06,
          (int) &h5x7_07,
          (int) &h5x7_08,
          (int) &h5x7_09,
          (int) &h5x7_10,
          (int) &h5x7_11,
          (int) &h5x7_12,
          (int) &h5x7_13,
          (int) &h5x7_14,
          (int) &h5x7_15,
          (int) &h5x7_16,
          (int) &h5x7_17,
          (int) &h5x7_18,
          (int) &h5x7_19,
          (int) &h5x7_20,
          (int) &h5x7_21,
          (int) &h5x7_22,
          (int) &h5x7_23,
          (int) &h5x7_24,
          (int) &h5x7_25,
          (int) &h5x7_26,
          (int) &h5x7_27,
          (int) &h5x7_28,
          (int) &h5x7_29,
          (int) &h5x7_30,
          (int) &h5x7_31,
          (int) &h5x7_32,
          (int) &h5x7_33,
          (int) &h5x7_34,
          (int) &h5x7_35,
          (int) &h5x7_36,
          (int) &h5x7_37,
          (int) &h5x7_38,
          (int) &h5x7_39,
          (int) &h5x7_40,
          (int) &h5x7_41,
          (int) &h5x7_42,
          (int) &h5x7_43,
          (int) &h5x7_44,
          (int) &h5x7_45,
          (int) &h5x7_46,
          (int) &h5x7_47,
          (int) &h5x7_48,
          (int) &h5x7_49,
          (int) &h5x7_50,
          (int) &h5x7_51,
          (int) &h5x7_52,
          (int) &h5x7_53,
          (int) &h5x7_54,
          (int) &h5x7_55,
          (int) &h5x7_56,
          (int) &h5x7_57,
          (int) &h5x7_58,
          (int) &h5x7_59,
          (int) &h5x7_60,
          (int) &h5x7_61,
          (int) &h5x7_62,
          (int) &h5x7_63,
          (int) &h5x7_64,
          (int) &h5x7_65,
          (int) &h5x7_66,
          (int) &h5x7_67,
          (int) &h5x7_68,
          (int) &h5x7_69,
          (int) &h5x7_70,
          (int) &h5x7_71,
          (int) &h5x7_72,
          (int) &h5x7_73,
          (int) &h5x7_74,
          (int) &h5x7_75,
          (int) &h5x7_76,
          (int) &h5x7_77,
          (int) &h5x7_78,
          (int) &h5x7_79,
          (int) &h5x7_80,
          (int) &h5x7_81,
          (int) &h5x7_82,
          (int) &h5x7_83,
          (int) &h5x7_84,
          (int) &h5x7_85,
          (int) &h5x7_86,
          (int) &h5x7_87,
          (int) &h5x7_88,
          (int) &h5x7_89,
          (int) &h5x7_90,
          (int) &h5x7_91,
          (int) &h5x7_92,
          (int) &h5x7_93,
          (int) &h5x7_94,
          (int) &h5x7_95,
          (int) &h5x7_96,
          (int) &h5x7_97,
          (int) &h5x7_98,
          (int) &h5x7_99,
          (int) &h5x7_100,
          (int) &h5x7_101,
          (int) &h5x7_102,
          (int) &h5x7_103,
          (int) &h5x7_104,
          (int) &h5x7_105,
          (int) &h5x7_106,
          (int) &h5x7_107,
          (int) &h5x7_108,
          (int) &h5x7_109,
          (int) &h5x7_110,
          (int) &h5x7_111,
          (int) &h5x7_112,
          (int) &h5x7_113,
          (int) &h5x7_114,
          (int) &h5x7_115,
          (int) &h5x7_116,
          (int) &h5x7_117,
          (int) &h5x7_118,
          (int) &h5x7_119,
          (int) &h5x7_120,
          (int) &h5x7_121,
          (int) &h5x7_122,
          (int) &h5x7_123,
          (int) &h5x7_124,
          (int) &h5x7_125,
          (int) &h5x7_126,
          (int) &h5x7_127,
          (int) &h5x7_128,
          (int) &h5x7_129,
          (int) &h5x7_130,
          (int) &h5x7_131,
          (int) &h5x7_132,
          (int) &h5x7_133,
          (int) &h5x7_134,
          (int) &h5x7_135,
          (int) &h5x7_136,
          (int) &h5x7_137,
          (int) &h5x7_138,
          (int) &h5x7_139,
          (int) &h5x7_140,
          (int) &h5x7_141,
          (int) &h5x7_142,
          (int) &h5x7_143,
          (int) &h5x7_144,
          (int) &h5x7_145,
          (int) &h5x7_146,
          (int) &h5x7_147,
          (int) &h5x7_148,
          (int) &h5x7_149,
          (int) &h5x7_150,
          (int) &h5x7_151,
          (int) &h5x7_152,
          (int) &h5x7_153,
          (int) &h5x7_154,
          (int) &h5x7_155,
          (int) &h5x7_156,
          (int) &h5x7_157,
          (int) &h5x7_158,
          (int) &h5x7_159,
          (int) &h5x7_160,
          (int) &h5x7_161,
          (int) &h5x7_162,
          (int) &h5x7_163,
          (int) &h5x7_164,
          (int) &h5x7_165,
          (int) &h5x7_166,
          (int) &h5x7_167,
          (int) &h5x7_168,
          (int) &h5x7_169,
          (int) &h5x7_170,
          (int) &h5x7_171,
          (int) &h5x7_172,
          (int) &h5x7_173,
          (int) &h5x7_174,
          (int) &h5x7_175,
          (int) &h5x7_176,
          (int) &h5x7_177,
          (int) &h5x7_178,
          (int) &h5x7_179,
          (int) &h5x7_180,
          (int) &h5x7_181,
          (int) &h5x7_182,
          (int) &h5x7_183,
          (int) &h5x7_184,
          (int) &h5x7_185,
          (int) &h5x7_186,
          (int) &h5x7_187,
          (int) &h5x7_188,
          (int) &h5x7_189,
          (int) &h5x7_190,
          (int) &h5x7_191,
          (int) &h5x7_192,
          (int) &h5x7_193,
          (int) &h5x7_194,
          (int) &h5x7_195,
          (int) &h5x7_196,
          (int) &h5x7_197,
          (int) &h5x7_198,
          (int) &h5x7_199,
          (int) &h5x7_200,
          (int) &h5x7_201,
          (int) &h5x7_202,
          (int) &h5x7_203,
          (int) &h5x7_204,
          (int) &h5x7_205,
          (int) &h5x7_206,
          (int) &h5x7_207,
          (int) &h5x7_208,
          (int) &h5x7_209,
          (int) &h5x7_210,
          (int) &h5x7_211,
          (int) &h5x7_212,
          (int) &h5x7_213,
          (int) &h5x7_214,
          (int) &h5x7_215,
          (int) &h5x7_216,
          (int) &h5x7_217,
          (int) &h5x7_218,
          (int) &h5x7_219,
          (int) &h5x7_220,
          (int) &h5x7_221,
          (int) &h5x7_222,
          (int) &h5x7_223,
          (int) &h5x7_224,
          (int) &h5x7_225,
          (int) &h5x7_226,
          (int) &h5x7_227,
          (int) &h5x7_228,
          (int) &h5x7_229,
          (int) &h5x7_230,
          (int) &h5x7_231,
          (int) &h5x7_232,
          (int) &h5x7_233,
          (int) &h5x7_234,
          (int) &h5x7_235,
          (int) &h5x7_236,
          (int) &h5x7_237,
          (int) &h5x7_238,
          (int) &h5x7_239,
          (int) &h5x7_240,
          (int) &h5x7_241,
          (int) &h5x7_242,
          (int) &h5x7_243,
          (int) &h5x7_244,
          (int) &h5x7_245,
          (int) &h5x7_246,
          (int) &h5x7_247,
          (int) &h5x7_248,
          (int) &h5x7_249,
          (int) &h5x7_250,
          (int) &h5x7_251,
          (int) &h5x7_252,
          (int) &h5x7_253,
          (int) &h5x7_254,
          (int) &h5x7_255

};


#endif
