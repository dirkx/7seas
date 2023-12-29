#include <stdint.h>
#include <stdio.h>
#include <string.h>


#include "iom.c"

#define RL 400

int main(int a, char **b) 
{
    unsigned char at[lights] = { 0 }, tocksleft[lights] = { 0 };
    char out[lights][RL] = { 0 };
    char buffer[17] = { 0 };

if (a == 2) {
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
		rnd = rnd * rnd | 2;
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
};

    for(int j = 0; j < RL; j++)
    {
	for(int i = 0; i < lights; i++) {
		if (tocksleft[i]) {
			// light not yet up for a change;
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
			buffer[ 1 + (i>>3) ] ^= (1 << (i & 7));
		} else {
			// force on at the start of a sequence; only
			// realy needed for the "F" lights; as the 
			// others end their sequence with an 'off'.
			buffer[ 1 + (i>>3) ] |= (1 << (i & 7));
		};

		at[i]++;
	};
	for(int i = 0; i < lights; i++) 
		out[i][j] = buffer[ 1 + (i>>3) ] & (1 << (i & 7)) ? 'X' : ' ';
    }
    for(int i = 0; i < lights; i++) {
	printf("%03d:",i+1);
	for(int j = 0; j < RL; j++)
		printf("%c", out[i][j]);
	printf("\n");
    };
}


