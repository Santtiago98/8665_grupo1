
#ifndef EJ3REQUIRED_H_
#define EJ3REQUIRED_H_

#include "..\inc\sc_types.h"
#include "Ej3.h"

#ifdef __cplusplus
extern "C"
{
#endif 

/*! \file This header defines prototypes for all functions that are required by the state machine implementation.

This is a state machine uses time events which require access to a timing service. Thus the function prototypes:
	- ej3_setTimer and
	- ej3_unsetTimer
are defined.

This state machine makes use of operations declared in the state machines interface or internal scopes. Thus the function prototypes:
	- ej3Iface_opSetForma
	- ej3Iface_opLED
	- ej3Iface_opAmplitudUp
	- ej3Iface_opAmplitudDown
	- ej3Iface_opSetAmplitudFrec
	- ej3Iface_opSetAmplitudVoltage
are defined.

These functions will be called during a 'run to completion step' (runCycle) of the statechart. 
There are some constraints that have to be considered for the implementation of these functions:
	- never call the statechart API functions from within these functions.
	- make sure that the execution time is as short as possible.
 
*/
extern void ej3Iface_opSetForma(const Ej3* handle, const sc_string Forma);
extern void ej3Iface_opLED(const Ej3* handle, const sc_integer LEDNumber, const sc_boolean State);
extern void ej3Iface_opAmplitudUp(const Ej3* handle, const sc_integer Amplitud);
extern void ej3Iface_opAmplitudDown(const Ej3* handle, const sc_integer Amplitud);
extern void ej3Iface_opSetAmplitudFrec(const Ej3* handle, const sc_integer Amplitud);
extern void ej3Iface_opSetAmplitudVoltage(const Ej3* handle, const sc_integer Amplitud);



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
extern void ej3_setTimer(Ej3* handle, const sc_eventid evid, const sc_integer time_ms, const sc_boolean periodic);

/*! This function has to unset timers for the time events that are required by the state machine. */
/*! 
	This function will be called for each time event taht is relevant for a state when a state will be left.
	\param evid An unique identifier of the event.
*/
extern void ej3_unsetTimer(Ej3* handle, const sc_eventid evid);



#ifdef __cplusplus
}
#endif 

#endif /* EJ3REQUIRED_H_ */
