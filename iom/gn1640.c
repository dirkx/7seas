#include "stm8.h"
#include "gn1640.h"

// GN1640T chip:
#define TM1640_PORT PB
#define TM1640_CLK  PIN5
#define TM1640_DIN  PIN4

#define TM1640_DATA 0x44 /* data command - 'fixed address' */
#define TM1640_DINC 0x40 /* data command - auto inc */
#define TM1640_ADR  0xC0 /* address command */
#define TM1640_DISP 0x80 /* display control command */

#define CLOCK_HIGH { PORT(TM1640_PORT, ODR) |= TM1640_CLK; }
#define CLOCK_LOW  { PORT(TM1640_PORT, ODR) &= ~TM1640_CLK; }
#define DATA_HIGH { PORT(TM1640_PORT, ODR) |= TM1640_DIN; }
#define DATA_LOW { PORT(TM1640_PORT, ODR) &= ~TM1640_DIN; }
#define DATA(x) { if (x) DATA_HIGH else DATA_LOW; }

#define START { DATA_LOW; TM_DELAY; CLOCK_LOW; TM_DELAY; }
#define STOP  { DATA_LOW; CLOCK_LOW; TM_DELAY; CLOCK_HIGH; DATA_HIGH; TM_DELAY; }

#define TM_DELAY { bitDelay(); }

static void bitDelay() {
    for(unsigned long i = 30; i; i--) nop();
}

void gn1640_sendByte(uint8_t b) {
  for (int i = 0; i < 8; i++) {
	DATA(b & (1<<i));
	CLOCK_HIGH;
	TM_DELAY;
	CLOCK_LOW;
	TM_DELAY;
  };
}

void gn1640_sendCommand(uint8_t cmd) {
  START;
  gn1640_sendByte(cmd);
  STOP;
}

void gn1640_setBrightness(uint8_t val) {
  gn1640_sendCommand(val);
}

void gn1640_sendBytes(uint8_t data[], uint8_t length, uint8_t adr) {
  START;
  gn1640_sendByte(TM1640_DINC | adr);
  for(int i = 0; i < length; i++) 
	gn1640_sendByte(data[i]);
  STOP;
}

void gn1640_init(brightness b) {
    /* Multiplexer */
    PORT(TM1640_PORT, DDR)  |= TM1640_CLK | TM1640_DIN;
    PORT(TM1640_PORT, CR1)  |= TM1640_CLK | TM1640_DIN;
    STOP;
    for(unsigned long i = 3000; i; i--) nop();
    gn1640_setBrightness(b);
    gn1640_sendCommand(TM1640_ADR);
}

