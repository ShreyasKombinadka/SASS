#include "SASS.h"

void SASS_transmitter(int pin, unsigned long T_us, int bit_len, uint64_t frame) // Transmitter function
{
    pinMode(pin, OUTPUT); // GPIO to send frames through

    digitalWrite(pin, LOW);  // Start transmission by pulling the line low
    delayMicroseconds(T_us); // Keep the start frame for T period

    for (int i = 0; i < bit_len; i++) // Repeat the loop for all bits
    {
        uint8_t bit_value = (frame >> i) & 1; // Select one bit at a time
        digitalWrite(pin, bit_value);         // Output one bit at a time
        delayMicroseconds(T_us);              // Keep each bit active for T period
    }

    digitalWrite(pin, LOW);  // Stop bit
    delayMicroseconds(T_us); // Keep the stop bit for T period

    digitalWrite(pin, HIGH); // Idle condition
}

void SASS_receiver(int pin, unsigned long T_us, int bit_len, uint64_t &frame) // Receiver function
{
    frame = 0;        // initialize frae value
    if (bit_len > 62) // Total number of bits should be lesser than 62
        return;
    while (digitalRead(pin) == HIGH) // Idle state
        ;                            // Wait for a start bit
    // If the start bit is detected
    delayMicroseconds(T_us + (T_us / 2)); // Skip the start bit and set the sampling time to right at the middle of next bit
    for (int i = 0; i < bit_len; i++)
    {
        if (digitalRead(pin) == HIGH)
            frame |= (1ULL << i);
        delayMicroseconds(T_us); // Wait till the next bits mid period
    }
    delayMicroseconds(T_us / 2); // Wait for a full T before checking for next transmission
}