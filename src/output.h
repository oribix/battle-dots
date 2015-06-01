#ifndef OUTPUT_H
#define OUTPUT_H

void printMatrix (char ** field, struct player * player1,
                  struct player * player2);
void printPlayer (struct player * p);
void printField (char ** field);
void printTimerGuage (unsigned short guage);

void transmit_data(unsigned short redData, unsigned short greenData);

#endif

