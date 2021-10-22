
#ifndef PUERTA_CORREDIZA_H_
#define PUERTA_CORREDIZA_H_

#include "..\inc\sc_types.h"

#ifdef __cplusplus
extern "C" { 
#endif 

/*! \file Header of the state machine 'puerta_corrediza'.
*/

/*! Define dimension of the state configuration vector for orthogonal states. */
#define PUERTA_CORREDIZA_MAX_ORTHOGONAL_STATES 1

/*! Define maximum number of time events that can be active at once */
#define PUERTA_CORREDIZA_MAX_PARALLEL_TIME_EVENTS 1

/*! Define indices of states in the StateConfVector */
#define SCVI_PUERTA_CORREDIZA_MAIN_REGION_PUERTA_CERRADA 0
#define SCVI_PUERTA_CORREDIZA_MAIN_REGION_PUERTA_ABIERTA 0
#define SCVI_PUERTA_CORREDIZA_MAIN_REGION_PUERTA_A_CERRAR 0
#define SCVI_PUERTA_CORREDIZA_MAIN_REGION_CERRANDO 0
#define SCVI_PUERTA_CORREDIZA_MAIN_REGION_OBSTACULO 0
#define SCVI_PUERTA_CORREDIZA_MAIN_REGION_FUERA_DE_SERVICIO 0
#define SCVI_PUERTA_CORREDIZA_MAIN_REGION_FUERA_DE_SERVICIO_R1_ON_LED 0
#define SCVI_PUERTA_CORREDIZA_MAIN_REGION_FUERA_DE_SERVICIO_R1_OFF_LED 0

/*! Enumeration of all states */ 
typedef enum
{
	Puerta_corrediza_last_state,
	Puerta_corrediza_main_region_PUERTA_CERRADA,
	Puerta_corrediza_main_region_PUERTA_ABIERTA,
	Puerta_corrediza_main_region_PUERTA_A_CERRAR,
	Puerta_corrediza_main_region_CERRANDO,
	Puerta_corrediza_main_region_OBSTACULO,
	Puerta_corrediza_main_region_FUERA_DE_SERVICIO,
	Puerta_corrediza_main_region_FUERA_DE_SERVICIO_r1_ON_LED,
	Puerta_corrediza_main_region_FUERA_DE_SERVICIO_r1_OFF_LED
} Puerta_corredizaStates;

/*! Type definition of the data structure for the Puerta_corredizaIface interface scope. */
typedef struct
{
	sc_boolean evSensor_raised;
	sc_boolean evFlagEmpty_raised;
	sc_boolean evFlagEmpty_value;
	sc_boolean evClosed_raised;
	sc_boolean evOpen_raised;
} Puerta_corredizaIface;


/* Declaration of constants for scope Puerta_corredizaIface. */
extern const sc_integer PUERTA_CORREDIZA_PUERTA_CORREDIZAIFACE_DOOR_1;
extern const sc_integer PUERTA_CORREDIZA_PUERTA_CORREDIZAIFACE_SENS_1;
extern const sc_integer PUERTA_CORREDIZA_PUERTA_CORREDIZAIFACE_TIME_CLOSE_DOOR;
extern const sc_integer PUERTA_CORREDIZA_PUERTA_CORREDIZAIFACE_TIME_OPEN_DOOR;
extern const sc_boolean PUERTA_CORREDIZA_PUERTA_CORREDIZAIFACE_LED_ON;
extern const sc_boolean PUERTA_CORREDIZA_PUERTA_CORREDIZAIFACE_LED_OFF;
extern const sc_integer PUERTA_CORREDIZA_PUERTA_CORREDIZAIFACE_LED1;
extern const sc_integer PUERTA_CORREDIZA_PUERTA_CORREDIZAIFACE_LED2;
extern const sc_integer PUERTA_CORREDIZA_PUERTA_CORREDIZAIFACE_LED3;
extern const sc_integer PUERTA_CORREDIZA_PUERTA_CORREDIZAIFACE_TEC1;
extern const sc_integer PUERTA_CORREDIZA_PUERTA_CORREDIZAIFACE_TEC2;
extern const sc_integer PUERTA_CORREDIZA_PUERTA_CORREDIZAIFACE_TEC3;
extern const sc_integer PUERTA_CORREDIZA_PUERTA_CORREDIZAIFACE_TEC4;
extern const sc_integer PUERTA_CORREDIZA_PUERTA_CORREDIZAIFACE_OUT_OF_SERVICE_TIMEOUT;


/*! Type definition of the data structure for the Puerta_corredizaInternal interface scope. */
typedef struct
{
	sc_boolean viflagEmpty;
} Puerta_corredizaInternal;



/*! Type definition of the data structure for the Puerta_corredizaTimeEvents interface scope. */
typedef struct
{
	sc_boolean puerta_corrediza_main_region_PUERTA_ABIERTA_tev0_raised;
	sc_boolean puerta_corrediza_main_region_PUERTA_A_CERRAR_tev0_raised;
	sc_boolean puerta_corrediza_main_region_CERRANDO_tev0_raised;
	sc_boolean puerta_corrediza_main_region_FUERA_DE_SERVICIO_r1_ON_LED_tev0_raised;
	sc_boolean puerta_corrediza_main_region_FUERA_DE_SERVICIO_r1_OFF_LED_tev0_raised;
} Puerta_corredizaTimeEvents;




/*! 
 * Type definition of the data structure for the Puerta_corrediza state machine.
 * This data structure has to be allocated by the client code. 
 */
typedef struct
{
	Puerta_corredizaStates stateConfVector[PUERTA_CORREDIZA_MAX_ORTHOGONAL_STATES];
	sc_ushort stateConfVectorPosition; 
	
	Puerta_corredizaIface iface;
	Puerta_corredizaInternal internal;
	Puerta_corredizaTimeEvents timeEvents;
} Puerta_corrediza;



/*! Initializes the Puerta_corrediza state machine data structures. Must be called before first usage.*/
extern void puerta_corrediza_init(Puerta_corrediza* handle);

/*! Activates the state machine */
extern void puerta_corrediza_enter(Puerta_corrediza* handle);

/*! Deactivates the state machine */
extern void puerta_corrediza_exit(Puerta_corrediza* handle);

/*! Performs a 'run to completion' step. */
extern void puerta_corrediza_runCycle(Puerta_corrediza* handle);

/*! Raises a time event. */
extern void puerta_corrediza_raiseTimeEvent(Puerta_corrediza* handle, sc_eventid evid);

/*! Raises the in event 'evSensor' that is defined in the default interface scope. */ 
extern void puerta_corredizaIface_raise_evSensor(Puerta_corrediza* handle);

/*! Raises the in event 'evFlagEmpty' that is defined in the default interface scope. */ 
extern void puerta_corredizaIface_raise_evFlagEmpty(Puerta_corrediza* handle, sc_boolean value);

/*! Raises the in event 'evClosed' that is defined in the default interface scope. */ 
extern void puerta_corredizaIface_raise_evClosed(Puerta_corrediza* handle);

/*! Raises the in event 'evOpen' that is defined in the default interface scope. */ 
extern void puerta_corredizaIface_raise_evOpen(Puerta_corrediza* handle);

/*! Gets the value of the variable 'DOOR_1' that is defined in the default interface scope. */ 
extern const sc_integer puerta_corredizaIface_get_dOOR_1(const Puerta_corrediza* handle);
/*! Gets the value of the variable 'SENS_1' that is defined in the default interface scope. */ 
extern const sc_integer puerta_corredizaIface_get_sENS_1(const Puerta_corrediza* handle);
/*! Gets the value of the variable 'TIME_CLOSE_DOOR' that is defined in the default interface scope. */ 
extern const sc_integer puerta_corredizaIface_get_tIME_CLOSE_DOOR(const Puerta_corrediza* handle);
/*! Gets the value of the variable 'TIME_OPEN_DOOR' that is defined in the default interface scope. */ 
extern const sc_integer puerta_corredizaIface_get_tIME_OPEN_DOOR(const Puerta_corrediza* handle);
/*! Gets the value of the variable 'LED_ON' that is defined in the default interface scope. */ 
extern const sc_boolean puerta_corredizaIface_get_lED_ON(const Puerta_corrediza* handle);
/*! Gets the value of the variable 'LED_OFF' that is defined in the default interface scope. */ 
extern const sc_boolean puerta_corredizaIface_get_lED_OFF(const Puerta_corrediza* handle);
/*! Gets the value of the variable 'LED1' that is defined in the default interface scope. */ 
extern const sc_integer puerta_corredizaIface_get_lED1(const Puerta_corrediza* handle);
/*! Gets the value of the variable 'LED2' that is defined in the default interface scope. */ 
extern const sc_integer puerta_corredizaIface_get_lED2(const Puerta_corrediza* handle);
/*! Gets the value of the variable 'LED3' that is defined in the default interface scope. */ 
extern const sc_integer puerta_corredizaIface_get_lED3(const Puerta_corrediza* handle);
/*! Gets the value of the variable 'TEC1' that is defined in the default interface scope. */ 
extern const sc_integer puerta_corredizaIface_get_tEC1(const Puerta_corrediza* handle);
/*! Gets the value of the variable 'TEC2' that is defined in the default interface scope. */ 
extern const sc_integer puerta_corredizaIface_get_tEC2(const Puerta_corrediza* handle);
/*! Gets the value of the variable 'TEC3' that is defined in the default interface scope. */ 
extern const sc_integer puerta_corredizaIface_get_tEC3(const Puerta_corrediza* handle);
/*! Gets the value of the variable 'TEC4' that is defined in the default interface scope. */ 
extern const sc_integer puerta_corredizaIface_get_tEC4(const Puerta_corrediza* handle);
/*! Gets the value of the variable 'OUT_OF_SERVICE_TIMEOUT' that is defined in the default interface scope. */ 
extern const sc_integer puerta_corredizaIface_get_oUT_OF_SERVICE_TIMEOUT(const Puerta_corrediza* handle);

/*!
 * Checks whether the state machine is active (until 2.4.1 this method was used for states).
 * A state machine is active if it was entered. It is inactive if it has not been entered at all or if it has been exited.
 */
extern sc_boolean puerta_corrediza_isActive(const Puerta_corrediza* handle);

/*!
 * Checks if all active states are final. 
 * If there are no active states then the state machine is considered being inactive. In this case this method returns false.
 */
extern sc_boolean puerta_corrediza_isFinal(const Puerta_corrediza* handle);

/*! Checks if the specified state is active (until 2.4.1 the used method for states was called isActive()). */
extern sc_boolean puerta_corrediza_isStateActive(const Puerta_corrediza* handle, Puerta_corredizaStates state);


#ifdef __cplusplus
}
#endif 

#endif /* PUERTA_CORREDIZA_H_ */
