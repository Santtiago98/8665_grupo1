
Ejercicio 7

![image](https://user-images.githubusercontent.com/55199405/146428114-215175ab-6413-4cd6-9a67-670024c3031c.png)

Se desea prender y apagar 2 LED mediante los 4 pulsadores de la EDU-CIAA. Al presionar un botón, se enviará un caracter por el pin RX de la UART3, la señal viajará por la resistencia de loopback hacia el pin TX de la UART3 y según el valor del caracter, se prenderá o apagara algúno de los 2 LED.

Para relaizar esto, se configuraró la UART 3 para trabajar con interrupciones, y dentro de la rutina de interrupción de RX se lee el caracter que se recibió, y se pasa a la función "keyboardLed()" utilizada en el ejercicio 3 para "parsear" el mensaje y prender el led correspondiente.

```{c}
void onRx( void *noUsado )
{
    uint8_t data_read;
    uartReadByte(UART_232, &data_read );
    keyboardLed(data_read);
}
```

Además, se utilizó la UART_USB para enviar mensajes de debugging y saber qué mensajes se envían y reciben en todo momento.
