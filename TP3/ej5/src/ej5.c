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


int main(void){

	boardConfig();
    // Inicializar UART_USB
    debugPrintConfigUart( UART_USB, 9600 );
    debugPrintlnString( "[Ej5] DEBUG: UART_USB configurada." );
    delay(500);
    ADCInit();

	volatile int16_t data_read;

	while (1){
		data_read = adcRead(CH1);
		printf("Valor leído: %d \r\n", data_read);
		delay(1000);
	}

	return 0;
}
