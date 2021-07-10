#ifndef RADIO_H /* include guards */
#define RADIO_H

#include <Arduino.h>            // Base Arduino library
#include <settings.h>           // Settings
#include <terminal.h>           // Terminal
#include <globals.h>            // Globals
#include <WiFi.h>               // WiFi

void INIT_WIFI();

void WiFiEvent(WiFiEvent_t);

#endif