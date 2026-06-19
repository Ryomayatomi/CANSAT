#include "sensor.h"
#include <Adafruit_BMP280.h>

Adafruit_BMP280 bmp;

bool initSensors() {

    if (!bmp.begin(0x77)) {
        return false;
    }

    return true;
}

SensorData readSensors() {

    SensorData data;

    data.temperature = bmp.readTemperature();
    data.pressure = bmp.readPressure() / 100.0;

    data.humidity = 0;

    data.ax = 0;
    data.ay = 0;
    data.az = 0;

    return data;
}