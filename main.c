#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include <stdio.h>
#include "led.h"
#include "serial.h"
#include "timer.h"

void set_brightness(uint8_t data)
{
	OCR0A = data;
}


int main(void) {
    uart_init();
    LED_init();
    timer_init();
    uint8_t brightness[6] = { 0,20,50,80,190,255 }; //different OCR0A values 
    while (1) {
        for (uint8_t i = 0; i < sizeof(brightness) / sizeof(brightness[0]); i++)//increase brightness
        {
            set_brightness(brightness[i]);
            _delay_ms(300);
        }

        for (uint8_t i = sizeof(brightness) / sizeof(brightness[0] - 1); i > 0; i--)//decrease brightness
        {
            set_brightness(brightness[i]);
            _delay_ms(300);
        }
    }
    return 0;
}