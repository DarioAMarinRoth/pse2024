#include "delay.h"
#include "serial.h"
#include "utils.h"

#define TRIGGER 1
#define ECHO 2
#define TIME_DISTANCE_RELATION 58
#define TIME_OUT_US 360000

volatile unsigned char *puerto_b = (unsigned char *)0x25;
volatile unsigned char *ddr_b = (unsigned char *)0x24;
volatile unsigned char *pin_b = (unsigned char *)0x23;

void ports_init();
void start_ranging();
unsigned int listening_echo();

int main(void) {
  unsigned int echo_time_us;
  float distance_cm = 0;
  unsigned int integer_digits = 2;
  unsigned int decimal_digits = 3;

  ports_init();
  serial_init();
  serial_put_str("Iniciando \r\n");

  while (1) {
    start_ranging();
    echo_time_us = listening_echo();
    distance_cm = ((float)(echo_time_us)) / TIME_DISTANCE_RELATION;

    serial_put_str("Distancia en cm: \r\n");
    serial_put_double(distance_cm, integer_digits, decimal_digits);
    serial_put_str("\r\n");

    delay_us(20);
  }
}

void ports_init() {
  *(puerto_b) &= 0;
  *(ddr_b) |= 0b00000001;
}

void start_ranging() {
  pull_up_bit(TRIGGER, puerto_b);
  delay_us(10);
  pull_down_bit(TRIGGER, puerto_b);
}

unsigned int listening_echo() {
  unsigned int echo_time_us = 0;
  serial_put_str("Echo pin en off \r\n");
  while (!is_on(ECHO, *pin_b)) {
  }
  serial_put_str("Echo pin en on\r\n");
  while (is_on(ECHO, *pin_b)) {
    delay_us(10);
    echo_time_us += 10;
    if (echo_time_us == TIME_OUT_US) {
      serial_put_str("FUERA DE RANGO: \r\n");
      break;
    }
  }
  return echo_time_us;
}
