/*
 * GPIO_setup.c
 *
 * Created: 01/11/2024 15:13:03
 *  Author: JOEL
 */ 


#include "GPIO_setup.h"
#include <avr/io.h>

 volatile uint8_t* ports[]={&PORTB, &PORTC, &PORTD};
 volatile uint8_t* ddrs[]={&DDRB, &DDRC, &DDRD };
 volatile uint8_t* pins[]={&PINB, &PINC, &PIND};


void derivePortnPin(Pins pinName,uint8_t* pinNum,uint8_t* port){// function to derive pin number and port name from encoded HEX values
	uint8_t encodedPin=(uint8_t)pinName;
	*pinNum = (encodedPin & 0x07);
	*port = (encodedPin&(0x03<<3))>>6;
}
void pinMode(Pins pin, Direction direction){//function that will set a particular pin as either output or input
	uint8_t port,pinNum;
	derivePortnPin(pin, &pinNum, &port);
	switch (direction)
	{
		case output:
			setPinOutput(port,pinNum);
			break;
		case input:
			setPinInput(port,pinNum);
			break;
	}
}

static inline void setPinOutput(uint8_t port, uint8_t pinNum){//function to set the data direction of a particular port as output
	*ddrs[port]|=(1<<pinNum);
}
static inline void setPinInput(uint8_t port, uint8_t pinNum){
	*ddrs[port]&= ~(1<<pinNum);
}
static inline void setPinHigh(uint8_t port, uint8_t pinNum){//function to set a particular pin to logic HIGH
	*ports[port]|=(1<<pinNum);
}
static inline void setPinLow(uint8_t port, uint8_t pinNum){
	*ports[port]&=~(1<<pinNum);
}

void pinState(Pins pin, State state){
	uint8_t port,pinNum;
	derivePortnPin(pin, &pinNum, &port);
	switch (state)
	{
		case high:
		setPinHigh(port,pinNum);
		break;
		case low:
		setPinLow(port,pinNum);
		break;
	}
}