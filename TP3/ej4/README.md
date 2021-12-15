# Ejercicio 4

## Enunciado

A partir del programa de ejemplo `rgb_led_uart`:
1. armar un PWM por software para disponer de distintos niveles de brillo en cada uno de los leds.
2. Por medio de la terminal serie implementada con el puerto USB de debug, asignar un caracter para incrementar y otro para
decrementar el brillo de 1 led.

## Solución

A partir de las definiciones dads en la sapi, en `sapi_pwm.c` se tiene:
```{c}
   /* PWM7 */  CTOUT2,  /* LED1   */
   /* PWM8 */  CTOUT5,  /* LED2   */
   /* PWM9 */  CTOUT4,  /* LED3   */
```

Para aumentar o disminuir los LEDs nos comunicaremos con la `EDU-CIAA` mediante `UART_USB`. La implementación se basa en definir 2 botones por LED para aumentar o dismnuir el brillo del mismo mediante un `PWM` implementado por software. 

Para esto utilizaremos el `pwm` previamente descripto, para inicializar la UART debemos utilizar el siguiente comando definiendo el baudrate.

```{c}
debugPrintConfigUart( UART_PC, baudrate );
```
Para setear una función callback para cada vez que se reciba un mensaje. Y luego habilitamos las interrupciones por `UART`.

```
uartCallbackSet(UART_PC, UART_RECEIVE, onRx, &dutyCycles);
uartInterrupt(UART_PC, 1);
```

`onRx` es nuestra función callback y `dutyCycles` pasa el parámetro que recibe esta función.

Este es un puntero a la siguiente estructura, que define el duty cycle de cada uno de los LEDs.

```{c}
typedef struct {
    uint8_t dutyCycle1; // LED 1
    uint8_t dutyCycle2; // LED 2
    uint8_t dutyCycle3; // LED 3
} dutyCycle_t;
```

El funcionamiento es simple, el programa se queda a en IDLE hasta llegar una interrupción.

Cuando llama a la función callback esta se encargar de incrementar o decrementar el dutycycle del respectivo LED.

Una vez leida la info, hay dos casos posibles para cada LED, incrementar o decrementar, esto se resuelve con el siguiente pedazo de código, asegurandonos de si supera 255 o decrece de 0, tenga un comportamiento cíclico e.g. [245 -> 255 -> 0] y así. El paso de incremento o decremento es el mismo y se setea en la macro `#define STEP`.
```{c}
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
```
Entonces, las indicaciones para utilizar el programa es cargarlo a la placa y tenerla conectada y monitoreada por terminal serie y luego utilizar los siguientes comandos.

| LED | Aumentar | Disminuir |
|:---:|:--------:|:---------:|
|  1  |    '1'   |    '2'    |
|  2  |    '3'   |    '4'    |
|  3  |    '5'   |    '6'    |