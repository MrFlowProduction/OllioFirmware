#ifndef TASKS_H /* include guards */
#define TASKS_H

#include <Arduino.h>            // Base Arduino library
#include <TaskScheduler.h>      // Task Handler
#include <leds.h>               // LED handler
#include <terminal.h>           // Terminal
#include <globals.h>            // Globals
#include <diagnostic.h>         // Diagnostic

Scheduler runner;                 // Task Scheduler (MAIN OBJECT)

// _________________________________ Tasks _______________________________________
// ===============================================================================
//   TASK NAME                                                   DESCRIPTION
// ===============================================================================
Task tLedHandling(1000, TASK_FOREVER, &ledHandling, &runner);     // LED handling
Task tTerminal(500, TASK_FOREVER, &terminal_handler, &runner);    // Terminal handling
// ===============================================================================


void INIT_TASKS();

void task_handling();


#endif