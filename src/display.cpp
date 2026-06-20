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
    Wire.begin(21,22);

    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
    {
        Serial.println("OLED FAIL");
        return false;
    }

    Serial.println("OLED OK");

    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0,0);
    display.println("OLED OK");
    display.display();

    delay(5000);

    return true;
}

void updateDisplay(float temp, float hum)
{
    display.clearDisplay();

    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);

    display.setCursor(0, 0);
    display.print("T:");
    display.print(temp, 1);
    display.println("C");

    display.setCursor(0, 30);
    display.print("H:");
    display.print(hum, 1);
    display.println("%");

    display.display();
}