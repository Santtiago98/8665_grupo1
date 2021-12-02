
### Ejercicio 2

![image](https://user-images.githubusercontent.com/39803285/143321978-c4de282e-8002-4987-9d2b-dde3cfccdd0b.png)

a) 

Para realizar una compilación condicional simplemente es necesario utilizar directivas al preprocesador.

```{c}
#ifdef
  ...
#endif
```

Para modificar el comportamiento del programa simplemente bastará con definir una macro que por medio de verificaciones condicionales podrá modificar cómo será compilado el programa.

Ejemplo:

En la siguiente captura se observa cómo mediante una macro se controla qué biblioteca será incluida y luego de la misma manera se podrá determinar que funciones utilizar en casa caso. Además, el compilar de C permite definir macros al momento de compilar haciendo uso del parámetro '-D'. \
![image](https://user-images.githubusercontent.com/39803285/143321426-02697fad-69f7-4578-9ccf-47640f36f64b.png)


b)

A continuación se muestra la secuencia de funciones que invoca el programa __switches_leds.c__

![image](https://user-images.githubusercontent.com/39803285/143322016-e4823375-0de3-4b9d-80b2-e88b0ee6b66f.png)

| Función       | Descripción   | Biblioteca  |
| ------------- |:-------------:| -----:|
| boardConfig()   | Se encarga de inicializar todo lo necesario para la EDU-CIAA | sAPI_board.h |
| delayConfig() | Configura el tiempo de delay que se utilizará luego | sapi_delay.h |
| delayRead() | Retornará TRUE cuando se cumpla el tiempo de delay especificado | sapi_delay.c  |
| gpioWrite()  | Se encarga de escribir el registro especificado de la gpio | sapi_gpio.c | 


Los puertos utilizados son los siguientes

| Puerto  | Descripción |
| ------------- | -------------: |
| LEDB  | Puerto 84 de la EDU-CIAA  |
| LED3  | Puerto 106 de la EDU-CIAA | 

Puerto del LEDB \
![image](https://user-images.githubusercontent.com/39803285/143323141-a99f9a86-98a4-4f71-b43b-80ba19d56542.png)

Puerto del LED3 \
![image](https://user-images.githubusercontent.com/39803285/143323167-1177b13d-211d-4100-a36e-5c5fc600f1c0.png)

