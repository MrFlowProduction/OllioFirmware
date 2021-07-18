#ifndef LCD_H /* include guards */
#define LCD_H

#include <Arduino.h> /* we need arduino functions to implement this */
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

extern LiquidCrystal_I2C lcd;

/* Init scale */
void INIT_LCD();

void lcd_print();

#endif