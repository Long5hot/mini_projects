#include "header.h"
void i2c_byte_write_frame(u8 sa, u8 mr, u8 d) 
{
	
	bit r;
	i2cStart();
	
	i2cWrite(sa); //SA + W
	r = i2cAck();
	if(r==1) 
		goto OUT;
	
	i2cWrite(mr);
	r = i2cAck();
	if(r==1)
		goto OUT;
	
	i2cWrite(d);
	r = i2cAck();
	
	OUT:
		i2cStop();
}

u8 i2c_byte_read_frame(u8 sa, u8 mr) {
	
	u8 temp;
	bit r;
	i2cStart();
	
	i2cWrite(sa); //SA + W
	r = i2cAck();
	if(r==1) 
		goto OUT;
	
	i2cWrite(mr);
	r = i2cAck();
	if(r==1)
		goto OUT;
	
	i2cStart(); //restart condn 
	
	i2cWrite(sa|1); // SA + R
	r = i2cAck();
	if(r==1) 
		goto OUT;
	
	temp = i2cRead();
	i2cNoAck();
	
	OUT:
		i2cStop();
	return temp;
	
}