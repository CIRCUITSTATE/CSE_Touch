
//======================================================================================//
/*
  Filename: CSE_Touch.h
  Description: Main header file for the CSE_Touch Arduino library.
  Framework: Arduino, PlatformIO
  Author: Vishnu Mohanan (@vishnumaiea, @vizmohanan)
  Maintainer: CIRCUITSTATE Electronics (@circuitstate)
  Version: 0.0.1
  License: MIT
  Source: https://github.com/CIRCUITSTATE/CSE_Touch
  Last Modified: +05:30 23:28:25 PM 26-03-2025, Wednesday
 */
//======================================================================================//

#include <Arduino.h>
#include <Wire.h>

//======================================================================================//

// Include guards
#ifndef CSE_TOUCH_H
#define CSE_TOUCH_H

// List of supported touch controllers.
enum CSE_Touch_t {
  CSE_TOUCH_NONE = 0,
  CSE_TOUCH_XPT2046 = 1,
  CSE_TOUCH_FT6206 = 2,
  CSE_TOUCH_CST328 = 3
};

//===================================================================================//

// Generic touch point class for storing touch information.
class CSE_TouchPoint {
  public:
    CSE_TouchPoint (void) {
      x = 0;
      y = 0;
      z = 0;
      id = 0;
    };
    
    CSE_TouchPoint (int16_t x, int16_t y, int16_t z, uint8_t id) {
      this->x = x;
      this->y = y;
      this->z = z;
      this->id = id;
    }

    bool operator== (CSE_TouchPoint);
    bool operator!= (CSE_TouchPoint);

    int16_t x; // X coordinate
    int16_t y; // Y coordinate
    int16_t z; // Z coordinate (often used for pressure)
    uint8_t id; // For multi-touch support
    uint8_t state;  // Touch state
};

//===================================================================================//

// Main class for the touch panel.
class CSE_Touch {
  public:
    CSE_Touch() {}
    virtual void init (void) = 0;
    virtual void begin (void) = 0;
    virtual uint8_t setRotation (uint8_t rotation) = 0;
    virtual uint8_t getRotation (void) = 0;
    virtual uint16_t getWidth (void) = 0;
    virtual uint16_t getHeight (void) = 0;
    virtual bool isTouched (void) = 0;
    virtual bool isTouched (uint8_t id) = 0;
    virtual uint8_t getTouches (void) = 0;  // Returns the number of touches detected
    virtual CSE_TouchPoint getPoint (uint8_t n = 0) = 0;
};

//===================================================================================//

// An abstract class for touch drivers.
class CSE_Touch_Driver {
  public:
    // Factory method - parameters cover most common configurations
    static CSE_Touch* createDriver (
      CSE_Touch_t type,
      uint16_t width,
      uint16_t height,
      TwoWire* wire = &Wire, // I2C bus (capacitive)
      uint8_t pinRst = -1,      // SPI CS pin (resistive)
      uint8_t pinIrq = -1     // IRQ pin (optional)
    );   // I2C address (capacitive, 0 = default)
};

//===================================================================================//

#endif
