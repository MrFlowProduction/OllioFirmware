#ifndef ADC_H /* include guards */
#define ADC_H

#include <Arduino.h> /* we need arduino functions to implement this */
#include <Wire.h>
#include <ADS1X15.h>
#include <globals.h>
#include <terminal.h>
#include <pinout.h>

extern ADS1115 ads;

/* INIT adc module */
void INIT_ADC();

/* Read probe voltage */
float readProbeVoltage();

/* ADC reading */
void adc_reading();

#endif