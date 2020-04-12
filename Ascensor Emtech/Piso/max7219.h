/*
* max7219.h
*
* Created: 16/02/2020 11:09:24
*  Author: Ericson
*/


#ifndef MAX7219_H_
#define MAX7219_H_

#define	DISPLAY_PISO_BASE		0
#define DISPLAY_FLECHA_SUBIR	1
#define DISPLAY_FLECHA_BAJAR	2
#define DISPLAY_EMERGENCIA		3
#define DISPLAY_PUERTA			4
#define DISPLAY_MANTENIMIENTO	5

void max7219_config(void);
void max7219_writeChar(uint8_t);

void max7219_config(void){
	
}

void max7219_writeChar(uint8_t d){
	
}

#endif /* MAX7219_H_ */