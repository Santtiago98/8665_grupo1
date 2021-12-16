Ejercicio 6

![image](https://user-images.githubusercontent.com/39803285/146306318-ddd9909b-4bd6-479b-9e8a-4087081d6647.png)

Se desea ingresar valores del 0 al 9 con el teclado para variar la tensión de salida del DAC. Donde el 0 corresponde con 0 V y 9 con 3.3V, que es el valor de referencia que utiliza el DAC. 

Para ello se realiza la misma configuración de interrupción rx que se utilizó en el ejercicio 3. Como se muestra a continuación.

```{c}
    // Seteo un callback al evento de recepcion y habilito su interrupcion
    uartCallbackSet(UART_USB, UART_RECEIVE, onRx, NULL);
    // Habilito todas las interrupciones de UART_USB
    uartInterrupt(UART_USB, 1);
```

Y la función que se configura para utilizar al ocurrir la excepción es
```{c}
void onRx(void *nothing){
	uint8_t data_read;
	uint8_t data_adc;
    data_read = uartRxRead( UART_USB);
    if (data_read < '0' || data_read > '9'){
    	printf("Ingrese un valor entre 0 y 9\r\n");
    	return;
    }
    printf("Valor ingresado: %i \r\n", atoi((char *)&data_read)+1);
    keyboardDAC( data_read );

    data_adc = adcRead(CH1);
    printf("Valor medido: %d \r\n", data_adc);
}
```
