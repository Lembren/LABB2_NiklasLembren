#include <avr/io.h>
#include <avr/interrupt.h>
#include "timer.h"

void timer_init(void)
{
	/*set fast PWM mode with none-inverting mode*/
	TCCR0A = (1 << WGM00) | (1 << WGM01) | (1 << COM0A1);
	/*Sets prescaler to 64*/
	TCCR0B |= (1 << CS00) | (1 << CS01);
}