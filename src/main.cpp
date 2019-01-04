#include "config.h"
#include "webserver.h"
#include "wifi.h"
#include "lights.h"

void setup() {
    // Setup serial
    Serial.begin(115200);

    // Set analog write resolution to just 8 bits
    analogWriteRange(255);
    
    // Set up IO pins
    pinMode(PIN_RED, OUTPUT);
    pinMode(PIN_GREEN, OUTPUT);
    pinMode(PIN_BLUE, OUTPUT);
    pinMode(PIN_WHITE, OUTPUT);
    pinMode(PIN_BUTTON, INPUT_PULLUP);

    lightsInit();
    
    // Connect to wifi
    wifiInit();

    // Set up webserver
    webserverInit();
}


void loop() {
    webserverLoop();
    lightsUpdate();
}
