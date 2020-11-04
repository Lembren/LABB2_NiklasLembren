#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include <stdio.h>
#include "led.h"
#include "serial.h"
#include "timer.h"


int main(void) {
	uart_init();
	LED_init();
	timer_init();
	uint8_t timerOverflowCount = 0; //count the number of overflows
	while (1)
	{
		if (TIFR0 & (1 << OCF0A)) //Timer/Counter Interrupt Flag Register,  interrupt flag set when TCNT0 reset to 0.
		{
			timerOverflowCount++;
			TIFR0 |= (1 << OCF0A);    //clear the overflow flag

			if (timerOverflowCount >= 10)
			{
				PORTB ^= (1 << PB0); //Toggle LED
				TCNT0 = 0; //reset counter
				timerOverflowCount = 0; //Reset overflowcounter

			}
		}

	}
}