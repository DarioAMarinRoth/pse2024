
#include "adc.h"
#include "serial.h"

int main(void) {

    volatile int adc_value;

    adc_init();
    serial_init();

    while (1) {
        adc_value = adc_get(A0, REF_5V);
        serial_put_int(adc_value,3);
        serial_put_char('\r');
    }
}
