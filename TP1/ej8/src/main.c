/*==================[inclusions]=============================================*/

#include "main.h"
#include "sapi.h"       // <= sAPI header

/* Include statechart header file. Be sure you run the statechart C code
 * generation tool!
 */
#include "EscaleraMecanica.h"
#include "TimerTicks.h"


/*==================[macros and definitions]=================================*/

#define TICKRATE_1MS	(1)				/* 1000 ticks per second */
#define TICKRATE_MS		(TICKRATE_1MS)	/* 1000 ticks per second */


/*==================[internal data declaration]==============================*/

volatile bool SysTick_Time_Flag = false;

/*! This is a state machine */
static EscaleraMecanica statechart;

/*! This is a timed state machine that requires timer services */
#define NOF_TIMERS (sizeof(EscaleraMecanicaTimeEvents)/sizeof(sc_boolean))

TimerTicks ticks[NOF_TIMERS];


/*==================[external functions definition]==========================*/

/*! Esta funcion para o prende la escalera (en este caso apaga y prende el LEDR y el LEDG).
 *  @param handle instancia de máquina de estados
 *  @param state estado anterior de la escalera
 */
void escaleraMecanicaIface_opSetLight(const EscaleraMecanica* handle, const sc_boolean state)
{

	if(state == false){
		gpioWrite( (LEDG), false);
		gpioWrite( (LEDR), true );
		// apaga el motor
	}
	else{
		gpioWrite( (LEDR), false);
		gpioWrite( (LEDG), true);
		// enciende el motor

	}

}

/*! Esta funcion cambia la velocidad del motor.
 *  @param handle instancia de máquina de estados
 *  @param speed  opción de velocidad
 */
void escaleraMecanicaIface_opSetSpeed(const EscaleraMecanica* handle, const sc_integer speed)
{
	if(speed == SPEED_1){
		gpioWrite( (LEDR+3), true);
		gpioWrite( (LEDR+4), false);
		// motor a velocidad 1
	}
	if(speed == SPEED_2){
		gpioWrite( (LEDR+3), false);
		gpioWrite( (LEDR+4), true);
		// motor a velocidad 2
	}

}

void escaleraMecanicaIface_opCount(const EscaleraMecanica* handle, const sc_integer counter, const sc_boolean last)
{
}

/*! \file This header defines prototypes for all functions that are required
 *  by the state machine implementation.
 *
 *  This is a state machine uses time events which require access to a timing
 *  service. Thus the function prototypes:
 *  - escaleraMecanica_setTimer and
 *  - escaleraMecanica_unsetTimer
 *  are defined.
 *
 *  This state machine makes use of operations declared in the state machines
 *  interface or internal scopes. Thus the function prototypes:
 *  - escaleraMecanicaIface_opLED
 *  are defined.
 *
 *  These functions will be called during a 'run to completion step' (runCycle)
 *  of the statechart.
 *  There are some constraints that have to be considered for the
 *  implementation of these functions:
 *  - never call the statechart API functions from within these functions.
 *  - make sure that the execution time is as short as possible.
 */

/** state machine user-defined external function (action)
 *
 * @param handle state machine instance
 * @param LEDNumber number of LED
 * @param onoff state machine operation parameter
 */


void escaleraMecanicaIface_opLED( EscaleraMecanica* handle, sc_integer LEDNumber, sc_boolean State )
{
	gpioWrite( (LEDR + LEDNumber), State );
}


/*! * This is a timed state machine that requires timer services
 */

/*! This function has to set up timers for the time events that are required
 *  by the state machine.
 */
/*! This function will be called for each time event that is relevant for a
 *  state when a state will be entered.
 *  \param evid An unique identifier of the event.
 *  \time_ms The time in milli seconds
 *  \periodic Indicates the the time event must be raised periodically until
 *   the timer is unset
 */
void escaleraMecanica_setTimer( EscaleraMecanica* handle, const sc_eventid evid, const sc_integer time_ms, const sc_boolean periodic )
{
	SetNewTimerTick(ticks, NOF_TIMERS, evid, time_ms, periodic);
}

/*! This function has to unset timers for the time events that are required
 *  by the state machine.
 */
/*! This function will be called for each time event that is relevant for a
 *  state when a state will be left.
 *  \param evid An unique identifier of the event.
 */
void escaleraMecanica_unsetTimer( EscaleraMecanica* handle, const sc_eventid evid )
{
	UnsetTimerTick( ticks, NOF_TIMERS, evid );
}


/**
 * @brief	Hook on Handle interrupt from SysTick timer
 * @return	Nothing
 */
void myTickHook( void *ptr ){

	/* The sysTick Interrupt Handler only set a Flag */
	SysTick_Time_Flag = true;
}

/*! This function scan all EDU-CIAA-NXP buttons (TEC1, TEC2, TEC3 and TEC4),
 *  and return ID of pressed button (TEC1 or TEC2 or TEC3 or TEC4)
 *  or false if no button was pressed.
 */
uint32_t Buttons_GetStatus_(void) {
	uint8_t ret = false;
	uint32_t idx;

	for (idx = 0; idx < 4; ++idx) {
		if (gpioRead( TEC1 + idx ) == 0)
			ret |= 1 << idx;
	}
	return ret;
}

/**
 * @brief	main routine for statechart example: EDU-CIAA-NXP - EscaleraMecanica LED3
 * @return	Function should not exit.
 */
int main(void)
{
	uint32_t i;
	uint32_t BUTTON_Status;

	/* Generic Initialization */
	boardConfig();

	/* Init Ticks counter => TICKRATE_MS */
	tickConfig( TICKRATE_MS );

	/* Add Tick Hook */
	tickCallbackSet( myTickHook, (void*)NULL );

	/* Init Timer Ticks */
	InitTimerTicks( ticks, NOF_TIMERS );

	/* Statechart Initialization */
	escaleraMecanica_init( &statechart );
	escaleraMecanica_enter( &statechart );

	/* LED state is toggled in the main program */
	while (1) {
		/* The uC sleeps waiting for an interruption */
		__WFI();

		/* When a interrupt wakes to the uC, the main program validates it,
		 * checking the waited Flag */
		if (SysTick_Time_Flag == true) {

			/* Then reset its Flag */
			SysTick_Time_Flag = false;

			/* Then Update all Timer Ticks */
			UpdateTimers( ticks, NOF_TIMERS );

			/* Then Scan all Timer Ticks */
			for (i = 0; i < NOF_TIMERS; i++) {

				/* Then if there are pending events */
				if (IsPendEvent( ticks, NOF_TIMERS, ticks[i].evid ) == true) {

					/* Then Raise an Event -> Ticks.evid => OK */
					escaleraMecanica_raiseTimeEvent( &statechart, ticks[i].evid );

					/* Then Mark as Attached -> Ticks.evid => OK */
					MarkAsAttEvent( ticks, NOF_TIMERS, ticks[i].evid );
				}
			}

			/* Then Get status of buttons */
			BUTTON_Status = Buttons_GetStatus_();

			/* Then if there are a pressed button */
			if (BUTTON_Status != 0){

				/* Then Raise an Event -> evTECXOprimodo => OK,
				 * and Value of pressed button -> viTecla */
				escaleraMecanicaIface_raise_evTECXOprimido(&statechart, BUTTON_Status);
			}
			else{
				/* Then else Raise an Event -> evTECXNoOprimido => OK */
				escaleraMecanicaIface_raise_evTECXNoOprimido(&statechart);
			}
			/* Then Run an Cycle of Statechart */
			escaleraMecanica_runCycle(&statechart);		// Run Cycle of Statechart
		}
	}
}


/** @} doxygen end group definition */

/*==================[end of file]============================================*/
