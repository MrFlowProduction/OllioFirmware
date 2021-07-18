#include <lcd.h>
#include <globals.h>
#include <enum.h>

LiquidCrystal_I2C lcd(0x27,20,4);

int prevMachineState = 1000;

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

// --------------------  Set Screen Methods  -------------------- START

void setNoneScreen() {
  lcd.setCursor(3,1);
  lcd.print("OllioFirmware");
  delay(200);
  lcd.setCursor(7,2);
  lcd.print("v0.1");
}

void setStartScreen() {
  lcd.setCursor(3,1);
  lcd.print("OllioFirmware");
  delay(200);
  lcd.setCursor(7,2);
  lcd.print("v0.1");
}

void setShortingScreen() {

}

void setSeparateScreen() {

}

void setMeasureScreen() {

}

void setPrintingScreen() {

}

void setClosingScreen() {

}

void setServiceScreen() {

}

void setDemoScreen() {

}

void setFaultScreen() {
  lcd.setCursor(1,1);
  lcd.print("OllioFirmware v0.1");
  delay(200);
  lcd.setCursor(5,2);
  lcd.print("Error: 32");
}

// --------------------  Set Screen Methods  -------------------- END

void lcd_print() {
  if (machineState != prevMachineState) {

    prevMachineState = machineState;

    lcd.clear();

    switch (machineState)
    {
      case NONE: setNoneScreen();
        break;
      
      //case START: setStartScreen();
      //  break;

      //case SHORTING: setShortingScreen();
      //  break;

      //case SEPARATE: setSeparateScreen();
      //  break;

      case MEASURE: setMeasureScreen();
        break;

      case PRINTING: setPrintingScreen();
        break;

      case CLOSING: setClosingScreen();
        break;

      //case SERVICE: setServiceScreen();
      //  break;

      case DEMO: setDemoScreen();
        break;

      case FAULT: setFaultScreen();
        break;

      default: setNoneScreen();
        break;
    }
  }
}