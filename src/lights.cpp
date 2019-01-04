#include "config.h"
#include "lights.h"
#include "Arduino.h"

static rgbw_t colors;

void lightsUpdate() {
    analogWrite(PIN_RED, colors.red);
    analogWrite(PIN_GREEN, colors.green);
    analogWrite(PIN_BLUE, colors.blue);
    analogWrite(PIN_WHITE, colors.white);
}

rgbw_t getRGBW() {
    return colors;
}

void setRGBW(uint8_t red, uint8_t green, uint8_t blue, uint8_t white) {
    colors.red = red;
    colors.green = green;
    colors.blue = blue;
    colors.white = white;

    lightsUpdate();
}

void lightsInit() {
    colors.red = 0;
    colors.green = 0;
    colors.blue = 0;
    colors.white = 0;

    lightsUpdate();
}
