
#ifndef PUERTA_CORREDIZA_H_
#define PUERTA_CORREDIZA_H_

#include "..\inc\sc_types.h"

#ifdef __cplusplus
extern "C" { 
#endif 

/*! \file Header of the state machine 'puerta_corrediza'.
*/

/*! Define dimension of the state configuration vector for orthogonal states. */
#define PUERTA_CORREDIZA_MAX_ORTHOGONAL_STATES 3

/*! Define maximum number of time events that can be active at once */
#define PUERTA_CORREDIZA_MAX_PARALLEL_TIME_EVENTS 2

/*! Define indices of states in the StateConfVector */
#define SCVI_PUERTA_CORREDIZA_TECX_DEBOUNCE 0
#define SCVI_PUERTA_CORREDIZA_TECX_NO_OPRIMIDO 0
#define SCVI_PUERTA_CORREDIZA_TECX_OPRIMIDO 0
#define SCVI_PUERTA_CORREDIZA_TECX_VALIDACION 0
#define SCVI_PUERTA_CORREDIZA_MAIN_REGION_ESPERA 1
#define SCVI_PUERTA_CORREDIZA_MAIN_PUERTA_PUERTA_CERRADA 2
#define SCVI_PUERTA_CORREDIZA_MAIN_PUERTA_PUERTA_ABIERTA 2
#define SCVI_PUERTA_CORREDIZA_MAIN_PUERTA_PUERTA_A_CERRAR 2
#define SCVI_PUERTA_CORREDIZA_MAIN_PUERTA_CERRANDO 2
#define SCVI_PUERTA_CORREDIZA_MAIN_PUERTA_OBSTACULO 2
#define SCVI_PUERTA_CORREDIZA_MAIN_PUERTA_FUERA_DE_SERVICIO 2
#define SCVI_PUERTA_CORREDIZA_MAIN_PUERTA_FUERA_DE_SERVICIO_R1_ON_LED 2
#define SCVI_PUERTA_CORREDIZA_MAIN_PUERTA_FUERA_DE_SERVICIO_R1_OFF_LED 2

/*! Enumeration of all states */ 
typedef enum
{
	Puerta_corrediza_last_state,
	Puerta_corrediza_TECX_DEBOUNCE,
	Puerta_corrediza_TECX_NO_OPRIMIDO,
	Puerta_corrediza_TECX_OPRIMIDO,
	Puerta_corrediza_TECX_VALIDACION,
	Puerta_corrediza_main_region_ESPERA,
	Puerta_corrediza_main_puerta_PUERTA_CERRADA,
	Puerta_corrediza_main_puerta_PUERTA_ABIERTA,
	Puerta_corrediza_main_puerta_PUERTA_A_CERRAR,
	Puerta_corrediza_main_puerta_CERRANDO,
	Puerta_corrediza_main_puerta_OBSTACULO,
	Puerta_corrediza_main_puerta_FUERA_DE_SERVICIO,
	Puerta_corrediza_main_puerta_FUERA_DE_SERVICIO_r1_ON_LED,
	Puerta_corrediza_main_puerta_FUERA_DE_SERVICIO_r1_OFF_LED
} Puerta_corredizaStates;

/*! Type definition of the data structure for the Puerta_corredizaIface interface scope. */
typedef struct
{
	sc_boolean evTECXOprimido_raised;
	sc_integer evTECXOprimido_value;
	sc_boolean evTECXNoOprimido_raised;
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
extern const sc_integer PUERTA_CORREDIZA_PUERTA_CORREDIZAIFACE_LEDR;
extern const sc_integer PUERTA_CORREDIZA_PUERTA_CORREDIZAIFACE_TEC1;
extern const sc_integer PUERTA_CORREDIZA_PUERTA_CORREDIZAIFACE_TEC2;
extern const sc_integer PUERTA_CORREDIZA_PUERTA_CORREDIZAIFACE_TEC3;
extern const sc_integer PUERTA_CORREDIZA_PUERTA_CORREDIZAIFACE_TEC4;
extern const sc_integer PUERTA_CORREDIZA_PUERTA_CORREDIZAIFACE_OUT_OF_SERVICE_TIMEOUT;


/*! Type definition of the data structure for the Puerta_corredizaInternal interface scope. */
typedef struct
{
	sc_boolean siTECXOK_raised;
	sc_boolean siSensor_raised;
	sc_boolean siClosed_raised;
	sc_boolean siOpen_raised;
	sc_integer viTecla;
	sc_boolean viClosed;
	sc_boolean viOpen;
	sc_boolean viflagEmpty;
} Puerta_corredizaInternal;



/*! Type definition of the data structure for the Puerta_corredizaTimeEvents interface scope. */
typedef struct
{
	sc_boolean puerta_corrediza_TECX_DEBOUNCE_tev0_raised;
	sc_boolean puerta_corrediza_main_puerta_PUERTA_ABIERTA_tev0_raised;
	sc_boolean puerta_corrediza_main_puerta_PUERTA_A_CERRAR_tev0_raised;
	sc_boolean puerta_corrediza_main_puerta_CERRANDO_tev0_raised;
	sc_boolean puerta_corrediza_main_puerta_OBSTACULO_tev0_raised;
	sc_boolean puerta_corrediza_main_puerta_FUERA_DE_SERVICIO_r1_ON_LED_tev0_raised;
	sc_boolean puerta_corrediza_main_puerta_FUERA_DE_SERVICIO_r1_OFF_LED_tev0_raised;
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

/*! Raises the in event 'evTECXOprimido' that is defined in the default interface scope. */ 
extern void puerta_corredizaIface_raise_evTECXOprimido(Puerta_corrediza* handle, sc_integer value);

/*! Raises the in event 'evTECXNoOprimido' that is defined in the default interface scope. */ 
extern void puerta_corredizaIface_raise_evTECXNoOprimido(Puerta_corrediza* handle);

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
/*! Gets the value of the variable 'LEDR' that is defined in the default interface scope. */ 
extern const sc_integer puerta_corredizaIface_get_lEDR(const Puerta_corrediza* handle);
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
