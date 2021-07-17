// ----------------------------------------------------------------------
// ########################### LIBRARIES ################################
// ----------------------------------------------------------------------
#include <TaskScheduler.h>      // Task Handler
#include <radio.h>
#include <leds.h>
#include <terminal.h>
#include <expander.h>
#include <scale.h>
#include <adc.h>
Scheduler runner; // Task Scheduler (MAIN OBJECT)

// _________________________________ Tasks _______________________________________
// ===============================================================================
//   TASK NAME                                                   DESCRIPTION
// ===============================================================================
Task tLedHandling(1000, TASK_FOREVER, &ledHandling, &runner);  // LED handling
Task tTerminal(500, TASK_FOREVER, &terminal_handler, &runner); // Terminal handling
Task tScale(500, TASK_FOREVER, &acquire_reading, &runner);
Task tAds(100, TASK_FOREVER, &adc_reading, &runner); 
// ===============================================================================

/* Task init */
void INIT_TASKS()
{
  // LED
  runner.addTask(tLedHandling);
  tLedHandling.enable();

  // Terminal
  runner.addTask(tTerminal);

  // Scale
  runner.addTask(tScale);
  tScale.enable();

  // ADC
  runner.addTask(tAds);

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
  INIT_SCALE();
  INIT_ADC();
  //INIT_WIFI();
  INIT_TASKS();
}

void loop() {
  runner.execute();
}