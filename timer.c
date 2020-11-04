#include <avr/io.h>
#include <avr/interrupt.h>
#include "timer.h"

void timer0_init(void)
{
	/*set fast PWM mode with none-inverting mode*/
	TCCR0A = (1 << WGM00) | (1 << WGM01) | (1 << COM0A1);
	/*Sets prescaler to 64*/
	TCCR0B |= (1 << CS00) | (1 << CS01);
}

void timer2_init(void) {
	//CTC
	TCCR2A |= (1 << WGM21);
	// set up timer with prescaler = 1024 
	TCCR2B |= (1 << CS22) | (1 << CS21) | (1 << CS20);
	OCR2A = 249; //16000000/1024 * 0.016 = 250-1
	TCNT2 = 0;
}