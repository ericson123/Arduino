/*
* mcp2515.h
*
* Created: 16/04/2019 15:56:44
*  Author: Uusario 1
*/


#ifndef MCP2515_H_
#define MCP2515_H_

#define TIMEOUTVALUE    50
#define MCP_SIDH        0
#define MCP_SIDL        1
#define MCP_EID8        2
#define MCP_EID0        3

#define MCP_TXB_EXIDE_M     0x08
#define MCP_DLC_MASK        0x0F
#define MCP_RTR_MASK        0x40

#define MCP_RXB_RX_ANY      0x60
#define MCP_RXB_RX_EXT      0x40
#define MCP_RXB_RX_STD      0x20
#define MCP_RXB_RX_STDEXT   0x00
#define MCP_RXB_RX_MASK     0x60
#define MCP_RXB_BUKT_MASK   (1<<2)

#define MCP_TXB_TXBUFE_M    0x80
#define MCP_TXB_ABTF_M      0x40
#define MCP_TXB_MLOA_M      0x20
#define MCP_TXB_TXERR_M     0x10
#define MCP_TXB_TXREQ_M     0x08
#define MCP_TXB_TXIE_M      0x04
#define MCP_TXB_TXP10_M     0x03

#define MCP_TXB_RTR_M       0x40
#define MCP_RXB_IDE_M       0x08
#define MCP_RXB_RTR_M       0x40

#define MCP_STAT_RXIF_MASK   (0x03)
#define MCP_STAT_RX0IF (1<<0)
#define MCP_STAT_RX1IF (1<<1)

#define MCP_EFLG_RX1OVR (1<<7)
#define MCP_EFLG_RX0OVR (1<<6)
#define MCP_EFLG_TXBO   (1<<5)
#define MCP_EFLG_TXEP   (1<<4)
#define MCP_EFLG_RXEP   (1<<3)
#define MCP_EFLG_TXWAR  (1<<2)
#define MCP_EFLG_RXWAR  (1<<1)
#define MCP_EFLG_EWARN  (1<<0)
#define MCP_EFLG_ERRORMASK  (0xF8)

#define MCP_RXF0SIDH    0x00
#define MCP_RXF0SIDL    0x01
#define MCP_RXF0EID8    0x02
#define MCP_RXF0EID0    0x03
#define MCP_RXF1SIDH    0x04
#define MCP_RXF1SIDL    0x05
#define MCP_RXF1EID8    0x06
#define MCP_RXF1EID0    0x07
#define MCP_RXF2SIDH    0x08
#define MCP_RXF2SIDL    0x09
#define MCP_RXF2EID8    0x0A
#define MCP_RXF2EID0    0x0B
#define MCPCANSTAT     0x0E
#define MCPCANCTRL     0x0F
#define MCP_RXF3SIDH    0x10
#define MCP_RXF3SIDL    0x11
#define MCP_RXF3EID8    0x12
#define MCP_RXF3EID0    0x13
#define MCP_RXF4SIDH    0x14
#define MCP_RXF4SIDL    0x15
#define MCP_RXF4EID8    0x16
#define MCP_RXF4EID0    0x17
#define MCP_RXF5SIDH    0x18
#define MCP_RXF5SIDL    0x19
#define MCP_RXF5EID8    0x1A
#define MCP_RXF5EID0    0x1B
#define MCP_TEC         0x1C
#define MCP_REC         0x1D
#define MCP_RXM0SIDH    0x20
#define MCP_RXM0SIDL    0x21
#define MCP_RXM0EID8    0x22
#define MCP_RXM0EID0    0x23
#define MCP_RXM1SIDH    0x24
#define MCP_RXM1SIDL    0x25
#define MCP_RXM1EID8    0x26
#define MCP_RXM1EID0    0x27
#define MCP_CNF3        0x28
#define MCP_CNF2        0x29
#define MCP_CNF1        0x2A
#define MCPCANINTE     0x2B
#define MCPCANINTF     0x2C
#define MCP_EFLG        0x2D
#define MCP_TXB0CTRL    0x30
#define MCP_TXB1CTRL    0x40
#define MCP_TXB2CTRL    0x50
#define MCP_RXB0CTRL    0x60
#define MCP_RXB0SIDH    0x61
#define MCP_RXB1CTRL    0x70
#define MCP_RXB1SIDH    0x71

#define MCP_TX_INT          0x1C
#define MCP_TX01_INT        0x0C
#define MCP_RX_INT          0x03
#define MCP_NO_INT          0x00

#define MCP_TX01_MASK       0x14
#define MCP_TX_MASK         0x54

#define MCP_WRITE           0x02

#define MCP_READ            0x03

#define MCP_BITMOD          0x05

#define MCP_LOAD_TX0        0x40
#define MCP_LOAD_TX1        0x42
#define MCP_LOAD_TX2        0x44

#define MCP_RTS_TX0         0x81
#define MCP_RTS_TX1         0x82
#define MCP_RTS_TX2         0x84
#define MCP_RTS_ALL         0x87

#define MCP_READ_RX0        0x90
#define MCP_READ_RX1        0x94

#define MCP_READ_STATUS     0xA0

#define MCP_RX_STATUS       0xB0

//Rx STATUS INSTRUCTION
//bit 7:6
#define MCP_MESGE_NO_MSK    (3 << 6)
#define MCP_MESGE_RXB0_MSK  (1 << 6)
#define MCP_MESGE_RXB1_MSK  (2 << 6)
#define MCP_MESGE_RXB01_MSK (3 << 6)
//bit 4:3
#define MCP_FRAME_STDDF_MASK    (0 << 3)
#define MCP_FRAME_REMOTERF_MASK (1 << 3)
#define MCP_FRAME_EXTDF_MASK    (2 << 3)
#define MCP_FRAME_EXTRF_MASK    (3 << 3)
//bit 2:0
#define MCP_FILMATCH_STD_MSK   (0x7FF < 0)
#define MCP_FILMATCH_EXT_MSK   (0x7FFFF < 0)

#define MCP_RESET           0xC0

#define MODE_NORMAL     0x00
#define MODE_SLEEP      0x20
#define MODE_LOOPBACK   0x40
#define MODE_LISTENONLY 0x60
#define MODE_CONFIG     0x80
#define MODE_POWERUP    0xE0
#define MODE_MASK       0xE0
#define ABORT_TX        0x10
#define MODE_ONESHOT    0x08
#define CLKOUT_ENABLE   0x04
#define CLKOUT_DISABLE  0x00
#define CLKOUT_PS1      0x00
#define CLKOUT_PS2      0x01
#define CLKOUT_PS4      0x02
#define CLKOUT_PS8      0x03

#define SJW1            0x00
#define SJW2            0x40
#define SJW3            0x80
#define SJW4            0xC0

#define BTLMODE         0x80
#define SAMPLE_1X       0x00
#define SAMPLE_3X       0x40

#define SOF_ENABLE      0x80
#define SOF_DISABLE     0x00
#define WAKFIL_ENABLE   0x40
#define WAKFIL_DISABLE  0x00

#define MCP_RX0IF       0x01
#define MCP_RX1IF       0x02
#define MCP_TX0IF       0x04
#define MCP_TX1IF       0x08
#define MCP_TX2IF       0x10
#define MCP_ERRIF       0x20
#define MCP_WAKIF       0x40
#define MCP_MERRF       0x80

#define MCP_16MHz_1000kBPS_CFG1 (0x00)
#define MCP_16MHz_1000kBPS_CFG2 (0xD0)
#define MCP_16MHz_1000kBPS_CFG3 (0x82)

#define MCP_16MHz_500kBPS_CFG1 (0x00)
#define MCP_16MHz_500kBPS_CFG2 (0xF0)
#define MCP_16MHz_500kBPS_CFG3 (0x86)

#define MCP_16MHz_250kBPS_CFG1 (0x41)
#define MCP_16MHz_250kBPS_CFG2 (0xF1)
#define MCP_16MHz_250kBPS_CFG3 (0x85)

#define MCP_16MHz_200kBPS_CFG1 (0x01)
#define MCP_16MHz_200kBPS_CFG2 (0xFA)
#define MCP_16MHz_200kBPS_CFG3 (0x87)

#define MCP_16MHz_125kBPS_CFG1 (0x03)
#define MCP_16MHz_125kBPS_CFG2 (0xF0)
#define MCP_16MHz_125kBPS_CFG3 (0x86)

#define MCP_16MHz_100kBPS_CFG1 (0x03)
#define MCP_16MHz_100kBPS_CFG2 (0xFA)
#define MCP_16MHz_100kBPS_CFG3 (0x87)


#define MCP_16MHz_95kBPS_CFG1 (0x03)
#define MCP_16MHz_95kBPS_CFG2 (0xAD)
#define MCP_16MHz_95kBPS_CFG3 (0x07)

#define MCP_16MHz_83k3BPS_CFG1 (0x03)
#define MCP_16MHz_83k3BPS_CFG2 (0xBE)
#define MCP_16MHz_83k3BPS_CFG3 (0x07)

#define MCP_16MHz_80kBPS_CFG1 (0x03)
#define MCP_16MHz_80kBPS_CFG2 (0xFF)
#define MCP_16MHz_80kBPS_CFG3 (0x87)

#define MCP_16MHz_50kBPS_CFG1 (0x07)
#define MCP_16MHz_50kBPS_CFG2 (0xFA)
#define MCP_16MHz_50kBPS_CFG3 (0x87)

#define MCP_16MHz_40kBPS_CFG1 (0x07)
#define MCP_16MHz_40kBPS_CFG2 (0xFF)
#define MCP_16MHz_40kBPS_CFG3 (0x87)

#define MCP_16MHz_33kBPS_CFG1 (0x09)
#define MCP_16MHz_33kBPS_CFG2 (0xBE)
#define MCP_16MHz_33kBPS_CFG3 (0x07)

#define MCP_16MHz_31k25BPS_CFG1 (0x0F)
#define MCP_16MHz_31k25BPS_CFG2 (0xF1)
#define MCP_16MHz_31k25BPS_CFG3 (0x85)

#define MCP_16MHz_20kBPS_CFG1 (0x0F)
#define MCP_16MHz_20kBPS_CFG2 (0xFF)
#define MCP_16MHz_20kBPS_CFG3 (0x87)

#define MCP_16MHz_10kBPS_CFG1 (0x1F)
#define MCP_16MHz_10kBPS_CFG2 (0xFF)
#define MCP_16MHz_10kBPS_CFG3 (0x87)

#define MCP_16MHz_5kBPS_CFG1 (0x3F)
#define MCP_16MHz_5kBPS_CFG2 (0xFF)
#define MCP_16MHz_5kBPS_CFG3 (0x87)

#define MCPDEBUG        (0)
#define MCPDEBUG_TXBUF  (0)
#define MCP_N_TXBUFFERS (3)

#define MCP_RXBUF_0 (MCP_RXB0SIDH)
#define MCP_RXBUF_1 (MCP_RXB1SIDH)

#define MCPSPI_SELECT()   (PORTB &= ~(1<<2))
#define MCPSPI_UNSELECT() (PORTB |= (1<<2))

#define MCP_OK         (0)
#define MCP_FAIL       (1)
#define MCP_ALLTXBUSY      (2)

#define CANDEBUG   1

#define CANUSELOOP 0

#define CANSENDTIMEOUT (200)

#define CANAUTOPROCESS (1)
#define CANAUTOON  (1)
#define CANAUTOOFF (0)

#define CAN_STDID (0)
#define CAN_EXTID (1)

#define CANDEFAULTIDENT    (0x55CC)
#define CANDEFAULTIDENTEXT (CAN_EXTID)

#define CAN_5KBPS    1
#define CAN_10KBPS   2
#define CAN_20KBPS   3
#define CAN_31K25BPS 4
#define CAN_33KBPS   5
#define CAN_40KBPS   6
#define CAN_50KBPS   7
#define CAN_80KBPS   8
#define CAN_83K3BPS  9
#define CAN_95KBPS   10
#define CAN_100KBPS  11
#define CAN_125KBPS  12
#define CAN_200KBPS  13
#define CAN_250KBPS  14
#define CAN_500KBPS  15
#define CAN_1000KBPS 16

#define CAN_OK                  (0)
#define CAN_FAILINIT            (1)
#define CAN_FAILTX              (2)
#define CAN_MSGAVAIL            (3)
#define CAN_NOMSG               (4)
#define CAN_CTRLERROR           (5)
#define CAN_GETTXBFTIMEOUT      (6)
#define CAN_SENDMSGTIMEOUT      (7)
#define CAN_FAIL                (0xff)

#define CAN_MAX_MESSAGE_LENGTH (8)

#define MAX_MESSAGE_LENGTH 8

uint8_t		can_ExtFlg;
uint32_t	can_ID;
uint8_t		can_Dlc;
uint8_t		can_Dta[MAX_MESSAGE_LENGTH];
uint8_t		can_Rtr;

void spi_begin(void);
uint8_t spi_readWrite(uint8_t);
uint8_t spi_read(void);

void mcp_writeId( uint8_t mcp_addr, uint8_t ext, uint32_t id );
void mcp_reset(void);
uint8_t mcp_init(uint8_t);
uint8_t mcp_setMode(uint8_t);
void mcp_modifyRegister(uint8_t,uint8_t,uint8_t);
uint8_t mcp_readRegister(uint8_t);
uint8_t mcp_configRate(uint8_t);
void mcp_setRegister(uint8_t,uint8_t);
void mcp_initBuffers(void);
uint8_t mcp_getNextFreeTXBuf(uint8_t *txbuf_n);
void mcp_writecanMsg( uint8_t sidh_addr);
void mcp_setMulitRegisterS(uint8_t RegAddr, uint8_t *buf, uint8_t len);
void mcp_readMulitiRegisters(uint8_t RegAddr, uint8_t *buf, uint8_t len);
void mcp_readid( uint8_t mcp_addr, uint8_t* ext, uint32_t* id );
void mcp_readcanMsg( uint8_t idh_addr);
uint8_t mcp_readStatus(void);
void mcp_starttransmit(uint8_t mcp_addr);

uint8_t can_config(uint8_t);
uint8_t can_read(void);
uint8_t can_write(void);
uint8_t can_begin(uint8_t);
uint8_t can_sendMsgBuf(uint8_t, uint8_t, uint8_t, uint8_t*);
uint8_t can_setMsg(uint8_t, uint8_t, uint8_t, uint8_t*);
uint8_t can_sendMsg(void);
uint8_t can_mcp_readStatus(void);
uint8_t can_checkReceive(void);
uint8_t can_readMsgBuf(uint8_t *len, uint8_t *buf);
uint8_t can_readMsg(void);
uint32_t can_readId(void);

void spi_begin(void){
	// Set MOSI, SCK, CS as Output
	DDRB |= (1<<PINB2)|(1<<PINB3)|(1<<PINB5);
	// Enable SPI, Set as Master
	//Prescaler: Fosc/16, Enable Interrupts
	SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);
	MCPSPI_UNSELECT();
}

uint8_t spi_readWrite(uint8_t d){
	// Load data into the buffer
	SPDR = d;
	asm volatile("nop");
	while(!(SPSR & (1<<SPIF) ));
	
	// Return received data
	return (SPDR);
}

uint8_t spi_read(void){
	return spi_readWrite(0x00);
}

uint8_t can_config(uint8_t d){
	spi_begin();
	mcp_reset();
	if(CAN_OK == can_begin(d)){return 1;}
	else{return 0;}
}
uint8_t can_begin(uint8_t speedSet){
	volatile uint8_t r = 0;
	r = mcp_init(speedSet);
	if(r == MCP_OK){return CAN_OK;}
	else{return CAN_FAILINIT;}
}

uint8_t can_sendMsgBuf(uint8_t id, uint8_t ext, uint8_t len, uint8_t *buf){
	can_setMsg(id, ext, len, buf);
	return can_sendMsg();
}

uint8_t can_setMsg(uint8_t id, uint8_t ext, uint8_t len, uint8_t *pData){
	int i = 0;
	can_ExtFlg = ext;
	can_ID     = id;
	can_Dlc    = len;
	for(i = 0; i < MAX_MESSAGE_LENGTH; i++){
		can_Dta[i] = *(pData+i);
	}
	return MCP_OK;
}

uint8_t can_sendMsg(void){
	uint8_t res, txindex;
	uint16_t uiTimeOut = 0;

	do {
		res = mcp_getNextFreeTXBuf(&txindex);
		uiTimeOut++;
	} while (res == MCP_ALLTXBUSY && (uiTimeOut < TIMEOUTVALUE));

	if(uiTimeOut == TIMEOUTVALUE){
		return CAN_GETTXBFTIMEOUT;
	}
	
	uiTimeOut = 0;
	mcp_writecanMsg( txindex);
	mcp_starttransmit( txindex );
	do{
		uiTimeOut++;
		res = mcp_readRegister(txindex);
		res = res & 0x08;
	}while(res && (uiTimeOut < TIMEOUTVALUE));
	
	if(uiTimeOut == TIMEOUTVALUE){
		return CAN_SENDMSGTIMEOUT;
	}
	return CAN_OK;
}

uint8_t can_checkReceive(void){
	uint8_t res;
	res = mcp_readStatus();
	if ( res & MCP_MESGE_NO_MSK ){
		return CAN_MSGAVAIL;
	}
	else{
		return CAN_NOMSG;
	}
}

uint8_t can_readMsgBuf(uint8_t *len, uint8_t *buf){
	uint8_t  res, i;
	res= can_readMsg();
	
	if (res == CAN_OK) {
		*len = can_Dlc;
		for( i = 0; i<can_Dlc; i++) {
			buf[i] = can_Dta[i];
		}
	}
	else {
		*len = 0;
	}
	return res;
}

uint8_t can_readMsg(void){
	uint8_t status, res;
	status = mcp_readStatus();
	
	if ( status & MCP_MESGE_RXB0_MSK ){
		mcp_readcanMsg( MCP_RXBUF_0);             //0x61
		mcp_modifyRegister(MCPCANINTF, MCP_RX0IF, 0);
		res = CAN_OK;
	}
	else if ( status & MCP_MESGE_RXB1_MSK ){               //message in rx buf1
		mcp_readcanMsg( MCP_RXBUF_1);
		mcp_modifyRegister(MCPCANINTF, MCP_RX1IF, 0);
		res = CAN_OK;
	}
	else if (status & MCP_MESGE_RXB01_MSK){
		res = CAN_OK;
	}
	else{
		res = CAN_NOMSG;
	}
	
	return res;
}

void mcp_reset(void){
	MCPSPI_SELECT();
	spi_readWrite(MCP_RESET);
	MCPSPI_UNSELECT();
	for(uint16_t i=0;i<50000;i++){asm("nop");}//_delay_ms(10);
}

uint8_t mcp_init(uint8_t canSpeed){
	volatile uint8_t r = 0;
	r = mcp_setMode(MODE_CONFIG);
	if(r>0){
		for(uint16_t i=0;i<50000;i++){asm("nop");}//_delay_ms(10);
		return r;
	}
	for(uint16_t i=0;i<50000;i++){asm("nop");}//_delay_ms(10);
	if(mcp_configRate(canSpeed)){
		for(uint16_t i=0;i<50000;i++){asm("nop");}//_delay_ms(10);
		return r;
	}
	for(uint16_t i=0;i<50000;i++){asm("nop");}//_delay_ms(10);
	if(r==MCP_OK){
		mcp_initBuffers();
		mcp_setRegister(MCPCANINTE, MCP_RX0IF | MCP_RX1IF);
		mcp_modifyRegister(MCP_RXB0CTRL, MCP_RXB_RX_MASK | MCP_RXB_BUKT_MASK, MCP_RXB_RX_STDEXT | MCP_RXB_BUKT_MASK );
		mcp_modifyRegister(MCP_RXB1CTRL, MCP_RXB_RX_MASK, MCP_RXB_RX_STDEXT);
		r = mcp_setMode(MODE_NORMAL);
		if(r){
			for(uint16_t i=0;i<50000;i++){asm("nop");}//_delay_ms(10);
			return r;
		}
		for(uint16_t i=0;i<50000;i++){asm("nop");}//_delay_ms(10);
	}
	
	return r;
}

uint8_t mcp_setMode(uint8_t newMode){
	volatile uint8_t r = 0;
	mcp_modifyRegister(MCPCANCTRL,MODE_MASK,newMode);
	r = mcp_readRegister(MCPCANCTRL);
	r &= MODE_MASK;
	if(r==newMode){ return MCP_OK;}
	return MCP_FAIL;
}

uint8_t mcp_readRegister(uint8_t regAddr){
	uint8_t r = 0;
	MCPSPI_SELECT();
	spi_readWrite(MCP_READ);
	spi_readWrite(regAddr);
	r = spi_read();
	MCPSPI_UNSELECT();
	return r;
}

void mcp_modifyRegister(uint8_t regAddr, uint8_t mask, uint8_t d){
	MCPSPI_SELECT();
	spi_readWrite(MCP_BITMOD);
	spi_readWrite(regAddr);
	spi_readWrite(mask);
	spi_readWrite(d);
	MCPSPI_UNSELECT();
}

void mcp_setRegister(uint8_t regAddr,uint8_t value){
	MCPSPI_SELECT();
	spi_readWrite(MCP_WRITE);
	spi_readWrite(regAddr);
	spi_readWrite(value);
	MCPSPI_UNSELECT();
}

void mcp_initBuffers(void){
	uint8_t i, a1, a2, a3;
	
	a1 = MCP_TXB0CTRL;
	a2 = MCP_TXB1CTRL;
	a3 = MCP_TXB2CTRL;
	for (i = 0; i < 14; i++) {
		mcp_setRegister(a1, 0);
		mcp_setRegister(a2, 0);
		mcp_setRegister(a3, 0);
		a1++;
		a2++;
		a3++;
	}
	mcp_setRegister(MCP_RXB0CTRL, 0);
	mcp_setRegister(MCP_RXB1CTRL, 0);
}

void mcp_starttransmit(uint8_t mcp_addr){
	mcp_modifyRegister( mcp_addr-1 , MCP_TXB_TXREQ_M, MCP_TXB_TXREQ_M );
}

uint8_t mcp_configRate(uint8_t canSpeed){
	uint8_t preSet, cfg1, cfg2, cfg3;
	
	preSet = 0;
	switch (canSpeed)
	{
		case (CAN_5KBPS):
		cfg1 = MCP_16MHz_5kBPS_CFG1;
		cfg2 = MCP_16MHz_5kBPS_CFG2;
		cfg3 = MCP_16MHz_5kBPS_CFG3;
		break;

		case (CAN_10KBPS):
		cfg1 = MCP_16MHz_10kBPS_CFG1;
		cfg2 = MCP_16MHz_10kBPS_CFG2;
		cfg3 = MCP_16MHz_10kBPS_CFG3;
		break;

		case (CAN_20KBPS):
		cfg1 = MCP_16MHz_20kBPS_CFG1;
		cfg2 = MCP_16MHz_20kBPS_CFG2;
		cfg3 = MCP_16MHz_20kBPS_CFG3;
		break;
		
		case (CAN_31K25BPS):
		cfg1 = MCP_16MHz_31k25BPS_CFG1;
		cfg2 = MCP_16MHz_31k25BPS_CFG2;
		cfg3 = MCP_16MHz_31k25BPS_CFG3;
		break;

		case (CAN_33KBPS):
		cfg1 = MCP_16MHz_33kBPS_CFG1;
		cfg2 = MCP_16MHz_33kBPS_CFG2;
		cfg3 = MCP_16MHz_33kBPS_CFG3;
		break;

		case (CAN_40KBPS):
		cfg1 = MCP_16MHz_40kBPS_CFG1;
		cfg2 = MCP_16MHz_40kBPS_CFG2;
		cfg3 = MCP_16MHz_40kBPS_CFG3;
		break;

		case (CAN_50KBPS):
		cfg1 = MCP_16MHz_50kBPS_CFG1;
		cfg2 = MCP_16MHz_50kBPS_CFG2;
		cfg3 = MCP_16MHz_50kBPS_CFG3;
		break;

		case (CAN_80KBPS):
		cfg1 = MCP_16MHz_80kBPS_CFG1;
		cfg2 = MCP_16MHz_80kBPS_CFG2;
		cfg3 = MCP_16MHz_80kBPS_CFG3;
		break;

		case (CAN_83K3BPS):
		cfg1 = MCP_16MHz_83k3BPS_CFG1;
		cfg2 = MCP_16MHz_83k3BPS_CFG2;
		cfg3 = MCP_16MHz_83k3BPS_CFG3;
		break;

		case (CAN_95KBPS):
		cfg1 = MCP_16MHz_95kBPS_CFG1;
		cfg2 = MCP_16MHz_95kBPS_CFG2;
		cfg3 = MCP_16MHz_95kBPS_CFG3;
		break;

		case (CAN_100KBPS):
		cfg1 = MCP_16MHz_100kBPS_CFG1;
		cfg2 = MCP_16MHz_100kBPS_CFG2;
		cfg3 = MCP_16MHz_100kBPS_CFG3;
		break;

		case (CAN_125KBPS):
		cfg1 = MCP_16MHz_125kBPS_CFG1;
		cfg2 = MCP_16MHz_125kBPS_CFG2;
		cfg3 = MCP_16MHz_125kBPS_CFG3;
		break;

		case (CAN_200KBPS):
		cfg1 = MCP_16MHz_200kBPS_CFG1;
		cfg2 = MCP_16MHz_200kBPS_CFG2;
		cfg3 = MCP_16MHz_200kBPS_CFG3;
		break;

		case (CAN_250KBPS):
		cfg1 = MCP_16MHz_250kBPS_CFG1;
		cfg2 = MCP_16MHz_250kBPS_CFG2;
		cfg3 = MCP_16MHz_250kBPS_CFG3;
		break;

		case (CAN_500KBPS):
		cfg1 = MCP_16MHz_500kBPS_CFG1;
		cfg2 = MCP_16MHz_500kBPS_CFG2;
		cfg3 = MCP_16MHz_500kBPS_CFG3;
		break;
		
		case (CAN_1000KBPS):
		cfg1 = MCP_16MHz_1000kBPS_CFG1;
		cfg2 = MCP_16MHz_1000kBPS_CFG2;
		cfg3 = MCP_16MHz_1000kBPS_CFG3;
		break;

		default:
		preSet = 1;
		break;
	}

	if (!preSet) {
		mcp_setRegister(MCP_CNF1, cfg1);
		mcp_setRegister(MCP_CNF2, cfg2);
		mcp_setRegister(MCP_CNF3, cfg3);
		return MCP_OK;
	}
	else {
		return MCP_FAIL;
	}
}

uint8_t mcp_getNextFreeTXBuf(uint8_t *txbuf_n){
	uint8_t res, i, ctrlval;
	uint8_t ctrlregs[MCP_N_TXBUFFERS] = { MCP_TXB0CTRL, MCP_TXB1CTRL, MCP_TXB2CTRL };

	res = MCP_ALLTXBUSY;
	*txbuf_n = 0x00;

	
	for (i=0; i < MCP_N_TXBUFFERS; i++) {
		ctrlval = mcp_readRegister( ctrlregs[i] );
		if ( (ctrlval & MCP_TXB_TXREQ_M) == 0 ) {
			*txbuf_n = ctrlregs[i]+1;
			
			res = MCP_OK;
			return res;
		}
	}
	return res;
}

void mcp_writecanMsg( uint8_t sidh_addr){
	uint8_t mcp_addr;
	mcp_addr = sidh_addr;
	mcp_setMulitRegisterS(mcp_addr+5, can_Dta, can_Dlc );
	if ( can_Rtr == 1){
		can_Dlc |= MCP_RTR_MASK;
	}
	mcp_setRegister((mcp_addr+4), can_Dlc );
	mcp_writeId(mcp_addr, can_ExtFlg, can_ID );
}

void mcp_setMulitRegisterS(uint8_t RegAddr, uint8_t *buf, uint8_t len){
	uint8_t i;
	MCPSPI_SELECT();
	spi_readWrite(MCP_WRITE);
	spi_readWrite(RegAddr);
	for (i=0; i < len; i++){
		spi_readWrite(buf[i]);
	}
	MCPSPI_UNSELECT();
}

void mcp_writeId( uint8_t mcp_addr, uint8_t ext, uint32_t id ){
	uint16_t canid;
	uint8_t tbufdata[4];
	canid = (uint16_t)(id & 0x0FFFF);
	if ( ext == 1){
		tbufdata[MCP_EID0] = (uint8_t) (canid & 0xFF);
		tbufdata[MCP_EID8] = (uint8_t) (canid >> 8);
		canid = (uint16_t)(id >> 15);
		tbufdata[MCP_SIDL] = (uint8_t) (canid & 0x03);
		tbufdata[MCP_SIDL] += (uint8_t) ((canid & 0x1C) << 3);
		tbufdata[MCP_SIDL] |= MCP_TXB_EXIDE_M;
		tbufdata[MCP_SIDH] = (uint8_t) (canid >> 5 );
	}
	else{
		tbufdata[MCP_SIDH] = (uint8_t) (canid >> 3 );
		tbufdata[MCP_SIDL] = (uint8_t) ((canid & 0x07 ) << 5);
		tbufdata[MCP_EID0] = 0;
		tbufdata[MCP_EID8] = 0;
	}
	mcp_setMulitRegisterS( mcp_addr, tbufdata, 4 );
}

uint8_t mcp_readStatus(void){
	uint8_t ret;
	
	MCPSPI_SELECT();
	spi_readWrite(MCP_RX_STATUS);
	ret = spi_read();
	MCPSPI_UNSELECT();
	return ret;
}

void mcp_readcanMsg( uint8_t idh_addr){
	mcp_readid( idh_addr, &can_ExtFlg,&can_ID );

	can_Rtr = mcp_readRegister( idh_addr - 1 );
	can_Dlc = mcp_readRegister( idh_addr + 4 );

	if ((can_Rtr & (1 << 3))) {
		can_Rtr = 1;
	}
	else {
		can_Rtr = 0;
	}

	can_Dlc &= MCP_DLC_MASK;
	mcp_readMulitiRegisters( idh_addr+5, (uint8_t *)can_Dta, can_Dlc);
}

void mcp_readid( uint8_t mcp_addr, uint8_t* ext, uint32_t* id ){
	uint8_t id_Buf[4];

	mcp_readMulitiRegisters( mcp_addr, (uint8_t *)id_Buf, 4 );

	*id = (id_Buf[MCP_SIDH]<< 3) + (id_Buf[MCP_SIDL]>>5);

	if ( (id_Buf[MCP_SIDL] & 1 << 3)){
		*id = (*id<<2) + (id_Buf[MCP_SIDL] & 0x03);
		*id = (*id<<8) + id_Buf[MCP_EID8];
		*id = (*id<<8) + id_Buf[MCP_EID0];
		*ext = 1;
	}
}

void mcp_readMulitiRegisters(uint8_t RegAddr, uint8_t *buf, uint8_t len){
	uint8_t i;

	if ( len > CAN_MAX_MESSAGE_LENGTH){
		len = CAN_MAX_MESSAGE_LENGTH;
	}
	
	MCPSPI_SELECT();
	spi_readWrite(MCP_READ);
	spi_readWrite(RegAddr);

	for (i=0; i < len; i++) {
		buf[i] = spi_read();
	}
	MCPSPI_UNSELECT();
}

uint32_t can_readId(void){
	return can_ID;
}

#endif /* MCP2515_H_ */