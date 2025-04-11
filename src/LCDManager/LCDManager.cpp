#include "LCDManager.h"


LiquidCrystal_I2C LCDManager::lcd(LCD_ADDRESS, LCD_COLUMNS, LCD_ROWS);

void LCDManager::begin() {
    lcd.init();
    lcd.backlight();
    lcd.clear();
}

void LCDManager::printLine(uint8_t line, const String &text) {
    lcd.setCursor(0, line);
    lcd.print(text);
}
