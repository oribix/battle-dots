#include <avr/io.h>
#include <avr/sleep.h>

#include "scheduler.h"
#include "timer.h"
#include "field.h"
#include "player.h"
#include "bdots.h"

#include "bit.h"


/* This code was created with the aid of the Riverside-Irvine State
   machine Builder tool */

struct player player1;
//struct player player2;

int main() {
  //initializing the task manager
  tasks_init();
  init_field();
  
  //initializing the game
  init_player(&player1, 1);
  
  //initializing timer
  TimerSet(TASKSGCD);
  TimerOn();
  
  while(1) { /* Sleep(); */ }
  return 0;
}