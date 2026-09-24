# ESP32 Birthday Greeting System

## Overview

ESP32 Birthday Greeting System is an embedded IoT project that uses an ESP32 Web Server as the user interface for creating a birthday greeting.

The user accesses the ESP32 Web Server from a browser, enters the name of the person being congratulated, and selects a countdown value from 0 to 9. The ESP32 then controls the connected hardware to perform the birthday greeting sequence.

## Features

- ESP32-based Web Server
- Web interface for entering the recipient's name
- Adjustable countdown from 0 to 9
- 7-segment LED countdown display
- OLED display for messages
- Passive buzzer for sound effects
- Happy Birthday melody playback
- Modular C/C++ code organization

## Hardware

- DOIT ESP32 DevKit V1
- OLED 128x64 SSD1306
- 1-digit 7-segment LED
- Passive buzzer

## Software & Technologies

- C/C++
- Arduino Framework
- PlatformIO
- ESP32 WiFi
- ESP32 WebServer
- Adafruit GFX Library
- Adafruit SSD1306 Library

## Block Diagram

```text
                ┌──────────────────────┐
                │      Web Browser     │
                │  Name + Countdown    │
                └──────────┬───────────┘
                           │ HTTP
                           ▼
                ┌──────────────────────┐
                │   ESP32 Web Server   │
                │                      │
                │  HTTP Request        │
                │       ↓              │
                │  Data Processing     │
                │       ↓              │
                │  Control Logic       │
                └──────┬─────┬─────┬───┘
                   SPI │     │GPIO │   PWM
                 ┌─────┘     │     └─────┐
                 ▼           ▼           ▼
          ┌────────────┐ ┌──────────┐ ┌─────────────┐
          │  OLED      │ │ 7-Segment│ │   Passive   │
          │  SSD1306   │ │   LED    │ │   Buzzer    │
          └────────────┘ └──────────┘ └─────────────┘
                 │           │              │
                 └───────────┴──────────────┘
                             │
                             ▼
                    Birthday Greeting
```
## How to Use

1. Clone the repository.
2. Open the project using PlatformIO.
3. Configure the WiFi SSID and password in the source code.
4. Build and upload the firmware to the ESP32.
5. Open the Serial Monitor and obtain the ESP32's local IP address.
6. Connect a device to the same WiFi network as the ESP32.
7. Open the ESP32 IP address in a web browser.
8. Enter the recipient's name and select the countdown value.
9. Press the start button and let the ESP32 perform the birthday greeting sequence.

## Demo

Real-world photos and demonstration media will be added later.

## Author

Lê Quang Tín

GitHub: quangtin194
