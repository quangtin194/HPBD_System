#ifndef __OLED_H
#define __OLED_H

#define SCREEN_W 128
#define SCREEN_H 64

#include <stdint.h>
#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

void Oled_init (uint8_t sda, uint8_t scl);
void Oled_display (const char *text1, const char *text2);

#endif