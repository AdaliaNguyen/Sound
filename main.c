#include <stdio.h>
#include <stdlib.h>
#include "sound.h"

int main(void) {
	while(1){
		// record 1 sec of sound into test1.wav
		system("arecord -r16000 -c1 -f S16_LE -d1 test1.wav");
		// open the wav file and read samples
		displayWAVheader("test1.wav");
		
		// calculate fast dBs
		displayBar("test1.wav");
		// display necessary information (duration, wav header etc)
		// calculate fast dBs
		// send fast dBs to web (php program on www.cc.puv.fi)	
		break; 		// for testing, just run the loop once
	}
}
