#ifndef LEDMANAGER_H
#define LEDMANAGER_H

#include <LiquidCrystal_I2C.h>
#include "Config/config.h"

class LCDManager {
public:
    static void begin();
    static void printLine(uint8_t line, const String &text);
    static LiquidCrystal_I2C lcd;
};
#endif