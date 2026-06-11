#include "sensor.h"

bool initSensors() {
    return true;
}

SensorData readSensors() {

    SensorData data;

    data.temperature = 25.0;
    data.humidity = 50.0;
    data.pressure = 1013.25;

    data.ax = 0;
    data.ay = 0;
    data.az = 9.8;

    return data;
}