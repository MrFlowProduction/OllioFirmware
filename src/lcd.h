#ifndef LCD_H /* include guards */
#define LCD_H

#include <Arduino.h> /* we need arduino functions to implement this */
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

extern LiquidCrystal_I2C lcd;

extern int prevMachineState;

/* Init LCD screen */
void INIT_LCD();

/*  */
void printRow(byte, char, int);

/*  */
void printByteRow(byte, byte, int);

/* Percentage animation */
void percentAnimation(byte);

/* Printing animation */
void printingAnimation(byte);

/* Slide up animation */
void slideUpEffect();

/* Slide down animation */
void slideDownEffect();

/* Display device name and software version */
void setNoneScreen();

/* Display init screen */
void setStartScreen();
 
/* Display analog measurements and its process feedback */
void setShortingScreen();

/* Display if it is necessary to transfer the loaded unfavorable oil to the separation tank */
void setSeparateScreen();

/* Display pouring and weighing good quality oil into barrels and calculated weight */
void setMeasureScreen();

/* Display printing a block certifying the accounted quantity */
void setPrintingScreen();

/* Display process termination and reset */
void setClosingScreen();

/* Display service mode */
void setServiceScreen();

/* Display demo mode */
void setDemoScreen();

/* Display error screen */
void setFaultScreen();

/* Checking current display state and displaying the correct screen */
void lcd_print();

#endif