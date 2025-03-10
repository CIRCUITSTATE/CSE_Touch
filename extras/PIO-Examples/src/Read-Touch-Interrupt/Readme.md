

# Read-Touch-Interrupt

This example demonstrate the use of the [CSE_Touch](https://github.com/CIRCUITSTATE/CSE_Touch) library to read the values from a touch panel. This example uses the interrupt method instead of the [polling](/extras/PIO-Examples/src/Read-Touch-Polling) method. The advantage of the interrupt method is that your processor does not need to poll the touch panel constantly. Instead, it will only be triggered when the touch panel is touched, through an interrupt output from the touch panel which is connected to a GPIO input of the microcontroller.

This example was written for and tested with [**FireBeetle-ESP32E**](https://www.dfrobot.com/product-2195.html) development board from **DFRobot** and the [**2.8" Capacitive Touch LCD**](https://www.waveshare.com/wiki/2.8inch_Capacitive_Touch_LCD) from **Waveshare**. But you can adapt the examples for any Arduino-compatible boards or other supported touch panels.
