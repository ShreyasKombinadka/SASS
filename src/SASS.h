#ifndef SASS_H
#define SASS_H

#include <Arduino.h>
#include <stdint.h>

void SASS_transmitter(int pin, unsigned long T_us, int bit_len, uint64_t frame);
void SASS_receiver(int pin, unsigned long T_us, int bit_len, uint64_t &frame);

#endif
