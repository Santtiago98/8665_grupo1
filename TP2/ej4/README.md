
- [Ejercicio 4](#ejercicio-4)
  - [Compilación Condicional](#compilación-condicional)
  - [Configuración tickHook](#configuración-tickhook)
  - [Configuración Toggle LEDs](#configuración-toggle-leds)
  - [Modificación multi-LEDs](#modificación-multi-LEDs)

# Ejercicio 4

Hacer portable el uso de **tickHooks** & **LEDs** c/sAPI
  1. Mediante compilación condicional, mantener en el archivo `TP2.c` los fuentes del TP2-1, TP2-2, TP2-3 y TP2-4.
  2. Documentar la modificación la configuración del tickHook en función de la constante `TICKRATE_MS` (1mS/10mS/100mS).
  3. Documentar la modificación el parpadeo del led en función de la constante `LED_TOGGLE_MS` (100mS/500mS/1000mS).
  4. Modificar ejemplo de aplicación para soportar todos los LEDs (encender/apagar -500mS/500mS- uno a la vez en secuencia).

<a name="compilación-condicional"></a>
## Compilación Condicional

Para mantener el archivo `TP2.c` los funetes de los 4 ejercicios, es necesario definir cuatro variables posibles, para utilizar en `ifdef`. Por ejemplo, 

```{c}
ifdef TP2-1
  tp2_1_source_code
else ifdef TP2-2
  tp2_2_source code
else ifdef TP2-3
  tp2_3_source code
else ifdef TP2-4
  tp2_4_source code
```

Si no, se puede definir una única variable:
```{c}
int main (void){

    #if EJERCICIO == 1
    printf("Ejercicio 1\n");
    #elif EJERCICIO == 2
    printf("Ejercicio 2\n");
    #elif EJERCICIO == 3
    printf("Ejercicio 3\n");
    #elif EJERCICIO == 4
    printf("Ejercicio 4\n");
    #endif

    return 0;
}
```
Como ejemplo rápido, correr `gcc -D EJERCICIO=n example.c`.

<a name="configuración-tickhook"></a>
## Configuración tickHook

A través de definir la macro `TICKRATE_MS`, y luego llamar a `tickConfig(TICKRATE_MS)` se setea la cantidad de ticks por segundo. Es decir, definimos, a que unidad de tiempo corresponde un tick del `sysTick`.

En el siguiente ejemplo, 1 tick correspondería a un milisegundo.

```{c}
#define TICKRATE_1MS	(1)	
#define TICKRATE_MS		(TICKRATE_1MS)	/* 1000 ticks per second */

int main (void){
    tickConfig( TICKRATE_MS );
}

```

Así podemos definir cualquier otro caso, por ejemplo, si `TICKRATE_MS=10` entonces cada tick correspondería a 10 milisegundos, lo mismo con 100.

## Configuración Toggle LEDs (`LED_TOGGLE_MS`)

`#define LED_TOGGLE_MS n`

Donde n es el valor en milisegundos del delay a buscar, luego entre led off y led on se usa el delay configurado a esta cantidad de milisegundos. Por ejemplo:

```{c}
#define LED_TOGGLE_MS 100

int main(void){
    
    while(1){
        /* Prendo el led azul */
        gpioWrite( LEDB, ON );

        delay(LED_TOGGLE_MS);

        /* Apago el led azul */
        gpioWrite( LEDB, OFF );

        delay(LED_TOGGLE_MS);
    }

    return 0; # no deberia llegar aca nunca
}
```

## Modificación multi-LEDs

Para hacer una secuencia de encendido de leds cada 500 milisegundos:

```{c}
#define LED_TOGGLE_MS 500

int main(void){
    int i = 1;
    while (1){
        /* Prendo el led LEDR+i */
        gpioWrite( LEDR + i, ON );

        delay(LED_TOGGLE_MS);

        /* Apago el led LEDR+i */
        gpioWrite( LEDR + i, OFF );

        delay(LED_TOGGLE_MS);

        i += 1;

        if (i == 5){
            i = 1;
        }
        }

    return 0; # no deberia llegar aca nunca
}
```
De esta manera se cumpliría en cada iteración:

`i = 0` : Toggle LED R\
`i = 1` : Toggle LED G\
`i = 2` : Toggle LED B\
`i = 3` : Toggle LED 1\
`i = 4` : Toggle LED 2\
`i = 5` : Toggle LED 3\

Y así ad-infinitum.
 