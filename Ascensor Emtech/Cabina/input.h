/*
* input.h
*
* Created: 16/02/2020 15:21:04
*  Author: Ericson
*/


#ifndef INPUT_H_
#define INPUT_H_

#define PULSADOR_1		1
#define PULSADOR_2		2
#define PULSADOR_3		3
#define PULSADOR_4		4
#define PULSADOR_5		5
#define PULSADOR_6		6
#define PULSADOR_7		7
#define PULSADOR_8		8
#define PULSADOR_9		9
#define PULSADOR_10		10
#define PULSADOR_11		11
#define PULSADOR_12		12
#define PULSADOR_13		13
#define PULSADOR_14		14
#define PULSADOR_15		15
#define PULSADOR_16		16

#define	MICRO_PUERTA_CERRADA	17
#define	MICRO_PUERTA_ABIERTA	18
#define PULSADOR_CERRAR_PUERTA	19
#define PULSADOR_ABRIR_PUERTA	20
#define TORQUE_MOTOR_OPERADOR	21
#define FALLA_OPERADOR			22
#define CORTINA_PUERTA			23
#define PULSADOR_EMERGENCIA		24

#define PULSADOR_SUBIR			25
#define PULSADOR_BAJAR			26
#define PULSADOR_MENU			27
#define PULSADOR_SALIR			28

void		input_config(void);
uint8_t		input_read(uint8_t);
uint16_t	input_pulsadores(void);
uint8_t		input_micro_puerta_cerrada();
uint8_t		input_micro_puerta_abierta();
uint8_t		input_pulsador_cerrar_puerta();
uint8_t		input_pulsador_abrir_puerta();
uint8_t		input_torque_operador();
uint8_t		input_falla_operador();
uint8_t		input_cortina_puerta();
uint8_t		input_emergencia();

void input_config(void){
	
}

uint8_t input_read(uint8_t d){
	return 0;
}

uint16_t input_pulsadores(void){
	return 0;
}

uint8_t input_micro_puerta_cerrada(void){
	return 0;
}

uint8_t input_micro_puerta_abierta(void){
	return 0;
}

uint8_t input_pulsador_cerrar_puerta(void){
	return 0;
}

uint8_t input_pulsador_abrir_puerta(void){
	return 0;
}

uint8_t input_torque_operador(void){
	return 0;
}

uint8_t input_falla_operador(void){
	return 0;
}

uint8_t input_cortina_puerta(void){
	return 0;
}

uint8_t input_emergencia(void){
	return 0;
}

#endif /* INPUT_H_ */