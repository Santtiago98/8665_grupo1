#include "sapi.h"

DEBUG_PRINT_ENABLE


#define _ADC_CHANNEL ADC_CH1
#define _LPC_ADC_ID LPC_ADC0
static ADC_CLOCK_SETUP_T ADCSetup;


int ADCInit(){
	//Board_ADC_Init();
	/*Inicializar el ADC en el canal correcto*/
	Chip_ADC_Init(_LPC_ADC_ID, &ADCSetup);
	ADCSetup.burstMode = false;
	Chip_ADC_EnableChannel(_LPC_ADC_ID, _ADC_CHANNEL, ENABLE);
	Chip_ADC_SetResolution(_LPC_ADC_ID, &ADCSetup, ADC_10BITS);
	Chip_ADC_SetSampleRate(_LPC_ADC_ID, &ADCSetup, 100000);

	return 0;
}

void keyboardDAC(uint8_t data_read){
	uint16_t aux;
	aux = atoi((char *)&data_read) *1023/9;
	dacWrite(DAC, aux);
	printf("Valor enviado: %ld \r\n", aux);
	//delay(600);
}


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


int main(void){

	boardConfig();
    // Inicializar UART_USB
    debugPrintConfigUart( UART_USB, 9600 );
    debugPrintlnString( "[Ej6] DEBUG: UART_USB configurada." );
    delay(500);
    ADCInit();
    dacConfig( DAC_ENABLE ); /* DAC */

    // Seteo un callback al evento de recepcion y habilito su interrupcion
    uartCallbackSet(UART_USB, UART_RECEIVE, onRx, NULL);
    // Habilito todas las interrupciones de UART_USB
    uartInterrupt(UART_USB, 1);

	volatile int16_t data_read;

	while (1){
		//data_read = adcRead(CH1);

		delay(1000);
	}

	return 0;
}
