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
#define STEP 50
// #define LED_ON 1
// #define LED_OFF 0
/*==================[internal data declaration]==============================*/

typedef struct {
    uint8_t dutyCycle1; // LED 1
    uint8_t dutyCycle2; // LED 2
    uint8_t dutyCycle3; // LED 3
} dutyCycle_t;

/*==================[internal functions declaration]=========================*/
void onRx( void * dutyCycles )
{
   dutyCycle_t * dutyCycles2 = (dutyCycle_t *) dutyCycles;
   uint8_t data_read;
   uartReadByte( UART_PC, &data_read );
   printf("Valor leido : %d \r\n", data_read);
   //uartWriteByte(UART_PC, data_read);
   //printf("\r\n");
   int16_t aux;
   switch (data_read){
      case '1':
         aux = (int16_t) (dutyCycles2->dutyCycle1);
         aux += STEP;
         if( aux > 255 ){
            aux = 0;
         }
         pwmWrite( PWM7, (uint8_t)aux );
         dutyCycles2->dutyCycle1 = (uint8_t)aux;

      break;
      case '2':
         aux = (int16_t) (dutyCycles2->dutyCycle1);
         aux -= STEP;
         if( aux < 0 ){
            aux = 255;
         }
         pwmWrite( PWM7, (uint8_t)aux );
         dutyCycles2->dutyCycle1 = (uint8_t)aux;
      break;

      case '3':
         aux = (int16_t) (dutyCycles2->dutyCycle2);
         aux += STEP;
         if( aux < 0 ){
            aux = 255;
         }
         pwmWrite( PWM8, (uint8_t)aux );
         dutyCycles2->dutyCycle2 = (uint8_t)aux;
      break;

      case '4':
         aux = (int16_t) (dutyCycles2->dutyCycle2);
         aux -= STEP;
         if( aux < 0 ){
            aux = 255;
         }
         pwmWrite( PWM8, (uint8_t)aux );
         dutyCycles2->dutyCycle2 = (uint8_t)aux;
      break;
      case '5':
         aux = (int16_t) (dutyCycles2->dutyCycle2);
         aux += STEP;
         if( aux < 0 ){
            aux = 255;
         }
         pwmWrite( PWM8, (uint8_t)aux );
         dutyCycles2->dutyCycle2 = (uint8_t)aux;
      break;

      case '6':
         aux = (int16_t) (dutyCycles2->dutyCycle2);
         aux -= STEP;
         if( aux < 0 ){
            aux = 255;
         }
         pwmWrite( PWM8, (uint8_t)aux );
         dutyCycles2->dutyCycle2 = (uint8_t)aux;
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

   /* inicializo dutyCycles */
   dutyCycle_t dutyCycles;

   dutyCycles.dutyCycle1 = 0;
   dutyCycles.dutyCycle2 = 0;
   dutyCycles.dutyCycle3 = 0;

   // Seteo un callback al evento de recepcion y habilito su interrupcion
   uartCallbackSet(UART_PC, UART_RECEIVE, onRx, &dutyCycles);
   // Habilito todas las interrupciones de UART_USB
   uartInterrupt(UART_PC, 1);

   /* Configurar PWM */
   pwmConfig( 0, PWM_ENABLE );
   pwmConfig( PWM7, PWM_ENABLE_OUTPUT );
   pwmConfig( PWM8, PWM_ENABLE_OUTPUT );
   pwmConfig( PWM9, PWM_ENABLE_OUTPUT );

   /* Usar PWM */
   pwmWrite( PWM7, dutyCycles.dutyCycle1 );
   pwmWrite( PWM8, dutyCycles.dutyCycle2 );
   pwmWrite( PWM9, dutyCycles.dutyCycle3 );


   /* ------------- PROGRAMA PRINCIPAL ------------- */
   while(1) {

   }

   /* NO DEBE LLEGAR NUNCA AQUI, debido a que a este programa no es llamado
      por ningun S.O. */
   return 0 ;
}

/*==================[end of file]============================================*/
