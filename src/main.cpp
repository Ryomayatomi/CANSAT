#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_AHTX0.h>

Adafruit_AHTX0 aht;

void setup() {
    Serial.begin(115200);

    if (!aht.begin()) {
        Serial.println("AHT20 Error");
        while (1);
    }

    Serial.println("AHT20 OK");
}

void loop() {
    sensors_event_t humidity, temp;

    aht.getEvent(&humidity, &temp);

    Serial.print("Temp: ");
    Serial.print(temp.temperature);
    Serial.println(" C");

    Serial.print("Humidity: ");
    Serial.print(humidity.relative_humidity);
    Serial.println(" %");

    Serial.println();

    delay(2000);
}