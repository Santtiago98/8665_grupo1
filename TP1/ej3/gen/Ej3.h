
#ifndef EJ3_H_
#define EJ3_H_

#include "..\inc\sc_types.h"

#ifdef __cplusplus
extern "C" { 
#endif 

/*! \file Header of the state machine 'ej3'.
*/

/*! Define dimension of the state configuration vector for orthogonal states. */
#define EJ3_MAX_ORTHOGONAL_STATES 4

/*! Define maximum number of time events that can be active at once */
#define EJ3_MAX_PARALLEL_TIME_EVENTS 3

/*! Define indices of states in the StateConfVector */
#define SCVI_EJ3_TECX_DEBOUNCE 0
#define SCVI_EJ3_TECX_NO_OPRIMIDO 0
#define SCVI_EJ3_TECX_OPRIMIDO 0
#define SCVI_EJ3_TECX_VALIDACION 0
#define SCVI_EJ3_MAIN_REGION_ESPERA 1
#define SCVI_EJ3_FORMA_TRIANGULAR 2
#define SCVI_EJ3_FORMA_CUADRADA 2
#define SCVI_EJ3_FORMA_SENOIDAL 2
#define SCVI_EJ3_FORMA_WAIT_SELEC_FORMA 2
#define SCVI_EJ3_FORMA_FORMA_SELECCIONADA 2
#define SCVI_EJ3_FORMA_SELECC_FORMA 2
#define SCVI_EJ3_MAGNITUD_FRECUENCIA 3
#define SCVI_EJ3_MAGNITUD_TENSION 3
#define SCVI_EJ3_MAGNITUD_WAIT_SELECCION_MAGNITUD 3
#define SCVI_EJ3_MAGNITUD_SELECC_MAGNITUD 3
#define SCVI_EJ3_MAGNITUD_ELEGIR_AMPLITUD_FREC 3
#define SCVI_EJ3_MAGNITUD_ELEGIR_AMPLITUD_FREC_R1_MAGNITUD_START 3
#define SCVI_EJ3_MAGNITUD_ELEGIR_AMPLITUD_FREC_R1_AMPLI_UP 3
#define SCVI_EJ3_MAGNITUD_ELEGIR_AMPLITUD_FREC_R1_AMPLI_DOWN 3
#define SCVI_EJ3_MAGNITUD_ELEGIR_AMPLITUD_FREC_R1_AMPLITUD_SELECCIONADA 3
#define SCVI_EJ3_MAGNITUD_ELEGIR_AMPLITUD_VOLTAGE 3
#define SCVI_EJ3_MAGNITUD_ELEGIR_AMPLITUD_VOLTAGE_R1_MAGNITUD_START 3
#define SCVI_EJ3_MAGNITUD_ELEGIR_AMPLITUD_VOLTAGE_R1_AMPLI_UP 3
#define SCVI_EJ3_MAGNITUD_ELEGIR_AMPLITUD_VOLTAGE_R1_AMPLI_DOWN 3
#define SCVI_EJ3_MAGNITUD_ELEGIR_AMPLITUD_VOLTAGE_R1_AMPLITUD_SELECCIONADA 3
#define SCVI_EJ3_MAGNITUD_LED_FREC 3
#define SCVI_EJ3_MAGNITUD_LED_VOLTAGE 3

/*! Enumeration of all states */ 
typedef enum
{
	Ej3_last_state,
	Ej3_TECX_DEBOUNCE,
	Ej3_TECX_NO_OPRIMIDO,
	Ej3_TECX_OPRIMIDO,
	Ej3_TECX_VALIDACION,
	Ej3_main_region_ESPERA,
	Ej3_forma_TRIANGULAR,
	Ej3_forma_CUADRADA,
	Ej3_forma_SENOIDAL,
	Ej3_forma_WAIT_SELEC_FORMA,
	Ej3_forma_FORMA_SELECCIONADA,
	Ej3_forma_SELECC_FORMA,
	Ej3_magnitud_FRECUENCIA,
	Ej3_magnitud_TENSION,
	Ej3_magnitud_WAIT_SELECCION_MAGNITUD,
	Ej3_magnitud_SELECC_MAGNITUD,
	Ej3_magnitud_ELEGIR_AMPLITUD_FREC,
	Ej3_magnitud_ELEGIR_AMPLITUD_FREC_r1_MAGNITUD_START,
	Ej3_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLI_UP,
	Ej3_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLI_DOWN,
	Ej3_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLITUD_SELECCIONADA,
	Ej3_magnitud_ELEGIR_AMPLITUD_VOLTAGE,
	Ej3_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_MAGNITUD_START,
	Ej3_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLI_UP,
	Ej3_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLI_DOWN,
	Ej3_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLITUD_SELECCIONADA,
	Ej3_magnitud_LED_FREC,
	Ej3_magnitud_LED_VOLTAGE
} Ej3States;

/*! Type definition of the data structure for the Ej3Iface interface scope. */
typedef struct
{
	sc_boolean evTECXOprimido_raised;
	sc_integer evTECXOprimido_value;
	sc_boolean evTECXNoOprimido_raised;
} Ej3Iface;


/* Declaration of constants for scope Ej3Iface. */
extern const sc_integer EJ3_EJ3IFACE_DOOR_1;
extern const sc_integer EJ3_EJ3IFACE_SENS_1;
extern const sc_integer EJ3_EJ3IFACE_TIME_CLOSE_DOOR;
extern const sc_integer EJ3_EJ3IFACE_TIME_OPEN_DOOR;
extern const sc_boolean EJ3_EJ3IFACE_LED_ON;
extern const sc_boolean EJ3_EJ3IFACE_LED_OFF;
extern const sc_integer EJ3_EJ3IFACE_LED1;
extern const sc_integer EJ3_EJ3IFACE_LED2;
extern const sc_integer EJ3_EJ3IFACE_LED3;
extern const sc_integer EJ3_EJ3IFACE_LEDR;
extern const sc_integer EJ3_EJ3IFACE_LEDG;
extern const sc_integer EJ3_EJ3IFACE_LEDB;
extern const sc_integer EJ3_EJ3IFACE_TEC1;
extern const sc_integer EJ3_EJ3IFACE_TEC2;
extern const sc_integer EJ3_EJ3IFACE_TEC3;
extern const sc_integer EJ3_EJ3IFACE_TEC4;
extern const sc_integer EJ3_EJ3IFACE_OUT_OF_SERVICE_TIMEOUT;


/*! Type definition of the data structure for the Ej3Internal interface scope. */
typedef struct
{
	sc_boolean siTECXOK_raised;
	sc_boolean siMagnitud_raised;
	sc_boolean siForma_raised;
	sc_boolean siUp_raised;
	sc_boolean siDown_raised;
	sc_integer viTecla;
	sc_boolean viSetForma;
	sc_boolean viSetMagnitud;
	sc_integer viSetMagnitudValue;
} Ej3Internal;



/*! Type definition of the data structure for the Ej3TimeEvents interface scope. */
typedef struct
{
	sc_boolean ej3_TECX_DEBOUNCE_tev0_raised;
	sc_boolean ej3_forma_FORMA_SELECCIONADA_tev0_raised;
	sc_boolean ej3_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLITUD_SELECCIONADA_tev0_raised;
	sc_boolean ej3_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLITUD_SELECCIONADA_tev0_raised;
	sc_boolean ej3_magnitud_LED_FREC_tev0_raised;
	sc_boolean ej3_magnitud_LED_VOLTAGE_tev0_raised;
} Ej3TimeEvents;




/*! 
 * Type definition of the data structure for the Ej3 state machine.
 * This data structure has to be allocated by the client code. 
 */
typedef struct
{
	Ej3States stateConfVector[EJ3_MAX_ORTHOGONAL_STATES];
	sc_ushort stateConfVectorPosition; 
	
	Ej3Iface iface;
	Ej3Internal internal;
	Ej3TimeEvents timeEvents;
} Ej3;



/*! Initializes the Ej3 state machine data structures. Must be called before first usage.*/
extern void ej3_init(Ej3* handle);

/*! Activates the state machine */
extern void ej3_enter(Ej3* handle);

/*! Deactivates the state machine */
extern void ej3_exit(Ej3* handle);

/*! Performs a 'run to completion' step. */
extern void ej3_runCycle(Ej3* handle);

/*! Raises a time event. */
extern void ej3_raiseTimeEvent(Ej3* handle, sc_eventid evid);

/*! Raises the in event 'evTECXOprimido' that is defined in the default interface scope. */ 
extern void ej3Iface_raise_evTECXOprimido(Ej3* handle, sc_integer value);

/*! Raises the in event 'evTECXNoOprimido' that is defined in the default interface scope. */ 
extern void ej3Iface_raise_evTECXNoOprimido(Ej3* handle);

/*! Gets the value of the variable 'DOOR_1' that is defined in the default interface scope. */ 
extern const sc_integer ej3Iface_get_dOOR_1(const Ej3* handle);
/*! Gets the value of the variable 'SENS_1' that is defined in the default interface scope. */ 
extern const sc_integer ej3Iface_get_sENS_1(const Ej3* handle);
/*! Gets the value of the variable 'TIME_CLOSE_DOOR' that is defined in the default interface scope. */ 
extern const sc_integer ej3Iface_get_tIME_CLOSE_DOOR(const Ej3* handle);
/*! Gets the value of the variable 'TIME_OPEN_DOOR' that is defined in the default interface scope. */ 
extern const sc_integer ej3Iface_get_tIME_OPEN_DOOR(const Ej3* handle);
/*! Gets the value of the variable 'LED_ON' that is defined in the default interface scope. */ 
extern const sc_boolean ej3Iface_get_lED_ON(const Ej3* handle);
/*! Gets the value of the variable 'LED_OFF' that is defined in the default interface scope. */ 
extern const sc_boolean ej3Iface_get_lED_OFF(const Ej3* handle);
/*! Gets the value of the variable 'LED1' that is defined in the default interface scope. */ 
extern const sc_integer ej3Iface_get_lED1(const Ej3* handle);
/*! Gets the value of the variable 'LED2' that is defined in the default interface scope. */ 
extern const sc_integer ej3Iface_get_lED2(const Ej3* handle);
/*! Gets the value of the variable 'LED3' that is defined in the default interface scope. */ 
extern const sc_integer ej3Iface_get_lED3(const Ej3* handle);
/*! Gets the value of the variable 'LEDR' that is defined in the default interface scope. */ 
extern const sc_integer ej3Iface_get_lEDR(const Ej3* handle);
/*! Gets the value of the variable 'LEDG' that is defined in the default interface scope. */ 
extern const sc_integer ej3Iface_get_lEDG(const Ej3* handle);
/*! Gets the value of the variable 'LEDB' that is defined in the default interface scope. */ 
extern const sc_integer ej3Iface_get_lEDB(const Ej3* handle);
/*! Gets the value of the variable 'TEC1' that is defined in the default interface scope. */ 
extern const sc_integer ej3Iface_get_tEC1(const Ej3* handle);
/*! Gets the value of the variable 'TEC2' that is defined in the default interface scope. */ 
extern const sc_integer ej3Iface_get_tEC2(const Ej3* handle);
/*! Gets the value of the variable 'TEC3' that is defined in the default interface scope. */ 
extern const sc_integer ej3Iface_get_tEC3(const Ej3* handle);
/*! Gets the value of the variable 'TEC4' that is defined in the default interface scope. */ 
extern const sc_integer ej3Iface_get_tEC4(const Ej3* handle);
/*! Gets the value of the variable 'OUT_OF_SERVICE_TIMEOUT' that is defined in the default interface scope. */ 
extern const sc_integer ej3Iface_get_oUT_OF_SERVICE_TIMEOUT(const Ej3* handle);

/*!
 * Checks whether the state machine is active (until 2.4.1 this method was used for states).
 * A state machine is active if it was entered. It is inactive if it has not been entered at all or if it has been exited.
 */
extern sc_boolean ej3_isActive(const Ej3* handle);

/*!
 * Checks if all active states are final. 
 * If there are no active states then the state machine is considered being inactive. In this case this method returns false.
 */
extern sc_boolean ej3_isFinal(const Ej3* handle);

/*! Checks if the specified state is active (until 2.4.1 the used method for states was called isActive()). */
extern sc_boolean ej3_isStateActive(const Ej3* handle, Ej3States state);


#ifdef __cplusplus
}
#endif 

#endif /* EJ3_H_ */
