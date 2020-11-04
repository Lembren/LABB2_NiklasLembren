#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include <stdio.h>
#include <avr/interrupt.h>
#include "led.h"
#include "serial.h"
#include "timer.h"


int main(void) {
	uart_init();
	LED_init();
	timer0_init();
	timer2_init();
	while (1)
	{
		while ((TIFR2 & (1 << OCF2A)) > 0) { //wait for overflow

			OCR0A = simple_ramp();
			TIFR2 |= (1 << OCF2A); // This resets the flag
		}
	}
}