#include <Arduino.h>
#include "sensor.h"
#include "display.h"

void setup()
{
    Serial.begin(115200);

    if(!initSensors())
    {
        Serial.println("Sensor Error");
        while(1);
    }

    if(!initDisplay())
    {
        Serial.println("Display Error");
        while(1);
    }

    Serial.println("System OK");
}

void loop()
{
    SensorData data = readSensors();

    Serial.print("Temp=");
    Serial.print(data.temperature);

    Serial.print(" Hum=");
    Serial.println(data.humidity);

    updateDisplay(
        data.temperature,
        data.humidity
    );

    delay(1000);
}