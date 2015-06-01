#include "field.h"

void init_field() {
  unsigned char i;
  unsigned char j;
  //init Player 1's side
  for (i = 0; i < 3; i++) { //columns
    for (j = 0; j < 3; j++) { //rows
      field[i][j] = field[i][j] & 0xFE; //b1111 1110
    }
  }
  //init Player 2's side
  for (i = 3; i < 5; i++) { //columns
    for (j = 0; j < 3; j++) { //rows
      field[i][j] = field[i][j] | 0x01; //b1111 1110
    }
  }
  return;
}