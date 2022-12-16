#include <stdio.h>
#include "KBD.h"
#include "GLCD.h"
#include "mainDriver.h"
#include <stdbool.h>
#define __FI        1                      /* Font index 16x24               */
#define __USE_LCD   0
#define MAXVERTICALPOSITION 10
#define MAXHORIZONTALPOSITION 10
#define PIXELWIDTH 320
#define PIXELHEIGHT 240

#define VLINE1 3
#define VLINE2 7
#define HLINE1 3
#define HLINE2 7
char testI[5]; 
char testY[5]; 

void delay(){
	int j;
	for(j = 0; j <= 5000000; j++){
	}
}


uint32_t array[9] = {0,1,2,3,4,5,6,7,8};		// array for 3x3 entries
bool arrays[9] = {false,false,false,false,false,false,false,false,false};
uint32_t count = 0;		// play count

void changeTurn(int *turn)		// ASCII code of Player O is 79 and Player X is 88
{
	if(*turn == 79)		// change turn to PLAYER X
		{
			*turn = 88;
		}
		else if(*turn == 88)		// change turn to PLAYER O
			{
				*turn = 79;
			}
}

void printOX(int input, int x, int y, int *turn)		// print O and X at (x,y) coordinates
{
	if(arrays[input])		// if the array already has O or X (TO PREVENT DUPLICATE ENTRIES)
		{
			GLCD_DisplayString(0, 1, 1,  "**TRY AGAIN**    ");
			//delay
		}
		else		// there are empty entries
			{
				array[input] = *turn;		// input O or X
				arrays[input] = true;	
				GLCD_SetTextColor(White);
				GLCD_DisplayChar(x, y, 1, *turn);		// print O and X at (x,y) coordinates
				changeTurn(&*turn);
				count++;		// increment the count
			}
			
			delay();
			delay();
}

void inputArray(int *turn)		// Input values(O or X) to the array
{
	
	int in = 0;
	
	int x = 0;
	int y = 0;
		
	
	uint32_t joystick;
	 uint32_t prevJoystick;
	
	
	KBD_Init();
	
	while(1){

	joystick = get_button();
		while(prevJoystick != joystick){
			
			switch(joystick){
			case KBD_UP:

				y = y - 1;
				if( y < 0){
				 y += 3;
					break;
				}
				break;
				
			case KBD_DOWN:
				y = y+1;
				y %= 3; 
				break;
			case KBD_LEFT:
				
				x = x - 1;
				if (x < 0){
					x += 3;
					break;
				}
				break;
			case KBD_RIGHT:
				x = x + 1;
				if(x >= 3){
					x = 0;
					break;
				}

				break;
			case KBD_SELECT:
				in = 1;
				break;
			default:
				break;
			
		}
			prevJoystick = joystick;
	}
		#ifdef __USE_LCD
				sprintf(testY, " y%d", y);
				GLCD_DisplayString(8,  2, 1, (unsigned char *)testY);
			
				sprintf(testI, "x%d", x);
				GLCD_DisplayString(8,  5, 1, (unsigned char *)testI);
				
		#endif
	
	
	// Row 1
	
	
	
		
		if ((y  == 0) && (x  == 0)){


				if(in == 1){
					in = 0;
					printOX(0, 3, 4, &*turn);
					break;
				}
			}

//			}
			if ((y  == 1) && (x  == 0)){

				if(in == 1){
					in = 0;
					printOX(1, 3, 8, &*turn);
					break;
				}
			}

				if ((y  == 2) && (x  == 0)){

				if(in == 1){
					in = 0;
					printOX(2, 3, 15, &*turn);
					break;
				}
			}

 // Row 2
				if ((y  == 0) && (x  == 1)){

				if(in == 1){
					in = 0;
					printOX(3, 5, 4, &*turn);
					break;
				}
			}

//				}
			if ((y  == 1) && (x  == 1)){

				if(in == 1){
					in = 0;
					printOX(4, 5, 8, &*turn);
					break;
				}
			}


			if ((y  == 2) && (x  == 1)){
				if(in == 1){
					in = 0;
					printOX(5, 5, 15, &*turn);
					break;
				}
			}
			
	// Row 3
			if ((y  == 0) && (x  == 2)){
				if(in == 1){
					in = 0;
					printOX(6, 7, 4, &*turn);
					break;
				}
			}
			if ((y  == 1) && (x  == 2)){
				if(in == 1){
					in = 0;
					printOX(7, 7, 8, &*turn);
					break;
				}
			}
				if ((y  == 2) && (x  == 2)){
				if(in == 1){
					in = 0;
					printOX(8, 7, 15, &*turn);
					break;
				}
			}
	}
	

}

void drawRect( int x0, int y0, int width, int height)		// the draw function for lines
{
	int i;
	int j;
	for(i=0; i<height; i++)
	{
		for(j=0; j<width; j++)
		{
			GLCD_PutPixel(x0+j, y0+i);
		}
	}
}

void gamedIsPlay()		// GUI for Game Display
{
	GLCD_Clear(Black);
	GLCD_SetBackColor(Black);
	GLCD_SetTextColor(White);
	GLCD_DisplayString(0, 1, 1, "***  TIC TAC TOE ***");
	GLCD_DisplayString(1, 1, 1,"*   Player O turn  *");
	GLCD_DisplayString(2, 1, 1,"*                  *");
	GLCD_DisplayString(3, 1, 1,"*                  *");
	GLCD_DisplayString(4, 1, 1, "*                  *");
	GLCD_DisplayString(5, 1, 1, "*                  *");
	GLCD_DisplayString(6, 1, 1, "*                  *");
	GLCD_DisplayString(7, 1, 1, "*                  *");
	GLCD_DisplayString(8, 1, 1, "*                  *");
	GLCD_DisplayString(9, 1, 1, "********************");
	drawRect(30, 100 , 260 , 5);		// draw lines
	drawRect(30, 160 , 260 , 5);		// draw lines
	drawRect(110, 60 , 5 , 150);		// draw lines
	drawRect(205, 60 , 5 , 150);		// draw lines
}

void intro()		// GUI for Intro Display
{
	GLCD_Clear(Black);
	GLCD_SetBackColor(Black);
	GLCD_SetTextColor(White);
	GLCD_DisplayString(0, 1, 1,"********************");
	GLCD_DisplayString(1, 1, 1,"*                  *");
	GLCD_DisplayString(2, 1, 1,"*                  *");
	GLCD_DisplayString(3, 1, 1,"*    TIC TAC TOE   *");		
	GLCD_DisplayString(4, 1, 1,"*                  *");
	GLCD_DisplayString(5, 1, 1,"*                  *");
  GLCD_DisplayString(6, 1, 1,"*                  *");		
	GLCD_DisplayString(7, 1, 1,"*                  *");
	GLCD_DisplayString(8, 1, 1,"*                  *");
	GLCD_DisplayString(9, 1, 1,"********************");
	//delay
}

void checkWinner(int *winFlag, int *turn){		// Check who the winner is!
	int i;
		if(*turn == 88)		// when PLAYER X turn
			{
			GLCD_DisplayString(1, 1, 1, "*   Player X turn  *");
			}
			else if(*turn == 79){		// when PLAYER O turn
				GLCD_DisplayString(1, 1, 1, "*   Player O turn  *");
			}
		
		for(i=0; i<10;){		// Check horizontal lines
			if( (array[i] == array[i+1]) && (array[i+1] == array[i+2]) ){
				if(array[i] == 79){
					*winFlag = 1;
				}else if(array[i] == 88){
					*winFlag = 1;
				}
			}
			i += 3;
		}
		
		for(i=0; i<3;){		// Check vertical lines
			if( (array[i] == array[i+2]) && (array[i+3] == array[i+5]) ){
				if(array[i] == 79){
					*winFlag = 1;
				}else if(array[i] == 88){
					*winFlag = 1;
				}
			}
			i += 1;
		}
		
		if( (array[0] == array[4]) && (array[4] == array[8]) ){		// Check diagonal lines
			if(array[0] == 79){
				*winFlag = 1;
			}else if(array[0] == 88){
				*winFlag = 1;
			}
		}
		if( (array[2] == array[4]) && (array[4] == array[6]) ){		// Check diagonal lines
			if(array[2] == 79){
				*winFlag = 1;
			}else if (array[2] == 88){
				*winFlag = 1;
			}
		}
}

int playTicTacToe(void){
	int winFlag = 0;		// init the win flag as 0
  int turn = 79;		// init the turn variable as 79(Player O; the first turn)
	int w;
		uint32_t joyTic = 0;
	
	count = 0;

	SystemInit();		// System Init
	KBD_Init();
	GLCD_Init();
	
	intro();		// Intro Display
	gamedIsPlay();		// Game Display
	
	
	
		for(w = 0; w<9; w++){
		array[w] = false;
	}
	while(1){
		inputArray(&turn);
		checkWinner(&winFlag, &turn);		// Check who is the winner
		
		if(count == 9){		// if the entries are full
			break;		// Game End
		}
		if(winFlag == 1){		// if there is a winner
			
			count = 0;
			
			
			for(w = 0; w<9; w++){
				array[w] = false;
			}

			break;		// Game End
		}
	}
	
	GLCD_Clear(Black);
	changeTurn(&turn);
	
    if(winFlag == 0)		// there are no winners; GAME DRAW
		{
			GLCD_Clear(Black);
			GLCD_SetBackColor(Black);
			GLCD_SetTextColor(White);
			GLCD_DisplayString(0, 1, 1,"********************");
			GLCD_DisplayString(1, 1, 1,"********************");
			GLCD_DisplayString(2, 1, 1,"********************");
			GLCD_DisplayString(3, 1, 1,"*******DRAW*********");		
			GLCD_DisplayString(4, 1, 1,"									  ");
			GLCD_DisplayString(5, 1, 1,"****            ****");
			GLCD_DisplayString(6, 1, 1," DOWN TO PLAY AGAIN*");		
			GLCD_DisplayString(7, 1, 1,"***  UP TO MENU  ***");
			GLCD_DisplayString(8, 1, 1,"**                **");
			GLCD_DisplayString(9, 1, 1,"********************");
			
			joyTic = get_button();
			
			switch(joyTic){
				case KBD_DOWN:
					GLCD_Clear(Cyan);
					return playTicTacToe();
			
				case KBD_UP:
					GLCD_Clear(Red);
					return main();
				
				default:
					
					return main();
				
			}
			
			
			
    }
		else{		// there is the winner
			GLCD_DisplayString(0, 1, 1,"********************");
			GLCD_DisplayString(1, 1, 1,"*									 *");
			GLCD_DisplayString(2, 1, 1,"*                  *");
			GLCD_DisplayString(3, 1, 1,"*******Winner!******");		
			GLCD_DisplayString(4, 1, 1,"			Player:	   		");
			GLCD_DisplayString(5, 1, 1,(unsigned char *) turn);
			GLCD_DisplayString(6, 1, 1,"*                  *");		
			GLCD_DisplayString(7, 1, 1,"*									 *");
			GLCD_DisplayString(8, 1, 1,"*                  *");
			GLCD_DisplayString(9, 1, 1,"********************");
			
			return main();
		}
}