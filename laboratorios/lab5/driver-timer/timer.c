#include "timer.h"
#include <avr/io.h>
#include <stdint.h>
#include <avr/interrupt.h>

typedef struct
{
  uint8_t tccr1a;
  uint8_t tccr1b;
  uint8_t tccr1c;
  uint8_t reserved;
  uint8_t tcnt1l;
  uint8_t tcnt1h;
  uint8_t icr1l;
  uint8_t icr1h;
  uint8_t ocr1al;
  uint8_t ocr1ah;
  uint8_t ocr1bl;
  uint8_t ocr1bh;
} volatile timer1_t;

timer1_t *timer1 = (timer1_t *)0x80;

void timer_init()
{
}
