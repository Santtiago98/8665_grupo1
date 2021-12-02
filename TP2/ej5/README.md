![image](https://user-images.githubusercontent.com/55199405/144501110-b9d86d35-bcea-443e-a1b7-8191c5bcd6dd.png)


a)
Nuevamente, se utilizó la misma metodólogía que se viene utilizando para la compilación condicional:


```{c}
#ifdef ej5
#include "ej5.h"
#endif ej5
```

b) Se configuró la comunicación serie como se pide en el enunciado y se escriben mensajes cuando comienza el programa mediante el puerto USB utilizando la funciones: debugPrintString( "DEBUG c/sAPI\r\n" ) y debugPrintString( "Ejercicio 5:\r\n" ).
Además, cada vez que se produce una interrupción por tick ( es decir, cada vez que se ingresa en myTickHook()), se escribe si se prendió o apagó un led de la siguiente manera: 

```{c}
void myTickHook( void *ptr )
{
   static bool_t ledState = OFF;

   gpioMap_t led = (gpioMap_t)ptr;

   if( ledState ) {
      ledState = OFF;
      debugPrintString( "LED OFF\r\n" );
   } else {
      ledState = ON;
      debugPrintString( "LED ON\r\n" );
   }
   gpioWrite( led, ledState );
}
```


c) 
| Función       | Descripción   | Biblioteca  |
| ------------- |:-------------:| -----:|
| boardConfig()   | Se encarga de inicializar todo lo necesario para la EDU-CIAA | sAPI_board.h |
| tickConfig() | Inicializa el conteo de Ticks con resolucion de 50ms | sapi_tick.h |
| tickCallbackSet() | Configura qué función se va a ejecutar cuando se produzca la interrupción del Tick (es decir el Hook) | sapi_tick.c  |
| DEBUG_PRINT_ENABLE | Es una macro de funcion que inicializa una variable estática "print_t debugPrint" la cual se utilizará para escribir en el puerto configurado| sapi_debugPrint.h|
| debugPrintConfigUart() | Configura la UART para el debug, con el baud rate especificado | sapi_debugPrint.h  |
| debugPrintString() | Imprime los mensajes de debug | sapi_debugPrint.h  |
| delay() | genera un delay de x ms | sapi_delay.c  |
| gpioWrite()  | Se encarga de escribir el registro especificado de la gpio | sapi_gpio.c | 



Los puertos utilizados son los siguientes

| Puerto  | Descripción |
| ------------- | -------------: |
| LEDR  | Puerto 75 de la EDU-CIAA  |
| LEDG  | Puerto 81 de la EDU-CIAA  |
| LEDB  | Puerto 84 de la EDU-CIAA  |
| LED1  | Puerto 104 de la EDU-CIAA  |
| LED2  | Puerto 105 de la EDU-CIAA  |
| LED3  | Puerto 106 de la EDU-CIAA | 
| U2_RXD | Puerto 115 de la EDU-CIAA|
| U2_TXD | Puerto 113 de la EDU-CIAA|

