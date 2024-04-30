
/* utils.h - funciones de soporte al programa principal */

#ifndef _UTILS_H
#define _UTILS_H

unsigned char is_on(char bit, unsigned char word);
void pull_up_bit(char bit, volatile unsigned char *reg);
void pull_up_bits(unsigned char bits, volatile unsigned char *reg);
void pull_down_bit(char bit, volatile unsigned char *reg);
void pull_down_bits(unsigned char bits, volatile unsigned char *reg);

#endif /* _UTILS_H */
