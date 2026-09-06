#ifndef GPS_H
#define GPS_H

#include <TinyGPS++.h>

extern TinyGPSPlus gps;

bool initGPS();
void updateGPS();

#endif