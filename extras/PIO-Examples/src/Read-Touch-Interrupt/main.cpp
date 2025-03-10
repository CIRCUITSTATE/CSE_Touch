

//============================================================================================//
/*
  Filename: main.cpp [Read-Touch-Interrupt]
  Description: Example Arduino program from the CSE_Touch Arduino library.
  Reads the touch sensor through interrupt method and prints the data to the serial monitor.
  You will only see anything printed on the serial monitor when the display is touched.
  This code was written for and tested with the FireBeetle-ESP32E board.
  
  Framework: Arduino, PlatformIO
  Author: Vishnu Mohanan (@vishnumaiea, @vizmohanan)
  Maintainer: CIRCUITSTATE Electronics (@circuitstate)
  Version: 0.1
  License: MIT
  Source: https://github.com/CIRCUITSTATE/CSE_Touch
  Last Modified: +05:30 19:57:50 PM 10-03-2025, Monday
 */
//============================================================================================//

#include <Arduino.h>
#include <Wire.h>
#include <CSE_Touch.h>

//============================================================================================//
// Macros and Constants

// Define the touch panel pins here.
#define  CST328_PIN_RST       4
#define  CST328_PIN_INT       16
#define  CST328_PIN_SDA       21
#define  CST328_PIN_SCL       22

#define  TS_ROTATION          3   // The touch panel rotation

//============================================================================================//
// Globals

// Create a new instance of the CST328 class.
// Parameters: Width, Height, &Wire, Reset pin, Interrupt pin
CSE_Touch* tsPanel = CSE_Touch_Driver:: createDriver (CSE_Touch_t::CSE_TOUCH_CST328, 240, 320, &Wire, CST328_PIN_RST, CST328_PIN_INT);

bool intReceived = false; // Flag to indicate that an interrupt has been received

//============================================================================================//
// Forward Declarations

void setup();
void loop();
void readTouch();
void touchISR();

//============================================================================================//
/**
 * @brief Setup runs once.
 * 
 */
void setup() {
  Serial.begin (115200);
  delay (100);

  Serial.println();
  Serial.println ("== CSE_Touch: Read-Touch-Interrupt ==");

  // Initialize the I2C interface (for ESP32).
  Wire.begin (CST328_PIN_SDA, CST328_PIN_SCL);

  // Initialize the touch panel.
  tsPanel->begin();
  tsPanel->setRotation (TS_ROTATION);

  // Attach the interrupt function.
  attachInterrupt (digitalPinToInterrupt (CST328_PIN_INT), touchISR, FALLING);
  
  delay (100);
}

//============================================================================================//
/**
 * @brief Inifinite loop.
 * 
 */
void loop() {
  if (intReceived) {
    readTouch();
    intReceived = false;
    attachInterrupt (digitalPinToInterrupt (CST328_PIN_INT), touchISR, FALLING);
  }
}

//============================================================================================//
/**
 * @brief Reads the touches from the panel and print their info to the serial monitor.
 * 
 */
void readTouch() {
  uint8_t point = 0;
  
  if (tsPanel->isTouched (point)) {
    Serial.print ("Touch ID: ");
    Serial.print (point);
    Serial.print (", X: ");
    Serial.print (tsPanel->getPoint (point).x);
    Serial.print (", Y: ");
    Serial.print (tsPanel->getPoint (point).y);
    Serial.print (", Z: ");
    Serial.print (tsPanel->getPoint (point).z);
    Serial.print (", State: ");
    Serial.println (tsPanel->getPoint (point).state);
  }
  else {
    Serial.println ("No touches detected");
  }
}

//============================================================================================//
/**
 * @brief The touch interrupt service routine.
 * 
 */
void touchISR() {
  // Detach the interrupt to prevent multiple interrupts
  detachInterrupt (digitalPinToInterrupt (CST328_PIN_INT));
  intReceived = true;
}

//============================================================================================//
