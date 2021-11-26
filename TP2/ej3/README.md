
![image](https://user-images.githubusercontent.com/39803285/143508944-201005ed-dcc2-4855-9245-7cbe790b0937.png)

a)

Al igual que se hizo en el ejercicio anterior, para realizar una compilación condicional simplemente es necesario utilizar directivas al preprocesador.

#ifdef \
... \
#endif

Para modificar el comportamiento del programa simplemente bastará con definir una macro que por medio de verificaciones condicionales podrá modificar cómo será compilado el programa.

Ejemplo:

En la siguiente captura se observa cómo mediante una macro se controla qué biblioteca será incluida y luego de la misma manera se podrá determinar que funciones utilizar en casa caso. Además, el compilar de C permite definir macros al momento de compilar haciendo uso del parámetro '-D'. \



b) Funciones utilizadas de la biblioteca __sAPI__

| Función | Descripción |  Ubicación |
| ------- | :--------: | :--------|
| tickConfig() | Inicializa el tiempo deseado para una interrupción tick | sapi_ticks.h |
