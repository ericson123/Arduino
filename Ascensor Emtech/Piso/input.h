/*
* input.h
*
* Created: 16/02/2020 11:09:01
*  Author: Ericson
*/


#ifndef INPUT_H_
#define INPUT_H_

#define PULSADOR_1		1
#define PULSADOR_2		2
#define PULSADOR_3		3
#define PULSADOR_EM		4
#define FIN_CARRERA_1	5
#define FIN_CARRERA_2	6
#define FIN_CARRERA_3	7
#define MICRO_PUERTA	8

void input_config(void);
uint8_t input_read(uint8_t);
uint8_t input_pulsador_subida();
uint8_t input_pulsador_bajada();
uint8_t input_fin_carrera();
uint8_t input_micro_puerta();

void input_config(void){
	
}

uint8_t input_read(uint8_t d){
	switch(d){
		case PULSADOR_1: break;
		case PULSADOR_2: break;
		case PULSADOR_3: break;
		case PULSADOR_EM: break;
		case FIN_CARRERA_1: break;
		case FIN_CARRERA_2: break;
		case FIN_CARRERA_3: break;
		case MICRO_PUERTA: break;
	}
	return 0;
}

uint8_t input_pulsador_subida(void){
	if(input_read(PULSADOR_1)){
		return 1;
	}
	return 0;
}

uint8_t input_pulsador_bajada(void){
	if(input_read(PULSADOR_2)){
		return 1;
	}
	return 0;
}

uint8_t input_fin_carrera(void){
	if(input_read(FIN_CARRERA_1)){
		return 1;
	}
	return 0;
}

uint8_t input_micro_puerta(void){
	if(input_read(MICRO_PUERTA)){
		return 1;
	}
	return 0;
}

#endif /* INPUT_H_ */