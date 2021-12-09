# Ejercicio 4

As defined in `sapi_pwm.c`
```{c}
   /* PWM7 */  CTOUT2,  /* LED1   */
   /* PWM8 */  CTOUT5,  /* LED2   */
   /* PWM9 */  CTOUT4,  /* LED3   */
```

Para aumentar o disminuir los LEDs se debe comunicar via `UART_USB` se tienen los siguientes comandos.

| LED | Aumentar | Disminuir |
|:---:|:--------:|:---------:|
|  1  |    '1'   |    '2'    |
|  2  |    '3'   |    '4'    |
|  3  |    '5'   |    '6'    |