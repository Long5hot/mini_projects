#include "header.h"

void i2cStart(void) {
	SCL = 1;
	SDA = 1;		//While SCL is 1, SDA transition from 1 to 0
	SDA = 0; 		
}

void i2cStop(void) {
	SCL = 0;
	SDA = 0;
	SCL = 1;		//While SCL is high SDA transition from LOW to HIGH
	SDA = 1;
}

void i2cWrite(u8 d) {
	s8 i;
	for(i=7;i>=0;i--) {
		SCL = 0;
		SDA = d&(1<<i);
		SCL = 1;
	}
}

u8 i2cRead(void) {
	s8 i;
	u8 temp = 0;
	for(i=7;i>=0;i--) {
		SCL = 1;
		if(SDA == 1) 
			temp |= (1<<i);
		SCL = 0;
	}
	return temp;
}

bit i2cAck(void) {
	SCL = 0;
	SDA = 1;
	SCL = 1;
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	if(SDA==0){
		SCL = 0;
		return 0; // if ACK
	}
	else {
		SCL = 0;
		return 1;
	}
}

void i2cNoAck(void) {
	SCL = 0;
	SDA = 1;
	SCL = 1;
}