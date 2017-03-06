/*
===============================================================================
 Name        : main.c
 Author      : $Lucas Gimenez
 Version     :
 Copyright   : $
 Description : main definition
===============================================================================
*/

#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif


#define led_port 0
#define led_pin 22

/* Prototipos de las funciones creadas*/

void led_init(void);
void led_on(void);
void led_off(void);
void led_invert(void);

void led_init(void){

	LPC_GPIO0->FIODIR |= (1<<led_pin); //Configuramos como salida el pin P0.22
}

void led_on(void){

	LPC_GPIO0->FIOSET = (1<<led_pin); //Colocamos un '1' en el pin P0.22
}

void led_off(void){

	LPC_GPIO0->FIOCLR = (1<<led_pin); //Colocamos un '0' en el pin P0.22
}

void led_invert(void){

	uint32_t ledstate;

	ledstate = LPC_GPIO0->FIOPIN;     //Leemos el estado del pin P0.22

	LPC_GPIO0->FIOCLR = ledstate & (1<<led_pin);

	LPC_GPIO0->FIOSET =((~ledstate)& (1<<led_pin));
}



int main(void) {

    led_init();
    led_off();
    led_on();

/*Bucle infinito*/

    while(1) {

    	ledInvert();

    	}

   	}

    return 0 ;
}


