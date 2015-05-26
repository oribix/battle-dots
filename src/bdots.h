#ifndef BDOTS_H
#define BDOTS_H

typedef struct task {
   int state;
   unsigned long period;
   unsigned long elapsedTime;
   int (*TickFct)(int);
} task;

//used to initialize tasks
unsigned char tasks_init();
void tasks_init_GCD(); /*should do this by hand*/

//tick function prototypes
int TickFct_Example(int state);

void TimerISR();

#endif
