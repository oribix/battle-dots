#ifndef PLAYER_H
#define PLAYER_H


enum condition {normal, stunned, rooted};

struct player
{
  unsigned char hp;       /* health bar */
  enum condition cond;    /* player condition */
};

#endif
