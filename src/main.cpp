// ----------------------------------------------------------------------
// ########################### LIBRARIES ################################
// ----------------------------------------------------------------------
#include <TaskScheduler.h>      // Task Handler
#include <radio.h>
#include <leds.h>
#include <terminal.h>
#include <expander.h>

Scheduler runner; // Task Scheduler (MAIN OBJECT)

// _________________________________ Tasks _______________________________________
// ===============================================================================
//   TASK NAME                                                   DESCRIPTION
// ===============================================================================
Task tLedHandling(1000, TASK_FOREVER, &ledHandling, &runner);  // LED handling
Task tTerminal(500, TASK_FOREVER, &terminal_handler, &runner); // Terminal handling
// ===============================================================================

/* Task init */
void INIT_TASKS()
{

  runner.addTask(tLedHandling);
  tLedHandling.enable();

  runner.addTask(tTerminal);

  if (terminal_enabled)
  {
    tTerminal.enable();
  }

  runner.startNow();

}


void setup() {
  INIT_TERMINAL();
  INIT_LEDS();
  INIT_EXTERNAL_PORTS();

  INIT_WIFI();

  INIT_TASKS();

}

void loop() {
  runner.execute();
}