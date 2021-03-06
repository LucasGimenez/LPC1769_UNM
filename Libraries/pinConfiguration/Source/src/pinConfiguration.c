

#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif

void ConfigPortPin (int PORT, int PIN, char TIPO){

	if(TIPO == 'O'){
		switch(PORT){

			case'0':
				LPC_GPIO0-> FIODIR |= (1<<PIN);
				break;

			case'1':
				LPC_GPIO1-> FIODIR |= (1<<PIN);
				break;

			case'2':
				LPC_GPIO2-> FIODIR |= (1<<PIN);
				break;

			case'3':
				LPC_GPIO3-> FIODIR |= (1<<PIN);
				break;
					}
				   }

	if(TIPO == 'I'){
		switch(PORT){

			case'0':
				LPC_GPIO0-> FIODIR &= ~(1<<PIN);
				break;

			case'1':
				LPC_GPIO1-> FIODIR &= ~(1<<PIN);
				break;

			case'2':
				LPC_GPIO2-> FIODIR &= ~(1<<PIN);
				break;

			case'3':
				LPC_GPIO3-> FIODIR &= ~(1<<PIN);
				break;
					}
	               }
	}


