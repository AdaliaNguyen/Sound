#include "sound.h"
#include <stdio.h>
#include <math.h>
// function definition of displayBar()
// this function opens the "test1.wav" file and read the second part (data) of 
// the file. The samples should be in S16_LE format, and there are 16000 of
// them. The function processes every 200 samples and calculate their RMS value
// and renders this value as a vertical bar on terminal screen
void displayBar(char filename[]){
	FILE *fp;
	short int samples[SAMPLERATE];
	double sum_200, rms_80[80], dB;
	int i, j;
	WAVHeader myhdr;		// dummy header to skip over the reading from the file
	fp = fopen(filename, "r");
	if(fp == NULL){
		printf("Error opening the file!\n");
		return;
	}
	fread(&myhdr, sizeof(WAVHeader), 1, fp);
	fread(&samples, sizeof(short), SAMPLERATE, fp);
	fclose(fp);	
	// all the samples of lsec are read to the array samples[], we need to run a loop 80 times
	// for 80 bars on the screen, and each iteration of this loop will calculate a RMS value
	// of 200 samples
	clearScreen();
	for(i=0; i<80; i++){
		for(j=0,sum_200=0.0; j<200; j++){
			sum_200 += samples[j+i*200]*samples[j+i*200];
		}
		rms_80[i] = sqrt(sum_200/200);
		dB = 20*log10(rms_80[i]);
#ifdef DEBUG
		printf("RMS[%d] = %10.4f = %10.4fdB\n", i,  rms_80[i], dB);
#else
		// in order to display sound value in a screen, we need to use decibel
		bar(i, dB);
#endif
	}
}

// function definition of dilayWAVheader()
void displayWAVheader(char filename[]){
	WAVHeader myhdr;		// an instance of definec struct
	FILE *fp;
	fp = fopen(filename, "r"); 	// open the file for reading
	if(fp == NULL){			// if fopen is failed
		printf("ERROR of opening file!\n");
		return;
	}
	fread(&myhdr, sizeof(WAVHeader), 1, fp);
	fclose(fp);
	printID(myhdr.chunkID);
	printf("Chunk size: %d\n", myhdr.chunkSize);
	printID(myhdr.format);
	printID(myhdr.subchunk1ID);
	printf("Subchunk 1 size: %d\n", myhdr.subchunk1Size);
	printf("Audio format: %d\n", myhdr.audioFormat);
	printf("Number of channels: %d\n", myhdr.numChannels);
	printf("Sample rate: %d\n", myhdr.sampleRate);
	printf("Byte rate: %d\n", myhdr.byteRate);
	printf("Block align: %d\n", myhdr.blockAlign);	
	printf("Bits per sample: %d\n", myhdr.bitsPerSample);
	printf("Subchunk 2 size: %d\n", myhdr.subchunk2Size);	
	// there are more fields to be displayed
}

void printID(char id[]){
	int i;
	for(i=0; i<4; i++)
		printf("%c", id[i]);

	printf("\n");
}
