
//======================================================================================//
/*
  Filename: Read_PM_Data.ino
  Description: Reads the PM data from the Winsen ZH06 laster dust sensor using the `CSE_ZH06` library.
  Framework: Arduino, PlatformIO
  Author: Vishnu Mohanan (@vishnumaiea, @vizmohanan)
  Maintainer: CIRCUITSTATE Electronics (@circuitstate)
  Version: 0.0.1
  License: MIT
  Source: https://github.com/CIRCUITSTATE/CSE_ZH06
  Last Modified: +05:30 20:40:55 PM 23-12-2024, Monday
 */
//======================================================================================//

#include <Arduino.h>
#include <CSE_ZH06.h>

// Define the serial port pins here.
#define  PIN_SERIAL_TX1  16
#define  PIN_SERIAL_RX1  17

CSE_ZH06 pmSensor (Serial1);  // Create a CSE_ZH06 object to access the sensor

// Setup runs once.
void setup() {
  Serial.begin (115200);  // Initialize the debug serial port
  Serial1.begin (9600, SERIAL_8N1, PIN_SERIAL_RX1, PIN_SERIAL_TX1); // Initialize the sensor serial port

  pmSensor.begin(); // Initialize the sensor
}

// Inifinite loop.
void loop() {
  if (pmSensor.getPmData()) {
    Serial.println ("Data received. Printing data..");
    Serial.print ("PM1.0: ");
    Serial.print (pmSensor.pm1);
    Serial.println (" ug/m3");

    Serial.print ("PM2.5: ");
    Serial.print (pmSensor.pm25);
    Serial.println (" ug/m3");

    Serial.print ("PM10: ");
    Serial.print (pmSensor.pm10);
    Serial.println (" ug/m3");
    Serial.println();
  }
  
  else {
    Serial.println ("Data not received. Retrying..");
  }

  delay (1000);

  // pmSensor.sleep();
  // delay (3000);

  // pmSensor.wake();
  // delay (3000);
}
