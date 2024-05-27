#include <stdint.h>

#include "operations.h"

#define USART_BAUDRATE 9600
#define BAUDRATE_PRESCALE 0b01100111
#define INIT 0b00000110
#define EN_RX_TX 0b00011000

typedef struct {
  uint8_t status_control_a;
  uint8_t status_control_b;
  uint8_t status_control_c;
  uint8_t reserved;
  uint8_t baud_rate_L;
  uint8_t baud_rate_H;
  uint8_t data_es;
} volatile uart_t;
