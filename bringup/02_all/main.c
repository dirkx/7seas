/* The "Hello world!" of microcontrollers. Blink LED on/off */
#include <stdint.h>
#include "stm8.h"
#include "gn1640.h"

// Test LED "2" -- R124 needs to be in place or jumpered
//
#define LED_PORT    PC
#define LED_PIN     PIN4

void delay(unsigned long count) {
    while (count--)
    nop();
}

int main(void)
{
    CLK_CKDIVR = 0;

    /* Diagnostics LED */
    PORT(LED_PORT, DDR)  |= LED_PIN; // i.e. PB_DDR |= (1 << 5);
    PORT(LED_PORT, CR1)  |= LED_PIN; // i.e. PB_CR1 |= (1 << 5);
    PORT(LED_PORT, ODR) &= ~LED_PIN; // PB_ODR &= ~(1 << 5);

    gn1640_init();

    int j = 0, k = 0;
    uint8_t b[16] = { 
		3 /* point of ayre/calf of mai */,0,0,39 /* snowfel and hils plus college */,  144 /* ramsey bridge and port erin */,1 /* port erin */,0,0,
		0,0,0,0,  0,0,0,0,
	};
    while(1) {
	b[ (j>>3) &7] |= 1 << (j & 7);

   	gn1640_sendBytes(b,sizeof(b),0);

        PORT(LED_PORT, ODR) |= LED_PIN; // PB_ODR |= (1 << 5);
        delay(50000L);
        PORT(LED_PORT, ODR) &= ~LED_PIN; // PB_ODR &= ~(1 << 5);

        delay(50000L);
	j = ( j + 1 ) % 48;
	k = (k + 1) % 300;
	if (k == 0)
		for(int i =0; i < sizeof(b); i++) b[i] = 0;
    }
}

