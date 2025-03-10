
//======================================================================================//
/*
  Filename: CSE_Touch.cpp
  Description: Main source file for the CSE_Touch Arduino library.
  Framework: Arduino, PlatformIO
  Author: Vishnu Mohanan (@vishnumaiea, @vizmohanan)
  Maintainer: CIRCUITSTATE Electronics (@circuitstate)
  Version: 0.0.1
  License: MIT
  Source: https://github.com/CIRCUITSTATE/CSE_Touch
  Last Modified: +05:30 15:36:39 PM 09-03-2025, Sunday
 */
//======================================================================================//

#include "CSE_Touch.h"

//======================================================================================//

// Conditionally include touch drivers
#ifdef ENABLE_XPT2046
  #include "CSE_XPT2046_Driver.h"
#endif

#ifdef ENABLE_FT6206
  #include "CSE_FT6206_Driver.h"
#endif

#ifdef ENABLE_CST328
  #include "CSE_CST328_Driver.h"
#endif

//======================================================================================//

CSE_Touch* CSE_Touch_Driver:: createDriver (CSE_Touch_t type, uint16_t width, uint16_t height, TwoWire* wire, uint8_t pinRst, uint8_t pinIrq) {
  switch (type) {
    #ifdef ENABLE_XPT2046
      case CSE_TOUCH_XPT2046:
      return new CSE_XPT2046_Driver (cs, irq);
    #endif

    #ifdef ENABLE_FT6206
      case CSE_TOUCH_FT6206:
      return new CSE_FT6206_Driver (width, height, wire, pinRst, pinIrq);
    #endif

    #ifdef ENABLE_CST328
      case CSE_TOUCH_CST328:
      // Serial.println ("CSE_Touch_Driver [INFO]: Driver is CST328..");
      return new CSE_CST328_Driver (width, height, wire, pinRst, pinIrq);
    #endif

    default:
    // Return a null implementation that does nothing
    Serial.println ("CSE_Touch_Driver [INFO]: No driver selected..");
    return nullptr;
  }
}

//======================================================================================//
