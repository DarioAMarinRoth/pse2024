#include "delay.h"
#include "utils.h"

#define trigger 1;
#define echo 2;

volatile unsigned char *puerto_b = (unsigned char *)0x25;
volatile unsigned char *ddr_b = (unsigned char *)0x24;
volatile unsigned char *pin_b = (unsigned char *)0x23;

void init();
void start_ranging();
unsigned char listening_echo();

int main(void) {
  unsigned char echo_result;
  init();

  while (1) {
    start_ranging();
    echo_result = listening_echo;
  }
}

void init() {
  *(puerto_b) &= 0;
  *(ddr_b) |= 0b00000001;
}

void start_ranging() {
  *(puerto_b) = trigger;
  delay_us(10);
  *(puerto_b) = 0;
}

unsigned char listening_echo() {}
