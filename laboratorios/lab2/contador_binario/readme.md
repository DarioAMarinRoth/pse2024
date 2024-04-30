# Contador Binario

## Armado del circuito

### Componentes necesarios

Para implementar el circuito se requieren:

- Arduino nano (x1).
- Protoboard (x1).
- Resistencias de 200 Ω. (x5).
- Resistencias de 10 kΩ (x1).
- Diodos LED (x5).
- Pulsador NA (x1).
- Cables (varios).

### Conexión a la placa

Un terminal del pulsador debe estar conectado a Vcc (+5 V). El segundo terminal debe estar conectado a GND a través de una resistencia de 10 kΩ y, en paralelo, al terminal PB5 del arduino (pin D13 normalmente - *verificar en la hoja de datos del Atmega328p*).

El terminal positivo de cada LED deberá conectarse un terminal diferente del puerto B del arduino. El código esta implementado para utilizar PB0-PB4. 