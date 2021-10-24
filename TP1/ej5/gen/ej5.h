/** Generated by YAKINDU Statechart Tools code generator. */

#ifndef EJ5_H_
#define EJ5_H_

#ifdef __cplusplus
extern "C" { 
#endif

/*!
* Forward declaration for the Ej5 state machine.
*/
typedef struct Ej5 Ej5;

/*!
* Forward declaration of the data structure for the Ej5Iface interface scope.
*/
typedef struct Ej5Iface Ej5Iface;

/*!
* Forward declaration of the data structure for the Ej5Internal interface scope.
*/
typedef struct Ej5Internal Ej5Internal;

/*!
* Forward declaration of the data structure for the Ej5TimeEvents interface scope.
*/
typedef struct Ej5TimeEvents Ej5TimeEvents;

#ifdef __cplusplus
}
#endif

#include "../inc/sc_types.h"

#ifdef __cplusplus
extern "C" { 
#endif 

/*! \file Header of the state machine 'ej5'.
*/

#ifndef EJ5_EVENTQUEUE_BUFFERSIZE
#define EJ5_EVENTQUEUE_BUFFERSIZE 20
#endif
#ifndef EJ5_IN_EVENTQUEUE_BUFFERSIZE
#define EJ5_IN_EVENTQUEUE_BUFFERSIZE EJ5_EVENTQUEUE_BUFFERSIZE
#endif
#ifndef EJ5_INTERNAL_EVENTQUEUE_BUFFERSIZE
#define EJ5_INTERNAL_EVENTQUEUE_BUFFERSIZE EJ5_EVENTQUEUE_BUFFERSIZE
#endif
#ifndef SC_INVALID_EVENT_VALUE
#define SC_INVALID_EVENT_VALUE 0
#endif
/*! Define number of states in the state enum */
#define EJ5_STATE_COUNT 10

/*! Define dimension of the state configuration vector for orthogonal states. */
#define EJ5_MAX_ORTHOGONAL_STATES 3
/*! Define maximum number of time events that can be active at once */
#define EJ5_MAX_PARALLEL_TIME_EVENTS 3

/*! Define indices of states in the StateConfVector */
#define SCVI_EJ5_TECX_DEBOUNCE 0
#define SCVI_EJ5_TECX_NO_OPRIMIDO 0
#define SCVI_EJ5_TECX_OPRIMIDO 0
#define SCVI_EJ5_TECX_VALIDACION 0
#define SCVI_EJ5_MAIN_REGION_ESPERA 1
#define SCVI_EJ5_PROGRAM_ABIERTO 2
#define SCVI_EJ5_PROGRAM_CERRADO 2
#define SCVI_EJ5_PROGRAM_CERRANDO 2
#define SCVI_EJ5_PROGRAM_ABRIENDO 2
#define SCVI_EJ5_PROGRAM_PARADO 2

/*
 * Union of all possible event value types.
 */
typedef union {
	sc_integer Ej5_evTECXOprimido_value;
} ej5_event_value;

/*
 * Enum of event names in the statechart.
 */
typedef enum  {
	Ej5_invalid_event = SC_INVALID_EVENT_VALUE,
	Ej5_evTECXNoOprimido,
	Ej5_evTECXOprimido,
	Ej5_internal_evCerrarPorton,
	Ej5_internal_evAbrirPorton,
	Ej5_internal_evFinalCarrera,
	Ej5_internal_evObstaculo,
	Ej5_internal_siTECXOK,
	Ej5_ej5_TECX_DEBOUNCE_time_event_0,
	Ej5_ej5_program_Parado_time_event_0,
	Ej5_ej5_program_Parado_time_event_1
} Ej5EventID;

/*
 * Struct that represents a single event.
 */
typedef struct {
	Ej5EventID name;
	sc_boolean has_value;
	ej5_event_value value;
} ej5_event;

/*
 * Queue that holds the raised events.
 */
typedef struct ej5_eventqueue_s {
	ej5_event *events;
	sc_integer capacity;
	sc_integer pop_index;
	sc_integer push_index;
	sc_integer size;
} ej5_eventqueue;

/*! Enumeration of all states */ 
typedef enum
{
	Ej5_last_state,
	Ej5_TECX_DEBOUNCE,
	Ej5_TECX_NO_OPRIMIDO,
	Ej5_TECX_OPRIMIDO,
	Ej5_TECX_VALIDACION,
	Ej5_main_region_ESPERA,
	Ej5_program_Abierto,
	Ej5_program_Cerrado,
	Ej5_program_Cerrando,
	Ej5_program_Abriendo,
	Ej5_program_Parado
} Ej5States;


/*! Type declaration of the data structure for the Ej5Iface interface scope. */
struct Ej5Iface
{
	sc_boolean evTECXNoOprimido_raised;
	sc_boolean evTECXOprimido_raised;
	sc_integer evTECXOprimido_value;
};


/* Declaration of constants for scope Ej5Iface. */
extern const sc_integer EJ5_EJ5IFACE_PORTNUMBER;
extern const sc_integer EJ5_EJ5IFACE_CERRANDO;
extern const sc_integer EJ5_EJ5IFACE_ABRIENDO;
extern const sc_integer EJ5_EJ5IFACE_LED1;
extern const sc_integer EJ5_EJ5IFACE_LED2;
extern const sc_integer EJ5_EJ5IFACE_LED3;
extern const sc_boolean EJ5_EJ5IFACE_LED_ON;
extern const sc_boolean EJ5_EJ5IFACE_LED_OFF;
extern const sc_integer EJ5_EJ5IFACE_TEC1;
extern const sc_integer EJ5_EJ5IFACE_TEC2;
extern const sc_integer EJ5_EJ5IFACE_TEC3;
extern const sc_integer EJ5_EJ5IFACE_TEC4;


/*! Type declaration of the data structure for the Ej5Internal interface scope. */
struct Ej5Internal
{
	sc_integer oldState;
	sc_integer viTecla;
	sc_boolean evCerrarPorton_raised;
	sc_boolean evAbrirPorton_raised;
	sc_boolean evFinalCarrera_raised;
	sc_boolean evObstaculo_raised;
	sc_boolean siTECXOK_raised;
};



/*! Type declaration of the data structure for the Ej5TimeEvents interface scope. */
struct Ej5TimeEvents
{
	sc_boolean ej5_TECX_DEBOUNCE_tev0_raised;
	sc_boolean ej5_program_Parado_tev0_raised;
	sc_boolean ej5_program_Parado_tev1_raised;
};






/*! 
 * Type declaration of the data structure for the Ej5 state machine.
 * This data structure has to be allocated by the client code. 
 */
struct Ej5
{
	Ej5States stateConfVector[EJ5_MAX_ORTHOGONAL_STATES];
	Ej5Iface iface;
	Ej5Internal internal;
	Ej5TimeEvents timeEvents;
	sc_boolean isExecuting;
	sc_integer stateConfVectorPosition;
	ej5_eventqueue internal_event_queue;
	ej5_event internal_buffer[EJ5_INTERNAL_EVENTQUEUE_BUFFERSIZE];
	ej5_eventqueue in_event_queue;
	ej5_event in_buffer[EJ5_IN_EVENTQUEUE_BUFFERSIZE];
};



/*! Initializes the Ej5 state machine data structures. Must be called before first usage.*/
extern void ej5_init(Ej5* handle);


/*! Activates the state machine. */
extern void ej5_enter(Ej5* handle);

/*! Deactivates the state machine. */
extern void ej5_exit(Ej5* handle);



/*! Raises a time event. */
extern void ej5_raise_time_event(Ej5* handle, sc_eventid evid);

/*! Raises the in event 'evTECXNoOprimido' that is defined in the default interface scope. */ 
extern void ej5_raise_evTECXNoOprimido(Ej5* handle);
/*! Raises the in event 'evTECXOprimido' that is defined in the default interface scope. */ 
extern void ej5_raise_evTECXOprimido(Ej5* handle, sc_integer value);
/*! Gets the value of the variable 'PortNumber' that is defined in the default interface scope. */ 
extern sc_integer ej5_get_portNumber(const Ej5* handle);
/*! Gets the value of the variable 'cerrando' that is defined in the default interface scope. */ 
extern sc_integer ej5_get_cerrando(const Ej5* handle);
/*! Gets the value of the variable 'abriendo' that is defined in the default interface scope. */ 
extern sc_integer ej5_get_abriendo(const Ej5* handle);
/*! Gets the value of the variable 'LED1' that is defined in the default interface scope. */ 
extern sc_integer ej5_get_lED1(const Ej5* handle);
/*! Gets the value of the variable 'LED2' that is defined in the default interface scope. */ 
extern sc_integer ej5_get_lED2(const Ej5* handle);
/*! Gets the value of the variable 'LED3' that is defined in the default interface scope. */ 
extern sc_integer ej5_get_lED3(const Ej5* handle);
/*! Gets the value of the variable 'LED_ON' that is defined in the default interface scope. */ 
extern sc_boolean ej5_get_lED_ON(const Ej5* handle);
/*! Gets the value of the variable 'LED_OFF' that is defined in the default interface scope. */ 
extern sc_boolean ej5_get_lED_OFF(const Ej5* handle);
/*! Gets the value of the variable 'TEC1' that is defined in the default interface scope. */ 
extern sc_integer ej5_get_tEC1(const Ej5* handle);
/*! Gets the value of the variable 'TEC2' that is defined in the default interface scope. */ 
extern sc_integer ej5_get_tEC2(const Ej5* handle);
/*! Gets the value of the variable 'TEC3' that is defined in the default interface scope. */ 
extern sc_integer ej5_get_tEC3(const Ej5* handle);
/*! Gets the value of the variable 'TEC4' that is defined in the default interface scope. */ 
extern sc_integer ej5_get_tEC4(const Ej5* handle);

/*!
 * Checks whether the state machine is active (until 2.4.1 this method was used for states).
 * A state machine is active if it was entered. It is inactive if it has not been entered at all or if it has been exited.
 */
extern sc_boolean ej5_is_active(const Ej5* handle);

/*!
 * Checks if all active states are final. 
 * If there are no active states then the state machine is considered being inactive. In this case this method returns false.
 */
extern sc_boolean ej5_is_final(const Ej5* handle);

/*! Checks if the specified state is active (until 2.4.1 the used method for states was called isActive()). */
extern sc_boolean ej5_is_state_active(const Ej5* handle, Ej5States state);


#ifdef __cplusplus
}
#endif 

#endif /* EJ5_H_ */