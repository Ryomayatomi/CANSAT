#include <Arduino.h>
#include "sensor.h"

void setup() {
    Serial.begin(115200);

    if(!initSensors()){
        Serial.println("Sensor Error");
    }
}

void loop() {

    SensorData data = readSensors();

    Serial.print("Temp:");
    Serial.println(data.temperature);

    delay(1000);
}