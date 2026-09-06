#ifndef DISPLAY_H
#define DISPLAY_H

bool initDisplay();

void updateDisplay(
    float temp,
    float hum,
    float pressure,
    float ax,
    float ay,
    float az
);

#endif