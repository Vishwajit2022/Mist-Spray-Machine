#ifndef RTCMANAGER_H
#define RTCMANAGER_H
#include "Config/config.h"
#include "LCDManager/LCDManager.h"
#include <RTClib.h>
#include <time.h>


class RTCManager {
public:
    static void begin();
    static void syncWithNTP();
    static void displayTime();
};
#endif
