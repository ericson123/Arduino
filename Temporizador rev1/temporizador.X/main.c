/*
 * File:   main.c
 * Author: Ericson
 *
 * Created on 6 de abril de 2020, 12:19 PM
 */

#include <xc.h>
#include "fuses.h"
#include "max7219.h"
#include "input.h"
#include "output.h"

void oscillator_config(void);
void timer_0_config(void);
void timer_0_enable(void);
void timer_0_disable(void);
void display_init(void);
void update_eeprom(void);

long k = 0;
int minutos_set = 0;
int segundos_set = 0;
int minutos_temp = 0;
int segundos_temp = 0;
int last_minutos_temp = 0;
int last_segundos_temp = 0;
int proceso = 0;

void main(void) {

    oscillator_config();
    input_config();
    output_config();
    timer_0_config();
    max7219_config();
    max7219_brillo(8);
    update_eeprom();
    display_init();

    while (1) {

        if (input_pulsador_subir()) {
            if (++minutos_set == 60) {
                minutos_set = 0;
            }
            max7219_writeChar(1, minutos_set / 10);
            max7219_writeChar(5, minutos_set % 10);
        }

        if (input_pulsador_bajar()) {
            if (++segundos_set == 60) {
                segundos_set = 0;
            }
            max7219_writeChar(7, segundos_set / 10);
            max7219_writeChar(3, segundos_set % 10);
        }

        if (proceso == 1) {
            if (last_minutos_temp != minutos_temp) {
                last_minutos_temp = minutos_temp;
                max7219_writeChar(8, minutos_temp / 10);
                max7219_writeChar(6, minutos_temp % 10);

            }
            if (last_segundos_temp != segundos_temp) {
                last_segundos_temp = segundos_temp;
                max7219_writeChar(2, segundos_temp / 10);
                max7219_writeChar(4, segundos_temp % 10);
            }

            if (minutos_set == minutos_temp && segundos_set == segundos_temp) {
                minutos_temp = 0;
                segundos_temp = 0;
                timer_0_disable();
                output_relay(1);
                for (k = 0; k < 4000000; k++);
                output_relay(0);
                proceso = 0;
                minutos_temp = 0;
                segundos_temp = 0;
                max7219_writeChar(8, minutos_temp / 10);
                max7219_writeChar(6, minutos_temp % 10);
                max7219_writeChar(2, segundos_temp / 10);
                max7219_writeChar(4, segundos_temp % 10);
            }
        } else {
            if (input_pulsador_ok()) {
                eeprom_write(0, minutos_set);
                eeprom_write(1, segundos_set);
                minutos_temp = 0;
                segundos_temp = 0;
                output_relay(1);
                for (k = 0; k < 100000; k++);
                output_relay(0);
                if (segundos_set > 2 || minutos_set > 0) {
                    timer_0_enable();
                    proceso = 1;
                }
            }
        }
    }
}

void oscillator_config(void) {
    OSCCONbits.IRCF = 0b1110;
    OSCCONbits.SCS = 0b00;
    OSCCONbits.SPLLEN = 1;
}

void timer_0_config(void) {
    TMR0 = 0;
    OPTION_REGbits.TMR0CS = 0;
    OPTION_REGbits.PSA = 0;
    OPTION_REGbits.PS = 0b111;
    OPTION_REGbits.TMR0CS = 0;

    INTCONbits.PEIE = 1;
    INTCONbits.TMR0IF = 0;
    INTCONbits.TMR0IE = 0;
    INTCONbits.GIE = 0;
}

void timer_0_enable(void) {
    TMR0 = 0;
    INTCONbits.TMR0IF = 0;
    INTCONbits.TMR0IE = 1;
    INTCONbits.GIE = 1;
}

void timer_0_disable(void) {
    TMR0 = 0;
    INTCONbits.TMR0IF = 0;
    INTCONbits.TMR0IE = 0;
    INTCONbits.GIE = 0;
}

void display_init(void) {
    int i = 0, j = 0;
    for (i = 10; i > 0; i--) {
        for (j = 1; j < 9; j++) {
            max7219_writeChar(j, i - 1);
        }
        for (k = 0; k < 200000; k++);
    }
    max7219_writeChar(1, minutos_set / 10);
    max7219_writeChar(5, minutos_set % 10);
    max7219_writeChar(7, segundos_set / 10);
    max7219_writeChar(3, segundos_set % 10);
    output_relay(1);
    for (k = 0; k < 100000; k++);
    output_relay(0);
}

void update_eeprom(void) {
    int var1 = 0, var2 = 0;
    unsigned int usos = 0;
    var1 = eeprom_read(0);
    minutos_set = var1;
    var2 = eeprom_read(1);
    segundos_set = var2;
    if (minutos_set == 0xFF || segundos_set == 0xFF) {
        minutos_set = 0;
        segundos_set = 0;
    }

    var1 = eeprom_read(2);
    var2 = eeprom_read(3);
    usos = var1;
    usos <<= 8;
    usos |= var2;
    if (usos == 0xFFFF) {
        usos = 0;
        usos++;
        eeprom_write(2, usos >> 8);
        eeprom_write(3, usos);
    } else {
        usos++;
        eeprom_write(2, usos >> 8);
        eeprom_write(3, usos);
    }
    max7219_writeChar(1, usos / 1000);
    max7219_writeChar(5, (usos % 1000) / 100);
    max7219_writeChar(7, ((usos % 1000) % 100) / 10);
    max7219_writeChar(3, ((usos % 1000) % 100) % 10);
    for (k = 0; k < 500000; k++);
}

void __interrupt() myISR(void) {
    static int f = 0;
    if (INTCONbits.TMR0IE && INTCONbits.TMR0IF) {
        TMR0 = 0;
        INTCONbits.TMR0IF = 0;
        if (++f >= 125) {
            f = 0;
            if (++segundos_temp == 60) {
                minutos_temp++;
                segundos_temp = 0;
            }
        }
    }
}