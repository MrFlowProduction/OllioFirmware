#ifndef DIAGNOSTIC_H /* include guards */
#define DIAGNOSTIC_H

#include <Arduino.h>    /* we need arduino functions to implement this */
#include <terminal.h>   /* Terminal */
#include <Wire.h> 

void i2c_scanner();

byte i2c_address_check(byte);

#endif