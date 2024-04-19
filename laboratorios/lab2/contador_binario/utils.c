
/* utils.c - funciones de soporte al programa principal */

char is_on(char bit, char word) {
  char aux = word & (1 << bit);
  return aux == (1 << bit);
}