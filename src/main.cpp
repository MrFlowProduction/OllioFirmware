// ----------------------------------------------------------------------
// ########################### LIBRARIES ################################
// ----------------------------------------------------------------------
#include <Arduino.h>            // Base Arduino library
#include <tasks.h>
#include <terminal.h>
#include <leds.h>
#include <radio.h>
#include <globals.h>


void setup() {
  INIT_TERMINAL();
  INIT_LEDS();

  INIT_WIFI();

  INIT_TASKS();
}

void loop() {
  runner.execute();
}