/*
* Piso.c
*
* Created: 16/02/2020 10:56:50
* Author : Ericson
*/

#include <avr/io.h>
#include "input.h"
#include "output.h"
#include "variables.h"
#include "canbus.h"
#include "display.h"

int main(void){
	
	input_config();
	output_config();
	canbus_config(CAN_500KBPS);
	display_config();
	
	while(1){
		
		canbus_run();
		
		fin_carrera = input_fin_carrera();
		pulsador_subida = input_pulsador_subida();
		pulsador_bajada = input_pulsador_bajada();
		micro_puerta = input_micro_puerta();
		
		variables_run();
		
		display_run(proceso, cabina, emergencia, puerta, piso_actual, mantenimiento);
		
	}
}

