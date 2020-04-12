/*
* output.h
*
* Created: 16/02/2020 11:09:12
*  Author: Ericson
*/


#ifndef OUTPUT_H_
#define OUTPUT_H_

#define	RELE_FWD	1
#define	RELE_REV	2
#define	RELE_BRK	3
#define	RELE_AUX	4
#define	LED			5
#define	BUZZER		6

void output_config(void);
void output_high(uint8_t);
void output_low(uint8_t);
void output_toggle(uint8_t);

void output_config(void){
	
}

void output_high(uint8_t d){
	switch(d){
		case RELE_FWD:	break;
		case RELE_REV:	break;
		case RELE_BRK:	break;
		case RELE_AUX:	break;
		case LED:		break;
		case BUZZER:	break;
	}
}

void output_low(uint8_t d){
	switch(d){
		case RELE_FWD:	break;
		case RELE_REV:	break;
		case RELE_BRK:	break;
		case RELE_AUX:	break;
		case LED:		break;
		case BUZZER:	break;
	}
}

void output_toggle(uint8_t d){
	switch(d){
		case RELE_FWD:	break;
		case RELE_REV:	break;
		case RELE_BRK:	break;
		case RELE_AUX:	break;
		case LED:		break;
		case BUZZER:	break;
	}
}

#endif /* OUTPUT_H_ */