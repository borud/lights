#ifndef LIGHTS_H
#define LIGHTS_H

#include <stdint.h>

struct rgbw_t {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
    uint8_t white;
};

void lightsUpdate();
void lightsInit();

void setRGBW(uint8_t red, uint8_t green, uint8_t blue, uint8_t white);
rgbw_t getRGBW();

#endif
