#include <avr/io.h>
#include <avr/interrupt.h>
#include "timer.h"

void timer_init(void)
{
	TCCR0A |= (1 << WGM01);//CTC MODE
	TCCR0B = (1 << CS00) | (1 << CS02); // set up prescaler = 1024
	TCNT0 = 0; //Timer/Counter Register ,initialize counter
	OCR0A = 156;//Output Compare Register, top value of counter.
	/*16MHz/1024 = 15.625Hz 15625/((1/10)*1000) = 156,25 */
}