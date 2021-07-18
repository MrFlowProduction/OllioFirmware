#include <lcd.h>
#include <globals.h>
#include <enum.h>

#if defined(ARDUINO) && ARDUINO >= 100
#define printByte(args)  write(args);
#else
#define printByte(args)  print(args,BYTE);
#endif

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

// --------------------  Screen Animation Methods  -------------------- START

void printRow(byte row, char ch, int interval = 5) {

  for(int c = 0; c < 20; c++){

      lcd.setCursor(c, row);
      lcd.print(ch);
      delay(interval);
  }
  
}

void printByteRow(byte row, byte ch, int interval = 5) {

  for(int c = 0; c < 20; c++){

      lcd.setCursor(c, row);
      lcd.printByte(ch);
      delay(interval);
  }
  
}

void printingAnimation(byte row) {

  printByteRow(row, 3, 5);

  double percent = 0;

  for(int i = 0; i < 21; i++){
     lcd.setCursor(i, row);
     
     if(i < 20) { lcd.printByte(1); }
     
     if(i > 0){
        lcd.setCursor(i - 1, row);
        lcd.printByte(4);

        percent += 2.5;
        lcd.setCursor(7, row + 1);
        lcd.print(percent, 1);
        lcd.print("%");
     }

     
     delay(150);
  }

  delay(50);

  for(int i = 19; i >= -1; i--){
     lcd.setCursor(i, row);
     
     if(i >= 0) { lcd.printByte(1); }
     
     if(i < 19){
       lcd.setCursor(i + 1, row);
        lcd.printByte(5);

        percent += 2.5;
        lcd.setCursor(7, row + 1);
        lcd.print(percent, 1);
        lcd.print("%");
     }

     delay(150);
  }
  
}

void slideUpEffect() {
  
  for(int c = 0; c < 20; c++){

    for(byte r = 0; r < 4; r++){
    
      lcd.setCursor(c, r);
      lcd.printByte(1);
      delay(5);
    }
  }
  
}

void slideDownEffect() {

  for(int c = 0; c < 20; c++){

    for(byte r = 0; r < 4; r++){
    
      lcd.setCursor(c, r);
      lcd.print(" ");
      delay(5);
    }
  }
  
}

// --------------------  Screen Animation Methods  -------------------- END


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
  while (machineState == DEMO) {
    slideUpEffect();
    delay(100);
    slideDownEffect();
    

    printRow(0, '/');

    printRow(3, '/');

    delay(200);
    lcd.setCursor(3,1);
    lcd.print("Ollio Automata");
    delay(200);
    lcd.setCursor(3,2);
    lcd.print("Revolution 1."); 

    delay(3000);

    slideDownEffect();

    lcd.setCursor(2,0);
    lcd.print("Clean");
    delay(1000);
    lcd.setCursor(4,1);
    lcd.print("Reliable");
    delay(1000);
    lcd.setCursor(6,2);
    lcd.print("Powerful");
    delay(1000);
    lcd.setCursor(8,3);
    lcd.print("Easy to use");

    delay(2000);

    slideDownEffect();

    printRow(0, '/');
    printRow(3, '/');

    lcd.setCursor(5,1);
    lcd.print("Filling...");

    

    for(double i = 0; i < 11; i = i + 0.1){
      lcd.setCursor(5,2);
      lcd.print(i, 1);
      lcd.print("L");
      delay(50);
    }

    lcd.print(" DONE");

    delay(2000);

    lcd.setCursor(5,1);
    lcd.print("Printing...");
    
    printingAnimation(2);

    delay(2000);
  }
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
      case NONE:
        setNoneScreen();
        break;
      
      //case START:
      //    setStartScreen();
      //  break;

      //case SHORTING:
      //  setShortingScreen();
      //  break;

      //case SEPARATE:
      //  setSeparateScreen();
      //  break;

      case MEASURE: 
        setMeasureScreen();
        break;

      case PRINTING:
        setPrintingScreen();
        break;

      case CLOSING:
        setClosingScreen();
        break;

      //case SERVICE:
      //  setServiceScreen();
      //  break;

      case DEMO:
        setDemoScreen();
        break;

      case FAULT:
        setFaultScreen();
        break;

      default:
        setNoneScreen();
        break;
    }
  }
}