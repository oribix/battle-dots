#include <avr/io.h>
#include "player.h"
#include "output.h"


/* Transmit data for matrix on PORTD
   THIS FUNCTION IS IN OCTAL FOR CONVENIENCE
   
   RED
   D0 = SER   0 = ON, 1 = OFF
   D1 = OE    0 = enabled, 1 = disabled
   D2 = CLK   SER is latched on rising edge
   
   GREEN
   D3 = SER   0 = ON, 1 = OFF
   D4 = OE    0 = enabled, 1 = disabled
   D5 = CLK   SER is latched on rising edge 

PORTD bit layout:               -76 543 210
DONT MESS WITH LCD BITS         LCD GRN RED
*/
void transmit_data(unsigned short redData,
                   unsigned short greenData) {
  PORTD |= 0022; // disable output (OE High) 
  int i;
  for (i = 0; i < 16 ; ++i) {
    PORTD &= 0322; // Set clock LOW, Clear data bit
    // set SER to next bit of data to be sent.
    PORTD |= (redData & 0x0001 << i)   ? 0000 : 0001;
    PORTD |= (greenData & 0x0001 << i) ? 0000 : 0010;
    // Set CLK high. Rising edge latches SER into Shift Register
    PORTD |= 0044;
  }
  PORTD &= 0322; // Set clock LOW, Clear data bit
  // set CLK High. Copies “Shift” register to “Storage” register
  PORTD |= 0044;
  // clears all lines in preparation of a new transmission
  PORTD &= 0100;
  return;
}