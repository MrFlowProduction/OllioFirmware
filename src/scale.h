#ifndef SCALE_H /* include guards */
#define SCALE_H

#include <Arduino.h> /* we need arduino functions to implement this */
#include <Wire.h>
#include <HX711.h>
#include <terminal.h>
#include <diagnostic.h>
#include <pinout.h>
#include <globals.h>

extern HX711 scale;

/* Init scale */
void INIT_SCALE();

/* Acquire reading */
void acquire_reading();

#endif