/*
* display.h
*
* Created: 16/02/2020 15:27:47
*  Author: Ericson
*/


#ifndef DISPLAY_H_
#define DISPLAY_H_

#include "max7219.h"

void display_config(void);
void display_run(void);

void display_config(void){
	max7219_config();
	max7219_writeChar(1);
}

void display_run(void){
	
}

#endif /* DISPLAY_H_ */