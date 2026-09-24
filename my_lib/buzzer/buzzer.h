#ifndef __BUZZER_H
#define __BUZZER_H

#include <stdint.h>
#include <Arduino.h>

void Buzzer_init (uint8_t pin, uint8_t channel);
void Buzzer_bip_Sound (void);
void Buzzer_stop (void);
void Buzzer_music (void);

#endif