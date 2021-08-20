#ifndef EXPANDER_H /* include guards */
#define EXPANDER_H

#include <Arduino.h> /* we need arduino functions to implement this */
#include <Wire.h>
#include <Adafruit_MCP23017.h>
#include <terminal.h>
#include <diagnostic.h>
#include <pinout.h>
#include <globals.h>

extern Adafruit_MCP23017 mcp;

extern bool isMcpConnected;
extern volatile bool isButtonPressed;

/* Init expander */
void INIT_EXTERNAL_PORTS();

/* Handling Interrupts */
void handlingExpInterrupt();

/* Init Default States */
void InitExpanderStates();

/* Set DC Motor driver pins */
void setDcMotorPins(bool, bool, bool);

/* Set User button backlight */
void setButtonLight(bool);

/* Reads a digital input */
int getSensValue(int pin);

#endif