#include "led7.h"

// === VARIABLES ===
static uint8_t Led7_pin_arr [7] = {};
static uint8_t seg7Code [] = 
{
    // abcdefg dp
    //  Led 7 seg Cathode (1 = Led on)
    0x3F, // 0
    0x06, // 1
    0x5B, // 2
    0x4F, // 3
    0x66, // 4
    0x6D, // 5
    0x7D, // 6
    0x07, // 7
    0x7F, // 8
    0x6F  // 9
};

// ==== FUNCTIONS ===
void Led7_init (uint8_t p1, uint8_t p2, uint8_t p3, uint8_t p4,uint8_t p5, uint8_t p6, uint8_t p7) {
    Led7_pin_arr[0] = p1;
    Led7_pin_arr[1] = p2;
    Led7_pin_arr[2] = p3;
    Led7_pin_arr[3] = p4;
    Led7_pin_arr[4] = p5;
    Led7_pin_arr[5] = p6;
    Led7_pin_arr[6] = p7;
    for (uint8_t i = 0; i < sizeof(Led7_pin_arr) / sizeof(Led7_pin_arr[0]); i++) {
        pinMode(Led7_pin_arr[i], OUTPUT);
    }
}

void Led7_display (uint8_t num) {
    uint8_t temp = seg7Code[num];
    for (uint8_t i = 0; i < 7; i++) {
        digitalWrite(Led7_pin_arr[i], temp & 0x01);

        temp >>= 1;
    }
}