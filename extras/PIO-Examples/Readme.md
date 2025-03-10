

# PlatformIO Examples

Here you can find examples for the CSE_Touch library. Simply open the `PIO-Examples` folder in VS Code and you will be able to compile all of the examples easily. The PlatformIO extension should be already installed and configured. When you open any folder in VS Code with the `platformio.ini` file in the root folder, the PIO extension is automatically invoked and you will be able to compile and upload. Check the screenshot below for a reference.

![Examples opened in VS Code and PlatformIO](/docs/images/exaples-opened-in-platformio-1.png)

To choose which folder to compile and upload, click on the `env:` tab on the bottom bar and then choose the example you want. Use the tick icon to compile and the right arrow icon to upload.

![Choose the example](/docs/images/choose-the-examples-1.png)

The default example is `Read-Touch-Polling`. To choose the touch controller and set other configurations, you can use the `platformio.ini` file. To choose the touch controller, use the `build_flags` option as shown below.

```ini
; Do not add any extra spaces before or after the "=" for define statements.
; It will cause the build to fail.
build_flags =
  -D ENABLE_CST328=1  ; Choose your touch controller here
```

Currently, the following touch controllers are supported.

- CST328 (`ENABLE_CST328=1`)
- FT6206 (`ENABLE_FT6206=1`)

The `=1` is how you tell PIO to define a macro in your main project. If the value is `0` the macro will not be defined. You can either put the value as `0` or comment out an unused macro. Only one touch controller should be enabled at a time.

The dependencies are added under the `lib_deps` option. You also need to add the correct touch controller library here. Since the examples reside inside the `CSE_Touch` library folder, the dependencies are added as backward traversed symlinks. This assumes that all of the dependencies are installed under the `libraries` folder.

```ini
; Assuming the dependencies are installed in the Arduino `libraries` folder
lib_deps =
  CSE_CST328 = symlink://../../../CSE_CST328
  CSE_Touch = symlink://../../../CSE_Touch
```

Learn more about the `platormio.ini` file in the [**PlatformIO Project Configuration File**](https://docs.platformio.org/en/latest/projectconf/index.html) documentation.
