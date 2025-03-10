# CSE_Touch Library API Reference

Version 0.0.1, +05:30 09:41:31 PM 10-03-2025, Monday

## Index

- [CSE\_Touch Library API Reference](#cse_touch-library-api-reference)
  - [Index](#index)
  - [Dependencies](#dependencies)
  - [Configuration](#configuration)
  - [Enums](#enums)
    - [`CSE_Touch_t`](#cse_touch_t)
  - [Classes](#classes)
  - [Class `CSE_TouchPoint`](#class-cse_touchpoint)
    - [Variables](#variables)
    - [Operators](#operators)
    - [`CSE_TouchPoint()`](#cse_touchpoint)
  - [Class `CSE_Touch`](#class-cse_touch)
    - [`CSE_Touch()`](#cse_touch)
    - [`init()`](#init)
    - [`begin()`](#begin)
    - [`setRotation()`](#setrotation)
    - [`getRotation()`](#getrotation)
    - [`getWidth()`](#getwidth)
    - [`getHeight()`](#getheight)
    - [`isTouched()`](#istouched)
    - [`getTouches()`](#gettouches)
    - [`getPoint()`](#getpoint)


## Dependencies

This library does not have any permanent dependencies other than the standard Arduino libraries. However, depending on the touch controller you are using, you will need to install on of the following libraries and select the correct touch controller in the `platformio.ini` configuration file. Check the [PIO-Examples](/extras/PIO-Examples/) to know how you can configure the library.

- [CSE_CST328](https://github.com/CIRCUITSTATE/CSE_CST328) - For CST328 capacitive touch controllers.
- [CSE_FT6206](https://github.com/CIRCUITSTATE/CSE_FT6206) - For FT6206 capacitive touch controllers.

## Configuration

The library requires defining one of the following macros to enable one of the supported touch controllers.

- `ENABLE_FT6206`
- `ENABLE_CST328`
- `ENABLE_XPT2046`

This can be done in your main application code or the `platformio.ini` configuration file.

## Enums

- `CSE_Touch_t` - The touch controller enum for the CSE_Touch library.

### `CSE_Touch_t`

This holds an enumerated list of supported touch controllers. This public enum can be used in your application code like the following:

```cpp
CSE_Touch_t touchController = CSE_Touch_t:: CSE_TOUCH_CST328;
```

#### Values

- `CSE_TOUCH_NONE` (0) - No touch controller.
- `CSE_TOUCH_XPT2046` (1) - XPT2046 capacitive touch controller.
- `CSE_TOUCH_FT6206` (2) - FT6206 capacitive touch controller.
- `CSE_TOUCH_CST328` (3) - CST328 capacitive touch controller.

## Classes

- `CSE_TouchPoint` - A generic class to manage touch points.
- `CSE_Touch` - The main class for the CSE_Touch library.
- `CSE_Touch_Driver` - The driver class for the CSE_Touch library.

## Class `CSE_TouchPoint`

This is a generic class to manage touch points. You can read the touch data directly to these objects and manipulate them as necessary.

### Variables

#### Public

- `int16_t x` : The x coordinate of the touch point.
- `int16_t y` : The y coordinate of the touch point.
- `uint16_t z` : The z coordinate of the touch point. Used for pressure sensitive touch controllers.
- `uint8_t id` : The id of the touch point. Used for multi-touch controllers.
- `uint8_t state` : The state of the touch point. `0` not touched, `>0` touched.

### Operators

- `bool operator==` : Compared two touch points for equality.
- `bool operator!=` : Compared two touch points for inequality.

### `CSE_TouchPoint()`

Creates a `CSE_TouchPoint` object. There are two overloads.

#### Syntax 1

```cpp
CSE_TouchPoint (void);
```

Creates an empty touch point with `id` 0. This is should not be used in normal cases. Create touch points with unique IDs always.

##### Parameters

- None

##### Returns

- `CSE_TouchPoint` object.

#### Syntax 2

```cpp
CSE_TouchPoint (int16_t x, int16_t y, int16_t z, uint8_t id);
```

Creates a new touch point object with the provided data.

##### Parameters

- `x` - The x coordinate of the touch point.
- `y` - The y coordinate of the touch point.
- `z` - The z coordinate of the touch point. Used for pressure sensitive touch controllers.
- `id` - The id of the touch point. Used for multi-touch controllers.

##### Returns

- `CSE_TouchPoint` object.

## Class `CSE_Touch`

This is the main class for the CSE_Touch library. You can define your touch panel as a `CSE_Touch` object in your main application code and read/write data to it. There are no variables associated with this class and all of the functions (except the constructor) are `virtual` that will be overridden in the `CSE_Touch_Driver` class.

### `CSE_Touch()`

This is the default constructor for the `CSE_Touch` class. This does nothing for now.

### `init()`

Initializes the target touch controller. `init()` and `begin()` are the same.

### `begin()`

Initializes the target touch controller. `init()` and `begin()` are the same.

### `setRotation()`

```cpp
uint8_t setRotation (uint8_t rotation);
```

Sets the rotation of the touch controller. You need to set this to the same as the LCD screen you have. If the touch point and the LCD point are not matching, you can try the other three rotation options.

#### Syntax

```cpp
uint8_t tsRotation = tsPanel.setRotation (rotation);
```

##### Parameters

- `rotation` - The rotation of the touch controller. `0` = 0°, `1` = 90°, `2` = 180°, `3` = 270°.

##### Returns

- `uint8_t` - The current rotation of the touch controller.

### `getRotation()`

```cpp
uint8_t getRotation (void);
```

Returns the current rotation of the touch controller.

#### Syntax

```cpp
uint8_t tsRotation = tsPanel.getRotation();
```

##### Parameters

- None

##### Returns

- `uint8_t` - The current rotation of the touch controller.

### `getWidth()`

```cpp
uint16_t getWidth (void);
```

Returns the width of the touch controller. This should be the same as the LCD width.

#### Syntax

```cpp
uint16_t tsWidth = tsPanel.getWidth();
```

##### Parameters

- None

##### Returns

- `uint16_t` - The width of the touch controller.

### `getHeight()`

```cpp
uint16_t getHeight (void);
```

Returns the height of the touch controller. This should be the same as the LCD height.

#### Syntax

```cpp
uint16_t tsHeight = tsPanel.getHeight();
```

##### Parameters

- None

##### Returns

- `uint16_t` - The height of the touch controller.

### `isTouched()`

```cpp
bool isTouched (void);
bool isTouched (uint8_t id)
```

Checks if a the touch panel is being touched or if a specific touch point is being touched.

#### Syntax 1

```cpp
bool tsTouched = tsPanel.isTouched();
```

For touch panels with multi-touch support, any touch will return `true`.

##### Parameters

- None

##### Returns

- `bool` - `true` if the touch panel is being touched, `false` otherwise.

#### Syntax 2

```cpp
bool tsTouched = tsPanel.isTouched (id);
```

Checks if a specific touch point is being touched.

##### Parameters

- `id` - The id of the touch point.

##### Returns

- `bool` - `true` if the touch point is being touched, `false` otherwise.

### `getTouches()`

```cpp
uint8_t getTouches (void);
```

Returns the number of touches on the touch panel.

#### Syntax

```cpp
uint8_t tsTouches = tsPanel.getTouches();
```

##### Parameters

- None

##### Returns

- `uint8_t` - The number of touches on the touch panel.

### `getPoint()`

```cpp
CSE_TouchPoint getPoint (uint8_t id);
```

Returns the position of a specific touch point as a `CSE_TouchPoint` object. The `id` is optional and defaults to `0` if not provided.

#### Syntax

```cpp
CSE_TouchPoint tsPoint = tsPanel.getPoint();
CSE_TouchPoint tsPoint = tsPanel.getPoint (id);
```

##### Parameters

- `id` - The id of the touch point. Defaults to `0`.

##### Returns

- `CSE_TouchPoint` - The position of the touch point as a `CSE_TouchPoint` object.





