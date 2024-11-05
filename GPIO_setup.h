/*
 * GPIO_setup.h
 *
 * Created: 01/11/2024 15:12:07
 *  Author: JOEL
 */ 

#include <avr/io.h>
#ifndef GPIO_SETUP_H_
#define GPIO_SETUP_H_
volatile extern uint8_t* ports[];
volatile extern uint8_t* ddrs[];
volatile extern uint8_t* pins[];

typedef enum{
	output=0,
	input,
}Direction;

typedef enum{
	high=0,
	low,
}State;

typedef enum{
	IO_0,IO_1,IO_2,IO_3,IO_4,IO_5,IO_6,IO_7,IO_8,IO_9,
	IO_10,IO_11,IO_12,IO_13,IO_14,IO_15,IO_16,IO_17,IO_18,IO_19,
	IO_20,IO_21,
	
}EncodingValues;

typedef enum{
	//defines PIN names as are used in the program
	UNUSED_0=IO_0,
	UNUSED_1=IO_1,
	UNUSED_2=IO_2,
	UNUSED_3=IO_3,
	UNUSED_4=IO_4,
	h_bridge_IN=IO_5, //D5 to HBRIDGE, IN
	h_bridge_SD=IO_6,//D6 to HBRIDGE, SD bar
	UNUSED_7=IO_7,
	load=IO_8, // D8 determines DC load connection and disconnection
	UNUSED_9=IO_9,
	led_red=IO_10, // D10,D11,D12 status indicator LEDs
	led_blue=IO_11,
	led_green=IO_12,
	UNUSED_13=IO_13,
	pot1=IO_14, //A0 to panel voltage divider
	UNUSED_15=IO_15,
	viout=IO_16, //A2 analog voltage from current sensor
	UNUSED_17=IO_17,
	SDA=IO_18, //A4 to IC I2C
	SCL=IO_19, //A5 to IC I2C
	UNUSED_20=IO_20,
	pot2=IO_21, //A7 to batter voltage divider
	
}Pins;

void derivePortnPin(Pins pinName,uint8_t*pinNum,uint8_t*port);
void pinMode(Pins pin, Direction direction);
void pinState(Pins pin, State state);

static inline void setPinOutput(uint8_t port, uint8_t pinNum);
static inline void setPinInput(uint8_t port, uint8_t pinNum);
static inline void setPinHigh(uint8_t port, uint8_t pinNum);
static inline void setPinLow(uint8_t port, uint8_t pinNum);	



#endif /* GPIO_SETUP_H_ */