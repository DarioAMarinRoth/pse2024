#include "utils.h"

#define LED 0x20                /* 0b00100000: el bit 5 */
#define CYCLES_PER_MS 450

void led_init() {
    volatile unsigned char *DDR_B = (unsigned char *) 0x24;
    volatile unsigned char *PUERTO_B = (unsigned char *) 0x25;
    *(PUERTO_B) &= LED;
    *(DDR_B) |= LED;
}

void led_on() {
    volatile unsigned char *PUERTO_B = (unsigned char *) 0x25;
    *(PUERTO_B) |= LED;
}

void led_off() {
    volatile unsigned char *PUERTO_B = (unsigned char *) 0x25;
    *(PUERTO_B) &= ~LED;
}

void esperar() {
    int milliseconds = 500;
    volatile unsigned long cycles = (milliseconds * CYCLES_PER_MS);

    while (cycles != 0)
        cycles--;
}

int main(void) {
    led_init();

    while (1) {
        esperar();
        led_on();

        esperar();
        led_off();
    }
}


