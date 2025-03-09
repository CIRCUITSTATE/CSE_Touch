
//======================================================================================//
/*
  Filename: Test.ino
  Description: Test code for the CSE_ZH06 Arduino library.
  Framework: Arduino, PlatformIO
  Author: Vishnu Mohanan (@vishnumaiea, @vizmohanan)
  Maintainer: CIRCUITSTATE Electronics (@circuitstate)
  Version: 0.0.1
  License: MIT
  Source: https://github.com/CIRCUITSTATE/CSE_ZH06
  Last Modified: +05:30 20:41:43 PM 23-12-2024, Monday
 */
//======================================================================================//

#include <Arduino.h>
#include <CSE_ZH06.h>

//======================================================================================//

#define  PIN_SERIAL_TX1  16
#define  PIN_SERIAL_RX1  17

//======================================================================================//

uint8_t rxInitiativeData [32] = {0};
uint8_t rxData [9] = {0};
uint8_t txData [9] = {0};

CSE_ZH06 pmSensor (Serial1);

//======================================================================================//

void readPmData();
void readInitiativeData();

//======================================================================================//

void setup() {
  Serial.begin (115200);
  Serial1.begin (9600, SERIAL_8N1, PIN_SERIAL_RX1, PIN_SERIAL_TX1);

  pmSensor.begin();
}

//======================================================================================//

void loop() {
  // readInitiativeData();
  // readPmData();
  
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

//======================================================================================//

void readPmData() {
  uint8_t rxDataByte = 0;
  bool readCompleted = false;
  uint8_t byteCount = 0;

  uint8_t aqiCommand [9] = {0xFF, 0x01, 0x86, 0x00, 0x00, 0x00, 0x00, 0x00, 0x79};

  Serial.println ("Sending read command to ZH06..");

  for (int i = 0; i < 9; i++) {
    Serial1.write (aqiCommand [i]);
  }

  Serial.println ("Reading data from ZH06..");

  while (!readCompleted) {
    if (Serial1.available() > 0) {
      rxDataByte = Serial1.read();

      if ((rxDataByte == 0xFF) && (byteCount == 0)) { // Read the Start Byte 1
        rxData [0] = rxDataByte;
        byteCount++;
      }

      else if ((rxDataByte == 0x86) && (byteCount == 1)) { // Read the Start Byte 2
        rxData [1] = rxDataByte;
        byteCount++;
      }

      else if ((byteCount > 1) && (byteCount < 9)) {
        rxData [byteCount] = rxDataByte;
        byteCount++;
      }

      if (byteCount >= 9) {
        readCompleted = true;
        byteCount = 0;
      }
    }
  }

  Serial.println ("Data received. Printing data..");

  for (int i = 0; i < 9; i++) {
    Serial.print (rxData [i], HEX);
    Serial.print (" ");
  }

  Serial.println();

  Serial.println ("Decoding data..");

  float pm1 = 0.0;
  float pm25 = 0.0;
  float pm10 = 0.0;

  // Combine bytes 2 and 3 to get the PM1.0 value
  pm1 = float (uint16_t (rxData [6] << 8) | uint16_t (rxData [7]));
  // Combine bytes 4 and 5 to get the PM2.5 value
  pm25 = float (uint16_t (rxData [2] << 8) | uint16_t (rxData [3]));
  // Combine bytes 6 and 7 to get the PM10 value
  pm10 = float (uint16_t (rxData [4] << 8) | uint16_t (rxData [5]));

  Serial.print ("PM1.0: ");
  Serial.print (pm1);
  Serial.println (" ug/m3");

  Serial.print ("PM2.5: ");
  Serial.print (pm25);
  Serial.println (" ug/m3");

  Serial.print ("PM10: ");
  Serial.print (pm10);
  Serial.println (" ug/m3");
  Serial.println();

  delay (1000);
}

//======================================================================================//

void readInitiativeData() {
  Serial.println ("Reading data from ZH06..");

  uint8_t rxDataByte = 0;
  bool readCompleted = false;
  uint8_t byteCount = 0;

  while (!readCompleted) {
    if (Serial1.available() > 0) {
      rxDataByte = Serial1.read();

      if ((rxDataByte == 0x42) && (byteCount == 0)) { // Read the Start Byte 1
        rxInitiativeData [0] = rxDataByte;
        byteCount++;
      }

      else if ((rxDataByte == 0x4D) && (byteCount == 1)) { // Read the Start Byte 2
        rxInitiativeData [1] = rxDataByte;
        byteCount++;
      }

      else if ((rxDataByte == 0x00) && (byteCount == 2)) { // Read the frame length byte 1
        rxInitiativeData [2] = rxDataByte;
        byteCount++;
      }

      else if ((rxDataByte == 0x1C) && (byteCount == 3)) { // Read the frame length byte 2
        rxInitiativeData [3] = rxDataByte;
        byteCount++;
      }

      else if ((byteCount > 3) && (byteCount < 32)) {
        rxInitiativeData [byteCount] = rxDataByte;
        byteCount++;
      }

      if (byteCount >= 32) {
        readCompleted = true;
        byteCount = 0;
      }
    }
  }

  Serial.println ("Data received. Printing data..");

  // Print the data in HEX format.
  for (int i = 0; i < 32; i++) {
    Serial.print (rxInitiativeData [i], HEX);
    Serial.print (" ");
  }

  Serial.println();

  Serial.println ("Decoding data..");

  float pm1 = 0.0;
  float pm25 = 0.0;
  float pm10 = 0.0;

  // Combine bytes 10 and 11 to get the PM1.0 value
  pm1 = float (uint16_t (rxInitiativeData [10] << 8) | uint16_t (rxInitiativeData [11]));
  // Combine bytes 12 and 13 to get the PM2.5 value
  pm25 = float (uint16_t (rxInitiativeData [12] << 8) | uint16_t (rxInitiativeData [13]));
  // Combine bytes 14 and 15 to get the PM10 value
  pm10 = float (uint16_t (rxInitiativeData [14] << 8) | uint16_t (rxInitiativeData [15]));

  Serial.print ("PM1.0: ");
  Serial.print (pm1);
  Serial.println (" ug/m3");

  Serial.print ("PM2.5: ");
  Serial.print (pm25);
  Serial.println (" ug/m3");

  Serial.print ("PM10: ");
  Serial.print (pm10);
  Serial.println (" ug/m3");
  Serial.println();

  delay (1000);
}

//======================================================================================//