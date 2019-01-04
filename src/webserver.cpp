#include <ESP8266WebServer.h>
#include <ArduinoJson.h>
#include "webserver.h"

#include "web/index.html.h"
#include "web/axios.min.js.h"

ESP8266WebServer server(HTTPPORT);

void handleRoot() {
    server.send(200, "text/html", INDEX_HTML);
}

void handleAxios() {
    server.send(200, "application/javascript", AXIOS_MIN_JS);
}

void handleGETrgbw() {
    char buffer[50];
    rgbw_t c = getRGBW();
    sprintf(buffer, "{\n \"r\": %d,\n \"g\": %d,\n \"b\": %d\n \"w\": %d\n}", c.red, c.green, c.blue, c.white);
    server.send(200, "application/json", buffer);
}

void handlePUTrgbw() {
    StaticJsonBuffer<500> jsonBuffer;
    JsonObject& jsonBody = jsonBuffer.parseObject(server.arg("plain"));

    Serial.print("HTTP Method: ");
    Serial.println(server.method());
    
    if (!jsonBody.success()) {
        Serial.println("JSON parse error");
        server.send(400, "JSON parse error");
        return;
    }

    uint8_t red = jsonBody["r"];
    uint8_t green = jsonBody["g"];
    uint8_t blue = jsonBody["b"];
    uint8_t white = jsonBody["w"];

    char response[100];
    sprintf(response, "Red   : %03d\nGreen : %03d\nBlue  : %03d\nWhite : %03d\n", red, green, blue, white);
    Serial.println(response);

    setRGBW(red, green, blue, white);
    
    server.send(201, "text/plain", response);
}

void handle404() {
    server.send(404, "text/plain", "Not found");
}

void webserverInit() {
    server.on("/", HTTP_GET, handleRoot);
    server.on("/axios.min.js", HTTP_GET, handleAxios);
    
    server.on("/rgbw", HTTP_GET, handleGETrgbw);
    server.on("/rgbw", HTTP_PUT, handlePUTrgbw);

    server.onNotFound(handle404);
    server.begin();
    Serial.printf("Started webserver on port %d", HTTPPORT);
}

void webserverLoop() {
    server.handleClient();
}
