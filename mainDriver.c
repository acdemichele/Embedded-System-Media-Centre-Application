
#include <stdio.h>
#include "KBD.h"
#include "GLCD.h"
#include "usbdmain.h"
#include <stdbool.h>
#include "usb.h"
#include "usbcfg.h"
#include "usbhw.h"
#include "usbaudio.h"
#include "usbcore.h"
#include "type.h"
#include "ticTac.h"
#include "blackjack.h"
//#include "Gandalf.c"
//#include "HouseoftheDragon.c"
//#include "Kratos.c"
extern unsigned char MAIAR_pixel_data[];
extern unsigned char DRAGON_pixel_data[]; 
extern unsigned char GODOFWAR_pixel_data[];
#define __FI        1                      /* Font index 16x24               */
#define __USE_LCD   0		




//---------------------------------------
//Function Definitions
//---------------------------------------





int gameMenu(){
		uint32_t joystick;
	int flag = 0;	
	int screenSelect = 0;	
	
	GLCD_Init();
	#ifdef __USE_LCD
	GLCD_Clear(White);
	#endif	
	KBD_Init();

	
	while(1){
		if(joystick!=get_button()){
	
		joystick = get_button();
		
		switch(joystick){
		
			case KBD_UP:
						if(flag == 0){
							flag = 1; 
						break;		
						}else
						flag--;
						break;
		
		
			case KBD_DOWN:
				if(flag == 1){
					flag = 0;
					break;
				}else
					flag++;
					break;
			case KBD_SELECT:
					screenSelect = flag;
					return screenSelect;
					
			
			default:
					GLCD_DisplayString(0, 0, __FI, "      Arcade		  			");
					screenSelect = -1;
			break;
		}
		
		switch(flag){
		
			case 0:
				
				#ifdef __USE_LCD                            /* Initialize graphical LCD (if enabled */
                       /* Clear graphical LCD display   */
					GLCD_SetBackColor(Red);
					GLCD_SetTextColor(Yellow);
					GLCD_DisplayString(0, 0, __FI, "      Arcade		  			     ");
					GLCD_DisplayString(1, 0, __FI, "       					  			     ");
					GLCD_DisplayString(2, 0, __FI, "     						  			     ");
					GLCD_SetBackColor(Yellow);
					GLCD_SetTextColor(Red);	
					GLCD_DisplayString(4,  2, __FI, "  Play: Blackjack ");
					GLCD_SetBackColor(Red);
					GLCD_SetTextColor(Yellow);
					GLCD_DisplayString(5,  2, __FI, "  Play: TicTacToe  ");
						
				#endif

			
			break;	
			
			case 1:
				#ifdef __USE_LCD                            /* Initialize graphical LCD (if enabled */

					                       /* Clear graphical LCD display   */
					GLCD_SetBackColor(Red);
					GLCD_SetTextColor(Yellow);
					GLCD_DisplayString(0, 0, __FI, "      Arcade		  			     ");
					GLCD_DisplayString(1, 0, __FI, "       					  			     ");
					GLCD_DisplayString(2, 0, __FI, "     						  			     ");
					GLCD_SetBackColor(Red);
					GLCD_SetTextColor(Yellow);	
					GLCD_DisplayString(4,  2, __FI, "  Play: Blackjack ");
					GLCD_SetBackColor(Yellow);
					GLCD_SetTextColor(Red);
					GLCD_DisplayString(5,  2, __FI, "  Play: TicTacToe  ");
						
				#endif
				
			break;	
		
				
			
			
			
		}
		
	}
 }
 }
	



int mainMenu(){

	uint32_t joystick;
	int flag = 0;	
	int screenSelect = 0;	
	while(1){
		if(joystick!=get_button()){
	
		joystick = get_button();
		
		
		switch(joystick){
		
			case KBD_UP:
						if(flag == 0){
							flag = 2; 
						break;		
						}else
						flag--;
						break;
		
		
			case KBD_DOWN:
				if(flag == 2){
					flag = 0;
					break;
				}else
					flag++;
					break;
			case KBD_SELECT:
					screenSelect = flag;
					return screenSelect;
			
		
		
		}
		
		switch(flag){
		
			case 0:
				
				#ifdef __USE_LCD                            /* Initialize graphical LCD (if enabled */

					                        /* Clear graphical LCD display   */
					GLCD_SetBackColor(Red);
					GLCD_SetTextColor(Yellow);
					GLCD_DisplayString(0, 0, __FI, "     Welcome to our     ");
					GLCD_DisplayString(1, 0, __FI, "       Multimedia          ");
					GLCD_DisplayString(2, 0, __FI, "     		Centre!          ");
					GLCD_SetBackColor(Yellow);
					GLCD_SetTextColor(Red);	
					GLCD_DisplayString(4,  2, __FI, "   Picture   ");
					GLCD_SetBackColor(Red);
					GLCD_SetTextColor(Yellow);
					GLCD_DisplayString(5,  2, __FI, "    Audio    ");
					GLCD_DisplayString(6,  2, __FI, "    Games    ");	
				#endif

			
			break;	
			
			case 1:
				#ifdef __USE_LCD                            /* Initialize graphical LCD (if enabled */

					                        /* Clear graphical LCD display   */
					GLCD_SetBackColor(Red);
					GLCD_SetTextColor(Yellow);
					GLCD_DisplayString(0, 0, __FI, "     Welcome to our     ");
					GLCD_DisplayString(1, 0, __FI, "       Multimedia          ");
					GLCD_DisplayString(2, 0, __FI, "     		Centre!          ");
					GLCD_SetBackColor(Red);
					GLCD_SetTextColor(Yellow);
					GLCD_DisplayString(4,  2, __FI, "   Picture   ");
					GLCD_SetBackColor(Yellow);
					GLCD_SetTextColor(Red);	
					GLCD_DisplayString(5,  2, __FI, "    Audio    ");
					GLCD_SetBackColor(Red);
					GLCD_SetTextColor(Yellow);	
					GLCD_DisplayString(6,  2, __FI, "    Games    ");	
				#endif	
			
			break;	
			case 2:
				#ifdef __USE_LCD                            /* Initialize graphical LCD (if enabled */

					                         /* Clear graphical LCD display   */
					GLCD_SetBackColor(Red);
					GLCD_SetTextColor(Yellow);
					GLCD_DisplayString(0, 0, __FI, "     Welcome to our  ");
					GLCD_DisplayString(1, 0, __FI, "       Multimedia    ");
					GLCD_DisplayString(2, 0, __FI, "     		Centre!      ");
					GLCD_DisplayString(4,  2, __FI, "   Picture   ");
					GLCD_DisplayString(5,  2, __FI, "    Audio    ");
					GLCD_SetBackColor(Yellow);
					GLCD_SetTextColor(Red);	
					GLCD_DisplayString(6,  2, __FI, "    Games    ");	
				#endif		
			
			
			break;
		
		
		
		}	
	}
 }
}


int picSlideshow(){
	#ifdef __USE_LCD      
	uint32_t joystick;
	int flag = 0;	
	int screenSelect = 0;	
	while(1){
		if(joystick!=get_button()){
	
		joystick = get_button();
		
		
		switch(joystick){
		
			case KBD_LEFT:
						if(flag == 0){
							flag = 2; 
						break;		
						}else
						flag--;
						break;
		
		
			case KBD_RIGHT:
				if(flag == 2){
					flag = 0;
					break;
				}else
					flag++;
					break;
				
			case KBD_UP:
					
					return 5;
			
		
		
		}
		
		switch(flag){
		
			case 0:
				GLCD_Clear(Black);
				GLCD_SetBackColor(Yellow);
				GLCD_Bitmap(5, 5, 201, 201, (GODOFWAR_pixel_data));
				
				break;
			
			case 1:
				GLCD_Clear(Black);
				GLCD_SetBackColor(Yellow);
				GLCD_Bitmap(5, 5, 282, 159, (DRAGON_pixel_data));
				
				break;
			
			case 2:	
				
				GLCD_Clear(Black);
				GLCD_SetBackColor(Yellow);
				GLCD_Bitmap(5, 5, 300, 169, (MAIAR_pixel_data));
				
				break;
		}
	}

}
	#endif
}


int main(void){
	//GLCD_Init();
	//GLCD_SetWindow(3, 3, 320, 240);
	//GLCD_SetWindow(7, 7, 320, 240);
	
	
	uint32_t joystick2;
	
	
GLCD_Init();
#ifdef __USE_LCD
GLCD_Clear(White);
#endif	
KBD_Init();

	while(1){
		int mainSelector = 0;
		int picReturn = 0;
		int audioSelector = 0;
		int gameSelector = 0;
		
		mainSelector = mainMenu();
		
		switch(mainSelector){
			
			case 0:
				#ifdef __USE_LCD
				GLCD_Clear(Black);
				#endif
				picReturn = picSlideshow();
				
				if (picReturn == 5){
				
				return main();
				}
				
			
			case 1:
			
			GLCD_Clear(Black);	
			
			playAudio();
			return main();
				
			
			
			
			case 2:
				
			
			
			gameSelector = gameMenu();
			
			switch(gameSelector){
			
				case 0:
				
				playTicTacToe();
				
				
				return main();
				
				
				case 1:
				
				// call game #2's function
				blackjack();
				
				
			
				
			}
			
			
				
		}
		
	
	
	}
	

}
