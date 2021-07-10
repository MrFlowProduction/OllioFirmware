#include <tasks.h>

/* Task init */
void INIT_TASKS(){
  
  runner.addTask(tLedHandling);
  tLedHandling.enable();

  runner.addTask(tTerminal);

  if(terminal_enabled){
    tTerminal.enable();
  }

  runner.startNow();
}

void task_handling(){
    
}