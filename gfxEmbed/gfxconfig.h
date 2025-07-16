//-------------------------------------------------------------------------------------------
//
//                  gfxconfig.h
//                  Configuration Header file for gfxEmdedLib
//                  (C) 1999 - 2025 Sonic2k
//-------------------------------------------------------------------------------------------

#ifndef GFXCONFIG_H_
#define GFXCONFIG_H_

// Display Resolution (in pixels)
//--------------------------------
#define DISPLAY_HORIZONTAL_SIZE 160
#define DISPLAY_VERTICAL_SIZE 32

// Enable framebuffer - Note that this can only be done if the target has sufficient resources. 
// If it doesn't have enough RAM, this will cause a compiler error
//---------------------------------------------------------------------------------------------

#define USE_FRAMEBUFFER

// Display Orientation Configuration
// This depends on the type of controller used, consult datasheet before setting
//-------------------------------------------------------------------------------

#define VERTICAL_ORIENTATION





#endif /* GFXCONFIG_H_ */
