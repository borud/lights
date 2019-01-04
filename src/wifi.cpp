#include "config.h"
#include "wifi.h"

static void wifiReconnect() {
    WiFi.begin(WIFI_SSID, WIFI_PASSWD);

    Serial.print("Connecting");
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println();
    
    Serial.print("Connected, IP address: ");
    Serial.println(WiFi.localIP());
}

static void onDisconnect(const WiFiEventStationModeDisconnected& event){
	Serial.println("WiFi disconnected");
    wifiReconnect();
}

void wifiInit() {
    WiFi.disconnect();
    WiFi.persistent(false);

    WiFi.onStationModeDisconnected(onDisconnect);
    WiFi.mode(WIFI_STA); 

    wifiReconnect();
}
