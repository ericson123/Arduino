/*
* display.h
*
* Created: 16/02/2020 12:55:34
*  Author: Ericson
*/


#ifndef DISPLAY_H_
#define DISPLAY_H_

#include "max7219.h"

void display_config(void);
void display_run(uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t);

void display_config(void){
	max7219_config();
	max7219_writeChar(DISPLAY_PISO_BASE+MY_ID);
}

void display_run(uint8_t pr, uint8_t ca, uint8_t em, uint8_t mp, uint8_t pi, uint8_t ma){
	static uint8_t last_proceso;
	static uint8_t last_cabina;
	static uint8_t last_emergencia;
	static uint8_t last_puerta;
	static uint8_t last_piso_actual;
	static uint8_t last_mantenimiento;
	
	if(last_proceso!=pr || last_cabina!=ca || last_emergencia!=em || last_puerta!=mp || last_piso_actual!=pi || last_mantenimiento!=ma){
		
		last_proceso = pr;
		last_cabina = ca;
		last_emergencia = em;
		last_puerta = mp;
		last_piso_actual = pi;
		last_mantenimiento = ma;
		max7219_config();
		
		if(emergencia==1){
			max7219_writeChar(DISPLAY_EMERGENCIA);
		}
		else if(cabina==0){
			if(piso_actual>0){max7219_writeChar(DISPLAY_PISO_BASE+piso_actual);}
		}
		else if(cabina==1){
			max7219_writeChar(DISPLAY_FLECHA_SUBIR);
		}
		else if(cabina==2){
			max7219_writeChar(DISPLAY_FLECHA_BAJAR);
		}
		if(proceso==0){
			last_cabina = 0;
		}
	}
	
}

#endif /* DISPLAY_H_ */