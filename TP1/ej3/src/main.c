/*==================[inclusions]=============================================*/

#include "main.h"
#include "sapi.h"       // <= sAPI header

/* Include statechart header file. Be sure you run the statechart C code
 * generation tool! */

#include "Ej3.h"
#include "TimerTicks.h"

/*==================[macros and definitions]=================================*/

#define TICKRATE_1MS	(1)				/* 1000 ticks per second */
#define TICKRATE_MS		(TICKRATE_1MS)	/* 1000 ticks per second */

/*==================[internal data declaration]==============================*/

volatile bool SysTick_Time_Flag = false;

/*! This is a state machine */
static Ej3 statechart;

/*! This is a timed state machine that requires timer services */
#define NOF_TIMERS (sizeof(Ej3TimeEvents)/sizeof(sc_boolean))

TimerTicks ticks[NOF_TIMERS];



void ej3_setTimer( Ej3* handle, const sc_eventid evid, const sc_integer time_ms, const sc_boolean periodic )
{
	SetNewTimerTick(ticks, NOF_TIMERS, evid, time_ms, periodic);
}

void ej3_unsetTimer( Ej3* handle, const sc_eventid evid )
{
	UnsetTimerTick( ticks, NOF_TIMERS, evid );
}


//// FUNCIONES PERSONALIZADAS

void ej3Iface_opSetForma(const Ej3* handle, const sc_string Forma){

}

void ej3Iface_opAmplitudUp(const Ej3* handle, const sc_integer Amplitud){

}

void ej3Iface_opAmplitudDown(const Ej3* handle, const sc_integer Amplitud){

}
void ej3Iface_opSetAmplitudFrec(const Ej3* handle, const sc_integer Amplitud){

}
void ej3Iface_opSetAmplitudVoltage(const Ej3* handle, const sc_integer Amplitud){

}

void ej3Iface_opLED( Ej3* handle, sc_integer LEDNumber, sc_boolean State )
{
	gpioWrite((LEDR + LEDNumber), State );
}



void myTickHook( void *ptr ){

	/* The sysTick Interrupt Handler only set a Flag */
	SysTick_Time_Flag = true;
}

uint32_t Buttons_GetStatus_(void) {
	uint8_t ret = false;
	uint32_t idx;

	for (idx = 0; idx < 4; ++idx) {
		if (gpioRead( TEC1 + idx ) == 0)
			ret |= 1 << idx;
	}
	return ret;
}

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
	ej3_init( &statechart );
	ej3_enter( &statechart );

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
					ej3_raiseTimeEvent( &statechart, ticks[i].evid );

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
				ej3Iface_raise_evTECXOprimido(&statechart, BUTTON_Status);
			}
			else{
				/* Then else Raise an Event -> evTECXNoOprimido => OK */
				ej3Iface_raise_evTECXNoOprimido(&statechart);
			}
			/* Then Run an Cycle of Statechart */
			ej3_runCycle(&statechart);		// Run Cycle of Statechart
		}
	}
}
