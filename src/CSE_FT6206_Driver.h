
//======================================================================================//
/*
  Filename: CSE_FT6206_Driver.cpp
  Description: CSE_TOUCH_DRIVER interface driver for the CSE_Touch Arduino library.
  Framework: Arduino, PlatformIO
  Author: Vishnu Mohanan (@vishnumaiea, @vizmohanan)
  Maintainer: CIRCUITSTATE Electronics (@circuitstate)
  Version: 0.0.1
  License: MIT
  Source: https://github.com/CIRCUITSTATE/CSE_Touch
  Last Modified: +05:30 11:31:14 AM 30-03-2025, Sunday
 */
//======================================================================================//

#ifndef CSE_FT6206_DRIVER_H
#define CSE_FT6206_DRIVER_H

//============================================================================================//

#include "CSE_Touch.h"
#include <CSE_FT6206.h>

// Define the touch driver name here.
#define   CSE_TOUCH_DRIVER    FT6206

//============================================================================================//

class CSE_FT6206_Driver : public CSE_Touch {
  private:
    CSE_FT6206* CSE_TOUCH_DRIVER;
    uint16_t width, height;
    uint8_t pinRst, pinIrq;
    TwoWire* wire;
  
  //--------------------------------------------------------------------------------------------//
  
  public:

  // Creates a new touch driver object.
  CSE_FT6206_Driver (uint16_t w, uint16_t h, TwoWire* tw, uint8_t rst, uint8_t irq) : width (w), height (h), wire (tw), pinRst (rst), pinIrq (irq) {
    CSE_TOUCH_DRIVER = new CSE_FT6206 (w, h, tw, rst, irq);
  }

  //--------------------------------------------------------------------------------------------//

  // Returns a pointer to the underyling touch driver.
  void* getDriver() override {
    return static_cast<void*>(CSE_TOUCH_DRIVER);
  }

  //--------------------------------------------------------------------------------------------//
  
  // Basic initialization.
  void init (void) override {
    CSE_TOUCH_DRIVER->begin();
    return;  // Initialization done in begin()
  }

  //--------------------------------------------------------------------------------------------//
  
  // Same as `init()`.
  void begin (void) override {
    CSE_TOUCH_DRIVER->begin();
    return;
  }

  //--------------------------------------------------------------------------------------------//
  
  // Sets the rotation of the touch panel.
  uint8_t setRotation (uint8_t r) override {
    return CSE_TOUCH_DRIVER->setRotation (r);
  }

  //--------------------------------------------------------------------------------------------//
  
  // Returns the current rotation of the touch panel.
  uint8_t getRotation (void) override {
    return CSE_TOUCH_DRIVER->getRotation();
  }

  //--------------------------------------------------------------------------------------------//
  
  // Returns the width of the touch panel.
  uint16_t getWidth (void) override {
    return CSE_TOUCH_DRIVER->getWidth();
  }

  //--------------------------------------------------------------------------------------------//
  
  // Returns the height of the touch panel.
  uint16_t getHeight (void) override {
    return CSE_TOUCH_DRIVER->getHeight();
  }

  //--------------------------------------------------------------------------------------------//
  
  // Checks if a touch is detected through any of the touch points.
  bool isTouched (void) override {
    return CSE_TOUCH_DRIVER->isTouched();
  }

  //--------------------------------------------------------------------------------------------//

  // Checks if a touch is detected through the specified touch point.
  bool isTouched (uint8_t id) override {
    return CSE_TOUCH_DRIVER->isTouched ((uint8_t) id);
  }

  //--------------------------------------------------------------------------------------------//
  
  // Returns the number of touches detected.
  uint8_t getTouches (void) override {
    return CSE_TOUCH_DRIVER->getTouches();
  }

  //--------------------------------------------------------------------------------------------//
  
  // Returns the current touch point.
  CSE_TouchPoint getPoint (uint8_t n) override {
    CSE_TouchPoint p = CSE_TOUCH_DRIVER->getPoint();

    CSE_TouchPoint cse_tp;
    cse_tp.x = p.x;
    cse_tp.y = p.y;
    cse_tp.z = 0;
    
    return cse_tp;
  }
};

//============================================================================================//

#endif // CSE_FT6206_DRIVER_H