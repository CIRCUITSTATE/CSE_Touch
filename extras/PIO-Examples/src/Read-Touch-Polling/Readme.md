
# Read-Touch-Polling

This example demonstrate the use of the [CSE_Touch](https://github.com/CIRCUITSTATE/CSE_Touch) library to read the values from a touch panel. This example uses the polling method instead of the [interrupt](/extras/PIO-Examples/src/Read-Touch-Interrupt) method. Polling method is useful when you want to read the values from the touch panel constantly, whenever you choose. This also avoids the need for an extra GPIO pin to be used for the interrupt input.

This example was written for and tested with [**FireBeetle-ESP32E**](https://www.dfrobot.com/product-2195.html) development board from **DFRobot** and the [**2.8" Capacitive Touch LCD**](https://www.waveshare.com/wiki/2.8inch_Capacitive_Touch_LCD) from **Waveshare**. But you can adapt the examples for any Arduino-compatible boards or other supported touch panels.
