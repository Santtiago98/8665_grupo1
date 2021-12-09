/* Copyright 2016, Eric Pernia.
 * All rights reserved.
 *
 * This file is part sAPI library for microcontrollers.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

/*
 * Date: 2016-07-03
 */

/*==================[inclusions]=============================================*/

#include "sapi.h"    // <= sAPI header

/*==================[definiciones y macros]==================================*/
#define UART_PC UART_USB
#define baudrate 115200
// #define LED_ON 1
// #define LED_OFF 0
/*==================[internal data declaration]==============================*/

typedef struct {
    uint8_t  dutyCycle1; // LED 1
    uint8_t dutyCycle2; // LED 2
    uint8_t dutyCycle3; // LED 3
} dutyCycle_t;

/*==================[internal functions declaration]=========================*/
void onRx( void * dutyCycles )
{
	uint8_t data_read;
   uartReadByte( UART_PC, &data_read );
   printf("Valor leido : ");
   uartWriteByte(UART_PC, data_read);
   printf("\r\n");
   callback(data_read, dutyCycles);
   switch (data_read){
      case '1':
         aux = (uint16_t) (dutyCycles->dutyCycle1);
         aux += 1;
         if( aux > 255 )
            aux = 0;
         pwmWrite( PWM7, aux );
         
      break;
      case '2':
         aux = (uint16_t) (dutyCycles->dutyCycle1);
         aux -= 1;
         if( aux < 0 )
            aux = 255;
         pwmWrite( PWM7, aux );
      break;
   }

    //data_read = '\n';
}

/*==================[definiciones de datos internos]=========================*/

DEBUG_PRINT_ENABLE
/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/

/* FUNCION PRINCIPAL, PUNTO DE ENTRADA AL PROGRAMA LUEGO DE RESET. */
int main(void){

   /* ------------- INICIALIZACIONES ------------- */

   /* Inicializar la placa */
   boardConfig();

   /* UART Config */
   debugPrintConfigUart( UART_PC, baudrate );
   debugPrintlnString( "DEBUG: UART_USB configurada." );

   /* 0 a 255 */ 
   dutyCycle_t dutyCycles {
      uint8_t  dutyCycle1 = 0; // LED 1
      uint16_t dutyCycle2 = 0; // LED 2
      uint16_t dutyCycle3 = 0; // LED 3
   };

   // Seteo un callback al evento de recepcion y habilito su interrupcion
   uartCallbackSet(UART_PC, UART_RECEIVE, onRx, &dutyCycles);
   // Habilito todas las interrupciones de UART_USB
   uartInterrupt(UART_PC, 1);


   // uint8_t pwmVal = 0; /* 0 a 255 */
   
   /* Configurar PWM */
   valor = pwmConfig( 0, PWM_ENABLE );

   valor = pwmConfig( PWM7, PWM_ENABLE_OUTPUT );
   valor = pwmConfig( PWM8, PWM_ENABLE_OUTPUT );
   valor = pwmConfig( PWM9, PWM_ENABLE_OUTPUT );

   /* Usar PWM */
   valor = pwmWrite( PWM7, dutyCycle1 );
   valor = pwmWrite( PWM8, dutyCycle2 );
   valor = pwmWrite( PWM9, dutyCycle3 );
   

   /* ------------- PROGRAMA PRINCIPAL ------------- */
   while(1) {
      // valor = !gpioRead( TEC1 );
      // gpioWrite( LEDB, valor );

      // if( delayRead(&delayBase1) )
      //    dutyCycle1++;
      // if( dutyCycle1>255 )
      //    dutyCycle1 = 0;
      // pwmWrite( PWM7, dutyCycle1 );

      // if( delayRead(&delayBase2) )
      //     dutyCycle2 += 25;
      // if( dutyCycle2>255 )
      //    dutyCycle2 = 0;
      // pwmWrite( PWM8, (uint8_t)dutyCycle2 );

      // if( delayRead(&delayBase3) )
      //     dutyCycle3 += 50;
      // if( dutyCycle3>255 )
      //    dutyCycle3 = 0;
      // pwmWrite( PWM9, (uint8_t)dutyCycle3 );

   }

   /* NO DEBE LLEGAR NUNCA AQUI, debido a que a este programa no es llamado
      por ningun S.O. */
   return 0 ;
}

/*==================[end of file]============================================*/
