#include <Arduino.h>
#include <Wire.h>
#include "wifi_Manager/WiFiManager.h"
#include "LCDManager/LCDManager.h"
#include "RTCManger/RTCManager.h"

void setup() {
    Serial.begin(115200);
    Wire.begin();

    LCDManager::begin();
    LCDManager::printLine(0, "Starting...");

    RTCManager::begin();
    WiFiManager::connect();
    RTCManager::syncWithNTP();
}

void loop() {
    RTCManager::displayTime();
    delay(1000);
}
