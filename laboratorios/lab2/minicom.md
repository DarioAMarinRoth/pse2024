# Configurar minicom

Para ejecutar minicom se debe usar el comando `minicom -D /dev/ttyUSB0/`

El baud rate de la biblioteca serial debe ser de 9600.

Con `ctrl-A` podemos ver cuál es la velocidad a la que está operando minicom.

## Cambiar la velocidad

1. Acceder al menú presionando `ctrl-A` y luego `Z`.
2. Presionar `O` para ingresar a la configuración.
3. Elegir la opción *Configuración del puerto serie*
4. Modificar la velocidad a 9600.
5. Desactivar la opción *control de flujo por hardware*.
6. Enter para salir de cualquier sub-menú.
7. Presionar `x` para salir del menú general.

## Observaciones

- No se puede ejecutar `make flash` si minicom se está ejecutando.

> GTkTerm es una alternativa a minicom.
> Se puede instalar el paquete gtkterm.