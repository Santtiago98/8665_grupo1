Ejercicio 3


![image](https://user-images.githubusercontent.com/39803285/146280680-2041ea32-1318-443b-888e-3a34bfb115ec.png)

Primeramente debe establecerse la conexión con por medio de la _UART_PC_, para ello se utiliza la siguiente sentencia que configura la _UART_PC_ como opción de debug.

```{c}
DEBUG_PRINT_ENABLE

```

Una vez establecida la conexión será necesario leer los mensajes que allí lleguen, para ello se utiliza una función de la SAPI

```{c}
uint8_t data_read;
uartWriteByte(UART_PC, data_read);
```
Finalmente, para poder prender/apagar cada uno de los leds se establecen las siguientes relaciones

```{c}
A --> LED rojo ON
a --> LED rojo OFF
B --> LED verde ON
b --> LED verde OFF
C --> LED azul ON
c --> LED azul OFF
```

La función encargada del procesamiento es 
```{c}
void keyboardLed(uint8_t data_read)
{
		printf("Valor leido : ");
		uartWriteByte(UART_PC, data_read);
		printf("\r\n");

		switch (data_read){
		case 'A':
			gpioWrite(LEDR, LED_ON);
			break;
		case 'B':
			gpioWrite(LEDG, LED_ON);
			break;
		case 'C':
			gpioWrite(LEDB, LED_ON);
			break;
		case 'a':
			gpioWrite(LEDR, LED_OFF);
			break;
		case 'b':
			gpioWrite(LEDG, LED_OFF);
			break;
		case 'c':
			gpioWrite(LEDB, LED_OFF);
			break;
		}
}
``` 


Para lograr que el programa funcione con y sin interrupciones se realiza una compilación condicional tal como se vió en el TP2.

![image](https://user-images.githubusercontent.com/39803285/146284573-a8f86b2c-406e-498e-b59f-04cb9b1d9187.png)

De esta forma definiendo la macro EJ3_INTERRUPCION se setea el callback para configurar la interrupción por _UART_PC_. 
Y la función que se ejecutará en caso de que salte la interrupción será
```{c}
void onRx( void *noUsado )
{
	uint8_t data_read;
    uartReadByte( UART_PC, &data_read );
    keyboardLed(data_read);
}
``` 
Si no se desea trabajar con interrupciones simplemente se evita hacer la definición de dicha macro y el programa funcionará igualmente.
