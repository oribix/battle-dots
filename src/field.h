#ifndef FIELD_H
#define FIELD_H

#include "player.h"

//enum panel_status {normal};
enum panel_owner {player1, player2};

struct panel
{
  enum panel_owner owner;
  //panel_status status;
};

#endif
