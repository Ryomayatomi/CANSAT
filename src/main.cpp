#include <Arduino.h>
#include "sensor.h"

void setup()
{
    Serial.begin(115200);

    if (!initSensors()) {
        Serial.println("Sensor Error");
        while (1);
    }

    Serial.println("Sensor OK");
}

void loop()
{
    SensorData data = readSensors();

    Serial.print("Temp: ");
    Serial.print(data.temperature);
    Serial.println(" C");

    Serial.print("Humidity: ");
    Serial.print(data.humidity);
    Serial.println(" %");

    Serial.println();

    delay(2000);
}