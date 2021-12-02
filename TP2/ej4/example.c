
#include <stdio.h>

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