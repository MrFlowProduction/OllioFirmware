#ifndef TERMINAL_H /* include guards */
#define TERMINAL_H

#include <Arduino.h>            // Base Arduino library
#include <settings.h>           // Settings
#include <diagnostic.h>
#include <enum.h>
#include <globals.h>

void INIT_TERMINAL();

void printSysData(char*);

void printtestpassed();

void printtestfailed();

void printready();

void printdone();

void printfail();

void printok();

void printerror();

void printinit(String, bool = false);

void printreason(String, bool = false);

void terminal_handler();

#endif /* TERMINAL_H */