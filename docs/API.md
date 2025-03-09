# CSE_ZH06 Library API Reference

Version 0.0.1, +05:30 09:47:56 PM 23-12-2024, Monday

## Index

- [CSE\_ZH06 Library API Reference](#cse_zh06-library-api-reference)
  - [Index](#index)
  - [Dependencies](#dependencies)
  - [Configuration](#configuration)
  - [Classes](#classes)
  - [Class `CSE_ZH06`](#class-cse_zh06)
    - [Variables](#variables)
    - [`CSE_ZH06()`](#cse_zh06)
    - [`~CSE_ZH06()`](#cse_zh06-1)
    - [`begin()`](#begin)
    - [`getPmData()`](#getpmdata)
    - [`sleep()`](#sleep)
    - [`wake()`](#wake)
    - [`sendData()`](#senddata)


## Dependencies

- [CSE_MillisTimer](https://github.com/CIRCUITSTATE/CSE_MillisTimer)

## Configuration

Since the library supports accepting both Hardware and Software serial ports, the library will be automatically configured to use either of them based on the platform you are compiling the code for. For example, targets with only one hardware serial ports can only use software serial port. The macro `SOFTWARE_SERIAL_REQUIRED` is automatically defined for such targets and the `SoftwareSerial.h` library is loaded. For all other targets with more than one hardware serial ports, the `SOFTWARE_SERIAL_REQUIRED` macro is not defined and therefore can use any of the hardware serial ports.

The number of hardware serial ports is defined using the `_HAVE_HWSERIAL1` macro. You can override or expand this behaviour in the `CSE_ZH06.h` file. Following are the defaults for the most common targets.

- Software Serial
  - `ARDUINO_AVR_UNO`
  - `ARDUINO_AVR_NANO`
  - `ESP8266`
- Hardware Serial
  - `ARDUINO_AVR_MEGA2560`
  - `ARDUINO_ARCH_ESP32`

## Classes

* `CSE_ZH06` - The main class for wrapping the data and functions of the library.

## Class `CSE_ZH06`

### Variables

#### Public

- `uint8_t rxData [32]` : Buffer to receive the data from the sensor. Initializes to `0`.
- `uint8_t txData [9]` : Buffer to hold the data to send to the sensor. Initializes to `0`.
- `uint16_t pm1` : PM 1.0 concentration in micrograms per cubic meter (ug/m3). Initializes to `0`.
- `uint16_t pm25` : PM 2.5 concentration in micrograms per cubic meter (ug/m3). Initializes to `0`.
- `uint16_t pm10` : PM 10.0 concentration in micrograms per cubic meter (ug/m3). Initializes to `0`.

#### Private

- `SoftwareSerial* _serial` : A pointer to a software serial port. Initializes to `nullptr`. This will only be used if the `SOFTWARE_SERIAL_REQUIRED` macro is defined.

- `HardwareSerial* _serial` : A pointer to a hardware serial port. Initializes to `nullptr`. This will only be used if the `SOFTWARE_SERIAL_REQUIRED` macro is not defined.

### `CSE_ZH06()`

This constructor creates a new `CSE_ZH06` object. There are two overloads based on the parameter type. User can send a `HardwareSerial` or a `SoftwareSerial` port object. The type of constructor is determined by the macro `SOFTWARE_SERIAL_REQUIRED`. The supplied serial port is saved to the `_serial` variable.

Throughout this documentation, an example `CSE_ZH06` object `sensor` will be used for examples.

#### Syntax 1

```cpp
CSE_ZH06 (SoftwareSerial& swSerial);
```

##### Parameters

- `swSerial` : A software serial port of type `SoftwareSerial`. Only allowed if the `SOFTWARE_SERIAL_REQUIRED` macro is defined.

##### Returns

`CSE_ZH06` object.

#### Syntax 2

```cpp
CSE_ZH06 (HardwareSerial& hwSerial);
```

##### Parameters

- `hwSerial` : A hardware serial port of type `HardwareSerial`. Only allowed if the `SOFTWARE_SERIAL_REQUIRED` macro is not defined.

##### Returns

- `CSE_ZH06` object.

### `~CSE_ZH06()`

Destroys the `CSE_ZH06` object.

#### Syntax

```cpp
sensor.~CSE_ZH06();
```

##### Parameters

None

##### Returns

None

### `begin()`

Does nothing for now. The user must initialize the serial port they want to use before interacting with the sensor.

#### Syntax

```cpp
sensor.begin();
```

##### Parameters

None

##### Returns

None

### `getPmData()`

Reads the PM data from the sensor. It first sends the request for the PM data and reads back the response. The response contains the PM data for PM1.0, PM2.5 and PM10. These values are then stored to the `pm1`, `pm25` and `pm10` variables and the user can directly read them. Additionally, the user can also pass a pointer to an array to store the data. The array should be of type `uint16_t` and should have a length of 3. Sending the array is optional.

#### Syntax

```cpp
sensor.getPmData (uint16_t* data = NULL);
```

##### Parameters

- `uint16_t* data` : A pointer to an array of `uint16_t` type. Optional. Defaults to `NULL`.

##### Returns

- `bool` : `true` if successful, `false` otherwise.

### `sleep()`

Puts the sensor into sleep mode as specified in the datasheet. This function can actually put the sensor to sleep mode as well as wake it up from the sleep mode. Use the `toSleep` parameter to specify whether to put the sensor to sleep or wake it up. Sending the parameter is optional. By default, the value is `true` (sleep mode).

#### Syntax

```cpp
sensor.sleep (bool toSleep = true);
```

##### Parameters

- `bool toSleep` : `true` to put the sensor to sleep, `false` to wake it up. Optional. Defaults to `true`.

##### Returns

- `bool` : `true` if successful, `false` otherwise.

### `wake()`

Wakes up the sensor from the sleep mode.

#### Syntax

```cpp
sensor.wake();
```

##### Parameters

None

##### Returns

- `bool` : `true` if successful, `false` otherwise.

### `sendData()`

Private function. Sends some data to the sensor. There are two overloads.

The first one expects a one way transfer and does not read back what the sensor sent.

#### Syntax 1

```cpp
sendData (uint8_t* txData, uint8_t txLength)
```

##### Parameters

- `uint8_t* txData` : A pointer to an array of `uint8_t` type. This is the data you want to send.
- `uint8_t txLength` : The length of the data you want to send. Should be less than or equal to `txData` length.

##### Returns

None

#### Syntax 2

This sends data to the sensor and the response is saved to the `rxData` array. Receiving does not work as expected for now. So don't use this.

```cpp
sendData (uint8_t* txData, uint8_t txLength, uint8_t* rxData, uint8_t rxLength);
```

##### Parameters

- `uint8_t* txData` : A pointer to an array of `uint8_t` type. This is the data you want to send.
- `uint8_t txLength` : The length of the data you want to send. Should be less than or equal to `txData` length.
- `uint8_t* rxData` : A pointer to an array of `uint8_t` type. This is the location to save the data you want to receive.
- `uint8_t rxLength` : The length of the data you want to receive. Should be less than or equal to `rxData` length.

