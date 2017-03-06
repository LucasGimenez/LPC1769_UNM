/*
 * getPrescaler.c
 *
 *  Created on: 27/2/2017
 *      Author: Agustinceravolo
 */

// La idea de la librería es que retorne el valor que se debe cargar en el PR (prescalar register)

#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif

unsigned int getPrescaler (int ptimer, int us){

	unsigned int pclk, prescalerForUs, displacement;

	switch (ptimer)		// Partiendo de saber con que timer queremos trabajar, definimos el desplazamiento que vamos a hacer despues.
	{
	case 0x00:
		displacement = 0x02;
		break;
	case 0x01:
		displacement = 0x04;
		break;
	case 0x02:
		displacement = 0x0C;
		break;
	case 0x03:
		displacement = 0x0E;
		break;
	}

	if((ptimer == 0) || (ptimer == 1)) // Si vamos a trabajar con uno de estos dos timers, trabajamos con el registro PCLKSEL0.
	{
	    pclk = (LPC_SC->PCLKSEL0 >> displacement) & 0x03; // desplazamos y enmascaramos, para saber por cuanto estamos dividiendo la frecuencia del clock.

	    switch ( pclk )
	    {
	    case 0x00:
	        pclk = SystemCoreClock/4;
	        break;

	    case 0x01:
	        pclk = SystemCoreClock;
	        break;

	    case 0x02:
	        pclk = SystemCoreClock/2;
	        break;

	    case 0x03:
	        pclk = SystemCoreClock/8;
	        break;
	    }
	}

	if((ptimer == 2) || (ptimer == 3)) //Si vamos a trabajar con uno de estos dos timers, trabajamos con el registro PCLKSEL1
	{
	    pclk = (LPC_SC->PCLKSEL1 >> displacement) & 0x03;

	    switch ( pclk )
	    {
	    case 0x00:
	        pclk = SystemCoreClock/4;
	        break;

	    case 0x01:
	        pclk = SystemCoreClock;
	        break;

	    case 0x02:
	        pclk = SystemCoreClock/2;
	        break;

	    case 0x03:
	        pclk = SystemCoreClock/8;
	        break;
	    }
	}

	    prescalerForUs = pclk / (1/(0.000001*us)) - 1;

	    return prescalerForUs;

}
