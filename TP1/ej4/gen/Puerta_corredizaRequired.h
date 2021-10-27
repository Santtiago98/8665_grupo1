
#ifndef PUERTA_CORREDIZAREQUIRED_H_
#define PUERTA_CORREDIZAREQUIRED_H_

#include "..\inc\sc_types.h"
#include "Puerta_corrediza.h"

#ifdef __cplusplus
extern "C"
{
#endif 

/*! \file This header defines prototypes for all functions that are required by the state machine implementation.

This is a state machine uses time events which require access to a timing service. Thus the function prototypes:
	- puerta_corrediza_setTimer and
	- puerta_corrediza_unsetTimer
are defined.

This state machine makes use of operations declared in the state machines interface or internal scopes. Thus the function prototypes:
	- puerta_corredizaIface_opOpenDoor
	- puerta_corredizaIface_opCloseDoor
	- puerta_corredizaIface_opCheckSensor
	- puerta_corredizaIface_opLED
are defined.

These functions will be called during a 'run to completion step' (runCycle) of the statechart. 
There are some constraints that have to be considered for the implementation of these functions:
	- never call the statechart API functions from within these functions.
	- make sure that the execution time is as short as possible.
 
*/
extern void puerta_corredizaIface_opOpenDoor(const Puerta_corrediza* handle, const sc_integer DOOR_Number);
extern void puerta_corredizaIface_opCloseDoor(const Puerta_corrediza* handle, const sc_integer DOOR_Number);
extern sc_boolean puerta_corredizaIface_opCheckSensor(const Puerta_corrediza* handle, const sc_integer SENS_Number);
extern void puerta_corredizaIface_opLED(const Puerta_corrediza* handle, const sc_integer LEDNumber, const sc_boolean State);



/*!
 * This is a timed state machine that requires timer services
 */ 

/*! This function has to set up timers for the time events that are required by the state machine. */
/*! 
	This function will be called for each time event that is relevant for a state when a state will be entered.
	\param evid An unique identifier of the event.
	\time_ms The time in milli seconds
	\periodic Indicates the the time event must be raised periodically until the timer is unset 
*/
extern void puerta_corrediza_setTimer(Puerta_corrediza* handle, const sc_eventid evid, const sc_integer time_ms, const sc_boolean periodic);

/*! This function has to unset timers for the time events that are required by the state machine. */
/*! 
	This function will be called for each time event taht is relevant for a state when a state will be left.
	\param evid An unique identifier of the event.
*/
extern void puerta_corrediza_unsetTimer(Puerta_corrediza* handle, const sc_eventid evid);



#ifdef __cplusplus
}
#endif 

#endif /* PUERTA_CORREDIZAREQUIRED_H_ */
