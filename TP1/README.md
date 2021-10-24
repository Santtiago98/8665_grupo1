# Trabajo Práctico 1

## Sistemas Embebidos - 2C2021 - Grupo 1

|       Integrante       | Padrón |        Mail        |
|:----------------------:|:------:|:------------------:|
|     Aupi, Santiago     |   100793  |   saupi@fi.uba.ar  |
| Piperno, Ignacio Tomás | 100677 | ipiperno@fi.uba.ar |
|    Rossi, Francisco    |  99540 |  frrossi@fi.uba.ar |

## Índice

- [Trabajo Práctico 1](#trabajo-práctico-1)
  - [Sistemas Embebidos - 2C2021 - Grupo 1](#sistemas-embebidos---2c2021---grupo-1)
  - [Índice](#índice)
- [Resumen](#resumen)
- [Funciones auxiliares](#funciones-auxiliares)
  - [TECX](#tecx)
  - [main_region](#main_region)
- [Ejercicio 3](#ejercicio-3)
- [Ejercicio 4](#ejercicio-4)
- [Ejercicio 5](#ejercicio-5)
- [Ejercicio 6](#ejercicio-6)
- [Ejercicio 7](#ejercicio-7)
- [Ejercicio 8](#ejercicio-8)


# Resumen

En este repositorio se desarrollará el trabajo práctico numero 1 de la materia 86.65 - Sistemas Embebidos, FIUBA. El mismo consiste de 6 ejercicios, cuyas resoluciones podrán encontrar en este repositorio. En este informe desarrollaremos la explicación de cada uno de los ejercicios.

# Funciones auxiliares

En los diferentes ejercicio desarrollados, utilizaremos dos bloques de maquina de estados ya desarrollada, que nos permiten interactuar con el programa mediante la botonera de la placa `EDU-CIAA-NXP`.

## TECX

Este pedazo de codigo nos permite detectar si un pulsador es accionado, tiene un debouncer incorporado y nos de vuelve un valor determinador dependiendo de que pulsador es el que disparo el evento.

|    TEC4   |    TEC3   |    TEC2   |    TEC1   |
|:---------:|:---------:|:---------:|:---------:|
| 8 [b1000] | 4 [b0100] | 2 [b0010] | 1 [b0001] |

El diagrama de la maquina de estados es:

![docs/images/TECX.png](docs/images/TECX.png)

## main_region

En la `main_region` tenemos el "handle" de los eventos dados por TECX, donde dependiendo del ejercicio que estemos resolviendo cambiara levemente, pero fundamentalmente se define que hacer para cada uno de los pulsadores, a continuacion, como ejemplo podemos ver `main_region` del [Ejercicio 5](#ejercicio-5)

![docs/images/main_region.png](docs/images/main_region.png)

# Ejercicio 3

> Implementar (editar, simular y generar el código) el modelo de control de Panel de Control de un generador de señales (tensión de 0 a
10V, frecuencia de 20 a 20.000Hz y 3 formas de señal).
>
> 1. Editar y simular
> 2. Generación de código

# Ejercicio 4

> Implementar (editar, simular y generar el código) el modelo de control de Puerta Corrediza automatizada (motor con movimiento en dos
sentidos, sensor de presencia y fines de carrera)
>
> 1. Editar y simular
> 2. Generación de código

# Ejercicio 5

> Implementar (editar, simular y generar el código) el modelo de control de Portón Levadizo automatizado (motor con movimiento en dos
sentidos, control remoto de apertura/cierre, fines de carrera y señalización luminosa)
>
> 1. Editar y simular
> 2. Generación de código

Autor: Francisco Rossi

***
Codigo fuente: [ej5](ej5)

Teniendo en cuenta el enunciado se definen los siguientes eventos:

1. `evCerrarPorton`:
    El mismo define el evento de indicar con el control remoto que se cierre la puerta.

2. `evAbrirPorton`
    Este se define al igual que el anterior, pero cuando se indicar de abrir la puerta.

3. `evFinalCarrera`
    Este evento indica que se detecto un final de carrera, puede ser tanto el de subida como el de bajada.

4. `evObstaculo`
    Est evento indica que existe un obstaculo, si bien no estaba en el enunciado, por la seguridad del mismo lo agregamos al diseno.

Luego, se definen 5 estados, los nombres de los mismos son autoexplicativos:

1. **Cerrado**
2. **Abierto**
3. **Abriendo**
4. **Cerrando**
5. **Parado**, en este caso vale la pena decir que se trata de un punto medio entre abierto y cerrado (en caso de obstaculo).

La **maquina de estados** puede observarse en la siguiente figura:
![docs/images/ej5_program.png](docs/images/ej5_program.png)

Por simplicidad se elije que un mismo evento abre o cierre el porton (un solo boton del control remoto), dependiendo del estado en el que este justo antes de presionarlo.

El programa, inicia en estado cerrado, hasta que se le de la indicacion de abrir y este entonces procedera abrirse (es decir, hasta que se detecte el final de carrera superior), en caso de que haya un obstaculo, se enviara una senal al porton para frenar y se esperar 1s para retomar la accion y asi sucesivamente hasta que no exista mas el obstaculo. Una vez que esta abierto sucede lo equivalente para cerrarse.

Las siguientes funciones son las ejecutadas al ingresar en cada uno de los estados. De esta manera se inician las acciones de abrir, cerrar o de parar el porton, segun corresponda.

```c
void ej5_opAbrirPorton(Ej5* handle, const sc_integer PortNumber){
  gpioWrite(LED1, true);
  //accionarMotor(arriba)
}
void ej5_opCerrarPorton(Ej5* handle, const sc_integer PortNumber){
  gpioWrite(LED2, true);
  //accionarMotor(abajo)
}
void ej5_opPararPorton(Ej5* handle, const sc_integer PortNumber){
  gpioWrite(LED3, true);
  //accionarMotor(frenar)
}
```

En este caso solo se estan llevando a cabo la senalizacion de los LEDS. Pero, en caso de tener realmente el motor, se accionaria el mismo correspondientemente (a esto refiere `accionarMotor()`).

# Ejercicio 6

> Implementar (editar, simular y generar el código) el modelo de control de Escalera Mecánica unidireccional automatizada (motor
c/movimiento en un sentido y dos velocidades, sensores de ingreso, egreso y señalización luminosa)
>
> 1. Editar y simular
> 2. Generación de código

# Ejercicio 7

> Implementar (editar, simular y generar el código) el modelo de control de Horno Microondas (3 modos de cocción seleccionable por
botón de modo, botón de comenzar/terminar y sensor de apertura de puerta)
>
> 1. Editar y simular
> 2. Generación de código

# Ejercicio 8

>Implementar (editar, simular) el modelo de control de xxxx xxxx (dicho modelo debe ser una parte de la implementación de su TPF)
>
> 1. Editar y simular
> 2. Generación de código
