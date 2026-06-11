#ifndef SENSOR_H
#define SENSOR_H

struct SensorData {
    float temperature;
    float humidity;
    float pressure;

    float ax;
    float ay;
    float az;
};

bool initSensors();
SensorData readSensors();

#endif