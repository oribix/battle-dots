#include <stdio.h>
#include "field.h"
#include "player.h"
#include "bdots.h"
/* This code was created with the aid of the Riverside-Irvine State
   machine Builder tool */

task tasks[2]; //update whenever tasks are added

//number of tasks
unsigned char tasksNum;

//declare task period GCD
//calculate the GCD by hand and hardcode it later
unsigned long tasksPeriodGCD = 0;

int main() {
  tasks_init();
  tasks_init_GCD();
  //TimerSet(tasksPeriodGCD);
  //TimerOn();
  while(1) { /* Sleep(); */ }

  return 0;
}

/* whenever sleep() is interrupted, the hardware calls this */
void TimerISR() {
  unsigned char i;
  for (i = 0; i < tasksNum; ++i) { // Heart of scheduler code
     if ( tasks[i].elapsedTime >= tasks[i].period ) { // Ready
        tasks[i].state = tasks[i].TickFct(tasks[i].state);
        tasks[i].elapsedTime = 0;
     }
     tasks[i].elapsedTime += tasksPeriodGCD;
  }
}

unsigned char tasks_init() {
  // Priority assigned to lower position tasks in array
  unsigned char i = 0;
  //initialize the tasks 
  tasks[i].TickFct      = &TickFct_Example;
  tasks[i].period       = 400;
  tasks[i].elapsedTime  = tasks[i].period;
  tasks[i].state        = -1;
  ++i;
  
  tasksNum = i;
  return i;
}

void tasks_init_GCD() {
  unsigned long GCD = 0;
  unsigned char i;
  for (i = 0; i < tasksNum ; i++) {
    
  }
  tasksPeriodGCD = GCD; 
  return;
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
   default: // ADD default behaviour below
      break;
  } // State actions

  SM1_State = state;
  return state;
}


