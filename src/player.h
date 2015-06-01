#ifndef PLAYER_H
#define PLAYER_H

//enum condition {normal, stunned, rooted};
struct player
{
  unsigned char hp;         /* health bar */
  unsigned char xpos;       /* x position on the field */
  unsigned char ypos;       /* y position on the field */
  //enum condition cond;      /* player condition */
};

void init_player(struct player * player, unsigned char pNum);

#endif
