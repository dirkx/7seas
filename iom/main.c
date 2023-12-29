#include <stdint.h>
#include "stm8.h"
#include "lights.h"
#include "gn1640.h"


// Test LED "2" -- R124 needs to be in place or jumpered
//
#define LED_PORT    PC
#define LED_PIN     PIN4

#define DCOR(x) ( (unsigned long)x * 1000UL / 1328UL)
void delay(unsigned long count) {
    while (count--)
        nop();
}

int main(void)
{
    /* Set clock to full speed (16 Mhz) */
    CLK_CKDIVR = 0;

    /* Diagnostics LED */
    PORT(LED_PORT, DDR)  |= LED_PIN; // i.e. PB_DDR |= (1 << 5);
    PORT(LED_PORT, CR1)  |= LED_PIN; // i.e. PB_CR1 |= (1 << 5);
    PORT(LED_PORT, ODR) &= ~LED_PIN; // drive low (off).

    gn1640_init(BRIGHTNESS_10);

    uint8_t buffer[16] = { 0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0 };
    unsigned char at[lights], tocksleft[lights];

    // If we start all patterns at the same time - they tend to rendevous
    // quite often. so we avoid this by randmizing the start positions a bit.
    //
    unsigned char rnd = 23;
    for(int i = 0; i < lights; i++) {
	at[i] = tocksleft[i] = 0;
	if (idx[i]) {
	  // find the lenth of this sequence
          int len = 0;
          for(int j = 0; patterns[idx[i] + j]; j++)
		len += patterns[idx[i] + j];
	  if (len) {
		// pick a somewhat 'random' place in this sequence; and 
		// have the pattern begin at that point.
		//	
		rnd = (17 + 11*i + (rnd * rnd)) | 2;
		len = rnd % len;
		int onoff = 0;
        	for(int j = 0; patterns[idx[i] + j]; at[i]++, j++) {
			onoff ^= 1;
			if (len >= patterns[idx[i] + j]) {
				len -=  patterns[idx[i] + j];
				continue;
			};
			tocksleft[i] = len;
			if (onoff)
				buffer[ i>>3 ] |= 1<<(i&7);
		};
        };
       };
    };

    uint16_t loper = 0;
    while(1) {
	loper++;
	for(int i = 0; i < lights; i++) {
		if (tocksleft[i]) {
			// light not yet up for a change;
			tocksleft[i]--;
			// Introduce some slight pertubations.
			//
			if (tocksleft[i] == 2 && i == loper)
				tocksleft[i]--;
			continue; 
		};

		if (patterns[idx[i]] == 0) {
			// Skip - not a light, not on.
			continue; 
		};
		
		if (patterns[idx[i] + at[i]] == 0) {
			// at the end of a sequence;
			at[i] = 0; 
		};
		tocksleft[i] = patterns[idx[i] + at[i]];
		if (at[i]) {
			// toggle during the sequence
			buffer[ (i>>3) ] ^= (1 << (i & 7));
		} else {
			// force on at the start of a sequence; only
			// realy needed for the "F" lights; as the 
			// others end their sequence with an 'off'.
			buffer[  (i>>3) ] |= (1 << (i & 7));
		};
		at[i]++;
	};
        gn1640_sendBytes(buffer,sizeof(buffer),0);
        // loop including send takes about 5 milliseconds.
        delay(DCOR((250-5) * 1000));
        PORT(LED_PORT, ODR) |= LED_PIN; 
        delay(DCOR(50));
        PORT(LED_PORT, ODR) &= ~LED_PIN; 
    }
}
