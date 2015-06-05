#include <stddef.h>
#include <avr/io.h>
#include "io.h"
#include "scheduler.h"

/* Initializes scheduler tasks */
unsigned char tasks_init() {
  // Priority assigned to lower position tasks in array
  unsigned char i = 0;
  //initialize the tasks
  tasks[i].TickFct      = &TickFct_Example;
  tasks[i].period       = 200;
  tasks[i].elapsedTime  = tasks[i].period;
  tasks[i].state        = -1;
  ++i;
  
  tasks[i].TickFct      = &TickFct_GetInput;
  tasks[i].period       = 16;
  tasks[i].elapsedTime  = tasks[i].period;
  tasks[i].state        = -1;
  ++i;
  
  tasks[i].TickFct      = &TickFct_movePlayer1;
  tasks[i].period       = 16;
  tasks[i].elapsedTime  = tasks[i].period;
  tasks[i].state        = -1;
  ++i;
  
  tasks[i].TickFct      = &TickFct_movePlayer2;
  tasks[i].period       = 16;
  tasks[i].elapsedTime  = tasks[i].period;
  tasks[i].state        = -1;
  ++i;
  
  tasks[i].TickFct      = &TickFct_updateMatrix;
  tasks[i].period       = 16;
  tasks[i].elapsedTime  = tasks[i].period;
  tasks[i].state        = -1;
  ++i;
  
  tasks[i].TickFct      = &TickFct_printMatrix;
  tasks[i].period       = 2;
  tasks[i].elapsedTime  = tasks[i].period;
  tasks[i].state        = -1;
  ++i;
  
  return i;
}

//literally just here for reference
enum SM1_States { SM1_init, SM1_wait } SM1_State;
int TickFct_Example(int state) {
  /*VARIABLES MUST BE DECLARED STATIC*/
  /*e.g., static int x = 0;*/

  switch(state) { // Transitions
    case -1:
    state = SM1_init;
    break;
    case SM1_init:
      if (1) {
        state = SM1_wait;
      }
      break;
    case SM1_wait:
      if (1) {
        state = SM1_wait;
      }
      break;
    default:
    state = -1;
  } // Transitions

  switch(state) { // State actions
    case SM1_init:
      LCD_ClearScreen();
      const unsigned char bdots[13] = "Battle Dots!";
      LCD_DisplayString(0x01, bdots);
      break;
    default: // ADD default behavior below
      //do nothing
      break;
  } // State actions

  SM1_State = state;
  return state;
}

//gets input from SNES controllers
enum SM4_States { SM4_init } SM4_State;
int TickFct_GetInput(int state) {
  /*VARIABLES MUST BE DECLARED STATIC*/
  /*e.g., static int x = 0;*/
  
  switch(state) { //Transitions
    case -1:
    state = SM4_init;
    break;
    
    case SM4_init:
    if (1) {
      state = SM4_init;
    }
    break;
    
    default:
    state = -1;
    break;
  } // Transitions

  switch(state) { // State actions
    case SM4_init:
    get_inputs();
    break;
    
    default:
    break;
  } // State actions

  SM4_State = state;
  return state;
}

//lights up the matrix
enum SM2_States { SM2_init} SM2_State;
int TickFct_printMatrix(int state) {
  /*VARIABLES MUST BE DECLARED STATIC*/
  /*e.g., static int x = 0;*/
  static unsigned char i;
  
  switch(state) { // Transitions
    case -1:
      state = SM2_init;
      break;
    
    case SM2_init:
      if (1) {
        state = SM2_init;
      }        
      break;
    
    default:
      state = -1;
  } // Transitions

  switch(state) { // State actions
    case SM2_init:
      PORTB = 0x00; //turn off output
      //if (i % 2) transmit_data(red1, green1);
      //else transmit_data(red2, green2);
      transmit_data(red[i], green[i]);
      PORTB = 0x01 << i;
      i++;
      if (i == 8) i = 0;
      break;
      
    default:
      break;
  } // State actions

  SM2_State = state;
  return state;
}

//updates the matrix
enum SM3_States { SM3_init} SM3_State;
int TickFct_updateMatrix(int state) {
  /*VARIABLES MUST BE DECLARED STATIC*/
  /*e.g., static int x = 0;*/
  
  switch(state) { //Transitions
    case -1:
    state = SM3_init;
    break;
    
    case SM3_init:
    if (1) {
      state = SM3_init;
    }
    break;
    
    default:
    state = -1;
  } // Transitions

  switch(state) { // State actions
    case SM3_init:
    updateMatrix();
    break;
    
    default:
    break;
  } // State actions

  SM3_State = state;
  return state;
}

enum SM5_States { SM5_init, SM5_letGo} SM5_State;
int TickFct_movePlayer1(int state) {
  /*VARIABLES MUST BE DECLARED STATIC*/
  /*e.g., static int x = 0;*/
  
  static unsigned short prev;
  
  switch(state) { //Transitions
    case -1:
      state = SM5_init;
      break;
    
    case SM5_init:
      if (p1_input & SNES_DPAD) {
        state = SM5_letGo;
        move_player1();
        prev = p1_input & SNES_DPAD;
      }        
      else state = SM5_init;
      break;
    
    case SM5_letGo:
      if (!(p1_input & SNES_DPAD)) state = SM5_init;
      else state = SM5_letGo;
      break;
    
    default:
      state = -1;
      break;
  } // Transitions

  switch(state) { // State actions
    case SM5_init:
      break;
    
    case SM5_letGo:
      if (prev != (p1_input & SNES_DPAD)) {
        move_player1();
        prev = p1_input & SNES_DPAD;
      }
      break;
    
    default:
      break;
  } // State actions

  SM5_State = state;
  return state;
}

enum SM6_States { SM6_init, SM6_letGo} SM6_State;
int TickFct_movePlayer2(int state) {
  /*VARIABLES MUST BE DECLARED STATIC*/
  /*e.g., static int x = 0;*/
  
  static unsigned short prev;
  
  switch(state) { //Transitions
    case -1:
      state = SM6_init;
      break;
    
    case SM6_init:
      if (p2_input & SNES_DPAD) {
         state = SM6_letGo;
         move_player2();
         prev = p2_input & SNES_DPAD;
      }
      else state = SM6_init;
      break;
    
    case SM6_letGo:
      if (p2_input & SNES_DPAD)
        state = SM6_letGo;
      else {
        state = SM6_init;
      }
      break; 
    
    default:
      state = -1;
      break;
  } // Transitions

  switch(state) { // State actions
    case SM6_init:
      break;
    
    case SM6_letGo:
    if (prev != (p2_input & SNES_DPAD)) {
      move_player2();
      prev = p2_input & SNES_DPAD;
    }
    break;
    
    default:
    break;
  } // State actions

  SM6_State = state;
  return state;
}