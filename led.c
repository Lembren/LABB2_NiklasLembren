#include <avr/io.h>
#include "led.h"

void LED_init() {
    DDRD |= (1 << PD6); /*arduino digital pin 6 output*/
}