#include <Arduino.h>
#include "gps.h"

void setup()
{
    Serial.begin(115200);

    initGPS();

    Serial.println("GPS Start");
}

void loop()
{
    updateGPS();

    if (gps.location.isUpdated())
    {
        Serial.println("------------");

        Serial.print("Latitude : ");
        Serial.println(gps.location.lat(), 6);

        Serial.print("Longitude: ");
        Serial.println(gps.location.lng(), 6);

        Serial.print("Altitude : ");
        Serial.print(gps.altitude.meters());
        Serial.println(" m");

        Serial.print("Satellites: ");
        Serial.println(gps.satellites.value());

        Serial.print("HDOP: ");
        Serial.println(gps.hdop.value());

        Serial.print("Speed: ");
        Serial.print(gps.speed.kmph());
        Serial.println(" km/h");

        Serial.print("Time: ");
        Serial.print(gps.time.hour());
        Serial.print(":");
        Serial.print(gps.time.minute());
        Serial.print(":");
        Serial.println(gps.time.second());

        Serial.println("------------");
    }
}