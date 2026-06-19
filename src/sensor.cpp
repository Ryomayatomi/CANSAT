#include "sensor.h"

#include <Wire.h>
#include <Adafruit_AHTX0.h>

Adafruit_AHTX0 aht;

bool initSensors()
{
    Wire.begin(21, 22);

    if (!aht.begin()) {
        return false;
    }

    return true;
}

SensorData readSensors()
{
    SensorData data;

    sensors_event_t humidity;
    sensors_event_t temp;

    aht.getEvent(&humidity, &temp);

    data.temperature = temp.temperature;
    data.humidity = humidity.relative_humidity;

    // 未実装部分
    data.pressure = 0;

    data.ax = 0;
    data.ay = 0;
    data.az = 0;

    return data;
}