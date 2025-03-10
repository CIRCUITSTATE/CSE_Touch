
//======================================================================================//
/*
  Filename: CSE_CST328_Driver.cpp
  Description: CST328 interface driver for the CSE_Touch Arduino library.
  Framework: Arduino, PlatformIO
  Author: Vishnu Mohanan (@vishnumaiea, @vizmohanan)
  Maintainer: CIRCUITSTATE Electronics (@circuitstate)
  Version: 0.0.1
  License: MIT
  Source: https://github.com/CIRCUITSTATE/CSE_Touch
  Last Modified: +05:30 15:33:34 PM 09-03-2025, Sunday
 */
//======================================================================================//

#ifndef CSE_CST328_DRIVER_H
#define CSE_CST328_DRIVER_H

//============================================================================================//

#include "CSE_Touch.h"
#include <CSE_CST328.h>

//============================================================================================//

#define   CSE_TOUCH_DRIVER    CST328

//============================================================================================//

class CSE_CST328_Driver : public CSE_Touch {
  private:
    CSE_CST328* CSE_TOUCH_DRIVER;
    uint16_t width, height;
    uint8_t pinRst, pinIrq;
    TwoWire* wire;
  
  //--------------------------------------------------------------------------------------------//
  
  public:

  CSE_CST328_Driver (uint16_t w, uint16_t h, TwoWire* tw, uint8_t rst, uint8_t irq) : width (w), height (h), wire (tw), pinRst (rst), pinIrq (irq) {
    CSE_TOUCH_DRIVER = new CSE_CST328 (w, h, tw, rst, irq);
  }
  
  //--------------------------------------------------------------------------------------------//

  void init (void) override {
    CSE_TOUCH_DRIVER->begin();
    return;
  }

  //--------------------------------------------------------------------------------------------//
  
  void begin (void) override {
    CSE_TOUCH_DRIVER->begin();
    return;
  }

  //--------------------------------------------------------------------------------------------//
  
  uint8_t setRotation (uint8_t r) override {
    return CSE_TOUCH_DRIVER->setRotation (r);
  }

  //--------------------------------------------------------------------------------------------//
  
  uint8_t getRotation (void) override {
    return CSE_TOUCH_DRIVER->getRotation();
  }

  //--------------------------------------------------------------------------------------------//
  
  uint16_t getWidth (void) override {
    return CSE_TOUCH_DRIVER->getWidth();
  }

  //--------------------------------------------------------------------------------------------//
  
  uint16_t getHeight (void) override {
    return CSE_TOUCH_DRIVER->getHeight();
  }

  //--------------------------------------------------------------------------------------------//
  
  bool isTouched (void) override {
    return CSE_TOUCH_DRIVER->isTouched();
  }
  
  //--------------------------------------------------------------------------------------------//
  
  bool isTouched (uint8_t id) override {
    return CSE_TOUCH_DRIVER->isTouched ((uint8_t) id);
  }
  
  //--------------------------------------------------------------------------------------------//
  
  uint8_t getTouches (void) override {
    return CSE_TOUCH_DRIVER->getTouches();
  }

  //--------------------------------------------------------------------------------------------//
  
  CSE_TouchPoint getPoint (uint8_t n) override {
    // return CSE_TOUCH_DRIVER->getPoint (n);
    CSE_TouchPoint p = CSE_TOUCH_DRIVER->getPoint (n);

    CSE_TouchPoint cse_tp;
    cse_tp.x = p.x;
    cse_tp.y = p.y;
    cse_tp.z = p.z;
    cse_tp.id = p.id;
    cse_tp.state = p.state;
    
    return cse_tp;
  }
};

//============================================================================================//

#endif // CSE_CST328_DRIVER_H