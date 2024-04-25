#include "delay.h"
#include "utils.h"

#define button 5

volatile unsigned char *puerto_b = (unsigned char *)0x25;
volatile unsigned char *ddr_b = (unsigned char *)0x24;

void init();
void count(unsigned char counter_max_value);
void test_button();

int main(void) {
  init();
  unsigned char counter_max_value = 31;

  while (1) {
    count(counter_max_value);
  }
}

void init() {
  *(puerto_b) &= 0;
  *(ddr_b) |= 0b00111110;
}

void count(unsigned char counter_max_value) {
  for (char i = 0; i <= counter_max_value; i++) {
    *(puerto_b) = i;
    delay_ms(300);
    test_button();
  }
}

void test_button() {
  if (is_on(button, *(puerto_b))) {
    delay_ms(10000);
    while (~is_on(button, *puerto_b)) {
    }
  }
}