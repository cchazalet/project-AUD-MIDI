# How to build PlatformIO based project

1. [Install PlatformIO Core](https://docs.platformio.org/page/core.html)
2. Download [development platform with examples](https://github.com/platformio/platform-teensy/archive/develop.zip)
3. Extract ZIP archive
4. Run these commands:

```shell
# Change directory to example
$ cd platform-teensy/examples/arduino-blink

# Build project
$ pio run

# Upload firmware
$ pio run --target upload

# Build specific environment
$ pio run -e teensy31

# Upload firmware for the specific environment
$ pio run -e teensy31 --target upload

# Clean build files
$ pio run --target clean
```

# project-AUD-MIDI

![Alt text](/img/2022-12-12%2014_59_11-Clipboard.png "Screenshot IDE Arduino")
