#include "buzzer.h"

// === VARIABLES ===
static uint8_t buzzer_pin;
static uint8_t buzzer_channel;

// Song: Happyy Birthday
static uint16_t melody[] =
{
    392, 392, 440, 392, 523, 494,
    392, 392, 440, 392, 587, 523,
    392, 392, 784, 659, 523, 494, 440,
    698, 698, 659, 523, 587, 523
};
static uint16_t duration[] =
{
    250, 250, 500, 500, 500, 1000,
    250, 250, 500, 500, 500, 1000,
    250, 250, 500, 500, 500, 500, 1000,
    250, 250, 500, 500, 500, 1000
};

// ==== FUNCTIONS ===

void Buzzer_init (uint8_t pin, uint8_t channel) {
    buzzer_pin = pin;
    buzzer_channel = channel;
    ledcSetup(buzzer_channel, 1000, 8);
    ledcAttachPin(buzzer_pin, buzzer_channel);
    
}

void Buzzer_bip_Sound (void) {
    ledcWrite(buzzer_channel, 128);
}

void Buzzer_stop (void) {
    ledcWrite(buzzer_channel, 0);
}

void Buzzer_music (void) {
    for (uint8_t i = 0; i <sizeof(melody) / sizeof(melody[0]); i++) {
        ledcSetup(buzzer_channel, (uint32_t)melody[i], 8);
        ledcWrite(buzzer_channel, 200);
        delay(duration[i]);
        Buzzer_stop();
    }
}

