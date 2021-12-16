
/*==================[inclusions]=============================================*/
#include "sapi.h"         // <= sAPI header
#define LED_ON 1
#define LED_OFF 0

/* The DEBUG* functions are sAPI debug print functions.
Code that uses the DEBUG* functions will have their I/O routed to
the sAPI DEBUG UART. */
DEBUG_PRINT_ENABLE

void keyboardLed(uint8_t data_read){

        debugPrintString("Valor leido : ");
        uartWriteByte(UART_USB, data_read);
        debugPrintString("\r\n");

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

void onRx( void *noUsado )
{
    uint8_t data_read;
    uartReadByte(UART_232, &data_read );
    keyboardLed(data_read);
}

/* FUNCION PRINCIPAL, PUNTO DE ENTRADA AL PROGRAMA LUEGO DE RESET. */
int main(void)
{
   /* ------------- INICIALIZACIONES ------------- */

   /* Inicializar la placa */
   boardConfig();

   /* UART for debug messages. */

   debugPrintConfigUart( UART_USB, 115200 );
   debugPrintString( "DEBUG c/sAPI\r\n" );
   debugPrintString( "TP3 - Ejercicio 2:\r\n" );

   uartConfig( UART_232, 115200 );
   uartCallbackSet(UART_232,UART_RECEIVE,onRx,NULL);
   uartInterrupt(UART_232, 1);



   bool_t valor;
   bool_t imprimio = FALSE;
   /* ------------- REPETIR POR SIEMPRE ------------- */
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

   /* no debe llegar acá */
   return 1;

}
/*==================[end of file]============================================*/
