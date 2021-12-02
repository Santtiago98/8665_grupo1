### Ejercicio 6

![image](https://user-images.githubusercontent.com/55199405/144509071-4d0d0944-126c-4fa3-93f3-c928d198e318.png)


a)
Nuevamente, se utilizó la misma metodólogía que se viene utilizando para la compilación condicional:


```{c}
#ifdef ej6
#include "ej6.h"
#endif ej6
```

b) La función que se utiliza para leer los pulsadores es gpioRead(). Los pines de gpio que se quieran utilizar deben estar configurados mediante gpioConfig() como "GPIO_INPUT" para poder utilizarlos como entrada.


c) Para poder soportar todos los led se pueden utilizar pines de gpio extra como entradas con pulsadores extra, o se pueden utilizar los 4 pulsadores en estilo binario para lograr encender todos mediante combinaciones de pulsadores. Por ejemplo, TEC1 -> LEDR, TEC2->LEDG, TEC1+TEC2 -> LEDB, TEC3-> LED1, TEC3+TEC1-> LED2, TEC3+TEC2 -> LED3.

Esto se hace mediante la funcion gpioRead() y el operador AND.
