
#include "Ej3.h"
#include "..\inc\sc_types.h"
#include "Ej3Required.h"

#include <stdlib.h>
#include <string.h>
/*! \file Implementation of the state machine 'ej3'
*/

/* prototypes of all internal functions */
static sc_boolean check_TECX_DEBOUNCE_tr0_tr0(const Ej3* handle);
static sc_boolean check_TECX_NO_OPRIMIDO_tr0_tr0(const Ej3* handle);
static sc_boolean check_TECX_OPRIMIDO_tr0_tr0(const Ej3* handle);
static sc_boolean check_TECX_VALIDACION_tr0_tr0(const Ej3* handle);
static sc_boolean check_TECX_VALIDACION_tr1_tr1(const Ej3* handle);
static sc_boolean check_main_region_ESPERA_tr0_tr0(const Ej3* handle);
static sc_boolean check_main_region_ESPERA_tr1_tr1(const Ej3* handle);
static sc_boolean check_main_region_ESPERA_tr2_tr2(const Ej3* handle);
static sc_boolean check_main_region_ESPERA_tr3_tr3(const Ej3* handle);
static sc_boolean check_forma_TRIANGULAR_tr0_tr0(const Ej3* handle);
static sc_boolean check_forma_TRIANGULAR_tr1_tr1(const Ej3* handle);
static sc_boolean check_forma_TRIANGULAR_tr2_tr2(const Ej3* handle);
static sc_boolean check_forma_CUADRADA_tr0_tr0(const Ej3* handle);
static sc_boolean check_forma_CUADRADA_tr1_tr1(const Ej3* handle);
static sc_boolean check_forma_CUADRADA_tr2_tr2(const Ej3* handle);
static sc_boolean check_forma_SENOIDAL_tr0_tr0(const Ej3* handle);
static sc_boolean check_forma_SENOIDAL_tr1_tr1(const Ej3* handle);
static sc_boolean check_forma_SENOIDAL_tr2_tr2(const Ej3* handle);
static sc_boolean check_forma_SELECCION_FORMA_tr0_tr0(const Ej3* handle);
static sc_boolean check_forma_SELECCION_FORMA_tr1_tr1(const Ej3* handle);
static sc_boolean check_forma_FORMA_SELECCIONADA_tr0_tr0(const Ej3* handle);
static sc_boolean check_magnitud_FRECUENCIA_tr0_tr0(const Ej3* handle);
static sc_boolean check_magnitud_TENSION_tr0_tr0(const Ej3* handle);
static sc_boolean check_magnitud_WAIT_SELECCION_MAGNITUD_tr0_tr0(const Ej3* handle);
static sc_boolean check_magnitud_SELECC_MAGNITUD_tr0_tr0(const Ej3* handle);
static sc_boolean check_magnitud_SELECC_MAGNITUD_tr1_tr1(const Ej3* handle);
static sc_boolean check_magnitud_ELEGIR_AMPLITUD_FREC_r1_MAGNITUD_START_tr0_tr0(const Ej3* handle);
static sc_boolean check_magnitud_ELEGIR_AMPLITUD_FREC_r1_MAGNITUD_START_tr1_tr1(const Ej3* handle);
static sc_boolean check_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLI_UP_tr0_tr0(const Ej3* handle);
static sc_boolean check_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLI_UP_tr1_tr1(const Ej3* handle);
static sc_boolean check_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLI_UP_tr2_tr2(const Ej3* handle);
static sc_boolean check_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLI_DOWN_tr0_tr0(const Ej3* handle);
static sc_boolean check_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLI_DOWN_tr1_tr1(const Ej3* handle);
static sc_boolean check_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLI_DOWN_tr2_tr2(const Ej3* handle);
static sc_boolean check_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLITUD_SELECCIONADA_tr0_tr0(const Ej3* handle);
static sc_boolean check_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_MAGNITUD_START_tr0_tr0(const Ej3* handle);
static sc_boolean check_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_MAGNITUD_START_tr1_tr1(const Ej3* handle);
static sc_boolean check_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLI_UP_tr0_tr0(const Ej3* handle);
static sc_boolean check_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLI_UP_tr1_tr1(const Ej3* handle);
static sc_boolean check_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLI_UP_tr2_tr2(const Ej3* handle);
static sc_boolean check_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLI_DOWN_tr0_tr0(const Ej3* handle);
static sc_boolean check_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLI_DOWN_tr1_tr1(const Ej3* handle);
static sc_boolean check_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLI_DOWN_tr2_tr2(const Ej3* handle);
static sc_boolean check_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLITUD_SELECCIONADA_tr0_tr0(const Ej3* handle);
static void effect_TECX_DEBOUNCE_tr0(Ej3* handle);
static void effect_TECX_NO_OPRIMIDO_tr0(Ej3* handle);
static void effect_TECX_OPRIMIDO_tr0(Ej3* handle);
static void effect_TECX_VALIDACION_tr0(Ej3* handle);
static void effect_TECX_VALIDACION_tr1(Ej3* handle);
static void effect_main_region_ESPERA_tr0(Ej3* handle);
static void effect_main_region_ESPERA_tr1(Ej3* handle);
static void effect_main_region_ESPERA_tr2(Ej3* handle);
static void effect_main_region_ESPERA_tr3(Ej3* handle);
static void effect_forma_TRIANGULAR_tr0(Ej3* handle);
static void effect_forma_TRIANGULAR_tr1(Ej3* handle);
static void effect_forma_TRIANGULAR_tr2(Ej3* handle);
static void effect_forma_CUADRADA_tr0(Ej3* handle);
static void effect_forma_CUADRADA_tr1(Ej3* handle);
static void effect_forma_CUADRADA_tr2(Ej3* handle);
static void effect_forma_SENOIDAL_tr0(Ej3* handle);
static void effect_forma_SENOIDAL_tr1(Ej3* handle);
static void effect_forma_SENOIDAL_tr2(Ej3* handle);
static void effect_forma_SELECCION_FORMA_tr0(Ej3* handle);
static void effect_forma_SELECCION_FORMA_tr1(Ej3* handle);
static void effect_forma_FORMA_SELECCIONADA_tr0(Ej3* handle);
static void effect_magnitud_FRECUENCIA_tr0(Ej3* handle);
static void effect_magnitud_TENSION_tr0(Ej3* handle);
static void effect_magnitud_WAIT_SELECCION_MAGNITUD_tr0(Ej3* handle);
static void effect_magnitud_SELECC_MAGNITUD_tr0(Ej3* handle);
static void effect_magnitud_SELECC_MAGNITUD_tr1(Ej3* handle);
static void effect_magnitud_ELEGIR_AMPLITUD_FREC_r1_MAGNITUD_START_tr0(Ej3* handle);
static void effect_magnitud_ELEGIR_AMPLITUD_FREC_r1_MAGNITUD_START_tr1(Ej3* handle);
static void effect_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLI_UP_tr0(Ej3* handle);
static void effect_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLI_UP_tr1(Ej3* handle);
static void effect_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLI_UP_tr2(Ej3* handle);
static void effect_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLI_DOWN_tr0(Ej3* handle);
static void effect_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLI_DOWN_tr1(Ej3* handle);
static void effect_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLI_DOWN_tr2(Ej3* handle);
static void effect_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLITUD_SELECCIONADA_tr0(Ej3* handle);
static void effect_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_MAGNITUD_START_tr0(Ej3* handle);
static void effect_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_MAGNITUD_START_tr1(Ej3* handle);
static void effect_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLI_UP_tr0(Ej3* handle);
static void effect_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLI_UP_tr1(Ej3* handle);
static void effect_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLI_UP_tr2(Ej3* handle);
static void effect_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLI_DOWN_tr0(Ej3* handle);
static void effect_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLI_DOWN_tr1(Ej3* handle);
static void effect_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLI_DOWN_tr2(Ej3* handle);
static void effect_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLITUD_SELECCIONADA_tr0(Ej3* handle);
static void enact_TECX_DEBOUNCE(Ej3* handle);
static void enact_TECX_OPRIMIDO(Ej3* handle);
static void enact_forma_TRIANGULAR(Ej3* handle);
static void enact_forma_CUADRADA(Ej3* handle);
static void enact_forma_SENOIDAL(Ej3* handle);
static void enact_forma_SELECCION_FORMA(Ej3* handle);
static void enact_forma_FORMA_SELECCIONADA(Ej3* handle);
static void enact_magnitud_FRECUENCIA(Ej3* handle);
static void enact_magnitud_TENSION(Ej3* handle);
static void enact_magnitud_WAIT_SELECCION_MAGNITUD(Ej3* handle);
static void enact_magnitud_ELEGIR_AMPLITUD_FREC_r1_MAGNITUD_START(Ej3* handle);
static void enact_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLI_UP(Ej3* handle);
static void enact_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLI_DOWN(Ej3* handle);
static void enact_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLITUD_SELECCIONADA(Ej3* handle);
static void enact_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_MAGNITUD_START(Ej3* handle);
static void enact_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLI_UP(Ej3* handle);
static void enact_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLI_DOWN(Ej3* handle);
static void enact_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLITUD_SELECCIONADA(Ej3* handle);
static void exact_TECX_DEBOUNCE(Ej3* handle);
static void exact_forma_TRIANGULAR(Ej3* handle);
static void exact_forma_CUADRADA(Ej3* handle);
static void exact_forma_SENOIDAL(Ej3* handle);
static void exact_forma_FORMA_SELECCIONADA(Ej3* handle);
static void exact_magnitud_FRECUENCIA(Ej3* handle);
static void exact_magnitud_TENSION(Ej3* handle);
static void exact_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLITUD_SELECCIONADA(Ej3* handle);
static void exact_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLITUD_SELECCIONADA(Ej3* handle);
static void enseq_TECX_DEBOUNCE_default(Ej3* handle);
static void enseq_TECX_NO_OPRIMIDO_default(Ej3* handle);
static void enseq_TECX_OPRIMIDO_default(Ej3* handle);
static void enseq_TECX_VALIDACION_default(Ej3* handle);
static void enseq_main_region_ESPERA_default(Ej3* handle);
static void enseq_forma_TRIANGULAR_default(Ej3* handle);
static void enseq_forma_CUADRADA_default(Ej3* handle);
static void enseq_forma_SENOIDAL_default(Ej3* handle);
static void enseq_forma_SELECCION_FORMA_default(Ej3* handle);
static void enseq_forma_FORMA_SELECCIONADA_default(Ej3* handle);
static void enseq_magnitud_FRECUENCIA_default(Ej3* handle);
static void enseq_magnitud_TENSION_default(Ej3* handle);
static void enseq_magnitud_WAIT_SELECCION_MAGNITUD_default(Ej3* handle);
static void enseq_magnitud_SELECC_MAGNITUD_default(Ej3* handle);
static void enseq_magnitud_ELEGIR_AMPLITUD_FREC_default(Ej3* handle);
static void enseq_magnitud_ELEGIR_AMPLITUD_FREC_r1_MAGNITUD_START_default(Ej3* handle);
static void enseq_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLI_UP_default(Ej3* handle);
static void enseq_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLI_DOWN_default(Ej3* handle);
static void enseq_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLITUD_SELECCIONADA_default(Ej3* handle);
static void enseq_magnitud_ELEGIR_AMPLITUD_VOLTAGE_default(Ej3* handle);
static void enseq_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_MAGNITUD_START_default(Ej3* handle);
static void enseq_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLI_UP_default(Ej3* handle);
static void enseq_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLI_DOWN_default(Ej3* handle);
static void enseq_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLITUD_SELECCIONADA_default(Ej3* handle);
static void enseq_TECX_default(Ej3* handle);
static void enseq_main_region_default(Ej3* handle);
static void enseq_forma_default(Ej3* handle);
static void enseq_magnitud_default(Ej3* handle);
static void enseq_magnitud_ELEGIR_AMPLITUD_FREC_r1_default(Ej3* handle);
static void enseq_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_default(Ej3* handle);
static void exseq_TECX_DEBOUNCE(Ej3* handle);
static void exseq_TECX_NO_OPRIMIDO(Ej3* handle);
static void exseq_TECX_OPRIMIDO(Ej3* handle);
static void exseq_TECX_VALIDACION(Ej3* handle);
static void exseq_main_region_ESPERA(Ej3* handle);
static void exseq_forma_TRIANGULAR(Ej3* handle);
static void exseq_forma_CUADRADA(Ej3* handle);
static void exseq_forma_SENOIDAL(Ej3* handle);
static void exseq_forma_SELECCION_FORMA(Ej3* handle);
static void exseq_forma_FORMA_SELECCIONADA(Ej3* handle);
static void exseq_magnitud_FRECUENCIA(Ej3* handle);
static void exseq_magnitud_TENSION(Ej3* handle);
static void exseq_magnitud_WAIT_SELECCION_MAGNITUD(Ej3* handle);
static void exseq_magnitud_SELECC_MAGNITUD(Ej3* handle);
static void exseq_magnitud_ELEGIR_AMPLITUD_FREC(Ej3* handle);
static void exseq_magnitud_ELEGIR_AMPLITUD_FREC_r1_MAGNITUD_START(Ej3* handle);
static void exseq_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLI_UP(Ej3* handle);
static void exseq_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLI_DOWN(Ej3* handle);
static void exseq_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLITUD_SELECCIONADA(Ej3* handle);
static void exseq_magnitud_ELEGIR_AMPLITUD_VOLTAGE(Ej3* handle);
static void exseq_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_MAGNITUD_START(Ej3* handle);
static void exseq_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLI_UP(Ej3* handle);
static void exseq_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLI_DOWN(Ej3* handle);
static void exseq_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLITUD_SELECCIONADA(Ej3* handle);
static void exseq_TECX(Ej3* handle);
static void exseq_main_region(Ej3* handle);
static void exseq_forma(Ej3* handle);
static void exseq_magnitud(Ej3* handle);
static void exseq_magnitud_ELEGIR_AMPLITUD_FREC_r1(Ej3* handle);
static void exseq_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1(Ej3* handle);
static void react_TECX_DEBOUNCE(Ej3* handle);
static void react_TECX_NO_OPRIMIDO(Ej3* handle);
static void react_TECX_OPRIMIDO(Ej3* handle);
static void react_TECX_VALIDACION(Ej3* handle);
static void react_main_region_ESPERA(Ej3* handle);
static void react_forma_TRIANGULAR(Ej3* handle);
static void react_forma_CUADRADA(Ej3* handle);
static void react_forma_SENOIDAL(Ej3* handle);
static void react_forma_SELECCION_FORMA(Ej3* handle);
static void react_forma_FORMA_SELECCIONADA(Ej3* handle);
static void react_magnitud_FRECUENCIA(Ej3* handle);
static void react_magnitud_TENSION(Ej3* handle);
static void react_magnitud_WAIT_SELECCION_MAGNITUD(Ej3* handle);
static void react_magnitud_SELECC_MAGNITUD(Ej3* handle);
static void react_magnitud_ELEGIR_AMPLITUD_FREC_r1_MAGNITUD_START(Ej3* handle);
static void react_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLI_UP(Ej3* handle);
static void react_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLI_DOWN(Ej3* handle);
static void react_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLITUD_SELECCIONADA(Ej3* handle);
static void react_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_MAGNITUD_START(Ej3* handle);
static void react_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLI_UP(Ej3* handle);
static void react_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLI_DOWN(Ej3* handle);
static void react_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLITUD_SELECCIONADA(Ej3* handle);
static void react_TECX__entry_Default(Ej3* handle);
static void react_main_region__entry_Default(Ej3* handle);
static void react_forma__entry_Default(Ej3* handle);
static void react_magnitud__entry_Default(Ej3* handle);
static void react_magnitud_ELEGIR_AMPLITUD_FREC_r1__entry_Default(Ej3* handle);
static void react_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1__entry_Default(Ej3* handle);
static void clearInEvents(Ej3* handle);
static void clearOutEvents(Ej3* handle);

const sc_integer EJ3_EJ3IFACE_DOOR_1 = 1;
const sc_integer EJ3_EJ3IFACE_SENS_1 = 1;
const sc_integer EJ3_EJ3IFACE_TIME_CLOSE_DOOR = 10;
const sc_integer EJ3_EJ3IFACE_TIME_OPEN_DOOR = 10;
const sc_boolean EJ3_EJ3IFACE_LED_ON = bool_true;
const sc_boolean EJ3_EJ3IFACE_LED_OFF = bool_false;
const sc_integer EJ3_EJ3IFACE_LED1 = 3;
const sc_integer EJ3_EJ3IFACE_LED2 = 4;
const sc_integer EJ3_EJ3IFACE_LED3 = 5;
const sc_integer EJ3_EJ3IFACE_LEDR = 0;
const sc_integer EJ3_EJ3IFACE_TEC1 = 1 << 0;
const sc_integer EJ3_EJ3IFACE_TEC2 = 1 << 1;
const sc_integer EJ3_EJ3IFACE_TEC3 = 1 << 2;
const sc_integer EJ3_EJ3IFACE_TEC4 = 1 << 3;
const sc_integer EJ3_EJ3IFACE_OUT_OF_SERVICE_TIMEOUT = 6;

void ej3_init(Ej3* handle)
{
		sc_integer i;
	
		for (i = 0; i < EJ3_MAX_ORTHOGONAL_STATES; ++i)
		{
			handle->stateConfVector[i] = Ej3_last_state;
		}
		
		
		handle->stateConfVectorPosition = 0;
	
		clearInEvents(handle);
		clearOutEvents(handle);
	
		/* Default init sequence for statechart ej3 */
		handle->internal.viTecla = 0;
		handle->internal.viSetForma = bool_false;
		handle->internal.viSetMagnitud = bool_false;
		handle->internal.viSetMagnitudValue = 0;
}

void ej3_enter(Ej3* handle)
{
	/* Default enter sequence for statechart ej3 */
	enseq_TECX_default(handle);
	enseq_main_region_default(handle);
	enseq_forma_default(handle);
	enseq_magnitud_default(handle);
}

void ej3_runCycle(Ej3* handle)
{
	clearOutEvents(handle);
	for (handle->stateConfVectorPosition = 0;
		handle->stateConfVectorPosition < EJ3_MAX_ORTHOGONAL_STATES;
		handle->stateConfVectorPosition++)
		{
			
		switch (handle->stateConfVector[handle->stateConfVectorPosition])
		{
		case Ej3_TECX_DEBOUNCE:
		{
			react_TECX_DEBOUNCE(handle);
			break;
		}
		case Ej3_TECX_NO_OPRIMIDO:
		{
			react_TECX_NO_OPRIMIDO(handle);
			break;
		}
		case Ej3_TECX_OPRIMIDO:
		{
			react_TECX_OPRIMIDO(handle);
			break;
		}
		case Ej3_TECX_VALIDACION:
		{
			react_TECX_VALIDACION(handle);
			break;
		}
		case Ej3_main_region_ESPERA:
		{
			react_main_region_ESPERA(handle);
			break;
		}
		case Ej3_forma_TRIANGULAR:
		{
			react_forma_TRIANGULAR(handle);
			break;
		}
		case Ej3_forma_CUADRADA:
		{
			react_forma_CUADRADA(handle);
			break;
		}
		case Ej3_forma_SENOIDAL:
		{
			react_forma_SENOIDAL(handle);
			break;
		}
		case Ej3_forma_SELECCION_FORMA:
		{
			react_forma_SELECCION_FORMA(handle);
			break;
		}
		case Ej3_forma_FORMA_SELECCIONADA:
		{
			react_forma_FORMA_SELECCIONADA(handle);
			break;
		}
		case Ej3_magnitud_FRECUENCIA:
		{
			react_magnitud_FRECUENCIA(handle);
			break;
		}
		case Ej3_magnitud_TENSION:
		{
			react_magnitud_TENSION(handle);
			break;
		}
		case Ej3_magnitud_WAIT_SELECCION_MAGNITUD:
		{
			react_magnitud_WAIT_SELECCION_MAGNITUD(handle);
			break;
		}
		case Ej3_magnitud_SELECC_MAGNITUD:
		{
			react_magnitud_SELECC_MAGNITUD(handle);
			break;
		}
		case Ej3_magnitud_ELEGIR_AMPLITUD_FREC_r1_MAGNITUD_START:
		{
			react_magnitud_ELEGIR_AMPLITUD_FREC_r1_MAGNITUD_START(handle);
			break;
		}
		case Ej3_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLI_UP:
		{
			react_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLI_UP(handle);
			break;
		}
		case Ej3_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLI_DOWN:
		{
			react_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLI_DOWN(handle);
			break;
		}
		case Ej3_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLITUD_SELECCIONADA:
		{
			react_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLITUD_SELECCIONADA(handle);
			break;
		}
		case Ej3_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_MAGNITUD_START:
		{
			react_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_MAGNITUD_START(handle);
			break;
		}
		case Ej3_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLI_UP:
		{
			react_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLI_UP(handle);
			break;
		}
		case Ej3_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLI_DOWN:
		{
			react_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLI_DOWN(handle);
			break;
		}
		case Ej3_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLITUD_SELECCIONADA:
		{
			react_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLITUD_SELECCIONADA(handle);
			break;
		}
		default:
			break;
		}
	}
	
	clearInEvents(handle);
}

void ej3_exit(Ej3* handle)
{
	/* Default exit sequence for statechart ej3 */
	exseq_TECX(handle);
	exseq_main_region(handle);
	exseq_forma(handle);
	exseq_magnitud(handle);
}

sc_boolean ej3_isActive(const Ej3* handle)
{
	sc_boolean result = bool_false;
	int i;
	
	for(i = 0; i < EJ3_MAX_ORTHOGONAL_STATES; i++)
	{
		result = result || handle->stateConfVector[i] != Ej3_last_state;
	}
	
	return result;
}

/* 
 * Always returns 'false' since this state machine can never become final.
 */
sc_boolean ej3_isFinal(const Ej3* handle)
{
   return bool_false;
}

void ej3_raiseTimeEvent(Ej3* handle, sc_eventid evid)
{
	if ( ((sc_intptr_t)evid) >= ((sc_intptr_t)&(handle->timeEvents))
		&&  ((sc_intptr_t)evid) < ((sc_intptr_t)&(handle->timeEvents)) + sizeof(Ej3TimeEvents))
		{
		*(sc_boolean*)evid = bool_true;
	}		
}

sc_boolean ej3_isStateActive(const Ej3* handle, Ej3States state)
{
	sc_boolean result = bool_false;
	switch (state)
	{
		case Ej3_TECX_DEBOUNCE :
			result = (sc_boolean) (handle->stateConfVector[SCVI_EJ3_TECX_DEBOUNCE] == Ej3_TECX_DEBOUNCE
			);
			break;
		case Ej3_TECX_NO_OPRIMIDO :
			result = (sc_boolean) (handle->stateConfVector[SCVI_EJ3_TECX_NO_OPRIMIDO] == Ej3_TECX_NO_OPRIMIDO
			);
			break;
		case Ej3_TECX_OPRIMIDO :
			result = (sc_boolean) (handle->stateConfVector[SCVI_EJ3_TECX_OPRIMIDO] == Ej3_TECX_OPRIMIDO
			);
			break;
		case Ej3_TECX_VALIDACION :
			result = (sc_boolean) (handle->stateConfVector[SCVI_EJ3_TECX_VALIDACION] == Ej3_TECX_VALIDACION
			);
			break;
		case Ej3_main_region_ESPERA :
			result = (sc_boolean) (handle->stateConfVector[SCVI_EJ3_MAIN_REGION_ESPERA] == Ej3_main_region_ESPERA
			);
			break;
		case Ej3_forma_TRIANGULAR :
			result = (sc_boolean) (handle->stateConfVector[SCVI_EJ3_FORMA_TRIANGULAR] == Ej3_forma_TRIANGULAR
			);
			break;
		case Ej3_forma_CUADRADA :
			result = (sc_boolean) (handle->stateConfVector[SCVI_EJ3_FORMA_CUADRADA] == Ej3_forma_CUADRADA
			);
			break;
		case Ej3_forma_SENOIDAL :
			result = (sc_boolean) (handle->stateConfVector[SCVI_EJ3_FORMA_SENOIDAL] == Ej3_forma_SENOIDAL
			);
			break;
		case Ej3_forma_SELECCION_FORMA :
			result = (sc_boolean) (handle->stateConfVector[SCVI_EJ3_FORMA_SELECCION_FORMA] == Ej3_forma_SELECCION_FORMA
			);
			break;
		case Ej3_forma_FORMA_SELECCIONADA :
			result = (sc_boolean) (handle->stateConfVector[SCVI_EJ3_FORMA_FORMA_SELECCIONADA] == Ej3_forma_FORMA_SELECCIONADA
			);
			break;
		case Ej3_magnitud_FRECUENCIA :
			result = (sc_boolean) (handle->stateConfVector[SCVI_EJ3_MAGNITUD_FRECUENCIA] == Ej3_magnitud_FRECUENCIA
			);
			break;
		case Ej3_magnitud_TENSION :
			result = (sc_boolean) (handle->stateConfVector[SCVI_EJ3_MAGNITUD_TENSION] == Ej3_magnitud_TENSION
			);
			break;
		case Ej3_magnitud_WAIT_SELECCION_MAGNITUD :
			result = (sc_boolean) (handle->stateConfVector[SCVI_EJ3_MAGNITUD_WAIT_SELECCION_MAGNITUD] == Ej3_magnitud_WAIT_SELECCION_MAGNITUD
			);
			break;
		case Ej3_magnitud_SELECC_MAGNITUD :
			result = (sc_boolean) (handle->stateConfVector[SCVI_EJ3_MAGNITUD_SELECC_MAGNITUD] == Ej3_magnitud_SELECC_MAGNITUD
			);
			break;
		case Ej3_magnitud_ELEGIR_AMPLITUD_FREC :
			result = (sc_boolean) (handle->stateConfVector[SCVI_EJ3_MAGNITUD_ELEGIR_AMPLITUD_FREC] >= Ej3_magnitud_ELEGIR_AMPLITUD_FREC
				&& handle->stateConfVector[SCVI_EJ3_MAGNITUD_ELEGIR_AMPLITUD_FREC] <= Ej3_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLITUD_SELECCIONADA);
			break;
		case Ej3_magnitud_ELEGIR_AMPLITUD_FREC_r1_MAGNITUD_START :
			result = (sc_boolean) (handle->stateConfVector[SCVI_EJ3_MAGNITUD_ELEGIR_AMPLITUD_FREC_R1_MAGNITUD_START] == Ej3_magnitud_ELEGIR_AMPLITUD_FREC_r1_MAGNITUD_START
			);
			break;
		case Ej3_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLI_UP :
			result = (sc_boolean) (handle->stateConfVector[SCVI_EJ3_MAGNITUD_ELEGIR_AMPLITUD_FREC_R1_AMPLI_UP] == Ej3_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLI_UP
			);
			break;
		case Ej3_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLI_DOWN :
			result = (sc_boolean) (handle->stateConfVector[SCVI_EJ3_MAGNITUD_ELEGIR_AMPLITUD_FREC_R1_AMPLI_DOWN] == Ej3_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLI_DOWN
			);
			break;
		case Ej3_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLITUD_SELECCIONADA :
			result = (sc_boolean) (handle->stateConfVector[SCVI_EJ3_MAGNITUD_ELEGIR_AMPLITUD_FREC_R1_AMPLITUD_SELECCIONADA] == Ej3_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLITUD_SELECCIONADA
			);
			break;
		case Ej3_magnitud_ELEGIR_AMPLITUD_VOLTAGE :
			result = (sc_boolean) (handle->stateConfVector[SCVI_EJ3_MAGNITUD_ELEGIR_AMPLITUD_VOLTAGE] >= Ej3_magnitud_ELEGIR_AMPLITUD_VOLTAGE
				&& handle->stateConfVector[SCVI_EJ3_MAGNITUD_ELEGIR_AMPLITUD_VOLTAGE] <= Ej3_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLITUD_SELECCIONADA);
			break;
		case Ej3_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_MAGNITUD_START :
			result = (sc_boolean) (handle->stateConfVector[SCVI_EJ3_MAGNITUD_ELEGIR_AMPLITUD_VOLTAGE_R1_MAGNITUD_START] == Ej3_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_MAGNITUD_START
			);
			break;
		case Ej3_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLI_UP :
			result = (sc_boolean) (handle->stateConfVector[SCVI_EJ3_MAGNITUD_ELEGIR_AMPLITUD_VOLTAGE_R1_AMPLI_UP] == Ej3_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLI_UP
			);
			break;
		case Ej3_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLI_DOWN :
			result = (sc_boolean) (handle->stateConfVector[SCVI_EJ3_MAGNITUD_ELEGIR_AMPLITUD_VOLTAGE_R1_AMPLI_DOWN] == Ej3_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLI_DOWN
			);
			break;
		case Ej3_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLITUD_SELECCIONADA :
			result = (sc_boolean) (handle->stateConfVector[SCVI_EJ3_MAGNITUD_ELEGIR_AMPLITUD_VOLTAGE_R1_AMPLITUD_SELECCIONADA] == Ej3_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLITUD_SELECCIONADA
			);
			break;
		default:
			result = bool_false;
			break;
	}
	return result;
}

static void clearInEvents(Ej3* handle)
{
	handle->iface.evTECXOprimido_raised = bool_false;
	handle->iface.evTECXNoOprimido_raised = bool_false;
	handle->internal.siTECXOK_raised = bool_false;
	handle->internal.siMagnitud_raised = bool_false;
	handle->internal.siForma_raised = bool_false;
	handle->internal.siUp_raised = bool_false;
	handle->internal.siDown_raised = bool_false;
	handle->timeEvents.ej3_TECX_DEBOUNCE_tev0_raised = bool_false;
	handle->timeEvents.ej3_forma_FORMA_SELECCIONADA_tev0_raised = bool_false;
	handle->timeEvents.ej3_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLITUD_SELECCIONADA_tev0_raised = bool_false;
	handle->timeEvents.ej3_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLITUD_SELECCIONADA_tev0_raised = bool_false;
}

static void clearOutEvents(Ej3* handle)
{
}

void ej3Iface_raise_evTECXOprimido(Ej3* handle, sc_integer value)
{
	handle->iface.evTECXOprimido_value = value;
	handle->iface.evTECXOprimido_raised = bool_true;
}
void ej3Iface_raise_evTECXNoOprimido(Ej3* handle)
{
	handle->iface.evTECXNoOprimido_raised = bool_true;
}


const sc_integer ej3Iface_get_dOOR_1(const Ej3* handle)
{
	return EJ3_EJ3IFACE_DOOR_1;
}
const sc_integer ej3Iface_get_sENS_1(const Ej3* handle)
{
	return EJ3_EJ3IFACE_SENS_1;
}
const sc_integer ej3Iface_get_tIME_CLOSE_DOOR(const Ej3* handle)
{
	return EJ3_EJ3IFACE_TIME_CLOSE_DOOR;
}
const sc_integer ej3Iface_get_tIME_OPEN_DOOR(const Ej3* handle)
{
	return EJ3_EJ3IFACE_TIME_OPEN_DOOR;
}
const sc_boolean ej3Iface_get_lED_ON(const Ej3* handle)
{
	return EJ3_EJ3IFACE_LED_ON;
}
const sc_boolean ej3Iface_get_lED_OFF(const Ej3* handle)
{
	return EJ3_EJ3IFACE_LED_OFF;
}
const sc_integer ej3Iface_get_lED1(const Ej3* handle)
{
	return EJ3_EJ3IFACE_LED1;
}
const sc_integer ej3Iface_get_lED2(const Ej3* handle)
{
	return EJ3_EJ3IFACE_LED2;
}
const sc_integer ej3Iface_get_lED3(const Ej3* handle)
{
	return EJ3_EJ3IFACE_LED3;
}
const sc_integer ej3Iface_get_lEDR(const Ej3* handle)
{
	return EJ3_EJ3IFACE_LEDR;
}
const sc_integer ej3Iface_get_tEC1(const Ej3* handle)
{
	return EJ3_EJ3IFACE_TEC1;
}
const sc_integer ej3Iface_get_tEC2(const Ej3* handle)
{
	return EJ3_EJ3IFACE_TEC2;
}
const sc_integer ej3Iface_get_tEC3(const Ej3* handle)
{
	return EJ3_EJ3IFACE_TEC3;
}
const sc_integer ej3Iface_get_tEC4(const Ej3* handle)
{
	return EJ3_EJ3IFACE_TEC4;
}
const sc_integer ej3Iface_get_oUT_OF_SERVICE_TIMEOUT(const Ej3* handle)
{
	return EJ3_EJ3IFACE_OUT_OF_SERVICE_TIMEOUT;
}

/* implementations of all internal functions */

static sc_boolean check_TECX_DEBOUNCE_tr0_tr0(const Ej3* handle)
{
	return handle->timeEvents.ej3_TECX_DEBOUNCE_tev0_raised;
}

static sc_boolean check_TECX_NO_OPRIMIDO_tr0_tr0(const Ej3* handle)
{
	return handle->iface.evTECXOprimido_raised;
}

static sc_boolean check_TECX_OPRIMIDO_tr0_tr0(const Ej3* handle)
{
	return handle->iface.evTECXNoOprimido_raised;
}

static sc_boolean check_TECX_VALIDACION_tr0_tr0(const Ej3* handle)
{
	return handle->iface.evTECXNoOprimido_raised;
}

static sc_boolean check_TECX_VALIDACION_tr1_tr1(const Ej3* handle)
{
	return handle->iface.evTECXOprimido_raised;
}

static sc_boolean check_main_region_ESPERA_tr0_tr0(const Ej3* handle)
{
	return ((handle->internal.siTECXOK_raised) && (handle->internal.viTecla == EJ3_EJ3IFACE_TEC2 && handle->internal.viSetForma == bool_false)) ? bool_true : bool_false;
}

static sc_boolean check_main_region_ESPERA_tr1_tr1(const Ej3* handle)
{
	return ((handle->internal.siTECXOK_raised) && (handle->internal.viTecla == EJ3_EJ3IFACE_TEC1 && handle->internal.viSetMagnitud == bool_false)) ? bool_true : bool_false;
}

static sc_boolean check_main_region_ESPERA_tr2_tr2(const Ej3* handle)
{
	return ((handle->internal.siTECXOK_raised) && (handle->internal.viTecla == EJ3_EJ3IFACE_TEC3)) ? bool_true : bool_false;
}

static sc_boolean check_main_region_ESPERA_tr3_tr3(const Ej3* handle)
{
	return ((handle->internal.siTECXOK_raised) && (handle->internal.viTecla == EJ3_EJ3IFACE_TEC4)) ? bool_true : bool_false;
}

static sc_boolean check_forma_TRIANGULAR_tr0_tr0(const Ej3* handle)
{
	return ((handle->internal.siUp_raised) && (handle->internal.viSetForma == bool_true)) ? bool_true : bool_false;
}

static sc_boolean check_forma_TRIANGULAR_tr1_tr1(const Ej3* handle)
{
	return ((handle->internal.siDown_raised) && (handle->internal.viSetForma == bool_true)) ? bool_true : bool_false;
}

static sc_boolean check_forma_TRIANGULAR_tr2_tr2(const Ej3* handle)
{
	return ((handle->internal.siForma_raised) && (handle->internal.viSetForma == bool_true)) ? bool_true : bool_false;
}

static sc_boolean check_forma_CUADRADA_tr0_tr0(const Ej3* handle)
{
	return ((handle->internal.siUp_raised) && (handle->internal.viSetForma == bool_true)) ? bool_true : bool_false;
}

static sc_boolean check_forma_CUADRADA_tr1_tr1(const Ej3* handle)
{
	return ((handle->internal.siDown_raised) && (handle->internal.viSetForma == bool_true)) ? bool_true : bool_false;
}

static sc_boolean check_forma_CUADRADA_tr2_tr2(const Ej3* handle)
{
	return ((handle->internal.siForma_raised) && (handle->internal.viSetForma == bool_true)) ? bool_true : bool_false;
}

static sc_boolean check_forma_SENOIDAL_tr0_tr0(const Ej3* handle)
{
	return ((handle->internal.siUp_raised) && (handle->internal.viSetForma == bool_true)) ? bool_true : bool_false;
}

static sc_boolean check_forma_SENOIDAL_tr1_tr1(const Ej3* handle)
{
	return ((handle->internal.siDown_raised) && (handle->internal.viSetForma == bool_true)) ? bool_true : bool_false;
}

static sc_boolean check_forma_SENOIDAL_tr2_tr2(const Ej3* handle)
{
	return ((handle->internal.siForma_raised) && (handle->internal.viSetForma == bool_true)) ? bool_true : bool_false;
}

static sc_boolean check_forma_SELECCION_FORMA_tr0_tr0(const Ej3* handle)
{
	return ((handle->internal.siDown_raised) && (handle->internal.viSetForma == bool_true)) ? bool_true : bool_false;
}

static sc_boolean check_forma_SELECCION_FORMA_tr1_tr1(const Ej3* handle)
{
	return ((handle->internal.siUp_raised) && (handle->internal.viSetForma == bool_true)) ? bool_true : bool_false;
}

static sc_boolean check_forma_FORMA_SELECCIONADA_tr0_tr0(const Ej3* handle)
{
	return handle->timeEvents.ej3_forma_FORMA_SELECCIONADA_tev0_raised;
}

static sc_boolean check_magnitud_FRECUENCIA_tr0_tr0(const Ej3* handle)
{
	return handle->internal.siMagnitud_raised;
}

static sc_boolean check_magnitud_TENSION_tr0_tr0(const Ej3* handle)
{
	return handle->internal.siMagnitud_raised;
}

static sc_boolean check_magnitud_WAIT_SELECCION_MAGNITUD_tr0_tr0(const Ej3* handle)
{
	return handle->internal.siMagnitud_raised;
}

static sc_boolean check_magnitud_SELECC_MAGNITUD_tr0_tr0(const Ej3* handle)
{
	return handle->internal.siDown_raised;
}

static sc_boolean check_magnitud_SELECC_MAGNITUD_tr1_tr1(const Ej3* handle)
{
	return handle->internal.siUp_raised;
}

static sc_boolean check_magnitud_ELEGIR_AMPLITUD_FREC_r1_MAGNITUD_START_tr0_tr0(const Ej3* handle)
{
	return handle->internal.siUp_raised;
}

static sc_boolean check_magnitud_ELEGIR_AMPLITUD_FREC_r1_MAGNITUD_START_tr1_tr1(const Ej3* handle)
{
	return handle->internal.siDown_raised;
}

static sc_boolean check_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLI_UP_tr0_tr0(const Ej3* handle)
{
	return handle->internal.siDown_raised;
}

static sc_boolean check_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLI_UP_tr1_tr1(const Ej3* handle)
{
	return handle->internal.siUp_raised;
}

static sc_boolean check_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLI_UP_tr2_tr2(const Ej3* handle)
{
	return handle->internal.siMagnitud_raised;
}

static sc_boolean check_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLI_DOWN_tr0_tr0(const Ej3* handle)
{
	return handle->internal.siDown_raised;
}

static sc_boolean check_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLI_DOWN_tr1_tr1(const Ej3* handle)
{
	return handle->internal.siUp_raised;
}

static sc_boolean check_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLI_DOWN_tr2_tr2(const Ej3* handle)
{
	return handle->internal.siMagnitud_raised;
}

static sc_boolean check_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLITUD_SELECCIONADA_tr0_tr0(const Ej3* handle)
{
	return handle->timeEvents.ej3_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLITUD_SELECCIONADA_tev0_raised;
}

static sc_boolean check_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_MAGNITUD_START_tr0_tr0(const Ej3* handle)
{
	return handle->internal.siUp_raised;
}

static sc_boolean check_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_MAGNITUD_START_tr1_tr1(const Ej3* handle)
{
	return handle->internal.siDown_raised;
}

static sc_boolean check_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLI_UP_tr0_tr0(const Ej3* handle)
{
	return handle->internal.siDown_raised;
}

static sc_boolean check_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLI_UP_tr1_tr1(const Ej3* handle)
{
	return handle->internal.siUp_raised;
}

static sc_boolean check_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLI_UP_tr2_tr2(const Ej3* handle)
{
	return handle->internal.siMagnitud_raised;
}

static sc_boolean check_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLI_DOWN_tr0_tr0(const Ej3* handle)
{
	return handle->internal.siDown_raised;
}

static sc_boolean check_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLI_DOWN_tr1_tr1(const Ej3* handle)
{
	return handle->internal.siUp_raised;
}

static sc_boolean check_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLI_DOWN_tr2_tr2(const Ej3* handle)
{
	return handle->internal.siMagnitud_raised;
}

static sc_boolean check_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLITUD_SELECCIONADA_tr0_tr0(const Ej3* handle)
{
	return handle->timeEvents.ej3_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLITUD_SELECCIONADA_tev0_raised;
}

static void effect_TECX_DEBOUNCE_tr0(Ej3* handle)
{
	exseq_TECX_DEBOUNCE(handle);
	enseq_TECX_VALIDACION_default(handle);
}

static void effect_TECX_NO_OPRIMIDO_tr0(Ej3* handle)
{
	exseq_TECX_NO_OPRIMIDO(handle);
	enseq_TECX_DEBOUNCE_default(handle);
}

static void effect_TECX_OPRIMIDO_tr0(Ej3* handle)
{
	exseq_TECX_OPRIMIDO(handle);
	enseq_TECX_NO_OPRIMIDO_default(handle);
}

static void effect_TECX_VALIDACION_tr0(Ej3* handle)
{
	exseq_TECX_VALIDACION(handle);
	enseq_TECX_NO_OPRIMIDO_default(handle);
}

static void effect_TECX_VALIDACION_tr1(Ej3* handle)
{
	exseq_TECX_VALIDACION(handle);
	enseq_TECX_OPRIMIDO_default(handle);
}

static void effect_main_region_ESPERA_tr0(Ej3* handle)
{
	exseq_main_region_ESPERA(handle);
	handle->internal.siMagnitud_raised = bool_true;
	handle->internal.viSetMagnitud = bool_true;
	enseq_main_region_ESPERA_default(handle);
}

static void effect_main_region_ESPERA_tr1(Ej3* handle)
{
	exseq_main_region_ESPERA(handle);
	handle->internal.siForma_raised = bool_true;
	handle->internal.viSetForma = bool_true;
	enseq_main_region_ESPERA_default(handle);
}

static void effect_main_region_ESPERA_tr2(Ej3* handle)
{
	exseq_main_region_ESPERA(handle);
	handle->internal.siUp_raised = bool_true;
	enseq_main_region_ESPERA_default(handle);
}

static void effect_main_region_ESPERA_tr3(Ej3* handle)
{
	exseq_main_region_ESPERA(handle);
	handle->internal.siDown_raised = bool_true;
	enseq_main_region_ESPERA_default(handle);
}

static void effect_forma_TRIANGULAR_tr0(Ej3* handle)
{
	exseq_forma_TRIANGULAR(handle);
	enseq_forma_CUADRADA_default(handle);
}

static void effect_forma_TRIANGULAR_tr1(Ej3* handle)
{
	exseq_forma_TRIANGULAR(handle);
	enseq_forma_SENOIDAL_default(handle);
}

static void effect_forma_TRIANGULAR_tr2(Ej3* handle)
{
	exseq_forma_TRIANGULAR(handle);
	enseq_forma_FORMA_SELECCIONADA_default(handle);
}

static void effect_forma_CUADRADA_tr0(Ej3* handle)
{
	exseq_forma_CUADRADA(handle);
	enseq_forma_SENOIDAL_default(handle);
}

static void effect_forma_CUADRADA_tr1(Ej3* handle)
{
	exseq_forma_CUADRADA(handle);
	enseq_forma_TRIANGULAR_default(handle);
}

static void effect_forma_CUADRADA_tr2(Ej3* handle)
{
	exseq_forma_CUADRADA(handle);
	enseq_forma_FORMA_SELECCIONADA_default(handle);
}

static void effect_forma_SENOIDAL_tr0(Ej3* handle)
{
	exseq_forma_SENOIDAL(handle);
	enseq_forma_TRIANGULAR_default(handle);
}

static void effect_forma_SENOIDAL_tr1(Ej3* handle)
{
	exseq_forma_SENOIDAL(handle);
	enseq_forma_CUADRADA_default(handle);
}

static void effect_forma_SENOIDAL_tr2(Ej3* handle)
{
	exseq_forma_SENOIDAL(handle);
	enseq_forma_FORMA_SELECCIONADA_default(handle);
}

static void effect_forma_SELECCION_FORMA_tr0(Ej3* handle)
{
	exseq_forma_SELECCION_FORMA(handle);
	enseq_forma_TRIANGULAR_default(handle);
}

static void effect_forma_SELECCION_FORMA_tr1(Ej3* handle)
{
	exseq_forma_SELECCION_FORMA(handle);
	enseq_forma_CUADRADA_default(handle);
}

static void effect_forma_FORMA_SELECCIONADA_tr0(Ej3* handle)
{
	exseq_forma_FORMA_SELECCIONADA(handle);
	enseq_forma_SELECCION_FORMA_default(handle);
}

static void effect_magnitud_FRECUENCIA_tr0(Ej3* handle)
{
	exseq_magnitud_FRECUENCIA(handle);
	enseq_magnitud_ELEGIR_AMPLITUD_FREC_default(handle);
}

static void effect_magnitud_TENSION_tr0(Ej3* handle)
{
	exseq_magnitud_TENSION(handle);
	enseq_magnitud_ELEGIR_AMPLITUD_VOLTAGE_default(handle);
}

static void effect_magnitud_WAIT_SELECCION_MAGNITUD_tr0(Ej3* handle)
{
	exseq_magnitud_WAIT_SELECCION_MAGNITUD(handle);
	enseq_magnitud_SELECC_MAGNITUD_default(handle);
}

static void effect_magnitud_SELECC_MAGNITUD_tr0(Ej3* handle)
{
	exseq_magnitud_SELECC_MAGNITUD(handle);
	enseq_magnitud_TENSION_default(handle);
}

static void effect_magnitud_SELECC_MAGNITUD_tr1(Ej3* handle)
{
	exseq_magnitud_SELECC_MAGNITUD(handle);
	enseq_magnitud_FRECUENCIA_default(handle);
}

static void effect_magnitud_ELEGIR_AMPLITUD_FREC_r1_MAGNITUD_START_tr0(Ej3* handle)
{
	exseq_magnitud_ELEGIR_AMPLITUD_FREC_r1_MAGNITUD_START(handle);
	enseq_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLI_UP_default(handle);
}

static void effect_magnitud_ELEGIR_AMPLITUD_FREC_r1_MAGNITUD_START_tr1(Ej3* handle)
{
	exseq_magnitud_ELEGIR_AMPLITUD_FREC_r1_MAGNITUD_START(handle);
	enseq_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLI_DOWN_default(handle);
}

static void effect_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLI_UP_tr0(Ej3* handle)
{
	exseq_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLI_UP(handle);
	enseq_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLI_DOWN_default(handle);
}

static void effect_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLI_UP_tr1(Ej3* handle)
{
	exseq_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLI_UP(handle);
	enseq_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLI_UP_default(handle);
}

static void effect_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLI_UP_tr2(Ej3* handle)
{
	exseq_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLI_UP(handle);
	enseq_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLITUD_SELECCIONADA_default(handle);
}

static void effect_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLI_DOWN_tr0(Ej3* handle)
{
	exseq_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLI_DOWN(handle);
	enseq_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLI_DOWN_default(handle);
}

static void effect_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLI_DOWN_tr1(Ej3* handle)
{
	exseq_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLI_DOWN(handle);
	enseq_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLI_UP_default(handle);
}

static void effect_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLI_DOWN_tr2(Ej3* handle)
{
	exseq_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLI_DOWN(handle);
	enseq_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLITUD_SELECCIONADA_default(handle);
}

static void effect_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLITUD_SELECCIONADA_tr0(Ej3* handle)
{
	exseq_magnitud_ELEGIR_AMPLITUD_FREC(handle);
	enseq_magnitud_WAIT_SELECCION_MAGNITUD_default(handle);
}

static void effect_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_MAGNITUD_START_tr0(Ej3* handle)
{
	exseq_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_MAGNITUD_START(handle);
	enseq_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLI_UP_default(handle);
}

static void effect_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_MAGNITUD_START_tr1(Ej3* handle)
{
	exseq_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_MAGNITUD_START(handle);
	enseq_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLI_DOWN_default(handle);
}

static void effect_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLI_UP_tr0(Ej3* handle)
{
	exseq_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLI_UP(handle);
	enseq_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLI_DOWN_default(handle);
}

static void effect_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLI_UP_tr1(Ej3* handle)
{
	exseq_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLI_UP(handle);
	enseq_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLI_UP_default(handle);
}

static void effect_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLI_UP_tr2(Ej3* handle)
{
	exseq_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLI_UP(handle);
	enseq_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLITUD_SELECCIONADA_default(handle);
}

static void effect_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLI_DOWN_tr0(Ej3* handle)
{
	exseq_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLI_DOWN(handle);
	enseq_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLI_DOWN_default(handle);
}

static void effect_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLI_DOWN_tr1(Ej3* handle)
{
	exseq_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLI_DOWN(handle);
	enseq_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLI_UP_default(handle);
}

static void effect_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLI_DOWN_tr2(Ej3* handle)
{
	exseq_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLI_DOWN(handle);
	enseq_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLITUD_SELECCIONADA_default(handle);
}

static void effect_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLITUD_SELECCIONADA_tr0(Ej3* handle)
{
	exseq_magnitud_ELEGIR_AMPLITUD_VOLTAGE(handle);
	enseq_magnitud_WAIT_SELECCION_MAGNITUD_default(handle);
}

/* Entry action for state 'DEBOUNCE'. */
static void enact_TECX_DEBOUNCE(Ej3* handle)
{
	/* Entry action for state 'DEBOUNCE'. */
	ej3_setTimer(handle, (sc_eventid) &(handle->timeEvents.ej3_TECX_DEBOUNCE_tev0_raised) , 100, bool_false);
}

/* Entry action for state 'OPRIMIDO'. */
static void enact_TECX_OPRIMIDO(Ej3* handle)
{
	/* Entry action for state 'OPRIMIDO'. */
	handle->internal.siTECXOK_raised = bool_true;
	handle->internal.viTecla = handle->iface.evTECXOprimido_value;
}

/* Entry action for state 'TRIANGULAR'. */
static void enact_forma_TRIANGULAR(Ej3* handle)
{
	/* Entry action for state 'TRIANGULAR'. */
	ej3Iface_opSetForma(handle, "Triangular");
	ej3Iface_opLED(handle, EJ3_EJ3IFACE_LED3, EJ3_EJ3IFACE_LED_ON);
}

/* Entry action for state 'CUADRADA'. */
static void enact_forma_CUADRADA(Ej3* handle)
{
	/* Entry action for state 'CUADRADA'. */
	ej3Iface_opSetForma(handle, "Cuadrada");
	ej3Iface_opLED(handle, EJ3_EJ3IFACE_LED1, EJ3_EJ3IFACE_LED_ON);
}

/* Entry action for state 'SENOIDAL'. */
static void enact_forma_SENOIDAL(Ej3* handle)
{
	/* Entry action for state 'SENOIDAL'. */
	ej3Iface_opSetForma(handle, "Senoidal");
	ej3Iface_opLED(handle, EJ3_EJ3IFACE_LED2, EJ3_EJ3IFACE_LED_ON);
}

/* Entry action for state 'SELECCION_FORMA'. */
static void enact_forma_SELECCION_FORMA(Ej3* handle)
{
	/* Entry action for state 'SELECCION_FORMA'. */
	handle->internal.viSetForma = bool_false;
}

/* Entry action for state 'FORMA_SELECCIONADA'. */
static void enact_forma_FORMA_SELECCIONADA(Ej3* handle)
{
	/* Entry action for state 'FORMA_SELECCIONADA'. */
	ej3_setTimer(handle, (sc_eventid) &(handle->timeEvents.ej3_forma_FORMA_SELECCIONADA_tev0_raised) , 10, bool_false);
}

/* Entry action for state 'FRECUENCIA'. */
static void enact_magnitud_FRECUENCIA(Ej3* handle)
{
	/* Entry action for state 'FRECUENCIA'. */
	ej3Iface_opLED(handle, EJ3_EJ3IFACE_LED2, EJ3_EJ3IFACE_LED_ON);
}

/* Entry action for state 'TENSION'. */
static void enact_magnitud_TENSION(Ej3* handle)
{
	/* Entry action for state 'TENSION'. */
	ej3Iface_opLED(handle, EJ3_EJ3IFACE_LED3, EJ3_EJ3IFACE_LED_ON);
}

/* Entry action for state 'WAIT_SELECCION_MAGNITUD'. */
static void enact_magnitud_WAIT_SELECCION_MAGNITUD(Ej3* handle)
{
	/* Entry action for state 'WAIT_SELECCION_MAGNITUD'. */
	handle->internal.viSetMagnitud = bool_false;
}

/* Entry action for state 'MAGNITUD_START'. */
static void enact_magnitud_ELEGIR_AMPLITUD_FREC_r1_MAGNITUD_START(Ej3* handle)
{
	/* Entry action for state 'MAGNITUD_START'. */
	handle->internal.viSetMagnitudValue = 0;
}

/* Entry action for state 'AMPLI_UP'. */
static void enact_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLI_UP(Ej3* handle)
{
	/* Entry action for state 'AMPLI_UP'. */
	ej3Iface_opAmplitudUp(handle, handle->internal.viSetMagnitudValue);
}

/* Entry action for state 'AMPLI_DOWN'. */
static void enact_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLI_DOWN(Ej3* handle)
{
	/* Entry action for state 'AMPLI_DOWN'. */
	ej3Iface_opAmplitudDown(handle, handle->internal.viSetMagnitudValue);
}

/* Entry action for state 'AMPLITUD_SELECCIONADA'. */
static void enact_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLITUD_SELECCIONADA(Ej3* handle)
{
	/* Entry action for state 'AMPLITUD_SELECCIONADA'. */
	ej3_setTimer(handle, (sc_eventid) &(handle->timeEvents.ej3_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLITUD_SELECCIONADA_tev0_raised) , 10, bool_false);
	ej3Iface_opSetAmplitudFrec(handle, handle->internal.viSetMagnitudValue);
}

/* Entry action for state 'MAGNITUD_START'. */
static void enact_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_MAGNITUD_START(Ej3* handle)
{
	/* Entry action for state 'MAGNITUD_START'. */
	handle->internal.viSetMagnitudValue = 0;
}

/* Entry action for state 'AMPLI_UP'. */
static void enact_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLI_UP(Ej3* handle)
{
	/* Entry action for state 'AMPLI_UP'. */
	ej3Iface_opAmplitudUp(handle, handle->internal.viSetMagnitudValue);
}

/* Entry action for state 'AMPLI_DOWN'. */
static void enact_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLI_DOWN(Ej3* handle)
{
	/* Entry action for state 'AMPLI_DOWN'. */
	ej3Iface_opAmplitudDown(handle, handle->internal.viSetMagnitudValue);
}

/* Entry action for state 'AMPLITUD_SELECCIONADA'. */
static void enact_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLITUD_SELECCIONADA(Ej3* handle)
{
	/* Entry action for state 'AMPLITUD_SELECCIONADA'. */
	ej3_setTimer(handle, (sc_eventid) &(handle->timeEvents.ej3_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLITUD_SELECCIONADA_tev0_raised) , 10, bool_false);
	ej3Iface_opSetAmplitudVoltage(handle, handle->internal.viSetMagnitudValue);
}

/* Exit action for state 'DEBOUNCE'. */
static void exact_TECX_DEBOUNCE(Ej3* handle)
{
	/* Exit action for state 'DEBOUNCE'. */
	ej3_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.ej3_TECX_DEBOUNCE_tev0_raised) );		
}

/* Exit action for state 'TRIANGULAR'. */
static void exact_forma_TRIANGULAR(Ej3* handle)
{
	/* Exit action for state 'TRIANGULAR'. */
	ej3Iface_opLED(handle, EJ3_EJ3IFACE_LED3, EJ3_EJ3IFACE_LED_OFF);
}

/* Exit action for state 'CUADRADA'. */
static void exact_forma_CUADRADA(Ej3* handle)
{
	/* Exit action for state 'CUADRADA'. */
	ej3Iface_opLED(handle, EJ3_EJ3IFACE_LED1, EJ3_EJ3IFACE_LED_OFF);
}

/* Exit action for state 'SENOIDAL'. */
static void exact_forma_SENOIDAL(Ej3* handle)
{
	/* Exit action for state 'SENOIDAL'. */
	ej3Iface_opLED(handle, EJ3_EJ3IFACE_LED2, EJ3_EJ3IFACE_LED_OFF);
}

/* Exit action for state 'FORMA_SELECCIONADA'. */
static void exact_forma_FORMA_SELECCIONADA(Ej3* handle)
{
	/* Exit action for state 'FORMA_SELECCIONADA'. */
	ej3_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.ej3_forma_FORMA_SELECCIONADA_tev0_raised) );		
}

/* Exit action for state 'FRECUENCIA'. */
static void exact_magnitud_FRECUENCIA(Ej3* handle)
{
	/* Exit action for state 'FRECUENCIA'. */
	ej3Iface_opLED(handle, EJ3_EJ3IFACE_LED2, EJ3_EJ3IFACE_LED_OFF);
}

/* Exit action for state 'TENSION'. */
static void exact_magnitud_TENSION(Ej3* handle)
{
	/* Exit action for state 'TENSION'. */
	ej3Iface_opLED(handle, EJ3_EJ3IFACE_LED3, EJ3_EJ3IFACE_LED_OFF);
}

/* Exit action for state 'AMPLITUD_SELECCIONADA'. */
static void exact_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLITUD_SELECCIONADA(Ej3* handle)
{
	/* Exit action for state 'AMPLITUD_SELECCIONADA'. */
	ej3_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.ej3_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLITUD_SELECCIONADA_tev0_raised) );		
}

/* Exit action for state 'AMPLITUD_SELECCIONADA'. */
static void exact_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLITUD_SELECCIONADA(Ej3* handle)
{
	/* Exit action for state 'AMPLITUD_SELECCIONADA'. */
	ej3_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.ej3_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLITUD_SELECCIONADA_tev0_raised) );		
}

/* 'default' enter sequence for state DEBOUNCE */
static void enseq_TECX_DEBOUNCE_default(Ej3* handle)
{
	/* 'default' enter sequence for state DEBOUNCE */
	enact_TECX_DEBOUNCE(handle);
	handle->stateConfVector[0] = Ej3_TECX_DEBOUNCE;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state NO_OPRIMIDO */
static void enseq_TECX_NO_OPRIMIDO_default(Ej3* handle)
{
	/* 'default' enter sequence for state NO_OPRIMIDO */
	handle->stateConfVector[0] = Ej3_TECX_NO_OPRIMIDO;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state OPRIMIDO */
static void enseq_TECX_OPRIMIDO_default(Ej3* handle)
{
	/* 'default' enter sequence for state OPRIMIDO */
	enact_TECX_OPRIMIDO(handle);
	handle->stateConfVector[0] = Ej3_TECX_OPRIMIDO;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state VALIDACION */
static void enseq_TECX_VALIDACION_default(Ej3* handle)
{
	/* 'default' enter sequence for state VALIDACION */
	handle->stateConfVector[0] = Ej3_TECX_VALIDACION;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state ESPERA */
static void enseq_main_region_ESPERA_default(Ej3* handle)
{
	/* 'default' enter sequence for state ESPERA */
	handle->stateConfVector[1] = Ej3_main_region_ESPERA;
	handle->stateConfVectorPosition = 1;
}

/* 'default' enter sequence for state TRIANGULAR */
static void enseq_forma_TRIANGULAR_default(Ej3* handle)
{
	/* 'default' enter sequence for state TRIANGULAR */
	enact_forma_TRIANGULAR(handle);
	handle->stateConfVector[2] = Ej3_forma_TRIANGULAR;
	handle->stateConfVectorPosition = 2;
}

/* 'default' enter sequence for state CUADRADA */
static void enseq_forma_CUADRADA_default(Ej3* handle)
{
	/* 'default' enter sequence for state CUADRADA */
	enact_forma_CUADRADA(handle);
	handle->stateConfVector[2] = Ej3_forma_CUADRADA;
	handle->stateConfVectorPosition = 2;
}

/* 'default' enter sequence for state SENOIDAL */
static void enseq_forma_SENOIDAL_default(Ej3* handle)
{
	/* 'default' enter sequence for state SENOIDAL */
	enact_forma_SENOIDAL(handle);
	handle->stateConfVector[2] = Ej3_forma_SENOIDAL;
	handle->stateConfVectorPosition = 2;
}

/* 'default' enter sequence for state SELECCION_FORMA */
static void enseq_forma_SELECCION_FORMA_default(Ej3* handle)
{
	/* 'default' enter sequence for state SELECCION_FORMA */
	enact_forma_SELECCION_FORMA(handle);
	handle->stateConfVector[2] = Ej3_forma_SELECCION_FORMA;
	handle->stateConfVectorPosition = 2;
}

/* 'default' enter sequence for state FORMA_SELECCIONADA */
static void enseq_forma_FORMA_SELECCIONADA_default(Ej3* handle)
{
	/* 'default' enter sequence for state FORMA_SELECCIONADA */
	enact_forma_FORMA_SELECCIONADA(handle);
	handle->stateConfVector[2] = Ej3_forma_FORMA_SELECCIONADA;
	handle->stateConfVectorPosition = 2;
}

/* 'default' enter sequence for state FRECUENCIA */
static void enseq_magnitud_FRECUENCIA_default(Ej3* handle)
{
	/* 'default' enter sequence for state FRECUENCIA */
	enact_magnitud_FRECUENCIA(handle);
	handle->stateConfVector[3] = Ej3_magnitud_FRECUENCIA;
	handle->stateConfVectorPosition = 3;
}

/* 'default' enter sequence for state TENSION */
static void enseq_magnitud_TENSION_default(Ej3* handle)
{
	/* 'default' enter sequence for state TENSION */
	enact_magnitud_TENSION(handle);
	handle->stateConfVector[3] = Ej3_magnitud_TENSION;
	handle->stateConfVectorPosition = 3;
}

/* 'default' enter sequence for state WAIT_SELECCION_MAGNITUD */
static void enseq_magnitud_WAIT_SELECCION_MAGNITUD_default(Ej3* handle)
{
	/* 'default' enter sequence for state WAIT_SELECCION_MAGNITUD */
	enact_magnitud_WAIT_SELECCION_MAGNITUD(handle);
	handle->stateConfVector[3] = Ej3_magnitud_WAIT_SELECCION_MAGNITUD;
	handle->stateConfVectorPosition = 3;
}

/* 'default' enter sequence for state SELECC_MAGNITUD */
static void enseq_magnitud_SELECC_MAGNITUD_default(Ej3* handle)
{
	/* 'default' enter sequence for state SELECC_MAGNITUD */
	handle->stateConfVector[3] = Ej3_magnitud_SELECC_MAGNITUD;
	handle->stateConfVectorPosition = 3;
}

/* 'default' enter sequence for state ELEGIR_AMPLITUD_FREC */
static void enseq_magnitud_ELEGIR_AMPLITUD_FREC_default(Ej3* handle)
{
	/* 'default' enter sequence for state ELEGIR_AMPLITUD_FREC */
	enseq_magnitud_ELEGIR_AMPLITUD_FREC_r1_default(handle);
}

/* 'default' enter sequence for state MAGNITUD_START */
static void enseq_magnitud_ELEGIR_AMPLITUD_FREC_r1_MAGNITUD_START_default(Ej3* handle)
{
	/* 'default' enter sequence for state MAGNITUD_START */
	enact_magnitud_ELEGIR_AMPLITUD_FREC_r1_MAGNITUD_START(handle);
	handle->stateConfVector[3] = Ej3_magnitud_ELEGIR_AMPLITUD_FREC_r1_MAGNITUD_START;
	handle->stateConfVectorPosition = 3;
}

/* 'default' enter sequence for state AMPLI_UP */
static void enseq_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLI_UP_default(Ej3* handle)
{
	/* 'default' enter sequence for state AMPLI_UP */
	enact_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLI_UP(handle);
	handle->stateConfVector[3] = Ej3_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLI_UP;
	handle->stateConfVectorPosition = 3;
}

/* 'default' enter sequence for state AMPLI_DOWN */
static void enseq_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLI_DOWN_default(Ej3* handle)
{
	/* 'default' enter sequence for state AMPLI_DOWN */
	enact_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLI_DOWN(handle);
	handle->stateConfVector[3] = Ej3_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLI_DOWN;
	handle->stateConfVectorPosition = 3;
}

/* 'default' enter sequence for state AMPLITUD_SELECCIONADA */
static void enseq_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLITUD_SELECCIONADA_default(Ej3* handle)
{
	/* 'default' enter sequence for state AMPLITUD_SELECCIONADA */
	enact_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLITUD_SELECCIONADA(handle);
	handle->stateConfVector[3] = Ej3_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLITUD_SELECCIONADA;
	handle->stateConfVectorPosition = 3;
}

/* 'default' enter sequence for state ELEGIR_AMPLITUD_VOLTAGE */
static void enseq_magnitud_ELEGIR_AMPLITUD_VOLTAGE_default(Ej3* handle)
{
	/* 'default' enter sequence for state ELEGIR_AMPLITUD_VOLTAGE */
	enseq_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_default(handle);
}

/* 'default' enter sequence for state MAGNITUD_START */
static void enseq_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_MAGNITUD_START_default(Ej3* handle)
{
	/* 'default' enter sequence for state MAGNITUD_START */
	enact_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_MAGNITUD_START(handle);
	handle->stateConfVector[3] = Ej3_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_MAGNITUD_START;
	handle->stateConfVectorPosition = 3;
}

/* 'default' enter sequence for state AMPLI_UP */
static void enseq_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLI_UP_default(Ej3* handle)
{
	/* 'default' enter sequence for state AMPLI_UP */
	enact_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLI_UP(handle);
	handle->stateConfVector[3] = Ej3_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLI_UP;
	handle->stateConfVectorPosition = 3;
}

/* 'default' enter sequence for state AMPLI_DOWN */
static void enseq_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLI_DOWN_default(Ej3* handle)
{
	/* 'default' enter sequence for state AMPLI_DOWN */
	enact_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLI_DOWN(handle);
	handle->stateConfVector[3] = Ej3_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLI_DOWN;
	handle->stateConfVectorPosition = 3;
}

/* 'default' enter sequence for state AMPLITUD_SELECCIONADA */
static void enseq_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLITUD_SELECCIONADA_default(Ej3* handle)
{
	/* 'default' enter sequence for state AMPLITUD_SELECCIONADA */
	enact_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLITUD_SELECCIONADA(handle);
	handle->stateConfVector[3] = Ej3_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLITUD_SELECCIONADA;
	handle->stateConfVectorPosition = 3;
}

/* 'default' enter sequence for region TECX */
static void enseq_TECX_default(Ej3* handle)
{
	/* 'default' enter sequence for region TECX */
	react_TECX__entry_Default(handle);
}

/* 'default' enter sequence for region main_region */
static void enseq_main_region_default(Ej3* handle)
{
	/* 'default' enter sequence for region main_region */
	react_main_region__entry_Default(handle);
}

/* 'default' enter sequence for region forma */
static void enseq_forma_default(Ej3* handle)
{
	/* 'default' enter sequence for region forma */
	react_forma__entry_Default(handle);
}

/* 'default' enter sequence for region magnitud */
static void enseq_magnitud_default(Ej3* handle)
{
	/* 'default' enter sequence for region magnitud */
	react_magnitud__entry_Default(handle);
}

/* 'default' enter sequence for region r1 */
static void enseq_magnitud_ELEGIR_AMPLITUD_FREC_r1_default(Ej3* handle)
{
	/* 'default' enter sequence for region r1 */
	react_magnitud_ELEGIR_AMPLITUD_FREC_r1__entry_Default(handle);
}

/* 'default' enter sequence for region r1 */
static void enseq_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_default(Ej3* handle)
{
	/* 'default' enter sequence for region r1 */
	react_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1__entry_Default(handle);
}

/* Default exit sequence for state DEBOUNCE */
static void exseq_TECX_DEBOUNCE(Ej3* handle)
{
	/* Default exit sequence for state DEBOUNCE */
	handle->stateConfVector[0] = Ej3_last_state;
	handle->stateConfVectorPosition = 0;
	exact_TECX_DEBOUNCE(handle);
}

/* Default exit sequence for state NO_OPRIMIDO */
static void exseq_TECX_NO_OPRIMIDO(Ej3* handle)
{
	/* Default exit sequence for state NO_OPRIMIDO */
	handle->stateConfVector[0] = Ej3_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state OPRIMIDO */
static void exseq_TECX_OPRIMIDO(Ej3* handle)
{
	/* Default exit sequence for state OPRIMIDO */
	handle->stateConfVector[0] = Ej3_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state VALIDACION */
static void exseq_TECX_VALIDACION(Ej3* handle)
{
	/* Default exit sequence for state VALIDACION */
	handle->stateConfVector[0] = Ej3_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state ESPERA */
static void exseq_main_region_ESPERA(Ej3* handle)
{
	/* Default exit sequence for state ESPERA */
	handle->stateConfVector[1] = Ej3_last_state;
	handle->stateConfVectorPosition = 1;
}

/* Default exit sequence for state TRIANGULAR */
static void exseq_forma_TRIANGULAR(Ej3* handle)
{
	/* Default exit sequence for state TRIANGULAR */
	handle->stateConfVector[2] = Ej3_last_state;
	handle->stateConfVectorPosition = 2;
	exact_forma_TRIANGULAR(handle);
}

/* Default exit sequence for state CUADRADA */
static void exseq_forma_CUADRADA(Ej3* handle)
{
	/* Default exit sequence for state CUADRADA */
	handle->stateConfVector[2] = Ej3_last_state;
	handle->stateConfVectorPosition = 2;
	exact_forma_CUADRADA(handle);
}

/* Default exit sequence for state SENOIDAL */
static void exseq_forma_SENOIDAL(Ej3* handle)
{
	/* Default exit sequence for state SENOIDAL */
	handle->stateConfVector[2] = Ej3_last_state;
	handle->stateConfVectorPosition = 2;
	exact_forma_SENOIDAL(handle);
}

/* Default exit sequence for state SELECCION_FORMA */
static void exseq_forma_SELECCION_FORMA(Ej3* handle)
{
	/* Default exit sequence for state SELECCION_FORMA */
	handle->stateConfVector[2] = Ej3_last_state;
	handle->stateConfVectorPosition = 2;
}

/* Default exit sequence for state FORMA_SELECCIONADA */
static void exseq_forma_FORMA_SELECCIONADA(Ej3* handle)
{
	/* Default exit sequence for state FORMA_SELECCIONADA */
	handle->stateConfVector[2] = Ej3_last_state;
	handle->stateConfVectorPosition = 2;
	exact_forma_FORMA_SELECCIONADA(handle);
}

/* Default exit sequence for state FRECUENCIA */
static void exseq_magnitud_FRECUENCIA(Ej3* handle)
{
	/* Default exit sequence for state FRECUENCIA */
	handle->stateConfVector[3] = Ej3_last_state;
	handle->stateConfVectorPosition = 3;
	exact_magnitud_FRECUENCIA(handle);
}

/* Default exit sequence for state TENSION */
static void exseq_magnitud_TENSION(Ej3* handle)
{
	/* Default exit sequence for state TENSION */
	handle->stateConfVector[3] = Ej3_last_state;
	handle->stateConfVectorPosition = 3;
	exact_magnitud_TENSION(handle);
}

/* Default exit sequence for state WAIT_SELECCION_MAGNITUD */
static void exseq_magnitud_WAIT_SELECCION_MAGNITUD(Ej3* handle)
{
	/* Default exit sequence for state WAIT_SELECCION_MAGNITUD */
	handle->stateConfVector[3] = Ej3_last_state;
	handle->stateConfVectorPosition = 3;
}

/* Default exit sequence for state SELECC_MAGNITUD */
static void exseq_magnitud_SELECC_MAGNITUD(Ej3* handle)
{
	/* Default exit sequence for state SELECC_MAGNITUD */
	handle->stateConfVector[3] = Ej3_last_state;
	handle->stateConfVectorPosition = 3;
}

/* Default exit sequence for state ELEGIR_AMPLITUD_FREC */
static void exseq_magnitud_ELEGIR_AMPLITUD_FREC(Ej3* handle)
{
	/* Default exit sequence for state ELEGIR_AMPLITUD_FREC */
	exseq_magnitud_ELEGIR_AMPLITUD_FREC_r1(handle);
}

/* Default exit sequence for state MAGNITUD_START */
static void exseq_magnitud_ELEGIR_AMPLITUD_FREC_r1_MAGNITUD_START(Ej3* handle)
{
	/* Default exit sequence for state MAGNITUD_START */
	handle->stateConfVector[3] = Ej3_last_state;
	handle->stateConfVectorPosition = 3;
}

/* Default exit sequence for state AMPLI_UP */
static void exseq_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLI_UP(Ej3* handle)
{
	/* Default exit sequence for state AMPLI_UP */
	handle->stateConfVector[3] = Ej3_last_state;
	handle->stateConfVectorPosition = 3;
}

/* Default exit sequence for state AMPLI_DOWN */
static void exseq_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLI_DOWN(Ej3* handle)
{
	/* Default exit sequence for state AMPLI_DOWN */
	handle->stateConfVector[3] = Ej3_last_state;
	handle->stateConfVectorPosition = 3;
}

/* Default exit sequence for state AMPLITUD_SELECCIONADA */
static void exseq_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLITUD_SELECCIONADA(Ej3* handle)
{
	/* Default exit sequence for state AMPLITUD_SELECCIONADA */
	handle->stateConfVector[3] = Ej3_last_state;
	handle->stateConfVectorPosition = 3;
	exact_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLITUD_SELECCIONADA(handle);
}

/* Default exit sequence for state ELEGIR_AMPLITUD_VOLTAGE */
static void exseq_magnitud_ELEGIR_AMPLITUD_VOLTAGE(Ej3* handle)
{
	/* Default exit sequence for state ELEGIR_AMPLITUD_VOLTAGE */
	exseq_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1(handle);
}

/* Default exit sequence for state MAGNITUD_START */
static void exseq_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_MAGNITUD_START(Ej3* handle)
{
	/* Default exit sequence for state MAGNITUD_START */
	handle->stateConfVector[3] = Ej3_last_state;
	handle->stateConfVectorPosition = 3;
}

/* Default exit sequence for state AMPLI_UP */
static void exseq_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLI_UP(Ej3* handle)
{
	/* Default exit sequence for state AMPLI_UP */
	handle->stateConfVector[3] = Ej3_last_state;
	handle->stateConfVectorPosition = 3;
}

/* Default exit sequence for state AMPLI_DOWN */
static void exseq_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLI_DOWN(Ej3* handle)
{
	/* Default exit sequence for state AMPLI_DOWN */
	handle->stateConfVector[3] = Ej3_last_state;
	handle->stateConfVectorPosition = 3;
}

/* Default exit sequence for state AMPLITUD_SELECCIONADA */
static void exseq_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLITUD_SELECCIONADA(Ej3* handle)
{
	/* Default exit sequence for state AMPLITUD_SELECCIONADA */
	handle->stateConfVector[3] = Ej3_last_state;
	handle->stateConfVectorPosition = 3;
	exact_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLITUD_SELECCIONADA(handle);
}

/* Default exit sequence for region TECX */
static void exseq_TECX(Ej3* handle)
{
	/* Default exit sequence for region TECX */
	/* Handle exit of all possible states (of ej3.TECX) at position 0... */
	switch(handle->stateConfVector[ 0 ])
	{
		case Ej3_TECX_DEBOUNCE :
		{
			exseq_TECX_DEBOUNCE(handle);
			break;
		}
		case Ej3_TECX_NO_OPRIMIDO :
		{
			exseq_TECX_NO_OPRIMIDO(handle);
			break;
		}
		case Ej3_TECX_OPRIMIDO :
		{
			exseq_TECX_OPRIMIDO(handle);
			break;
		}
		case Ej3_TECX_VALIDACION :
		{
			exseq_TECX_VALIDACION(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region main_region */
static void exseq_main_region(Ej3* handle)
{
	/* Default exit sequence for region main_region */
	/* Handle exit of all possible states (of ej3.main_region) at position 1... */
	switch(handle->stateConfVector[ 1 ])
	{
		case Ej3_main_region_ESPERA :
		{
			exseq_main_region_ESPERA(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region forma */
static void exseq_forma(Ej3* handle)
{
	/* Default exit sequence for region forma */
	/* Handle exit of all possible states (of ej3.forma) at position 2... */
	switch(handle->stateConfVector[ 2 ])
	{
		case Ej3_forma_TRIANGULAR :
		{
			exseq_forma_TRIANGULAR(handle);
			break;
		}
		case Ej3_forma_CUADRADA :
		{
			exseq_forma_CUADRADA(handle);
			break;
		}
		case Ej3_forma_SENOIDAL :
		{
			exseq_forma_SENOIDAL(handle);
			break;
		}
		case Ej3_forma_SELECCION_FORMA :
		{
			exseq_forma_SELECCION_FORMA(handle);
			break;
		}
		case Ej3_forma_FORMA_SELECCIONADA :
		{
			exseq_forma_FORMA_SELECCIONADA(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region magnitud */
static void exseq_magnitud(Ej3* handle)
{
	/* Default exit sequence for region magnitud */
	/* Handle exit of all possible states (of ej3.magnitud) at position 3... */
	switch(handle->stateConfVector[ 3 ])
	{
		case Ej3_magnitud_FRECUENCIA :
		{
			exseq_magnitud_FRECUENCIA(handle);
			break;
		}
		case Ej3_magnitud_TENSION :
		{
			exseq_magnitud_TENSION(handle);
			break;
		}
		case Ej3_magnitud_WAIT_SELECCION_MAGNITUD :
		{
			exseq_magnitud_WAIT_SELECCION_MAGNITUD(handle);
			break;
		}
		case Ej3_magnitud_SELECC_MAGNITUD :
		{
			exseq_magnitud_SELECC_MAGNITUD(handle);
			break;
		}
		case Ej3_magnitud_ELEGIR_AMPLITUD_FREC_r1_MAGNITUD_START :
		{
			exseq_magnitud_ELEGIR_AMPLITUD_FREC_r1_MAGNITUD_START(handle);
			break;
		}
		case Ej3_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLI_UP :
		{
			exseq_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLI_UP(handle);
			break;
		}
		case Ej3_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLI_DOWN :
		{
			exseq_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLI_DOWN(handle);
			break;
		}
		case Ej3_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLITUD_SELECCIONADA :
		{
			exseq_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLITUD_SELECCIONADA(handle);
			break;
		}
		case Ej3_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_MAGNITUD_START :
		{
			exseq_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_MAGNITUD_START(handle);
			break;
		}
		case Ej3_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLI_UP :
		{
			exseq_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLI_UP(handle);
			break;
		}
		case Ej3_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLI_DOWN :
		{
			exseq_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLI_DOWN(handle);
			break;
		}
		case Ej3_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLITUD_SELECCIONADA :
		{
			exseq_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLITUD_SELECCIONADA(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region r1 */
static void exseq_magnitud_ELEGIR_AMPLITUD_FREC_r1(Ej3* handle)
{
	/* Default exit sequence for region r1 */
	/* Handle exit of all possible states (of ej3.magnitud.ELEGIR_AMPLITUD_FREC.r1) at position 3... */
	switch(handle->stateConfVector[ 3 ])
	{
		case Ej3_magnitud_ELEGIR_AMPLITUD_FREC_r1_MAGNITUD_START :
		{
			exseq_magnitud_ELEGIR_AMPLITUD_FREC_r1_MAGNITUD_START(handle);
			break;
		}
		case Ej3_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLI_UP :
		{
			exseq_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLI_UP(handle);
			break;
		}
		case Ej3_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLI_DOWN :
		{
			exseq_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLI_DOWN(handle);
			break;
		}
		case Ej3_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLITUD_SELECCIONADA :
		{
			exseq_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLITUD_SELECCIONADA(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region r1 */
static void exseq_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1(Ej3* handle)
{
	/* Default exit sequence for region r1 */
	/* Handle exit of all possible states (of ej3.magnitud.ELEGIR_AMPLITUD_VOLTAGE.r1) at position 3... */
	switch(handle->stateConfVector[ 3 ])
	{
		case Ej3_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_MAGNITUD_START :
		{
			exseq_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_MAGNITUD_START(handle);
			break;
		}
		case Ej3_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLI_UP :
		{
			exseq_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLI_UP(handle);
			break;
		}
		case Ej3_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLI_DOWN :
		{
			exseq_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLI_DOWN(handle);
			break;
		}
		case Ej3_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLITUD_SELECCIONADA :
		{
			exseq_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLITUD_SELECCIONADA(handle);
			break;
		}
		default: break;
	}
}

/* The reactions of state DEBOUNCE. */
static void react_TECX_DEBOUNCE(Ej3* handle)
{
	/* The reactions of state DEBOUNCE. */
	if (check_TECX_DEBOUNCE_tr0_tr0(handle) == bool_true)
	{ 
		effect_TECX_DEBOUNCE_tr0(handle);
	} 
}

/* The reactions of state NO_OPRIMIDO. */
static void react_TECX_NO_OPRIMIDO(Ej3* handle)
{
	/* The reactions of state NO_OPRIMIDO. */
	if (check_TECX_NO_OPRIMIDO_tr0_tr0(handle) == bool_true)
	{ 
		effect_TECX_NO_OPRIMIDO_tr0(handle);
	} 
}

/* The reactions of state OPRIMIDO. */
static void react_TECX_OPRIMIDO(Ej3* handle)
{
	/* The reactions of state OPRIMIDO. */
	if (check_TECX_OPRIMIDO_tr0_tr0(handle) == bool_true)
	{ 
		effect_TECX_OPRIMIDO_tr0(handle);
	} 
}

/* The reactions of state VALIDACION. */
static void react_TECX_VALIDACION(Ej3* handle)
{
	/* The reactions of state VALIDACION. */
	if (check_TECX_VALIDACION_tr0_tr0(handle) == bool_true)
	{ 
		effect_TECX_VALIDACION_tr0(handle);
	}  else
	{
		if (check_TECX_VALIDACION_tr1_tr1(handle) == bool_true)
		{ 
			effect_TECX_VALIDACION_tr1(handle);
		} 
	}
}

/* The reactions of state ESPERA. */
static void react_main_region_ESPERA(Ej3* handle)
{
	/* The reactions of state ESPERA. */
	if (check_main_region_ESPERA_tr0_tr0(handle) == bool_true)
	{ 
		effect_main_region_ESPERA_tr0(handle);
	}  else
	{
		if (check_main_region_ESPERA_tr1_tr1(handle) == bool_true)
		{ 
			effect_main_region_ESPERA_tr1(handle);
		}  else
		{
			if (check_main_region_ESPERA_tr2_tr2(handle) == bool_true)
			{ 
				effect_main_region_ESPERA_tr2(handle);
			}  else
			{
				if (check_main_region_ESPERA_tr3_tr3(handle) == bool_true)
				{ 
					effect_main_region_ESPERA_tr3(handle);
				} 
			}
		}
	}
}

/* The reactions of state TRIANGULAR. */
static void react_forma_TRIANGULAR(Ej3* handle)
{
	/* The reactions of state TRIANGULAR. */
	if (check_forma_TRIANGULAR_tr0_tr0(handle) == bool_true)
	{ 
		effect_forma_TRIANGULAR_tr0(handle);
	}  else
	{
		if (check_forma_TRIANGULAR_tr1_tr1(handle) == bool_true)
		{ 
			effect_forma_TRIANGULAR_tr1(handle);
		}  else
		{
			if (check_forma_TRIANGULAR_tr2_tr2(handle) == bool_true)
			{ 
				effect_forma_TRIANGULAR_tr2(handle);
			} 
		}
	}
}

/* The reactions of state CUADRADA. */
static void react_forma_CUADRADA(Ej3* handle)
{
	/* The reactions of state CUADRADA. */
	if (check_forma_CUADRADA_tr0_tr0(handle) == bool_true)
	{ 
		effect_forma_CUADRADA_tr0(handle);
	}  else
	{
		if (check_forma_CUADRADA_tr1_tr1(handle) == bool_true)
		{ 
			effect_forma_CUADRADA_tr1(handle);
		}  else
		{
			if (check_forma_CUADRADA_tr2_tr2(handle) == bool_true)
			{ 
				effect_forma_CUADRADA_tr2(handle);
			} 
		}
	}
}

/* The reactions of state SENOIDAL. */
static void react_forma_SENOIDAL(Ej3* handle)
{
	/* The reactions of state SENOIDAL. */
	if (check_forma_SENOIDAL_tr0_tr0(handle) == bool_true)
	{ 
		effect_forma_SENOIDAL_tr0(handle);
	}  else
	{
		if (check_forma_SENOIDAL_tr1_tr1(handle) == bool_true)
		{ 
			effect_forma_SENOIDAL_tr1(handle);
		}  else
		{
			if (check_forma_SENOIDAL_tr2_tr2(handle) == bool_true)
			{ 
				effect_forma_SENOIDAL_tr2(handle);
			} 
		}
	}
}

/* The reactions of state SELECCION_FORMA. */
static void react_forma_SELECCION_FORMA(Ej3* handle)
{
	/* The reactions of state SELECCION_FORMA. */
	if (check_forma_SELECCION_FORMA_tr0_tr0(handle) == bool_true)
	{ 
		effect_forma_SELECCION_FORMA_tr0(handle);
	}  else
	{
		if (check_forma_SELECCION_FORMA_tr1_tr1(handle) == bool_true)
		{ 
			effect_forma_SELECCION_FORMA_tr1(handle);
		} 
	}
}

/* The reactions of state FORMA_SELECCIONADA. */
static void react_forma_FORMA_SELECCIONADA(Ej3* handle)
{
	/* The reactions of state FORMA_SELECCIONADA. */
	if (check_forma_FORMA_SELECCIONADA_tr0_tr0(handle) == bool_true)
	{ 
		effect_forma_FORMA_SELECCIONADA_tr0(handle);
	} 
}

/* The reactions of state FRECUENCIA. */
static void react_magnitud_FRECUENCIA(Ej3* handle)
{
	/* The reactions of state FRECUENCIA. */
	if (check_magnitud_FRECUENCIA_tr0_tr0(handle) == bool_true)
	{ 
		effect_magnitud_FRECUENCIA_tr0(handle);
	} 
}

/* The reactions of state TENSION. */
static void react_magnitud_TENSION(Ej3* handle)
{
	/* The reactions of state TENSION. */
	if (check_magnitud_TENSION_tr0_tr0(handle) == bool_true)
	{ 
		effect_magnitud_TENSION_tr0(handle);
	} 
}

/* The reactions of state WAIT_SELECCION_MAGNITUD. */
static void react_magnitud_WAIT_SELECCION_MAGNITUD(Ej3* handle)
{
	/* The reactions of state WAIT_SELECCION_MAGNITUD. */
	if (check_magnitud_WAIT_SELECCION_MAGNITUD_tr0_tr0(handle) == bool_true)
	{ 
		effect_magnitud_WAIT_SELECCION_MAGNITUD_tr0(handle);
	} 
}

/* The reactions of state SELECC_MAGNITUD. */
static void react_magnitud_SELECC_MAGNITUD(Ej3* handle)
{
	/* The reactions of state SELECC_MAGNITUD. */
	if (check_magnitud_SELECC_MAGNITUD_tr0_tr0(handle) == bool_true)
	{ 
		effect_magnitud_SELECC_MAGNITUD_tr0(handle);
	}  else
	{
		if (check_magnitud_SELECC_MAGNITUD_tr1_tr1(handle) == bool_true)
		{ 
			effect_magnitud_SELECC_MAGNITUD_tr1(handle);
		} 
	}
}

/* The reactions of state MAGNITUD_START. */
static void react_magnitud_ELEGIR_AMPLITUD_FREC_r1_MAGNITUD_START(Ej3* handle)
{
	/* The reactions of state MAGNITUD_START. */
	if (check_magnitud_ELEGIR_AMPLITUD_FREC_r1_MAGNITUD_START_tr0_tr0(handle) == bool_true)
	{ 
		effect_magnitud_ELEGIR_AMPLITUD_FREC_r1_MAGNITUD_START_tr0(handle);
	}  else
	{
		if (check_magnitud_ELEGIR_AMPLITUD_FREC_r1_MAGNITUD_START_tr1_tr1(handle) == bool_true)
		{ 
			effect_magnitud_ELEGIR_AMPLITUD_FREC_r1_MAGNITUD_START_tr1(handle);
		} 
	}
}

/* The reactions of state AMPLI_UP. */
static void react_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLI_UP(Ej3* handle)
{
	/* The reactions of state AMPLI_UP. */
	if (check_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLI_UP_tr0_tr0(handle) == bool_true)
	{ 
		effect_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLI_UP_tr0(handle);
	}  else
	{
		if (check_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLI_UP_tr1_tr1(handle) == bool_true)
		{ 
			effect_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLI_UP_tr1(handle);
		}  else
		{
			if (check_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLI_UP_tr2_tr2(handle) == bool_true)
			{ 
				effect_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLI_UP_tr2(handle);
			} 
		}
	}
}

/* The reactions of state AMPLI_DOWN. */
static void react_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLI_DOWN(Ej3* handle)
{
	/* The reactions of state AMPLI_DOWN. */
	if (check_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLI_DOWN_tr0_tr0(handle) == bool_true)
	{ 
		effect_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLI_DOWN_tr0(handle);
	}  else
	{
		if (check_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLI_DOWN_tr1_tr1(handle) == bool_true)
		{ 
			effect_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLI_DOWN_tr1(handle);
		}  else
		{
			if (check_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLI_DOWN_tr2_tr2(handle) == bool_true)
			{ 
				effect_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLI_DOWN_tr2(handle);
			} 
		}
	}
}

/* The reactions of state AMPLITUD_SELECCIONADA. */
static void react_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLITUD_SELECCIONADA(Ej3* handle)
{
	/* The reactions of state AMPLITUD_SELECCIONADA. */
	if (check_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLITUD_SELECCIONADA_tr0_tr0(handle) == bool_true)
	{ 
		effect_magnitud_ELEGIR_AMPLITUD_FREC_r1_AMPLITUD_SELECCIONADA_tr0(handle);
	} 
}

/* The reactions of state MAGNITUD_START. */
static void react_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_MAGNITUD_START(Ej3* handle)
{
	/* The reactions of state MAGNITUD_START. */
	if (check_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_MAGNITUD_START_tr0_tr0(handle) == bool_true)
	{ 
		effect_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_MAGNITUD_START_tr0(handle);
	}  else
	{
		if (check_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_MAGNITUD_START_tr1_tr1(handle) == bool_true)
		{ 
			effect_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_MAGNITUD_START_tr1(handle);
		} 
	}
}

/* The reactions of state AMPLI_UP. */
static void react_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLI_UP(Ej3* handle)
{
	/* The reactions of state AMPLI_UP. */
	if (check_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLI_UP_tr0_tr0(handle) == bool_true)
	{ 
		effect_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLI_UP_tr0(handle);
	}  else
	{
		if (check_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLI_UP_tr1_tr1(handle) == bool_true)
		{ 
			effect_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLI_UP_tr1(handle);
		}  else
		{
			if (check_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLI_UP_tr2_tr2(handle) == bool_true)
			{ 
				effect_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLI_UP_tr2(handle);
			} 
		}
	}
}

/* The reactions of state AMPLI_DOWN. */
static void react_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLI_DOWN(Ej3* handle)
{
	/* The reactions of state AMPLI_DOWN. */
	if (check_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLI_DOWN_tr0_tr0(handle) == bool_true)
	{ 
		effect_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLI_DOWN_tr0(handle);
	}  else
	{
		if (check_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLI_DOWN_tr1_tr1(handle) == bool_true)
		{ 
			effect_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLI_DOWN_tr1(handle);
		}  else
		{
			if (check_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLI_DOWN_tr2_tr2(handle) == bool_true)
			{ 
				effect_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLI_DOWN_tr2(handle);
			} 
		}
	}
}

/* The reactions of state AMPLITUD_SELECCIONADA. */
static void react_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLITUD_SELECCIONADA(Ej3* handle)
{
	/* The reactions of state AMPLITUD_SELECCIONADA. */
	if (check_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLITUD_SELECCIONADA_tr0_tr0(handle) == bool_true)
	{ 
		effect_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_AMPLITUD_SELECCIONADA_tr0(handle);
	} 
}

/* Default react sequence for initial entry  */
static void react_TECX__entry_Default(Ej3* handle)
{
	/* Default react sequence for initial entry  */
	enseq_TECX_NO_OPRIMIDO_default(handle);
}

/* Default react sequence for initial entry  */
static void react_main_region__entry_Default(Ej3* handle)
{
	/* Default react sequence for initial entry  */
	enseq_main_region_ESPERA_default(handle);
}

/* Default react sequence for initial entry  */
static void react_forma__entry_Default(Ej3* handle)
{
	/* Default react sequence for initial entry  */
	enseq_forma_SELECCION_FORMA_default(handle);
}

/* Default react sequence for initial entry  */
static void react_magnitud__entry_Default(Ej3* handle)
{
	/* Default react sequence for initial entry  */
	enseq_magnitud_WAIT_SELECCION_MAGNITUD_default(handle);
}

/* Default react sequence for initial entry  */
static void react_magnitud_ELEGIR_AMPLITUD_FREC_r1__entry_Default(Ej3* handle)
{
	/* Default react sequence for initial entry  */
	enseq_magnitud_ELEGIR_AMPLITUD_FREC_r1_MAGNITUD_START_default(handle);
}

/* Default react sequence for initial entry  */
static void react_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1__entry_Default(Ej3* handle)
{
	/* Default react sequence for initial entry  */
	enseq_magnitud_ELEGIR_AMPLITUD_VOLTAGE_r1_MAGNITUD_START_default(handle);
}


