#ifndef __LED7_H
#define __LED7_H

#include <stdint.h>
#include <Arduino.h>

void Led7_init (uint8_t p1, uint8_t p2, uint8_t p3, uint8_t p4,uint8_t p5, uint8_t p6, uint8_t p7);
void Led7_display (uint8_t num);

#endif