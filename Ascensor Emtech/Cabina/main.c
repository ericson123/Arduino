/*
* Cabina.c
*
* Created: 16/02/2020 14:21:10
* Author : Ericson
*/

#include <avr/io.h>
#include "input.h"
#include "output.h"
#include "variables.h"
#include "canbus.h"
#include "display.h"
#include "operador.h"

int main(void){
	input_config();
	output_config();
	//canbus_config(CAN_5000KBPS);
	display_config();
	operador_config();
	
	while(1){
		
		//canbus_run();
		
		pulsadores = input_pulsadores();
		pulsador_emergencia = input_emergencia();
		pulsador_abrir_puerta = input_pulsador_abrir_puerta();
		pulsador_cerrar_puerta = input_pulsador_cerrar_puerta();
		micro_puerta_abierta = input_micro_puerta_abierta();
		micro_puerta_cerrada = input_micro_puerta_cerrada();
		cortina_puerta = input_cortina_puerta();
		torque_operador = input_torque_operador();
		falla_operador = input_falla_operador();
		
		variables_run();
		
		display_run();
		
		operador_run();
		
	}
}
