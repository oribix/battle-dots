#include "player.h"

/* initializes player attributes. pNum = player number */
void init_player(struct player * player, unsigned char pNum) {
  player->hp = 80;
  
  if (pNum == 1) {
    player->xpos = 1;
    player->ypos = 1;
  }
  else if (pNum == 2) {
    player->xpos = 4;
    player->ypos = 1;
  }
  else exit(-1); /* something terribly wrong if it gets here */
}

