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

unsigned char gpio(unsigned char *port, unsigned char operation,
                   unsigned char n) {
  switch (operation) {
    case ON:
      set_bit(port, n);
      break;
    case OFF:
      clear_bit(port, n);
      break;
    case TOGGLE:
      toggle_bit(port, n);
      break;
    case WRITE:
      write_bits(port, n);
      break;
    case READ:
      return *port;
    case GET:
      return get_bit(port, n);
  }
  return 0;
}

unsigned char get_bit(unsigned char *reg, unsigned char n) {
  return (*reg & (1 << n)) ? 1 : 0;
}

void set_bit(unsigned char *reg, char n) { *reg |= (1 << n); }

void clear_bit(unsigned char *reg, char n) { *reg &= ~(1 << n); }

void toggle_bit(unsigned char *reg, unsigned char n) { *reg ^= (1 << n); }

void write_bits(unsigned char *reg, unsigned char n) { *reg = n; }