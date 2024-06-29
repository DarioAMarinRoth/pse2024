/* PUERTOS */

#define PORTB (unsigned char *)0x25
#define DDRB (unsigned char *)0x24
#define PINB (unsigned char *)0x23

/* OPERACIONES*/
#define ON 0
#define OFF 1
#define TOGGLE 2
#define GET 3
#define WRITE 4
#define READ 5

/* MODOS */
#define INPUT 0
#define OUTPUT 1

void gpio_mode(unsigned char target, unsigned char mode) {}

unsigned char gpio(unsigned char *port, unsigned char operation,
                   unsigned char n) {
  switch (operation) {
    case ON:
      *port |= (1 << n);
      break;
    case OFF:
      *port &= ~(1 << n);
      break;
    case TOGGLE:
      *port ^= (1 << n);
      break;
    case WRITE:
      *port = n;
      break;
    case READ:
      return *port;
    case GET:
      return (*port & (1 << n)) ? 1 : 0;
  }
  return 0;
}