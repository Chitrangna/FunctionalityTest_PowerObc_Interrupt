/*
 * OBCm--OBCm-Power.c
 *
 * Created: 01-08-2017 21:45:03
 * Author : Chitrangna Bhatt
 */ 

#define F_CPU 8000000
#include <avr/io.h>
#include "common.h"
#include "uart.h"
#include "i2c.h"


int main(void)
{
	DDRA = 0xF0;
	// Initializations 
	init_UART0();
	//PORTA = 0xF0;
	_delay_ms(300);
	TWI_init_master();
	// Variables 
	
	//receive_UART0();
	//sei();
	uint8_t m=100;
	transmit_UART0(m);
	transmit_UART0('a');
	transmit_UART0('b');
	transmit_UART0('c');
	_delay_ms(200);
	
    while (1) 
    {
		uint8_t data= '5';
		//uint8_t data=receive_UART0();
		transmit_UART0('1');
		PORTA = 0x10;
		_delay_ms(100);
		
		TWI_start();
		transmit_UART0('a');
		PORTA = 0x20;
		_delay_ms(100);
		
		TWI_write_address(0x20);
		transmit_UART0('b');
		PORTA = 0x40;
		_delay_ms(100);
		
		TWI_write_data(data);
		transmit_UART0('c');
		PORTA=0x80;
		_delay_ms(100);
		
		TWI_stop();
		transmit_UART0('d');
		//PORTA=0xF0;
		_delay_ms(100);
    }
}

