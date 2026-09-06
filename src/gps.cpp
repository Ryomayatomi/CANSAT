#include "gps.h"

HardwareSerial GPSSerial(2);

TinyGPSPlus gps;

bool initGPS()
{
    GPSSerial.begin(9600, SERIAL_8N1, 16, 17);
    return true;
}

void updateGPS()
{
    while (GPSSerial.available())
    {
        gps.encode(GPSSerial.read());
    }
}