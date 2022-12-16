#include <stdio.h>
#include "KBD.h"
#include "GLCD.h"
#include "mainDriver.h"
#include <stdbool.h>
#include <stdlib.h>
#include <String.h>
#define __FI        1                      /* Font index 16x24               */
#define __USE_LCD   0


char testI2[5]; 

char currentCard[10]; 

bool suitChosen[4] = {false}; // Suit boolean array for selection check
bool cardChosen[13] = {false}; // Card boolean array for selection check

char * deck[52];

int newSuit;
int newCard;

int newSuit1;
int newCard1;

int score1 = 0;
int score2 = 0;

bool isWin = false;

bool deckCheck[52] = {false}; // Deck checker array

const char* getSuit(const int v){ // Get current suite of the card
	
	const char* kSuits[] = {
		"Heart",
		"Clubs", 
		"Diamonds",
		"Spades"
		
	};
	return kSuits [ v % 4];
}

const char* getCards(const int v){
	const char* kCards[] = {
			"Ace",
			"Two",
			"Three",
			"Four",
			"Five", 
			"Six",
			"Seven",
			"Eight",
			"Nine",
			"Ten",
			"Jack",
			"Queen",
			"King"
	};
	return kCards [v % 13];
	
	
}

void initDeck(){
	int i;
	int j;
	
	//int shuffle[52];
	
	int counter = 0;
	for(i = 0; i<4; i++){
		for(j = 0; j<13; j++){
			sprintf(currentCard, "%s-%s", getSuit(i),getCards(j));
			deck[counter] = currentCard;
			
			counter++;
		}
		
		
	}
	//srand(time(NULL));
	
	
}
void shuffle(){
	
}

void delay1(){
	int j;
	for(j = 0; j <= 5000000; j++){
	}
}
void changeTurnI(int *turn)		// ASCII code of Player O is 79 and Player X is 88
{
	if(*turn == 79)		// change turn to PLAYER X
		{
			GLCD_DisplayString(1, 0, 1,"*   Player 1 turn  *");
			*turn = 88;
		}
		else if(*turn == 88)		// change turn to PLAYER O
			{
				GLCD_DisplayString(1, 0, 1,"*   Player 0 turn  *");
				*turn = 79;
				
			}
}

void currentHand(const char* suit, const char* cards, int *turn)		// print O and X at (x,y) coordinates
{

	char check[10];
	char check2[10];
	
	
	
	const char* newSuitC;
	const char* newCards;
	
	int updateSuit, updateCard;
	
	bool doesExist = false;
	
	int i,w,p;
	


	for(i = 0; i < 52; i++){
		sprintf(check, "%s-%s", suit, cards);
		if(strcmp(deck[i],check)){

			if(deckCheck[i] == true){
				doesExist = true;

				break;
			}
			else{

				deckCheck[i] = true;
				doesExist = false;
				
				
				//Get index of the values so we can print em
				
				for(p = 0; p < 4; p++){
					if(strcmp(getSuit(p), suit)){
						if(*turn == 79){
							newSuit = p;
						}
						else{
							newSuit1 = p;
						}

						break;
					}
				}
				
				for(p = 0; p < 13; p++){
					if(strcmp(getCards(p), cards)){
						if(*turn == 79){
							newCard = p;
						}
						else{
							newCard1 = p;
						}

						break;
					}
				}

				break;
			}

		}


	}

	
	while(doesExist == true)		// Card has been used so use another
		{
				
			// Call to get new card
			updateSuit = (rand() % 4) + 1;
			updateCard = (rand() % 13) + 1;
			
			newSuitC = getSuit(updateSuit);
			newCards = getCards(updateCard);
			sprintf(check2, "%s-%s", newSuitC, newCards);
			
			for(w = 0; w < 52; w++){
				if(strcmp(deck[w],check2)){
					if(deckCheck[w] == true){
							doesExist = true;
					}
					else{
						deckCheck[w] = true;
						doesExist = false;
						break;
					}

					
				}

		
	}
			if(*turn == 79){
				newSuit = updateSuit;
				newCard = updateCard;
			}
			else{
				newSuit1 = updateSuit;
				newCard1 = updateCard;
			}


			//delay
		}
		
		changeTurnI(&*turn);

			delay1();
			delay1();
			


	}
void drawRect1( int x0, int y0, int width, int height)		// the draw function for lines
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


void gamedIsPlay1()		// GUI for Game Display
{
	GLCD_Clear(Black);
	GLCD_SetBackColor(Black);
	GLCD_SetTextColor(White);
	GLCD_DisplayString(0, 0, 1, "***  Blackjack ***");
	GLCD_DisplayString(1, 0, 1,"*   Player 0 turn  *");
	GLCD_DisplayString(2, 0, 1,"*                  *");
	GLCD_DisplayString(3, 0, 1,"*                  *");
	GLCD_DisplayString(4, 0, 1, "*                  *");
	GLCD_DisplayString(5, 0, 1, "*                  *");
	GLCD_DisplayString(6, 0, 1, "*                  *");
	GLCD_DisplayString(7, 0, 1, "*  Draw            *");
	GLCD_DisplayString(8, 0, 1, "*  Stay            *");
	GLCD_DisplayString(9, 0, 1, "********************");
	
	drawRect1(30, 81 , 260 , 5);		// draw lines
	drawRect1(150, 60 , 5 , 150);		// draw lines
	
	
}
void intro1()		// GUI for Intro Display
{
	GLCD_Init();
	GLCD_Clear(Black);
	GLCD_SetBackColor(Black);
	GLCD_SetTextColor(White);
	GLCD_DisplayString(0, 0, 1,"********************");
	GLCD_DisplayString(1, 0, 1,"*                  *");
	GLCD_DisplayString(2, 0, 1,"*                  *");
	GLCD_DisplayString(3, 0, 1,"*    Blackjack     *");		
	GLCD_DisplayString(4, 0, 1,"*                  *");
	GLCD_DisplayString(5, 0, 1,"*                  *");
  GLCD_DisplayString(6, 0, 1,"*                  *");		
	GLCD_DisplayString(7, 0, 1,"*                  *");
	GLCD_DisplayString(8, 0, 1,"*                  *");
	GLCD_DisplayString(9, 0, 1,"********************");
	delay1();
	delay1();
}

void displayWinner(int *turn){
	GLCD_Clear(Black);
	GLCD_SetBackColor(Black);
	GLCD_SetTextColor(White);
	GLCD_DisplayString(0, 0, 1,"********************");
	GLCD_DisplayString(1, 0, 1,"*                  *");
	GLCD_DisplayString(2, 0, 1,"*    Winner:       *");
	
	if(*turn == 79 && isWin == true){
		GLCD_DisplayString(3, 0, 1,"*    Player 0     *");	
	}
	if(*turn == 88 && isWin == true){
		GLCD_DisplayString(3, 0, 1,"*    Player 1     *");	
	}
		
	
	
	
	GLCD_DisplayString(4, 0, 1,"**");
	GLCD_DisplayString(5, 0, 1,"*                  *");
  GLCD_DisplayString(6, 0, 1,"*                  *");		
	GLCD_DisplayString(7, 0, 1,"*                  *");
	GLCD_DisplayString(8, 0, 1,"*                  *");
	GLCD_DisplayString(9, 0, 1,"********************");
	delay1();
	delay1();
	
	GLCD_Clear(White);
	
	intro1();		// Intro Display
	gamedIsPlay1();		// Game Display
	
	initDeck(); // Create Deck
	
	score1 = 0;
	score2 = 0;
	

	
}
void checkWinner1(int *turn){
	// Calculate score
		
		char oScore[5];
		char oScore2[5];
		
		char test1[2];
		char test2[2];
	

		// For player 1
		if(*turn == 79){
			if(score1 == 21 && score2 <= 21){
				isWin = true;
				score1 = 0;
				score2 = 0;
				
				changeTurnI(&*turn);
				displayWinner(turn);
			}
			else{
					// From 2 -> 10
					if(newCard >= 1 && newCard <= 8){
						if(score1 + newCard <= 21){
								score1 += newCard;
								sprintf(oScore, "%d", score1);
								GLCD_DisplayString(6, 3, 1,(unsigned char*)oScore);
								sprintf(oScore2, "%d", score2);
								GLCD_DisplayString(6, 10, 1,(unsigned char*)oScore2);
						}
						else{
								isWin = true;
								score1 = 0;
								score2 = 0;
								
								changeTurnI(&*turn);
								displayWinner(turn);
						}
					
						
				
					}
					// From jack -> king
					if(newCard >= 9 && newCard <= 11){
						if(score1 + 10 <= 21){
								score1 += 10;
								sprintf(oScore, "%d", score1);
								GLCD_DisplayString(6, 3, 1,(unsigned char*)oScore);
								sprintf(oScore2, "%d", score2);
								GLCD_DisplayString(6, 10, 1,(unsigned char*)oScore2);
						}
			
						
					}
					
					// Ace high or low
					if(newCard == 12){
						
						// Check if you cannot use ace high
						if(score1 + 11 >= 21){
							
							// Check ace low if you cannot use ace high
							if(score1 + 1 >= 21){ // Cannot use ace low
								
									isWin = true;
									score1 = 0;
									score2 = 0;
									sprintf(oScore, "%d", score1);
									GLCD_DisplayString(6, 3, 1,(unsigned char*)oScore);
									sprintf(oScore2, "%d", score2);
									GLCD_DisplayString(6, 10, 1,(unsigned char*)oScore2);
								
									changeTurnI(&*turn);
									displayWinner(turn);
							
							}
							else{ // You can use ace low
								score1 += 1;
								sprintf(oScore, "%d", score1);
								GLCD_DisplayString(6, 3, 1,(unsigned char*)oScore);
								sprintf(oScore2, "%d", score2);
								GLCD_DisplayString(6, 10, 1,(unsigned char*)oScore2);
							}
						}
						else{ // You can use ace high
							score1 += 11;
							sprintf(oScore, "%d", score1);
							GLCD_DisplayString(6, 3, 1,(unsigned char*)oScore);
							sprintf(oScore2, "%d", score2);
							GLCD_DisplayString(6, 10, 1,(unsigned char*)oScore2);
						}
					}
			}
		}
		else{
			

			// For player 2
			
			if(score2 >= 21 && score1 <= 21){
				isWin = true;
				score1 = 0;
				score2 = 0;
				
				changeTurnI(&*turn);
				displayWinner(turn);
			}
			else{
					// From 2 -> 10
					if(newCard1 >= 1 && newCard1 <= 8){
						if(score2 + newCard1 <= 21){
							score2 += newCard1;
							sprintf(oScore, "%d", score1);
							GLCD_DisplayString(6, 3, 1,(unsigned char*)oScore);
							sprintf(oScore2, "%d", score2);
							GLCD_DisplayString(6, 10, 1,(unsigned char*)oScore2);
						}
						else{
							isWin = true;
							score1 = 0;
							score2 = 0;
							
							changeTurnI(&*turn);
							displayWinner(turn);
						}

//						sprintf(oScore, "%d", score1);
//						GLCD_DisplayString(6, 3, 1,(unsigned char*)oScore);
				
					}
					// From jack -> king
					if(newCard1 >= 9 && newCard1 <= 11){
						if(score2 + newCard1 <= 21){
								score2 += 10;
								sprintf(oScore, "%d", score1);
								GLCD_DisplayString(6, 3, 1,(unsigned char*)oScore);
								sprintf(oScore2, "%d", score2);
								GLCD_DisplayString(6, 10, 1,(unsigned char*)oScore2);
						}
							else{
							isWin = true;
							score1 = 0;
							score2 = 0;
							
							changeTurnI(&*turn);
							displayWinner(turn);
						}
					
					}
					
					// Ace high or low
					if(newCard == 12){
						
						// Check if you can use ace high
						if(score2 + 11 >= 21){
							
							// Check ace low if you cannot use ace high
							if(score2 + 1 >= 21){ // Cannot use ace low
								
									isWin = true;
									score1 = 0;
									score2 = 0;
									sprintf(oScore, "%d", score1);
									GLCD_DisplayString(6, 3, 1,(unsigned char*)oScore);
									sprintf(oScore2, "%d", score2);
									GLCD_DisplayString(6, 10, 1,(unsigned char*)oScore2);
				
									changeTurnI(&*turn);
									displayWinner(turn);
							
							}
							else{ // You can use ace low
								score2 += 1;
								sprintf(oScore, "%d", score1);
								GLCD_DisplayString(6, 3, 1,(unsigned char*)oScore);
								sprintf(oScore2, "%d", score2);
								GLCD_DisplayString(6, 10, 1,(unsigned char*)oScore2);
							}
						}
						else{ // You can use ace high
							score2 += 11;
							sprintf(oScore, "%d", score1);
							GLCD_DisplayString(6, 3, 1,(unsigned char*)oScore);
							sprintf(oScore2, "%d", score2);
							GLCD_DisplayString(6, 10, 1,(unsigned char*)oScore2);
						}
					}
			}
		}
		sprintf(test1, "%d", newCard);
		GLCD_DisplayString(4, 9, 1,(unsigned char*)test1);
	

		sprintf(test2, "%d", newCard1);
		GLCD_DisplayString(4, 11, 1,(unsigned char*)test2);
	
			
		
}


int inputArray2(int *turn)		// Input values(O or X) to the array
{
	
	int in = 0;
	
	int x = 0;
	const char * randomSuit1;
	const char * randomType1;
	
	const char * randomSuit2;
	const char * randomType2;
	
	int suitVar, cardType;

	
	uint32_t joystick;
	 uint32_t prevJoystick;
	
	
	KBD_Init();
	
	while(1){

	joystick = get_button();
		while(prevJoystick != joystick){
			
			switch(joystick){

			case KBD_UP:
				
				x = x - 1;
				if (x < 0){
					x += 2;
					break;
				}
				break;
			case KBD_DOWN:
				x = x + 1;
				if(x >= 2){
					x = 0;
					break;
				}

				break;
			case KBD_SELECT:
				in = 1;
				break;
			
			
			case KBD_LEFT:
				
				return main();
			
			
			default:
				break;
			
		}
			prevJoystick = joystick;
	}
		#ifdef __USE_LCD
				GLCD_DisplayString(2,  1, 1, "Player 0");
				GLCD_DisplayString(2,  11, 1, "Player 1");
				
		#endif

	
	if(x == 0){
		
		#ifdef __USE_LCD
				GLCD_SetTextColor(Black);
				GLCD_SetBackColor(White);
				GLCD_DisplayString(7, 0, 1, "*  Draw            *");
				
				GLCD_SetTextColor(White);
				GLCD_SetBackColor(Black);
				GLCD_DisplayString(8, 0, 1, "*  Stay            *");

		#endif
		if(in == 1){

			in = 0;
			
			suitVar = (rand() % 4) + 1;
			
			
			cardType = (rand() % 13) + 1;
			
			
		
			
			
			
			if(*turn == 79){
				
				
				 
				randomSuit1 = getSuit(suitVar);
				randomType1 = getCards(cardType);
			
				currentHand(randomSuit1,randomType1, &*turn);
			
				randomSuit1 = getSuit(newSuit);
				randomType1 = getCards(newCard);
				
				checkWinner1(turn);
				
				#ifdef __USE_LCD

				GLCD_ClearLn(4,1);
				GLCD_ClearLn(5,1);
				GLCD_SetBackColor(Black);
				GLCD_SetTextColor(White);
				
				GLCD_DisplayString(4, 0, 1, "*                  *");
				GLCD_DisplayString(5, 0, 1, "*                  *");
			
				GLCD_DisplayString(4,  1, 1, (unsigned char *)randomType1);
				GLCD_DisplayString(5,  1, 1, (unsigned char *)randomSuit1);
				

				
				GLCD_DisplayString(4,  10, 1, (unsigned char *)randomType2);
				GLCD_DisplayString(5,  10, 1, (unsigned char *)randomSuit2);
				GLCD_SetTextColor(White);
				GLCD_SetBackColor(Black);
				drawRect1(150, 60 , 5 , 150);		// draw lines
			
			

				
				#endif


			}
			else{
				randomSuit2 = getSuit(suitVar);
				randomType2 = getCards(cardType);
			
				currentHand(randomSuit2,randomType2, &*turn);
			
				randomSuit2 = getSuit(newSuit1);
				randomType2 = getCards(newCard1);
				
				checkWinner1(turn);

				
				#ifdef __USE_LCD

				GLCD_ClearLn(4,1);
				GLCD_ClearLn(5,1);
				GLCD_SetBackColor(Black);
				GLCD_SetTextColor(White);
				
				GLCD_DisplayString(4, 0, 1, "*                  *");
				GLCD_DisplayString(5, 0, 1, "*                  *");
			
				GLCD_DisplayString(4,  1, 1, (unsigned char *)randomType1);
				GLCD_DisplayString(5,  1, 1, (unsigned char *)randomSuit1);
				GLCD_DisplayString(4,  10, 1, (unsigned char *)randomType2);
				GLCD_DisplayString(5,  10, 1, (unsigned char *)randomSuit2);
				
				GLCD_SetTextColor(White);
				GLCD_SetBackColor(Black);
				drawRect1(150, 60 , 5 , 150);		// draw lines
			
			

				
				#endif
								

			}
			
			
			
			
	}
		
	}
	else{

		#ifdef __USE_LCD
				GLCD_SetTextColor(White);
				GLCD_SetBackColor(Black);
				GLCD_DisplayString(7, 0, 1, "*  Draw            *");
				
				GLCD_SetTextColor(Black);
				GLCD_SetBackColor(White);
				GLCD_DisplayString(8, 0, 1, "*  Stay            *");
		
				GLCD_SetTextColor(White);
				GLCD_SetBackColor(Black);

		#endif
		
		if(in == 1){
			in = 0;
			changeTurnI(&*turn);
		}
	

	}
	
	in = 0;


	
}
		return in;
	}


void blackjack(){
//	int winFlag = 0;		// init the win flag as 0
  int turnI = 79;		// init the turn variable as 79(Player O; the first turn)
//	uint32_t blacktic = 0;
	SystemInit();		// System Init
	KBD_Init();
	GLCD_Init();
	GLCD_Clear(White);
	
	intro1();		// Intro Display
	gamedIsPlay1();		// Game Display
	
	initDeck(); // Create Deck
	
	score1 = 0;
	score2 = 0;
	
	while(1){
		inputArray2(&turnI);
		displayWinner(&turnI);
		
	}
	
}