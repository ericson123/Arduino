/*
* canbus.h
*
* Created: 16/02/2020 11:09:39
*  Author: Ericson
*/


#ifndef CANBUS_H_
#define CANBUS_H_

#include "mcp2515.h"

uint8_t canbus_config(uint8_t);
void	canbus_send(uint8_t, uint8_t*);
void	canbus_read(uint8_t*);
uint8_t canbus_read_id(void);
uint8_t	canbus_available(void);
uint8_t canbus_run(void);

struct{
	uint8_t buffer_tx[8];
	uint8_t buffer_rx[8];
	uint8_t address_tx;
	uint8_t address_rx;
}canbus;

uint8_t canbus_config(uint8_t d){
	uint8_t r;
	r = can_config(d);
	return r;
}

void canbus_send(uint8_t id, uint8_t* d){
	can_sendMsgBuf(id, 0, 8, d);
}

void canbus_read(uint8_t* d){
	uint8_t l;
	can_readMsgBuf(&l, d);
}

uint8_t canbus_read_id(void){
	return can_readId();
}

uint8_t canbus_available(void){
	uint8_t r;
	r = can_checkReceive();
	return r;
}

uint8_t canbus_run(void){
	if(canbus_available()==CAN_MSGAVAIL){
		canbus_read(canbus.buffer_rx);
		canbus.address_rx = canbus_read_id();
		if( canbus.address_rx == (ID_MAESTRO+ID_PISO_1) ){
			proceso = canbus.buffer_rx[0]&(0x03);
			cabina = (canbus.buffer_rx[0]>>2)&(0x03);
			emergencia = (canbus.buffer_rx[0]>>4)&(0x01);
			puerta = (canbus.buffer_rx[0]>>5)&(0x01);
			mantenimiento = (canbus.buffer_rx[0]>>6)&(0x01);
			piso_actual = canbus.buffer_rx[1];
			
			canbus.buffer_tx[0] = 0;
			if(pulsador_subida){canbus.buffer_tx[0]|=(1<<0);}
			if(pulsador_bajada){canbus.buffer_tx[0]|=(1<<1);}
			if(fin_carrera){canbus.buffer_tx[0]|=(1<<2);}
			if(micro_puerta){canbus.buffer_tx[0]|=(1<<3);}
			canbus.buffer_tx[0] = error;
			canbus.address_tx = MY_ID+ID_CRC;
			canbus_send(canbus.address_tx,canbus.buffer_tx);
			return 1;
		}
	}
	return 0;
}

#endif /* CANBUS_H_ */