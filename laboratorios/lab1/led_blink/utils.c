
/* utils.c - funciones de soporte al programa principal */

/* Enciende y apaga un led conectado al puerto B bit 5 de un atmega328p
 * El puerto B de un atmega328p tiene los bits 0-5 mapeados a los 
 * pines 8-13 de arduino 
 */



#define LED 0x20                /* 0b00100000: el bit 5 */

/* puertos de E/S */

/* direccion de PORTB (registro de datos) */
volatile unsigned char * puerto_b = (unsigned char *) 0x25;

/* direccion de DDR B (registro de control) */
volatile unsigned char * ddr_b = (unsigned char *) 0x24;

/* direccion PIN B (registro de datos de entrada) */
volatile unsigned char * pin_b = (unsigned char *) 0x23;


void esperar() {
	volatile unsigned long i;
	/* delay de aprox. 1 segundo */
	for (i=0; i<450000; i++);
}

/* led_init: configura el puerto b bit 5 como salida */
void led_init() {
    volatile unsigned char *DDR_B = (unsigned char *) 0x24;
    volatile unsigned char *PUERTO_B = (unsigned char *) 0x25;
    *(PUERTO_B) &= LED;
    *(DDR_B) |= LED;
}

/* led_on: enciende el led conectado al puerto b bit 5 */
void led_on() {
    volatile unsigned char *PUERTO_B = (unsigned char *) 0x25;
    *(PUERTO_B) |= LED;
}

/* led_off: apaga el led conectado al puerto b bit 5 */
void led_off() {
    volatile unsigned char *PUERTO_B = (unsigned char *) 0x25;
    *(PUERTO_B) &= ~LED;
}
