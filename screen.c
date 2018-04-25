// contains screen manipulation function, such as clearScreen(), gotoxy(), setColor(), etc
#include "screen.h"
#include <stdio.h>

/*
	Function defination of clearScreen()
	This function will use VT100 escape sequence "\ESC[2J" to erase the total terminal screen
	Input argument: none
	return argument: none
*/

void clearScreen(void){
	printf("%c[2J", ESC);
	fflush(stdout);
}

/*
	Function definition of gotoxy()
	This function uses VT100 escape sequence "\ESC[row;colH" to set the cursor to the specific 
	location of the terminal screen
	Input argument:
		int row: row number (1 is top)
		int col: col number (1 is left)
	return argument: none
*/

void gotoxy(int row, int col){
	printf("%c[%d;%dH", ESC, row, col);
	fflush(stdout);
}

/* 
	Function definition of bar()
	This function displays a vertical bar on the i-th column of the screen, the height of vertical 
	bar describes the decibel value of 200 samples.
	To be possibly illustrated on the terminal screen, the height of vertical bar should be resized 
	by taking the value of dB/4.   
	Input argument: 
		int col: col number
		double dB: decibel value
	return argument: none
*/

void bar(int col, double dB){
	int i;
	for(i=0; i<dB/4; i++){
		gotoxy(25-i, col+1);					// the first bar start form col=1
#ifndef UNICODE
		printf("%c", '*');
#else
		if(i<60/4) setColor(WHITE);
		else if(i<80/4 && i>=60/4) setColor(YELLOW);
		else setColor(RED);
		printf("%s",BAR);
#endif
	}
}

/*
	Function definition of setColor()
	This function uses VT100 escape sequence "\ESC[color" to set colors for veritcal bar with 
	different decibel values in the terminal screen
	Input argument: int color
	return argument: none
*/

void setColor(int color){
	printf("%c[1;%dm",ESC,color);
	fflush(stdout);
}
