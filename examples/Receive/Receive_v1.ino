#include <SASS.h>

uint64_t frame_r = 0;

void setup()
{
    Serial.begin(9600);
    pinMode(4, INPUT);
}

void loop()
{
    SASS_receiver(4, 200, 6, frame_r);

    Serial.print("Received: ");
    Serial.println(frame_r, BIN);

    delay(100);
}
