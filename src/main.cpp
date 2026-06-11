#include <Arduino.h>

void setup()
{
    Serial.begin(115200);
    Serial.println("Hello CanSat!");
}

void loop()
{
    Serial.println("ESP32 OK");
    delay(1000);
}