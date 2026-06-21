#include <Arduino.h>
#include "sensor.h"

void setup()
{
    Serial.begin(115200);

    if (!initSensors())
    {
        Serial.println("Sensor Error");
        while (1);
    }

    Serial.println("Sensor OK");
}

void loop()
{
    SensorData data = readSensors();

    Serial.print("T=");
    Serial.print(data.temperature);

    Serial.print(" H=");
    Serial.print(data.humidity);

    Serial.print(" AX=");
    Serial.print(data.ax);

    Serial.print(" AY=");
    Serial.print(data.ay);

    Serial.print(" AZ=");
    Serial.println(data.az);

    delay(500);
}