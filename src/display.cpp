#include "display.h"

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(
    SCREEN_WIDTH,
    SCREEN_HEIGHT,
    &Wire,
    -1
);

bool initDisplay()
{
    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
    {
        return false;
    }

    display.clearDisplay();
    display.display();

    return true;
}

void updateDisplay(
    float temp,
    float hum,
    float ax,
    float ay,
    float az
)
{
    display.clearDisplay();

    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);

    display.setCursor(0, 0);
    display.print("T: ");
    display.print(temp, 1);
    display.println(" C");

    display.setCursor(0, 10);
    display.print("H: ");
    display.print(hum, 1);
    display.println(" %");

    display.setCursor(0, 30);
    display.print("AX:");
    display.print(ax, 2);

    display.setCursor(0, 40);
    display.print("AY:");
    display.print(ay, 2);

    display.setCursor(0, 50);
    display.print("AZ:");
    display.print(az, 2);

    display.display();
}