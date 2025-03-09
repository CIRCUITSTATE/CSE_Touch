
//======================================================================================//
/*
  Filename: CSE_FT6206_Driver.cpp
  Description: FT6206 interface driver for the CSE_Touch Arduino library.
  Framework: Arduino, PlatformIO
  Author: Vishnu Mohanan (@vishnumaiea, @vizmohanan)
  Maintainer: CIRCUITSTATE Electronics (@circuitstate)
  Version: 0.0.1
  License: MIT
  Source: https://github.com/CIRCUITSTATE/CSE_Touch
  Last Modified: +05:30 12:35:52 PM 09-03-2025, Sunday
 */
//======================================================================================//

#ifndef CSE_FT6206_DRIVER_H
#define CSE_FT6206_DRIVER_H

#include <Wire.h>
#include "CSE_Touch.h"
#include <CSE_FT6206.h>

class CSE_FT6206_Driver : public CSE_Touch {
  private:
    CSE_FT6206* FT6206;
    uint16_t width, height;
    uint8_t pinRst, pinIrq;
    TwoWire* wire;
    
  public:

  CSE_FT6206_Driver (uint16_t w, uint16_t h, TwoWire* tw, uint8_t rst, uint8_t irq) : width (w), height (h), wire (tw), pinRst (rst), pinIrq (irq) {
    FT6206 = new CSE_FT6206 (width, height, wire, pinRst);
  }
  
  void init (void) override {
    FT6206->begin();
    return;  // Initialization done in begin()
  }
  
  void begin (void) override {
    FT6206->begin();
    return
  }
  
  uint8_t setRotation (uint8_t r) override {
    return FT6206->setRotation (r);
  }
  
  uint8_t getRotation (void) override {
    return FT6206->getRotation();
  }
  
  uint16_t getWidth (void) override {
    return FT6206->getWidth();
  }
  
  uint16_t getHeight (void) override {
    return FT6206->getHeight();
  }
  
  bool isTouched (void) override {
    return FT6206->isTouched();
  }
  
  uint8_t getTouches (void) override {
    return FT6206->getTouches();
  }
  
  CSE_TouchPoint getPoint (uint8_t n) override {
    TS_Point p = FT6206->getPoint();

    CSE_TouchPoint cse_tp;
    cse_tp.x = p.x;
    cse_tp.y = p.y;
    cse_tp.z = 0;
    
    return cse_tp;
  }
};

#endif // CSE_FT6206_DRIVER_H