
/* utils.c - funciones de soporte al programa principal */

unsigned char is_on(unsigned char bit, volatile unsigned char word) {
    unsigned char aux = word & (1 << bit);
  return aux == (1 << bit);
}

void pull_up_bit(char bit, volatile unsigned char *reg) { *reg |= (1 << bit); }

void pull_up_bits(unsigned char bits, volatile unsigned char *reg) {
  *(reg) |= bits;
}

void pull_down_bit(char bit, volatile unsigned char *reg) {
  *reg &= (0xFE << bit);
}

void pull_down_bits(unsigned char bits, volatile unsigned char *reg) {
  *(reg) &= ~bits;
}