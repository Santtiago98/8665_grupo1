
#include "Puerta_corrediza.h"
#include "..\inc\sc_types.h"
#include "Puerta_corredizaRequired.h"

#include <stdlib.h>
#include <string.h>
/*! \file Implementation of the state machine 'puerta_corrediza'
*/

/* prototypes of all internal functions */
static sc_boolean check_main_region_PUERTA_CERRADA_tr0_tr0(const Puerta_corrediza* handle);
static sc_boolean check_main_region_PUERTA_ABIERTA_tr0_tr0(const Puerta_corrediza* handle);
static sc_boolean check_main_region_PUERTA_A_CERRAR_tr0_tr0(const Puerta_corrediza* handle);
static sc_boolean check_main_region_PUERTA_A_CERRAR_tr1_tr1(const Puerta_corrediza* handle);
static sc_boolean check_main_region_CERRANDO_tr0_tr0(const Puerta_corrediza* handle);
static sc_boolean check_main_region_CERRANDO_tr1_tr1(const Puerta_corrediza* handle);
static sc_boolean check_main_region_CERRANDO_tr2_tr2(const Puerta_corrediza* handle);
static sc_boolean check_main_region_OBSTACULO_tr0_tr0(const Puerta_corrediza* handle);
static sc_boolean check_main_region_FUERA_DE_SERVICIO_r1_ON_LED_tr0_tr0(const Puerta_corrediza* handle);
static sc_boolean check_main_region_FUERA_DE_SERVICIO_r1_OFF_LED_tr0_tr0(const Puerta_corrediza* handle);
static void effect_main_region_PUERTA_CERRADA_tr0(Puerta_corrediza* handle);
static void effect_main_region_PUERTA_ABIERTA_tr0(Puerta_corrediza* handle);
static void effect_main_region_PUERTA_A_CERRAR_tr0(Puerta_corrediza* handle);
static void effect_main_region_PUERTA_A_CERRAR_tr1(Puerta_corrediza* handle);
static void effect_main_region_CERRANDO_tr0(Puerta_corrediza* handle);
static void effect_main_region_CERRANDO_tr1(Puerta_corrediza* handle);
static void effect_main_region_CERRANDO_tr2(Puerta_corrediza* handle);
static void effect_main_region_OBSTACULO_tr0(Puerta_corrediza* handle);
static void effect_main_region_FUERA_DE_SERVICIO_r1_ON_LED_tr0(Puerta_corrediza* handle);
static void effect_main_region_FUERA_DE_SERVICIO_r1_OFF_LED_tr0(Puerta_corrediza* handle);
static void enact_main_region_PUERTA_CERRADA(Puerta_corrediza* handle);
static void enact_main_region_PUERTA_ABIERTA(Puerta_corrediza* handle);
static void enact_main_region_PUERTA_A_CERRAR(Puerta_corrediza* handle);
static void enact_main_region_CERRANDO(Puerta_corrediza* handle);
static void enact_main_region_OBSTACULO(Puerta_corrediza* handle);
static void enact_main_region_FUERA_DE_SERVICIO_r1_ON_LED(Puerta_corrediza* handle);
static void enact_main_region_FUERA_DE_SERVICIO_r1_OFF_LED(Puerta_corrediza* handle);
static void exact_main_region_PUERTA_CERRADA(Puerta_corrediza* handle);
static void exact_main_region_PUERTA_ABIERTA(Puerta_corrediza* handle);
static void exact_main_region_PUERTA_A_CERRAR(Puerta_corrediza* handle);
static void exact_main_region_CERRANDO(Puerta_corrediza* handle);
static void exact_main_region_FUERA_DE_SERVICIO_r1_ON_LED(Puerta_corrediza* handle);
static void exact_main_region_FUERA_DE_SERVICIO_r1_OFF_LED(Puerta_corrediza* handle);
static void enseq_main_region_PUERTA_CERRADA_default(Puerta_corrediza* handle);
static void enseq_main_region_PUERTA_ABIERTA_default(Puerta_corrediza* handle);
static void enseq_main_region_PUERTA_A_CERRAR_default(Puerta_corrediza* handle);
static void enseq_main_region_CERRANDO_default(Puerta_corrediza* handle);
static void enseq_main_region_OBSTACULO_default(Puerta_corrediza* handle);
static void enseq_main_region_FUERA_DE_SERVICIO_default(Puerta_corrediza* handle);
static void enseq_main_region_FUERA_DE_SERVICIO_r1_ON_LED_default(Puerta_corrediza* handle);
static void enseq_main_region_FUERA_DE_SERVICIO_r1_OFF_LED_default(Puerta_corrediza* handle);
static void enseq_main_region_default(Puerta_corrediza* handle);
static void enseq_main_region_FUERA_DE_SERVICIO_r1_default(Puerta_corrediza* handle);
static void exseq_main_region_PUERTA_CERRADA(Puerta_corrediza* handle);
static void exseq_main_region_PUERTA_ABIERTA(Puerta_corrediza* handle);
static void exseq_main_region_PUERTA_A_CERRAR(Puerta_corrediza* handle);
static void exseq_main_region_CERRANDO(Puerta_corrediza* handle);
static void exseq_main_region_OBSTACULO(Puerta_corrediza* handle);
static void exseq_main_region_FUERA_DE_SERVICIO_r1_ON_LED(Puerta_corrediza* handle);
static void exseq_main_region_FUERA_DE_SERVICIO_r1_OFF_LED(Puerta_corrediza* handle);
static void exseq_main_region(Puerta_corrediza* handle);
static void exseq_main_region_FUERA_DE_SERVICIO_r1(Puerta_corrediza* handle);
static void react_main_region_PUERTA_CERRADA(Puerta_corrediza* handle);
static void react_main_region_PUERTA_ABIERTA(Puerta_corrediza* handle);
static void react_main_region_PUERTA_A_CERRAR(Puerta_corrediza* handle);
static void react_main_region_CERRANDO(Puerta_corrediza* handle);
static void react_main_region_OBSTACULO(Puerta_corrediza* handle);
static void react_main_region_FUERA_DE_SERVICIO_r1_ON_LED(Puerta_corrediza* handle);
static void react_main_region_FUERA_DE_SERVICIO_r1_OFF_LED(Puerta_corrediza* handle);
static void react_main_region__entry_Default(Puerta_corrediza* handle);
static void react_main_region_FUERA_DE_SERVICIO_r1__entry_Default(Puerta_corrediza* handle);
static void clearInEvents(Puerta_corrediza* handle);
static void clearOutEvents(Puerta_corrediza* handle);

const sc_integer PUERTA_CORREDIZA_PUERTA_CORREDIZAIFACE_DOOR_1 = 1;
const sc_integer PUERTA_CORREDIZA_PUERTA_CORREDIZAIFACE_SENS_1 = 1;
const sc_integer PUERTA_CORREDIZA_PUERTA_CORREDIZAIFACE_TIME_CLOSE_DOOR = 10;
const sc_integer PUERTA_CORREDIZA_PUERTA_CORREDIZAIFACE_TIME_OPEN_DOOR = 10;
const sc_boolean PUERTA_CORREDIZA_PUERTA_CORREDIZAIFACE_LED_ON = bool_true;
const sc_boolean PUERTA_CORREDIZA_PUERTA_CORREDIZAIFACE_LED_OFF = bool_false;
const sc_integer PUERTA_CORREDIZA_PUERTA_CORREDIZAIFACE_LED1 = 3;
const sc_integer PUERTA_CORREDIZA_PUERTA_CORREDIZAIFACE_LED2 = 4;
const sc_integer PUERTA_CORREDIZA_PUERTA_CORREDIZAIFACE_LED3 = 5;
const sc_integer PUERTA_CORREDIZA_PUERTA_CORREDIZAIFACE_TEC1 = 1 << 0;
const sc_integer PUERTA_CORREDIZA_PUERTA_CORREDIZAIFACE_TEC2 = 1 << 1;
const sc_integer PUERTA_CORREDIZA_PUERTA_CORREDIZAIFACE_TEC3 = 1 << 2;
const sc_integer PUERTA_CORREDIZA_PUERTA_CORREDIZAIFACE_TEC4 = 1 << 3;
const sc_integer PUERTA_CORREDIZA_PUERTA_CORREDIZAIFACE_OUT_OF_SERVICE_TIMEOUT = 6;

void puerta_corrediza_init(Puerta_corrediza* handle)
{
		sc_integer i;
	
		for (i = 0; i < PUERTA_CORREDIZA_MAX_ORTHOGONAL_STATES; ++i)
		{
			handle->stateConfVector[i] = Puerta_corrediza_last_state;
		}
		
		
		handle->stateConfVectorPosition = 0;
	
		clearInEvents(handle);
		clearOutEvents(handle);
	
		/* Default init sequence for statechart puerta_corrediza */
		handle->internal.viflagEmpty = bool_true;
}

void puerta_corrediza_enter(Puerta_corrediza* handle)
{
	/* Default enter sequence for statechart puerta_corrediza */
	enseq_main_region_default(handle);
}

void puerta_corrediza_runCycle(Puerta_corrediza* handle)
{
	clearOutEvents(handle);
	for (handle->stateConfVectorPosition = 0;
		handle->stateConfVectorPosition < PUERTA_CORREDIZA_MAX_ORTHOGONAL_STATES;
		handle->stateConfVectorPosition++)
		{
			
		switch (handle->stateConfVector[handle->stateConfVectorPosition])
		{
		case Puerta_corrediza_main_region_PUERTA_CERRADA:
		{
			react_main_region_PUERTA_CERRADA(handle);
			break;
		}
		case Puerta_corrediza_main_region_PUERTA_ABIERTA:
		{
			react_main_region_PUERTA_ABIERTA(handle);
			break;
		}
		case Puerta_corrediza_main_region_PUERTA_A_CERRAR:
		{
			react_main_region_PUERTA_A_CERRAR(handle);
			break;
		}
		case Puerta_corrediza_main_region_CERRANDO:
		{
			react_main_region_CERRANDO(handle);
			break;
		}
		case Puerta_corrediza_main_region_OBSTACULO:
		{
			react_main_region_OBSTACULO(handle);
			break;
		}
		case Puerta_corrediza_main_region_FUERA_DE_SERVICIO_r1_ON_LED:
		{
			react_main_region_FUERA_DE_SERVICIO_r1_ON_LED(handle);
			break;
		}
		case Puerta_corrediza_main_region_FUERA_DE_SERVICIO_r1_OFF_LED:
		{
			react_main_region_FUERA_DE_SERVICIO_r1_OFF_LED(handle);
			break;
		}
		default:
			break;
		}
	}
	
	clearInEvents(handle);
}

void puerta_corrediza_exit(Puerta_corrediza* handle)
{
	/* Default exit sequence for statechart puerta_corrediza */
	exseq_main_region(handle);
}

sc_boolean puerta_corrediza_isActive(const Puerta_corrediza* handle)
{
	sc_boolean result = bool_false;
	int i;
	
	for(i = 0; i < PUERTA_CORREDIZA_MAX_ORTHOGONAL_STATES; i++)
	{
		result = result || handle->stateConfVector[i] != Puerta_corrediza_last_state;
	}
	
	return result;
}

/* 
 * Always returns 'false' since this state machine can never become final.
 */
sc_boolean puerta_corrediza_isFinal(const Puerta_corrediza* handle)
{
   return bool_false;
}

void puerta_corrediza_raiseTimeEvent(Puerta_corrediza* handle, sc_eventid evid)
{
	if ( ((sc_intptr_t)evid) >= ((sc_intptr_t)&(handle->timeEvents))
		&&  ((sc_intptr_t)evid) < ((sc_intptr_t)&(handle->timeEvents)) + sizeof(Puerta_corredizaTimeEvents))
		{
		*(sc_boolean*)evid = bool_true;
	}		
}

sc_boolean puerta_corrediza_isStateActive(const Puerta_corrediza* handle, Puerta_corredizaStates state)
{
	sc_boolean result = bool_false;
	switch (state)
	{
		case Puerta_corrediza_main_region_PUERTA_CERRADA :
			result = (sc_boolean) (handle->stateConfVector[SCVI_PUERTA_CORREDIZA_MAIN_REGION_PUERTA_CERRADA] == Puerta_corrediza_main_region_PUERTA_CERRADA
			);
			break;
		case Puerta_corrediza_main_region_PUERTA_ABIERTA :
			result = (sc_boolean) (handle->stateConfVector[SCVI_PUERTA_CORREDIZA_MAIN_REGION_PUERTA_ABIERTA] == Puerta_corrediza_main_region_PUERTA_ABIERTA
			);
			break;
		case Puerta_corrediza_main_region_PUERTA_A_CERRAR :
			result = (sc_boolean) (handle->stateConfVector[SCVI_PUERTA_CORREDIZA_MAIN_REGION_PUERTA_A_CERRAR] == Puerta_corrediza_main_region_PUERTA_A_CERRAR
			);
			break;
		case Puerta_corrediza_main_region_CERRANDO :
			result = (sc_boolean) (handle->stateConfVector[SCVI_PUERTA_CORREDIZA_MAIN_REGION_CERRANDO] == Puerta_corrediza_main_region_CERRANDO
			);
			break;
		case Puerta_corrediza_main_region_OBSTACULO :
			result = (sc_boolean) (handle->stateConfVector[SCVI_PUERTA_CORREDIZA_MAIN_REGION_OBSTACULO] == Puerta_corrediza_main_region_OBSTACULO
			);
			break;
		case Puerta_corrediza_main_region_FUERA_DE_SERVICIO :
			result = (sc_boolean) (handle->stateConfVector[SCVI_PUERTA_CORREDIZA_MAIN_REGION_FUERA_DE_SERVICIO] >= Puerta_corrediza_main_region_FUERA_DE_SERVICIO
				&& handle->stateConfVector[SCVI_PUERTA_CORREDIZA_MAIN_REGION_FUERA_DE_SERVICIO] <= Puerta_corrediza_main_region_FUERA_DE_SERVICIO_r1_OFF_LED);
			break;
		case Puerta_corrediza_main_region_FUERA_DE_SERVICIO_r1_ON_LED :
			result = (sc_boolean) (handle->stateConfVector[SCVI_PUERTA_CORREDIZA_MAIN_REGION_FUERA_DE_SERVICIO_R1_ON_LED] == Puerta_corrediza_main_region_FUERA_DE_SERVICIO_r1_ON_LED
			);
			break;
		case Puerta_corrediza_main_region_FUERA_DE_SERVICIO_r1_OFF_LED :
			result = (sc_boolean) (handle->stateConfVector[SCVI_PUERTA_CORREDIZA_MAIN_REGION_FUERA_DE_SERVICIO_R1_OFF_LED] == Puerta_corrediza_main_region_FUERA_DE_SERVICIO_r1_OFF_LED
			);
			break;
		default:
			result = bool_false;
			break;
	}
	return result;
}

static void clearInEvents(Puerta_corrediza* handle)
{
	handle->iface.evSensor_raised = bool_false;
	handle->iface.evFlagEmpty_raised = bool_false;
	handle->iface.evClosed_raised = bool_false;
	handle->iface.evOpen_raised = bool_false;
	handle->timeEvents.puerta_corrediza_main_region_PUERTA_ABIERTA_tev0_raised = bool_false;
	handle->timeEvents.puerta_corrediza_main_region_PUERTA_A_CERRAR_tev0_raised = bool_false;
	handle->timeEvents.puerta_corrediza_main_region_CERRANDO_tev0_raised = bool_false;
	handle->timeEvents.puerta_corrediza_main_region_FUERA_DE_SERVICIO_r1_ON_LED_tev0_raised = bool_false;
	handle->timeEvents.puerta_corrediza_main_region_FUERA_DE_SERVICIO_r1_OFF_LED_tev0_raised = bool_false;
}

static void clearOutEvents(Puerta_corrediza* handle)
{
}

void puerta_corredizaIface_raise_evSensor(Puerta_corrediza* handle)
{
	handle->iface.evSensor_raised = bool_true;
}
void puerta_corredizaIface_raise_evFlagEmpty(Puerta_corrediza* handle, sc_boolean value)
{
	handle->iface.evFlagEmpty_value = value;
	handle->iface.evFlagEmpty_raised = bool_true;
}
void puerta_corredizaIface_raise_evClosed(Puerta_corrediza* handle)
{
	handle->iface.evClosed_raised = bool_true;
}
void puerta_corredizaIface_raise_evOpen(Puerta_corrediza* handle)
{
	handle->iface.evOpen_raised = bool_true;
}


const sc_integer puerta_corredizaIface_get_dOOR_1(const Puerta_corrediza* handle)
{
	return PUERTA_CORREDIZA_PUERTA_CORREDIZAIFACE_DOOR_1;
}
const sc_integer puerta_corredizaIface_get_sENS_1(const Puerta_corrediza* handle)
{
	return PUERTA_CORREDIZA_PUERTA_CORREDIZAIFACE_SENS_1;
}
const sc_integer puerta_corredizaIface_get_tIME_CLOSE_DOOR(const Puerta_corrediza* handle)
{
	return PUERTA_CORREDIZA_PUERTA_CORREDIZAIFACE_TIME_CLOSE_DOOR;
}
const sc_integer puerta_corredizaIface_get_tIME_OPEN_DOOR(const Puerta_corrediza* handle)
{
	return PUERTA_CORREDIZA_PUERTA_CORREDIZAIFACE_TIME_OPEN_DOOR;
}
const sc_boolean puerta_corredizaIface_get_lED_ON(const Puerta_corrediza* handle)
{
	return PUERTA_CORREDIZA_PUERTA_CORREDIZAIFACE_LED_ON;
}
const sc_boolean puerta_corredizaIface_get_lED_OFF(const Puerta_corrediza* handle)
{
	return PUERTA_CORREDIZA_PUERTA_CORREDIZAIFACE_LED_OFF;
}
const sc_integer puerta_corredizaIface_get_lED1(const Puerta_corrediza* handle)
{
	return PUERTA_CORREDIZA_PUERTA_CORREDIZAIFACE_LED1;
}
const sc_integer puerta_corredizaIface_get_lED2(const Puerta_corrediza* handle)
{
	return PUERTA_CORREDIZA_PUERTA_CORREDIZAIFACE_LED2;
}
const sc_integer puerta_corredizaIface_get_lED3(const Puerta_corrediza* handle)
{
	return PUERTA_CORREDIZA_PUERTA_CORREDIZAIFACE_LED3;
}
const sc_integer puerta_corredizaIface_get_tEC1(const Puerta_corrediza* handle)
{
	return PUERTA_CORREDIZA_PUERTA_CORREDIZAIFACE_TEC1;
}
const sc_integer puerta_corredizaIface_get_tEC2(const Puerta_corrediza* handle)
{
	return PUERTA_CORREDIZA_PUERTA_CORREDIZAIFACE_TEC2;
}
const sc_integer puerta_corredizaIface_get_tEC3(const Puerta_corrediza* handle)
{
	return PUERTA_CORREDIZA_PUERTA_CORREDIZAIFACE_TEC3;
}
const sc_integer puerta_corredizaIface_get_tEC4(const Puerta_corrediza* handle)
{
	return PUERTA_CORREDIZA_PUERTA_CORREDIZAIFACE_TEC4;
}
const sc_integer puerta_corredizaIface_get_oUT_OF_SERVICE_TIMEOUT(const Puerta_corrediza* handle)
{
	return PUERTA_CORREDIZA_PUERTA_CORREDIZAIFACE_OUT_OF_SERVICE_TIMEOUT;
}

/* implementations of all internal functions */

static sc_boolean check_main_region_PUERTA_CERRADA_tr0_tr0(const Puerta_corrediza* handle)
{
	return handle->iface.evSensor_raised;
}

static sc_boolean check_main_region_PUERTA_ABIERTA_tr0_tr0(const Puerta_corrediza* handle)
{
	return handle->timeEvents.puerta_corrediza_main_region_PUERTA_ABIERTA_tev0_raised;
}

static sc_boolean check_main_region_PUERTA_A_CERRAR_tr0_tr0(const Puerta_corrediza* handle)
{
	return handle->timeEvents.puerta_corrediza_main_region_PUERTA_A_CERRAR_tev0_raised;
}

static sc_boolean check_main_region_PUERTA_A_CERRAR_tr1_tr1(const Puerta_corrediza* handle)
{
	return handle->iface.evSensor_raised;
}

static sc_boolean check_main_region_CERRANDO_tr0_tr0(const Puerta_corrediza* handle)
{
	return handle->iface.evSensor_raised;
}

static sc_boolean check_main_region_CERRANDO_tr1_tr1(const Puerta_corrediza* handle)
{
	return handle->iface.evClosed_raised;
}

static sc_boolean check_main_region_CERRANDO_tr2_tr2(const Puerta_corrediza* handle)
{
	return handle->timeEvents.puerta_corrediza_main_region_CERRANDO_tev0_raised;
}

static sc_boolean check_main_region_OBSTACULO_tr0_tr0(const Puerta_corrediza* handle)
{
	return handle->iface.evOpen_raised;
}

static sc_boolean check_main_region_FUERA_DE_SERVICIO_r1_ON_LED_tr0_tr0(const Puerta_corrediza* handle)
{
	return handle->timeEvents.puerta_corrediza_main_region_FUERA_DE_SERVICIO_r1_ON_LED_tev0_raised;
}

static sc_boolean check_main_region_FUERA_DE_SERVICIO_r1_OFF_LED_tr0_tr0(const Puerta_corrediza* handle)
{
	return handle->timeEvents.puerta_corrediza_main_region_FUERA_DE_SERVICIO_r1_OFF_LED_tev0_raised;
}

static void effect_main_region_PUERTA_CERRADA_tr0(Puerta_corrediza* handle)
{
	exseq_main_region_PUERTA_CERRADA(handle);
	puerta_corredizaIface_opOpenDoor(handle, PUERTA_CORREDIZA_PUERTA_CORREDIZAIFACE_DOOR_1);
	enseq_main_region_PUERTA_ABIERTA_default(handle);
}

static void effect_main_region_PUERTA_ABIERTA_tr0(Puerta_corrediza* handle)
{
	exseq_main_region_PUERTA_ABIERTA(handle);
	enseq_main_region_PUERTA_A_CERRAR_default(handle);
}

static void effect_main_region_PUERTA_A_CERRAR_tr0(Puerta_corrediza* handle)
{
	exseq_main_region_PUERTA_A_CERRAR(handle);
	enseq_main_region_CERRANDO_default(handle);
}

static void effect_main_region_PUERTA_A_CERRAR_tr1(Puerta_corrediza* handle)
{
	exseq_main_region_PUERTA_A_CERRAR(handle);
	enseq_main_region_PUERTA_ABIERTA_default(handle);
}

static void effect_main_region_CERRANDO_tr0(Puerta_corrediza* handle)
{
	exseq_main_region_CERRANDO(handle);
	enseq_main_region_OBSTACULO_default(handle);
}

static void effect_main_region_CERRANDO_tr1(Puerta_corrediza* handle)
{
	exseq_main_region_CERRANDO(handle);
	enseq_main_region_PUERTA_CERRADA_default(handle);
}

static void effect_main_region_CERRANDO_tr2(Puerta_corrediza* handle)
{
	exseq_main_region_CERRANDO(handle);
	enseq_main_region_FUERA_DE_SERVICIO_default(handle);
}

static void effect_main_region_OBSTACULO_tr0(Puerta_corrediza* handle)
{
	exseq_main_region_OBSTACULO(handle);
	enseq_main_region_PUERTA_ABIERTA_default(handle);
}

static void effect_main_region_FUERA_DE_SERVICIO_r1_ON_LED_tr0(Puerta_corrediza* handle)
{
	exseq_main_region_FUERA_DE_SERVICIO_r1_ON_LED(handle);
	enseq_main_region_FUERA_DE_SERVICIO_r1_OFF_LED_default(handle);
}

static void effect_main_region_FUERA_DE_SERVICIO_r1_OFF_LED_tr0(Puerta_corrediza* handle)
{
	exseq_main_region_FUERA_DE_SERVICIO_r1_OFF_LED(handle);
	enseq_main_region_FUERA_DE_SERVICIO_r1_ON_LED_default(handle);
}

/* Entry action for state 'PUERTA_CERRADA'. */
static void enact_main_region_PUERTA_CERRADA(Puerta_corrediza* handle)
{
	/* Entry action for state 'PUERTA_CERRADA'. */
	puerta_corredizaIface_opFlagClose(handle, handle->internal.viflagEmpty);
	puerta_corredizaIface_opLED(handle, PUERTA_CORREDIZA_PUERTA_CORREDIZAIFACE_LED1, PUERTA_CORREDIZA_PUERTA_CORREDIZAIFACE_LED_ON);
}

/* Entry action for state 'PUERTA_ABIERTA'. */
static void enact_main_region_PUERTA_ABIERTA(Puerta_corrediza* handle)
{
	/* Entry action for state 'PUERTA_ABIERTA'. */
	puerta_corrediza_setTimer(handle, (sc_eventid) &(handle->timeEvents.puerta_corrediza_main_region_PUERTA_ABIERTA_tev0_raised) , 5 * 1000, bool_false);
	puerta_corredizaIface_opLED(handle, PUERTA_CORREDIZA_PUERTA_CORREDIZAIFACE_LED3, PUERTA_CORREDIZA_PUERTA_CORREDIZAIFACE_LED_ON);
}

/* Entry action for state 'PUERTA_A_CERRAR'. */
static void enact_main_region_PUERTA_A_CERRAR(Puerta_corrediza* handle)
{
	/* Entry action for state 'PUERTA_A_CERRAR'. */
	puerta_corrediza_setTimer(handle, (sc_eventid) &(handle->timeEvents.puerta_corrediza_main_region_PUERTA_A_CERRAR_tev0_raised) , 1 * 1000, bool_false);
	handle->internal.viflagEmpty = puerta_corredizaIface_opCheckSensor(handle, PUERTA_CORREDIZA_PUERTA_CORREDIZAIFACE_SENS_1);
}

/* Entry action for state 'CERRANDO'. */
static void enact_main_region_CERRANDO(Puerta_corrediza* handle)
{
	/* Entry action for state 'CERRANDO'. */
	puerta_corrediza_setTimer(handle, (sc_eventid) &(handle->timeEvents.puerta_corrediza_main_region_CERRANDO_tev0_raised) , PUERTA_CORREDIZA_PUERTA_CORREDIZAIFACE_OUT_OF_SERVICE_TIMEOUT * 1000, bool_false);
	puerta_corredizaIface_opCloseDoor(handle, PUERTA_CORREDIZA_PUERTA_CORREDIZAIFACE_DOOR_1);
}

/* Entry action for state 'OBSTACULO'. */
static void enact_main_region_OBSTACULO(Puerta_corrediza* handle)
{
	/* Entry action for state 'OBSTACULO'. */
	puerta_corredizaIface_opOpenDoor(handle, PUERTA_CORREDIZA_PUERTA_CORREDIZAIFACE_DOOR_1);
}

/* Entry action for state 'ON_LED'. */
static void enact_main_region_FUERA_DE_SERVICIO_r1_ON_LED(Puerta_corrediza* handle)
{
	/* Entry action for state 'ON_LED'. */
	puerta_corrediza_setTimer(handle, (sc_eventid) &(handle->timeEvents.puerta_corrediza_main_region_FUERA_DE_SERVICIO_r1_ON_LED_tev0_raised) , 1 * 1000, bool_false);
	puerta_corredizaIface_opLED(handle, PUERTA_CORREDIZA_PUERTA_CORREDIZAIFACE_LED2, PUERTA_CORREDIZA_PUERTA_CORREDIZAIFACE_LED_ON);
}

/* Entry action for state 'OFF_LED'. */
static void enact_main_region_FUERA_DE_SERVICIO_r1_OFF_LED(Puerta_corrediza* handle)
{
	/* Entry action for state 'OFF_LED'. */
	puerta_corrediza_setTimer(handle, (sc_eventid) &(handle->timeEvents.puerta_corrediza_main_region_FUERA_DE_SERVICIO_r1_OFF_LED_tev0_raised) , 1 * 1000, bool_false);
	puerta_corredizaIface_opLED(handle, PUERTA_CORREDIZA_PUERTA_CORREDIZAIFACE_LED2, PUERTA_CORREDIZA_PUERTA_CORREDIZAIFACE_LED_ON);
}

/* Exit action for state 'PUERTA_CERRADA'. */
static void exact_main_region_PUERTA_CERRADA(Puerta_corrediza* handle)
{
	/* Exit action for state 'PUERTA_CERRADA'. */
	puerta_corredizaIface_opLED(handle, PUERTA_CORREDIZA_PUERTA_CORREDIZAIFACE_LED1, PUERTA_CORREDIZA_PUERTA_CORREDIZAIFACE_LED_OFF);
}

/* Exit action for state 'PUERTA_ABIERTA'. */
static void exact_main_region_PUERTA_ABIERTA(Puerta_corrediza* handle)
{
	/* Exit action for state 'PUERTA_ABIERTA'. */
	puerta_corrediza_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.puerta_corrediza_main_region_PUERTA_ABIERTA_tev0_raised) );		
	puerta_corredizaIface_opLED(handle, PUERTA_CORREDIZA_PUERTA_CORREDIZAIFACE_LED3, PUERTA_CORREDIZA_PUERTA_CORREDIZAIFACE_LED_OFF);
}

/* Exit action for state 'PUERTA_A_CERRAR'. */
static void exact_main_region_PUERTA_A_CERRAR(Puerta_corrediza* handle)
{
	/* Exit action for state 'PUERTA_A_CERRAR'. */
	puerta_corrediza_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.puerta_corrediza_main_region_PUERTA_A_CERRAR_tev0_raised) );		
}

/* Exit action for state 'CERRANDO'. */
static void exact_main_region_CERRANDO(Puerta_corrediza* handle)
{
	/* Exit action for state 'CERRANDO'. */
	puerta_corrediza_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.puerta_corrediza_main_region_CERRANDO_tev0_raised) );		
}

/* Exit action for state 'ON_LED'. */
static void exact_main_region_FUERA_DE_SERVICIO_r1_ON_LED(Puerta_corrediza* handle)
{
	/* Exit action for state 'ON_LED'. */
	puerta_corrediza_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.puerta_corrediza_main_region_FUERA_DE_SERVICIO_r1_ON_LED_tev0_raised) );		
}

/* Exit action for state 'OFF_LED'. */
static void exact_main_region_FUERA_DE_SERVICIO_r1_OFF_LED(Puerta_corrediza* handle)
{
	/* Exit action for state 'OFF_LED'. */
	puerta_corrediza_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.puerta_corrediza_main_region_FUERA_DE_SERVICIO_r1_OFF_LED_tev0_raised) );		
}

/* 'default' enter sequence for state PUERTA_CERRADA */
static void enseq_main_region_PUERTA_CERRADA_default(Puerta_corrediza* handle)
{
	/* 'default' enter sequence for state PUERTA_CERRADA */
	enact_main_region_PUERTA_CERRADA(handle);
	handle->stateConfVector[0] = Puerta_corrediza_main_region_PUERTA_CERRADA;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state PUERTA_ABIERTA */
static void enseq_main_region_PUERTA_ABIERTA_default(Puerta_corrediza* handle)
{
	/* 'default' enter sequence for state PUERTA_ABIERTA */
	enact_main_region_PUERTA_ABIERTA(handle);
	handle->stateConfVector[0] = Puerta_corrediza_main_region_PUERTA_ABIERTA;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state PUERTA_A_CERRAR */
static void enseq_main_region_PUERTA_A_CERRAR_default(Puerta_corrediza* handle)
{
	/* 'default' enter sequence for state PUERTA_A_CERRAR */
	enact_main_region_PUERTA_A_CERRAR(handle);
	handle->stateConfVector[0] = Puerta_corrediza_main_region_PUERTA_A_CERRAR;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state CERRANDO */
static void enseq_main_region_CERRANDO_default(Puerta_corrediza* handle)
{
	/* 'default' enter sequence for state CERRANDO */
	enact_main_region_CERRANDO(handle);
	handle->stateConfVector[0] = Puerta_corrediza_main_region_CERRANDO;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state OBSTACULO */
static void enseq_main_region_OBSTACULO_default(Puerta_corrediza* handle)
{
	/* 'default' enter sequence for state OBSTACULO */
	enact_main_region_OBSTACULO(handle);
	handle->stateConfVector[0] = Puerta_corrediza_main_region_OBSTACULO;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state FUERA_DE_SERVICIO */
static void enseq_main_region_FUERA_DE_SERVICIO_default(Puerta_corrediza* handle)
{
	/* 'default' enter sequence for state FUERA_DE_SERVICIO */
	enseq_main_region_FUERA_DE_SERVICIO_r1_default(handle);
}

/* 'default' enter sequence for state ON_LED */
static void enseq_main_region_FUERA_DE_SERVICIO_r1_ON_LED_default(Puerta_corrediza* handle)
{
	/* 'default' enter sequence for state ON_LED */
	enact_main_region_FUERA_DE_SERVICIO_r1_ON_LED(handle);
	handle->stateConfVector[0] = Puerta_corrediza_main_region_FUERA_DE_SERVICIO_r1_ON_LED;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state OFF_LED */
static void enseq_main_region_FUERA_DE_SERVICIO_r1_OFF_LED_default(Puerta_corrediza* handle)
{
	/* 'default' enter sequence for state OFF_LED */
	enact_main_region_FUERA_DE_SERVICIO_r1_OFF_LED(handle);
	handle->stateConfVector[0] = Puerta_corrediza_main_region_FUERA_DE_SERVICIO_r1_OFF_LED;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for region main region */
static void enseq_main_region_default(Puerta_corrediza* handle)
{
	/* 'default' enter sequence for region main region */
	react_main_region__entry_Default(handle);
}

/* 'default' enter sequence for region r1 */
static void enseq_main_region_FUERA_DE_SERVICIO_r1_default(Puerta_corrediza* handle)
{
	/* 'default' enter sequence for region r1 */
	react_main_region_FUERA_DE_SERVICIO_r1__entry_Default(handle);
}

/* Default exit sequence for state PUERTA_CERRADA */
static void exseq_main_region_PUERTA_CERRADA(Puerta_corrediza* handle)
{
	/* Default exit sequence for state PUERTA_CERRADA */
	handle->stateConfVector[0] = Puerta_corrediza_last_state;
	handle->stateConfVectorPosition = 0;
	exact_main_region_PUERTA_CERRADA(handle);
}

/* Default exit sequence for state PUERTA_ABIERTA */
static void exseq_main_region_PUERTA_ABIERTA(Puerta_corrediza* handle)
{
	/* Default exit sequence for state PUERTA_ABIERTA */
	handle->stateConfVector[0] = Puerta_corrediza_last_state;
	handle->stateConfVectorPosition = 0;
	exact_main_region_PUERTA_ABIERTA(handle);
}

/* Default exit sequence for state PUERTA_A_CERRAR */
static void exseq_main_region_PUERTA_A_CERRAR(Puerta_corrediza* handle)
{
	/* Default exit sequence for state PUERTA_A_CERRAR */
	handle->stateConfVector[0] = Puerta_corrediza_last_state;
	handle->stateConfVectorPosition = 0;
	exact_main_region_PUERTA_A_CERRAR(handle);
}

/* Default exit sequence for state CERRANDO */
static void exseq_main_region_CERRANDO(Puerta_corrediza* handle)
{
	/* Default exit sequence for state CERRANDO */
	handle->stateConfVector[0] = Puerta_corrediza_last_state;
	handle->stateConfVectorPosition = 0;
	exact_main_region_CERRANDO(handle);
}

/* Default exit sequence for state OBSTACULO */
static void exseq_main_region_OBSTACULO(Puerta_corrediza* handle)
{
	/* Default exit sequence for state OBSTACULO */
	handle->stateConfVector[0] = Puerta_corrediza_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state ON_LED */
static void exseq_main_region_FUERA_DE_SERVICIO_r1_ON_LED(Puerta_corrediza* handle)
{
	/* Default exit sequence for state ON_LED */
	handle->stateConfVector[0] = Puerta_corrediza_last_state;
	handle->stateConfVectorPosition = 0;
	exact_main_region_FUERA_DE_SERVICIO_r1_ON_LED(handle);
}

/* Default exit sequence for state OFF_LED */
static void exseq_main_region_FUERA_DE_SERVICIO_r1_OFF_LED(Puerta_corrediza* handle)
{
	/* Default exit sequence for state OFF_LED */
	handle->stateConfVector[0] = Puerta_corrediza_last_state;
	handle->stateConfVectorPosition = 0;
	exact_main_region_FUERA_DE_SERVICIO_r1_OFF_LED(handle);
}

/* Default exit sequence for region main region */
static void exseq_main_region(Puerta_corrediza* handle)
{
	/* Default exit sequence for region main region */
	/* Handle exit of all possible states (of puerta_corrediza.main_region) at position 0... */
	switch(handle->stateConfVector[ 0 ])
	{
		case Puerta_corrediza_main_region_PUERTA_CERRADA :
		{
			exseq_main_region_PUERTA_CERRADA(handle);
			break;
		}
		case Puerta_corrediza_main_region_PUERTA_ABIERTA :
		{
			exseq_main_region_PUERTA_ABIERTA(handle);
			break;
		}
		case Puerta_corrediza_main_region_PUERTA_A_CERRAR :
		{
			exseq_main_region_PUERTA_A_CERRAR(handle);
			break;
		}
		case Puerta_corrediza_main_region_CERRANDO :
		{
			exseq_main_region_CERRANDO(handle);
			break;
		}
		case Puerta_corrediza_main_region_OBSTACULO :
		{
			exseq_main_region_OBSTACULO(handle);
			break;
		}
		case Puerta_corrediza_main_region_FUERA_DE_SERVICIO_r1_ON_LED :
		{
			exseq_main_region_FUERA_DE_SERVICIO_r1_ON_LED(handle);
			break;
		}
		case Puerta_corrediza_main_region_FUERA_DE_SERVICIO_r1_OFF_LED :
		{
			exseq_main_region_FUERA_DE_SERVICIO_r1_OFF_LED(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region r1 */
static void exseq_main_region_FUERA_DE_SERVICIO_r1(Puerta_corrediza* handle)
{
	/* Default exit sequence for region r1 */
	/* Handle exit of all possible states (of puerta_corrediza.main_region.FUERA_DE_SERVICIO.r1) at position 0... */
	switch(handle->stateConfVector[ 0 ])
	{
		case Puerta_corrediza_main_region_FUERA_DE_SERVICIO_r1_ON_LED :
		{
			exseq_main_region_FUERA_DE_SERVICIO_r1_ON_LED(handle);
			break;
		}
		case Puerta_corrediza_main_region_FUERA_DE_SERVICIO_r1_OFF_LED :
		{
			exseq_main_region_FUERA_DE_SERVICIO_r1_OFF_LED(handle);
			break;
		}
		default: break;
	}
}

/* The reactions of state PUERTA_CERRADA. */
static void react_main_region_PUERTA_CERRADA(Puerta_corrediza* handle)
{
	/* The reactions of state PUERTA_CERRADA. */
	if (check_main_region_PUERTA_CERRADA_tr0_tr0(handle) == bool_true)
	{ 
		effect_main_region_PUERTA_CERRADA_tr0(handle);
	} 
}

/* The reactions of state PUERTA_ABIERTA. */
static void react_main_region_PUERTA_ABIERTA(Puerta_corrediza* handle)
{
	/* The reactions of state PUERTA_ABIERTA. */
	if (check_main_region_PUERTA_ABIERTA_tr0_tr0(handle) == bool_true)
	{ 
		effect_main_region_PUERTA_ABIERTA_tr0(handle);
	} 
}

/* The reactions of state PUERTA_A_CERRAR. */
static void react_main_region_PUERTA_A_CERRAR(Puerta_corrediza* handle)
{
	/* The reactions of state PUERTA_A_CERRAR. */
	if (check_main_region_PUERTA_A_CERRAR_tr0_tr0(handle) == bool_true)
	{ 
		effect_main_region_PUERTA_A_CERRAR_tr0(handle);
	}  else
	{
		if (check_main_region_PUERTA_A_CERRAR_tr1_tr1(handle) == bool_true)
		{ 
			effect_main_region_PUERTA_A_CERRAR_tr1(handle);
		} 
	}
}

/* The reactions of state CERRANDO. */
static void react_main_region_CERRANDO(Puerta_corrediza* handle)
{
	/* The reactions of state CERRANDO. */
	if (check_main_region_CERRANDO_tr0_tr0(handle) == bool_true)
	{ 
		effect_main_region_CERRANDO_tr0(handle);
	}  else
	{
		if (check_main_region_CERRANDO_tr1_tr1(handle) == bool_true)
		{ 
			effect_main_region_CERRANDO_tr1(handle);
		}  else
		{
			if (check_main_region_CERRANDO_tr2_tr2(handle) == bool_true)
			{ 
				effect_main_region_CERRANDO_tr2(handle);
			} 
		}
	}
}

/* The reactions of state OBSTACULO. */
static void react_main_region_OBSTACULO(Puerta_corrediza* handle)
{
	/* The reactions of state OBSTACULO. */
	if (check_main_region_OBSTACULO_tr0_tr0(handle) == bool_true)
	{ 
		effect_main_region_OBSTACULO_tr0(handle);
	} 
}

/* The reactions of state ON_LED. */
static void react_main_region_FUERA_DE_SERVICIO_r1_ON_LED(Puerta_corrediza* handle)
{
	/* The reactions of state ON_LED. */
	if (check_main_region_FUERA_DE_SERVICIO_r1_ON_LED_tr0_tr0(handle) == bool_true)
	{ 
		effect_main_region_FUERA_DE_SERVICIO_r1_ON_LED_tr0(handle);
	} 
}

/* The reactions of state OFF_LED. */
static void react_main_region_FUERA_DE_SERVICIO_r1_OFF_LED(Puerta_corrediza* handle)
{
	/* The reactions of state OFF_LED. */
	if (check_main_region_FUERA_DE_SERVICIO_r1_OFF_LED_tr0_tr0(handle) == bool_true)
	{ 
		effect_main_region_FUERA_DE_SERVICIO_r1_OFF_LED_tr0(handle);
	} 
}

/* Default react sequence for initial entry  */
static void react_main_region__entry_Default(Puerta_corrediza* handle)
{
	/* Default react sequence for initial entry  */
	enseq_main_region_PUERTA_CERRADA_default(handle);
}

/* Default react sequence for initial entry  */
static void react_main_region_FUERA_DE_SERVICIO_r1__entry_Default(Puerta_corrediza* handle)
{
	/* Default react sequence for initial entry  */
	enseq_main_region_FUERA_DE_SERVICIO_r1_ON_LED_default(handle);
}


