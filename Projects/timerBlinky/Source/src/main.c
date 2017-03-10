/*
===============================================================================
 Name        : main.c
 Author      : $Lucas Gimenez
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

/*Este código fue modificado para que funcione con un solo timer (timer 0), y produzca un toggle en el pin P0.22 cada 1 segundo.
 *La base de tiempo puede ser modificada cambiando el valor de MiliToMicroSec*/

#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif


#define PCLK_TIMER0  2

#define MiliToMicroSec(x)  (x*1000)  /* ms is multiplied by 1000 to get us*/

extern unsigned int SystemCoreClock;

unsigned int getPrescalarForUs(uint8_t timerPclkBit);

int main (void)
{
    SystemInit();

    LPC_SC->PCONP |= (1 << 1);                        /* Power ON Timer0*/

    LPC_TIM0->MCR  = (1 << 0) | (1 << 1);             /* Clear TC on MR0 match and Generate Interrupt*/
    LPC_TIM0->PR   = getPrescalarForUs(PCLK_TIMER0);  /* Prescalar for 1us */
    LPC_TIM0->MR0  = MiliToMicroSec(100);             /* Load timer value to generate 100ms delay*/
    LPC_TIM0->TCR  = (1 << 0);                        /* Start timer by setting the Counter Enable*/


    NVIC_EnableIRQ(TIMER0_IRQn);                      /* Enable Timer0 Interrupt */


    LPC_GPIO0->FIODIR |= (1 << 22);                   /* Configure the LED pins(P2_0,P2_1) as outputs */

    while(1)
    {
      __WFI();
    }
}


void TIMER0_IRQHandler(void)
{
    unsigned int isrMask;

    isrMask = LPC_TIM0->IR;
    LPC_TIM0->IR = isrMask;

/*Se invierte el estado del led una vez leído su estado anterior.*/

    uint32_t ledstate;

	ledstate = LPC_GPIO0->FIOPIN;                       /*Leemos el estado del pin P0.22*/

	LPC_GPIO0->FIOCLR = ledstate & (1<<led_pin);

	LPC_GPIO0->FIOSET =((~ledstate)& (1<<led_pin));
}



unsigned int getPrescalarForUs(uint8_t timerPclkBit)
{
    unsigned int pclk,prescalarForUs;
    pclk = (LPC_SC->PCLKSEL0 >> timerPclkBit) & 0x03;  /* get the pclk info for required timer */

    switch ( pclk )                                    /* Decode the bits to determine the pclk*/
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

    default:
        pclk = SystemCoreClock/4;
        break;
    }

    prescalarForUs =pclk/1000000 - 1;                    /* Prescalar for 1us (1000000Counts/sec) */

    return prescalarForUs;
}
