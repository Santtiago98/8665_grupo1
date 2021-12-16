#define SAPI_USE_INTERRUPTS

#include "sapi.h"        // <= Biblioteca sAPI

/*==================[definiciones y macros]==================================*/
#define UART_PC UART_USB
#define baudrate 115200
#define LED_ON 1
#define LED_OFF 0

#define EJ3_INTERRUPCION
/*==================[definiciones de datos internos]=========================*/

DEBUG_PRINT_ENABLE

/*==================[funcion principal]======================================*/
void keyboardLed(uint8_t data_read){

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

void onRx( void *noUsado )
{
	uint8_t data_read;
    uartReadByte( UART_PC, &data_read );
    keyboardLed(data_read);
    //data_read = '\n';
}

// FUNCION PRINCIPAL, PUNTO DE ENTRADA AL PROGRAMA LUEGO DE ENCENDIDO O RESET.
int main( void )
{

   // ---------- CONFIGURACIONES ------------------------------

   // Inicializar y configurar la plataforma
   boardConfig();

   // Inicializar UART_USB
   debugPrintConfigUart( UART_PC, baudrate );
   debugPrintlnString( "DEBUG: UART_USB configurada." );

   uint8_t data_read='\n';
   // ---------- REPETIR POR SIEMPRE --------------------------


#ifdef EJ3_INTERRUPCION
	    // Seteo un callback al evento de recepcion y habilito su interrupcion
	    uartCallbackSet(UART_PC, UART_RECEIVE, onRx, NULL);
	    // Habilito todas las interrupciones de UART_USB
	    uartInterrupt(UART_PC, 1);
	    while (TRUE ){delay(100);}
#else
	    while( TRUE ) {
	 		printf("Ingrese un caracter. \r\n");
	 		uartReadByte(UART_PC, &data_read);

			while (data_read == '\n'){
				uartReadByte(UART_PC, &data_read);
			}

			printf("Valor leido : ");
			uartWriteByte(UART_PC, data_read);
			printf("\r\n");

			keyboardLed(data_read);

			data_read = '\n';
			delay(1000);
   }
#endif


   return 0;
}
