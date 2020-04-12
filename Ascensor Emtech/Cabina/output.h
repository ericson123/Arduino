/*
* output.h
*
* Created: 16/02/2020 15:27:31
*  Author: Ericson
*/


#ifndef OUTPUT_H_
#define OUTPUT_H_

#define RELE_EMERGENCIA		1
#define RELE_ABRIR_PUERTA	2
#define RELE_CERRAR_PUERTA	3
#define RELE_P1				4
#define RELE_P2				5
#define RELE_P3				6
#define RELE_P4				7
#define RELE_P5				8
#define RELE_P6				9
#define RELE_P7				10

#define BUZZER				11
#define LED_RUN				12
#define LED_CANBUS			13
#define LED_SD				14
#define LED_RTC				15
#define LED_BLUETHOOTH		16
#define LED_SUBIR			17
#define LED_BAJAR			18
#define LED_GPRS			19
#define LED_GPS				20

void output_config(void);
void output_high(uint8_t);
void output_low(uint8_t);
void output_toggle(uint8_t);

void output_config(void){
	
}

void output_high(uint8_t d){
	
}

void output_low(uint8_t d){
	
}

void output_toggle(uint8_t d){
	
}

#endif /* OUTPUT_H_ */