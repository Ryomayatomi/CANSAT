#include "sensor.h"

#include <Wire.h>
#include <Adafruit_AHTX0.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>

Adafruit_AHTX0 aht;
Adafruit_MPU6050 mpu;

bool initSensors()
{
    Wire.begin(21, 22);

    Serial.println("Checking AHT20...");
    if (!aht.begin())
    {
        Serial.println("AHT20 FAIL");
        return false;
    }
    Serial.println("AHT20 OK");

    Serial.println("Checking MPU6050...");
    if (!mpu.begin(0x68, &Wire))
    {
        Serial.println("MPU6050 FAIL");
        return false;
    }
    Serial.println("MPU6050 OK");

    return true;
}

SensorData readSensors()
{
    SensorData data;

    // AHT20
    sensors_event_t humidity;
    sensors_event_t temp;

    aht.getEvent(&humidity, &temp);

    data.temperature = temp.temperature;
    data.humidity = humidity.relative_humidity;

    // MPU6050
    sensors_event_t accel;
    sensors_event_t gyro;
    sensors_event_t mpuTemp;

    mpu.getEvent(&accel, &gyro, &mpuTemp);

    data.ax = accel.acceleration.x;
    data.ay = accel.acceleration.y;
    data.az = accel.acceleration.z;

    data.pressure = 0;

    return data;
}