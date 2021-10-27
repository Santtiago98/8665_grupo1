/** @brief This is a simple statechart example using Yakindu Statechart Tool
 * Plug-in (update site: http://updates.yakindu.org/sct/mars/releases/).
 */

/** \addtogroup statechart Simple UML Statechart example.
 ** @{ */

/*==================[inclusions]=============================================*/

#include "main.h"
#include "sapi.h"       // <= sAPI header

/* Include statechart header file. Be sure you run the statechart C code
 * generation tool!
 */
//#include "ej7.h"
#include "ej7.h"
#include "TimerTicks.h"


/*==================[macros and definitions]=================================*/

#define TICKRATE_1MS	(1)				/* 1000 ticks per second */
#define TICKRATE_MS		(TICKRATE_1MS)	/* 1000 ticks per second */


/*==================[internal data declaration]==============================*/

volatile bool SysTick_Time_Flag = false;

/*! This is a state machine */
static Ej7 statechart;

/*! This is a timed state machine that requires timer services */
#define NOF_TIMERS (sizeof(Ej7TimeEvents)/sizeof(sc_boolean))

TimerTicks ticks[NOF_TIMERS];


/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/

/*! \file This header defines prototypes for all functions that are required
 *  by the state machine implementation.
 *
 *  This is a state machine uses time events which require access to a timing
 *  service. Thus the function prototypes:
// *  - ej7_setTimer and
 *  - ej7_set_timer and
// *  - ej7_unsetTimer
 *  - ej7_unset_timer
 *  are defined.
 *
 *  This state machine makes use of operations declared in the state machines
 *  interface or internal scopes. Thus the function prototypes:
// *  - ej7Iface_opLED
 *  - ej7_opLED
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

//void ej7Iface_opLED( Ej7* handle, sc_integer LEDNumber, sc_boolean State )
void ej7_opLED( Ej7* handle, const sc_integer LEDNumber, const sc_boolean State)
{
	gpioWrite(LEDR + LEDNumber, State );
}

// funciones

void ej7_opSelectCookType( Ej7* handle, const sc_integer type){

	// Turn all LEDs off
	gpioWrite(LED1, false);
	gpioWrite(LED2, false);
	gpioWrite(LED3, false);

	// Turn LEDx ON
	gpioWrite(LED1 + (type - 1),  true);
}
void ej7_opStartCooking( Ej7* handle){

	// stand-by indicator off
	gpioWrite(LEDR,  false);

	// LED indicator cooking on
	gpioWrite(LEDG,  true);
}
void ej7_opStopCooking( Ej7* handle){
	
	// LED indicator cooking off
	gpioWrite(LEDG, false);
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
//void ej7_setTimer( Ej7* handle, const sc_eventid evid, const sc_integer time_ms, const sc_boolean periodic )
void ej7_set_timer( Ej7* handle, const sc_eventid evid, const sc_integer time_ms, const sc_boolean periodic )
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
//void ej7_unsetTimer( Ej7* handle, const sc_eventid evid )
void ej7_unset_timer( Ej7* handle, const sc_eventid evid )
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
 * @brief	main routine for statechart example: EDU-CIAA-NXP - ej7
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
	ej7_init( &statechart );
	ej7_enter( &statechart );

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
//					ej7_raiseTimeEvent( &statechart, ticks[i].evid );
					ej7_raise_time_event( &statechart, ticks[i].evid );

					/* Then Mark as Attached -> Ticks.evid => OK */
					MarkAsAttEvent( ticks, NOF_TIMERS, ticks[i].evid );
				}
			}

			/* Then Get status of buttons */
			BUTTON_Status = Buttons_GetStatus_();

			/* Then if there are a pressed button */
			if (BUTTON_Status != 0)

				/* Then Raise an Event -> evTECXOprimodo => OK,
				 * and Value of pressed button -> viTecla */
//				ej7Iface_raise_evTECXOprimido(&statechart, BUTTON_Status);
				ej7_raise_evTECXOprimido(&statechart, BUTTON_Status);



			else
				/* Then else Raise an Event -> evTECXNoOprimido => OK */
//				ej7Iface_raise_evTECXNoOprimido(&statechart);
				ej7_raise_evTECXNoOprimido(&statechart);

			/* Then Run an Cycle of Statechart */
//			ej7_runCycle(&statechart);		// Run Cycle of Statechart
		}
	}
}


/** @} doxygen end group definition */

/*==================[end of file]============================================*/
