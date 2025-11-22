#include "SASS.h"

void SASS_transmitter(int pin, unsigned long T_us, int bit_len, uint64_t frame)
{
    pinMode(pin, OUTPUT);

    digitalWrite(pin, LOW);
    delayMicroseconds(T_us);

    for (int i = 0; i < bit_len; i++)
    {
        uint8_t bit_value = (frame >> i) & 1;
        digitalWrite(pin, bit_value);
        delayMicroseconds(T_us);
    }

    digitalWrite(pin, LOW);
    delayMicroseconds(T_us);

    digitalWrite(pin, HIGH);
}

void SASS_receiver(int pin, unsigned long T_us, int bit_len, uint64_t &frame)
{
    frame = 0;
    if (bit_len > 62)
        return;
    while (digitalRead(pin) == HIGH)
        ;
    delayMicroseconds(T_us / 2); // Changed from T_us + T_us/2
    for (int i = 0; i < bit_len; i++)
    {
        if (digitalRead(pin) == HIGH)
            frame |= (1ULL << i);
        delayMicroseconds(T_us);
    }
    delayMicroseconds(T_us / 2);
}