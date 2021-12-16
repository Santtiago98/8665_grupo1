#define SAPI_USE_INTERRUPTS

#include "sapi.h"        // <= Biblioteca sAPI

/*==================[definiciones y macros]==================================*/
#define UART_PC UART_USB
#define UART_3 UART_232
#define baudrate 115200
#define LED_ON 1
#define LED_OFF 0

//TECLA (PC) -> TERMINAL (PC) -> UART (USB).RX -> LED

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

void onRx( void *none ){
	uint8_t data_read;
    uartReadByte( UART_PC, &data_read );
    keyboardLed(data_read);

	uartWriteByte(UART_3, data_read);
}

void onRx_UART3( void *none ){
	uint8_t data_read;
	uartReadByte( UART_3, &data_read );
	keyboardLed(data_read);

	uartWriteByte( UART_PC, data_read );
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
	// Seteo un callback al evento de recepcion y habilito su interrupcion
	uartCallbackSet(UART_PC, UART_RECEIVE, onRx, NULL);
	// Habilito todas las interrupciones de UART_USB
	uartInterrupt(UART_PC, 1);

	// Seteo un callback al evento de recepcion y habilito su interrupcion
	uartCallbackSet(UART_3, UART_RECEIVE, onRx_UART3, NULL);
	// Habilito todas las interrupciones de UART_USB
	uartInterrupt(UART_3, 1);
   // ---------- REPETIR POR SIEMPRE --------------------------
   while( TRUE ) {
		printf("Ingrese un caracter. \r\n");
		uartReadByte(UART_PC, &data_read);


		delay(1000);
   }

   return 0;
}
