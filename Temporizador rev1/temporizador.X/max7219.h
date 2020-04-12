/* 
 * File:   max7219.h
 * Author: Ericson
 *
 * Created on 6 de abril de 2020, 04:23 PM
 */

#ifndef MAX7219_H
#define	MAX7219_H

char dig1[11] = {
    0b11110101,
    0b01100000,
    0b10110110,
    0b11110010,
    0b01100011,
    0b11010011,
    0b11010111,
    0b01110000,
    0b11110111,
    0b11110011,
    0b00000000
};

char dig2[11] = {
    0b11001111,
    0b00000011,
    0b10101110,
    0b00101111,
    0b01100011,
    0b01101101,
    0b11101101,
    0b00001011,
    0b11101111,
    0b01101111,
    0b00000000
};

#define din         LATCbits.LATC1
#define din_tris    TRISCbits.TRISC1
#define load        LATCbits.LATC2
#define load_tris   TRISCbits.TRISC2
#define clk         LATCbits.LATC3
#define clk_tris    TRISCbits.TRISC3

#define DIGIT_0 1
#define DIGIT_1 2
#define DIGIT_2 3
#define DIGIT_3 4
#define DIGIT_4 5
#define DIGIT_5 6
#define DIGIT_6 7
#define DIGIT_7 8
#define	DECO	0x09
#define	BRIG	0x0A
#define	SCAN	0x0B
#define	SHUT	0x0C
#define	TEST	0x0F

void max7219_config(void);
void __max7219_write(unsigned int, unsigned int);
void max7219_writeChar(unsigned int, unsigned int);
void max7219_brillo(unsigned int);

void __max7219_write(unsigned int address, unsigned int data) {
    unsigned int i = 0, j;
    unsigned int dataSend = 0;
    dataSend = address;
    dataSend <<= 8;
    dataSend += data;
    dataSend &= 0x0FFF;
    load = 0;
    for (i = 16; i > 0; i--) {
        if (dataSend & (1 << (i - 1))) {
            din = 1;
        } else {
            din = 0;
        }
        clk = 1;
        clk = 0;
    }
    load = 1;
}

void max7219_config(void) {
    load = 1;
    din_tris = 0;
    load_tris = 0;
    clk_tris = 0;
    load = 0;
    __max7219_write(DECO, 0x00);
    load = 1;
    load = 0;
    __max7219_write(BRIG, 0x00);
    load = 1;
    load = 0;
    __max7219_write(SCAN, 0x07);
    load = 1;
    load = 0;
    __max7219_write(SHUT, 0x01);
    load = 1;
    load = 0;
    __max7219_write(TEST, 0x00);
    load = 1;
}

void max7219_writeChar(unsigned int pos, unsigned int data) {
    if (pos > 0 && pos < 10 && data < 10) {
        if (pos == 1 || pos == 5 || pos == 7 || pos == 3) {
            __max7219_write(pos, dig1[data]);
        } else {
            __max7219_write(pos, dig2[data]);
        }
    }
}

void max7219_brillo(unsigned int data) {
    if (data < 15) {
        load = 0;
        __max7219_write(BRIG, data);
        load = 1;
    }
}

#endif	/* MAX7219_H */

