#include "delay.h"

#define button 0b00100000

volatile unsigned char *puerto_b = (unsigned char *)0x25;
volatile unsigned char *ddr_b = (unsigned char *)0x24;

void init();
void count(unsigned char counter_max_value);

int main(void) {
  init();
  unsigned char counter_max_value = 31;

  while (1) {
    count(counter_max_value);
  }
}

void init() {
  *(puerto_b) &= 0;
  *(ddr_b) |= 0b00011111;
}

void count(unsigned char counter_max_value) {
  for (char i = 0; i <= counter_max_value; i++) {
    *(puerto_b) = i;
    delay_ms(300);
  }
}