# Ejercicio 5

Agregar al ejemplo anterior (4.d) envío de mensajes de depuración por puerto serie c/sAPI
    a. Mediante compilación condicional, mantener en el archivo TP1.c los fuentes del TP1-1, TP1-2, TP1-3, TP1-4 y TP1-5
    b. Para usar UART2 como interfaz de DEBUG, instalar y ejecutar en su PC un programa de terminal comunicación serie, p/e Putty y
    el driver del chip U6 FT2232-H (conversor USB-Serie) DEBUG:
        i. Los pasos son: Habilitar - Configurar - Invocar la funcionalidad
        /* The DEBUG* functions are sAPI debug print functions.
         Code that uses the DEBUG* functions will have their I/O routed to
         the sAPI DEBUG UART. */

        DEBUG_PRINT_ENABLE;

        /* UART for debug messages. */
        debugPrintConfigUart( UART_USB, 115200 );
        debugPrintString( "DEBUG c/sAPI\r\n" );
        debugPrintString( "LED Toggle\n" );

    c. Identificar funciones de librería sAPI útiles para esta nueva funcionalidad
        i. Documentar mediante tablas c/texto e imágenes la secuencia de funciones invocadas durante la ejecución del
        ejemplo de aplicación, en qué archivo se encuentran, su descripción detallada, qué efecto tiene la aplicación sobre el
        hardware (identificar circuitos, puertos, pines, niveles, etc.) así como la interacción entre las mismas (tanto en
        ResetISR() como en main())
        ii. Idem c pero con datos (definiciones, constantes, variables, estructuras, etc.) (tanto en ResetISR() como en main())
