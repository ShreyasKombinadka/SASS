#include <SASS.h>

void setup()
{
    Serial.begin(9600);

    uint64_t frame_t = 0b101101;
    Serial.println("Sending SASS frame...");

    SASS_transmitter(5, 200, 6, frame_t);
}

void loop() {}
