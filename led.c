#include <avr/io.h>
#include "led.h"

void LED_init() {
    DDRB |= (1 << PB0);  /*arduino digital pin 8 output*/
}