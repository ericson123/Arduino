/*
* variables.h
*
* Created: 16/02/2020 11:08:45
*  Author: Ericson
*/


#ifndef VARIABLES_H_
#define VARIABLES_H_

#define ID_CABINA	0
#define ID_PISO_1	1
#define ID_PISO_2	2
#define ID_PISO_3	3
#define ID_PISO_4	4
#define ID_PISO_5	5
#define ID_PISO_6	6
#define ID_PISO_7	7
#define ID_PISO_8	8
#define ID_PISO_9	9
#define ID_PISO_10	10
#define ID_PISO_11	11
#define ID_PISO_12	12
#define ID_PISO_13	13
#define ID_PISO_14	14
#define ID_PISO_15	15
#define ID_PISO_16	16
#define ID_CRC		20
#define ID_MAESTRO	21
#define ID_ENCODER	22
#define ID_GPRS		23
#define ID_PESO		24
#define ID_ENERGIA	25

#define MY_ID				ID_PISO_1
#define	PROCESO_DETENIDO		0
#define PROCESO_MOVIMIENTO		1

#define CABINA_DETENIDO			1
#define CABINA_SUBIENDO			2
#define	CABINA_BAJANADO			3

#define CONTADOR_MAX_LUZ		10000
#define	CONTADOR_MAX_PRESIONADO	100000

uint8_t proceso;
uint8_t cabina;
uint8_t piso_actual;
uint8_t puerta;
uint8_t emergencia;
uint8_t mantenimiento;

uint8_t pulsador_subida;
uint8_t pulsador_bajada;
uint8_t fin_carrera;
uint8_t micro_puerta;
uint8_t error;
uint32_t contador_luz_subida;
uint32_t contador_luz_bajada;
uint32_t contador_pulsador_subida_presionado;
uint32_t contador_pulsador_bajada_presionado;

void variables_run(void){
	if(piso_actual==MY_ID && proceso==PROCESO_DETENIDO && cabina==CABINA_DETENIDO){
		if(++contador_luz_subida>CONTADOR_MAX_LUZ){
			contador_luz_subida = 0;
			output_low(RELE_FWD);
		}
		if(++contador_luz_bajada>CONTADOR_MAX_LUZ){
			contador_luz_bajada = 0;
			output_low(RELE_REV);
		}
		output_high(RELE_AUX);
	}
	
	if(pulsador_subida && piso_actual==MY_ID){
		contador_luz_subida = 0;
		output_high(RELE_FWD);
	}
	
	if(pulsador_bajada && piso_actual==MY_ID){
		contador_luz_bajada = 0;
		output_high(RELE_REV);
	}
	
	error = 0;
	if(pulsador_subida){
		if(++contador_pulsador_subida_presionado>CONTADOR_MAX_PRESIONADO){
			contador_pulsador_subida_presionado = CONTADOR_MAX_PRESIONADO;
			error |= (1<<0);
		}
	}
	
	if(pulsador_bajada){
		if(++contador_pulsador_bajada_presionado>CONTADOR_MAX_PRESIONADO){
			contador_pulsador_bajada_presionado = CONTADOR_MAX_PRESIONADO;
			error |= (1<<1);
		}
	}
	
	if(piso_actual==MY_ID && fin_carrera==0){
		error |= (1<<2);
	}
}

#endif /* VARIABLES_H_ */