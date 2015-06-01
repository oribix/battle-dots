#include "scheduler.h"

/* Initializes scheduler tasks */
unsigned char tasks_init() {
  // Priority assigned to lower position tasks in array
  unsigned char i = 0;
  //initialize the tasks
  tasks[i].TickFct      = &TickFct_Example;
  tasks[i].period       = 400;
  tasks[i].elapsedTime  = tasks[i].period;
  tasks[i].state        = -1;
  ++i;
  
  return i;
}

//literally just here for reference
enum SM1_States { SM1_init } SM1_State;
int TickFct_Example(int state) {
  /*VARIABLES MUST BE DECLARED STATIC*/
  /*e.g., static int x = 0;*/

  switch(state) { // Transitions
    case -1:
    state = SM1_init;
    break;
    case SM1_init:
    if (1) {
      state = SM1_init;
    }
    break;
    default:
    state = -1;
  } // Transitions

  switch(state) { // State actions
    case SM1_init:
    break;
    default: // ADD default behavior below
    break;
  } // State actions

  SM1_State = state;
  return state;
}

int TickFct_GetInput(int state) {
  
  return 0;
}