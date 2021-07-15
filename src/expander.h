#ifndef EXPANDER_H /* include guards */
#define EXPANDER_H

#include <Arduino.h> /* we need arduino functions to implement this */
#include <Wire.h>
#include <Adafruit_MCP23017.h>
#include <terminal.h>
#include <diagnostic.h>
#include <pinout.h>

extern Adafruit_MCP23017 mcp;

extern bool isMcpConnected;


void INIT_EXTERNAL_PORTS();

#endif