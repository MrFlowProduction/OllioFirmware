#include <lcd.h>

LiquidCrystal_I2C lcd(0x27,20,4);

uint8_t bell[8]  = {0x4,0xe,0xe,0xe,0x1f,0x0,0x4};
uint8_t full[8] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
};

uint8_t arrow[8] = {
  B11111,
  B10111,
  B10011,
  B10001,
  B10001,
  B10011,
  B10111,
  B11111,
};


uint8_t rd[8] = {
  B00000,
  B00000,
  B00000,
  B11111,
  B11111,
  B00000,
  B00000,
  B00000,
};

uint8_t ry[8] = {
  B11000,
  B11000,
  B11000,
  B11111,
  B11111,
  B00011,
  B00011,
  B00011,
};

uint8_t rh[8] = {
  B11011,
  B11011,
  B11011,
  B11111,
  B11111,
  B11011,
  B11011,
  B11011,
};

void INIT_LCD() {
    lcd.init();                      // initialize the lcd 
    lcd.backlight();

    lcd.createChar(0, bell);
    lcd.createChar(1, full);
    lcd.createChar(2, arrow);
    lcd.createChar(3, rd);
    lcd.createChar(4, ry);
    lcd.createChar(5, rh);
}

void lcd_print() {
    lcd.clear();
    delay(500);
    lcd.setCursor(3,1);
    lcd.print("Ollio Automata");
    delay(200);
    lcd.setCursor(3,2);
    lcd.print("Revolution 1."); 
}