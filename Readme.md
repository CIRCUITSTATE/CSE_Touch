
![CSE_Touch](https://socialify.git.ci/CIRCUITSTATE/CSE_Touch/image?description=1&font=KoHo&forks=1&issues=1&logo=https%3A%2F%2Fwww.circuitstate.com%2Fwp-content%2Fuploads%2F2024%2F05%2FCIRCUITSTATE-R-Emblem-20052024-2.svg&name=1&pattern=Circuit%20Board&pulls=1&stargazers=1&theme=Auto)

# CSE_Touch

**CSE_Touch** is an Arduino library from [*CIRCUITSTATE Electronics*](https://www.circuitstate.com/). It is a unified touch interface library for the Arduino platform. The advantage of using a unified library is that you can change the touch panel in your application code very easily with only minor changes to the code. CSE_Touch is designed to be extensible and compatible with our CSE_UI library.Currently, the library supports the following touch controllers.

- FT6206
- CST328

## Installation

This library is available from the official **Arduino Library Manager**. Open the Arduino IDE, search for "CSE_Touch" and install the latest version of the library.

Additionally, you can download the latest release package from the GitHub repository and install it manually. To do so, open the Arduino IDE, go to `Sketch > Include Library > Add .ZIP Library…` and select the downloaded file.

Another method is to clone the GitHub repository directly into your `libraries` folder. The development branch will have the latest features, bug fixes and other changes. To do so, navigate to your `libraries` folder (usually located at `Documents/Arduino/libraries` on Windows and `~/Documents/Arduino/libraries` on macOS) and execute the following command:

```
git clone https://github.com/CIRCUITSTATE/CSE_Touch.git
```

[**Git**](https://git-scm.com) should be installed on your computer.

The library can also be installed via [**PlatformIO**](https://platformio.org). All officially listed Arduino listed libraries are automatically fetched by PlatformIO. Use the [`lib_deps`](https://docs.platformio.org/en/latest/projectconf/sections/env/options/library/lib_deps.html) search option to install the library.

## Dependencies

Based on the touch controller you want to use, the driver is automatically selected by the CSE_Touch library. Currently, the following libraries from CIRCUTISTATE are supported. Make sure to install them depending on which one you are going to use.

- [CSE_CST328](https://github.com/CIRCUITSTATE/CSE_CST328) - For CST328 capacitive touch controllers.
- [CSE_FT6206](https://github.com/CIRCUITSTATE/CSE_FT6206) - For FT6206 capacitive touch controllers.

## Example

There are no examples that are directly supported by the Arduino IDE. This is because of the Arduino's complex and convoluted dependency resolution and compilation design. However, you can find examples in the [examples folder](../extras/PIO-Examples/) that are compatible with the PlatformIO IDE. These examples were written for and tested with [**FireBeetle-ESP32E**](https://www.dfrobot.com/product-2195.html) development board from **DFRobot** and the [**2.8" Capacitive Touch LCD**](https://www.waveshare.com/wiki/2.8inch_Capacitive_Touch_LCD) from **Waveshare**. But you can adapt the examples for any Arduino-compatible boards or other supported touch panels.

- [Read-Touch-Interrupt](extras/PIO-Examples/src/Read-Touch-Interrupt/) - Demonstrates the use of the interrupt method instead of the polling method.
- [Read-Touch-Polling](extras/PIO-Examples/src/Read-Touch-Polling/) - Demonstrates the use of the polling method instead of the interrupt method.

## API Reference

Please see the [API.md](/docs/API.md) file for the API reference.

## References

- [**CSE_UI - CIRCUITSTATE GitHub**](https://github.com/CIRCUITSTATE/CSE_UI) - An Arduino GUI library for common TFT/IPS screens.
- [**CSE_CST328 Library**](https://github.com/CIRCUITSTATE/CSE_CST328) - An Arduino library for CST328 capacitive touch controllers.
- [**CSE_FT6206 Library**](https://github.com/CIRCUITSTATE/CSE_FT6206) - An Arduino library for FT6206 capacitive touch controllers.
- [**Waveshare 2.8" Capacitive Touch LCD**](https://www.waveshare.com/wiki/2.8inch_Capacitive_Touch_LCD)
- [**DFRobot FireBeetle-ESP32E**](https://www.dfrobot.com/product-2195.html)