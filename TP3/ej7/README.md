
Ejercicio 7

![image](https://user-images.githubusercontent.com/55199405/146428114-215175ab-6413-4cd6-9a67-670024c3031c.png)

Se desea prender y apagar 2 LED mediante los 4 pulsadores de la EDU-CIAA. Al presionar un botón, se enviará un caracter por el pin RX de la UART3, la señal viajará por la resistencia de loopback hacia el pin TX de la UART3 y según el valor del caracter, se prenderá o apagara algúno de los 2 LED.

Para relaizar esto, cada vez que se presiona un botón se envía un mensaje mediante la UART3 con el caracter asociado al botón.
```{c}
while(1) {

	   	  valor = !gpioRead( TEC1 );
	      while(valor == TRUE){
	    	  if(imprimio == FALSE){
	    		  debugPrintString( "pulse A\r\n" );
	    		  uartWriteByte(UART_232, 'A');
	    		  imprimio = TRUE;
	    	  }
	    	  valor = !gpioRead(TEC1);
	      }


	   	  valor = !gpioRead( TEC2 );
	      while(valor == TRUE){
	    	  if(imprimio == FALSE){
	    		  debugPrintString( "pulse a\r\n" );
	    		  uartWriteByte(UART_232, 'a');
	    		  imprimio = TRUE;

	    	  }
	    	  valor = !gpioRead(TEC2);
	      }

	   	  valor = !gpioRead( TEC3 );
	      while(valor == TRUE){
	    	  if(imprimio == FALSE){
	    		  debugPrintString( "pulse B\r\n" );
	    		  uartWriteByte(UART_232, 'B');
	    		  imprimio = TRUE;
	    	  }
	    	  valor = !gpioRead(TEC3);
	      }

	   	  valor = !gpioRead( TEC4 );
	      while(valor == TRUE){
	    	  if(imprimio == FALSE){
	    		  debugPrintString( "pulse b\r\n" );
	    		  uartWriteByte(UART_232, 'b');
	    		  imprimio = TRUE;
	    	  }
	    	  valor = !gpioRead(TEC4);
	      }

	      imprimio = FALSE;

   }

```

Por otro lado, se configuraró la UART 3 para trabajar con interrupciones, y dentro de la rutina de interrupción de RX se lee el caracter que se recibió, y se pasa a la función "keyboardLed()" utilizada en el ejercicio 3 para "parsear" el mensaje y prender el led correspondiente.

```{c}
void onRx( void *noUsado )
{
    uint8_t data_read;
    uartReadByte(UART_232, &data_read );
    keyboardLed(data_read);
}
```

Además, se utilizó la UART_USB para enviar mensajes de debugging y saber qué mensajes se envían y reciben en todo momento.
