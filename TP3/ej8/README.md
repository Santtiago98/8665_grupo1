# Ejercicio 8

## Solución

Para desarrollar la solución nos basamos en el `ej3.c`. En el mismo se desarrolla en torno al `UART USB`, en este ejercicio debemos agregarle comunicación contra `UART_3`. Para esto se pide que la información que reciba `UART USB` por `RX` sea también recibido por `UART_3`, dado que la función `onRx`, callback de recibir por `UART USB` ya esta implementada, queda ademas de llamar a la función que define que LED encender o apagar, escribir a `UART_3 Rx` una copia del valor recibido por `UART USB`

```{c}
void onRx( void *none )
{
	uint8_t data_read;
    uartReadByte( UART_PC, &data_read );
    keyboardLed(data_read);

	uartWriteByte(UART_3, data_read);
}
```

De esta manera, se le mandara a `UART_3` la información que reciba `UART USB`.

Además se pide que la información leida por `UART_3` sea también enviada a `UART USB`.

Se crea entonces la función de callback que llama a accionar sbre los LEDS y ademas escribe sobre `UART USB`.

```{c}
onRx_UART3(void *none){
	uint8_t data_read;
	uartReadByte( UART_3, &data_read );
	keyboardLed(data_read);
	
	uartWriteByte( UART_PC, data_read );
}
```

y en el `main` se habilitan las interrupciones por `UART_3`
```{c}
uartCallbackSet(UART_3, UART_RECEIVE, onRx_UART3, NULL);
uartInterrupt(UART_3, 1);
```