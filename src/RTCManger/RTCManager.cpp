#include "RTCManager.h"


RTC_DS3231 rtc;

void RTCManager::begin() {
    if (!rtc.begin()) {
        Serial.println("RTC not found");
        LCDManager::printLine(1, "RTC Error!");
        while (true);
    }

    if (rtc.lostPower()) {
        Serial.println("RTC lost power, setting to compile time...");
        rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    }
}

void RTCManager::syncWithNTP() {
    configTime(GMT_OFFSET_SEC, DAYLIGHT_OFFSET_SEC, NTP_SERVER);
    struct tm timeinfo;

    if (getLocalTime(&timeinfo)) {
        rtc.adjust(DateTime(timeinfo.tm_year + 1900, timeinfo.tm_mon + 1, timeinfo.tm_mday,
                            timeinfo.tm_hour, timeinfo.tm_min, timeinfo.tm_sec));
        Serial.println("RTC synced from NTP.");
        LCDManager::printLine(0, "Time synced NTP");
    } else {
        Serial.println("NTP sync failed");
        LCDManager::printLine(0, "NTP failed");
    }

    delay(2000);
    LCDManager::lcd.clear();
}

void RTCManager::displayTime() {
    DateTime now = rtc.now();

    char dateBuf[17];
    snprintf(dateBuf, sizeof(dateBuf), "%02d-%02d-%04d", now.day(), now.month(), now.year());
    LCDManager::printLine(0, dateBuf);

    int hour12 = now.hour() % 12;
    if (hour12 == 0) hour12 = 12;
    String ampm = (now.hour() >= 12) ? "PM" : "AM";

    char timeBuf[17];
    snprintf(timeBuf, sizeof(timeBuf), "%02d:%02d:%02d %s", hour12, now.minute(), now.second(), ampm.c_str());
    LCDManager::printLine(1, timeBuf);
}
