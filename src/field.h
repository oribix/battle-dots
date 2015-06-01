#ifndef FIELD_H
#define FIELD_H

/*
enum panel_status {normal};
enum panel_owner {player1, player2};

struct panel
{
  enum panel_owner owner;
  //panel_status status;
};
*/

void init_field();

//bit 0: 0 = player1 is owner; 1 = player2 is owner
unsigned char field[6][3];

#endif
