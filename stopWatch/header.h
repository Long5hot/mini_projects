/* Stop watch header file */

#ifndef __Stopwatch__
#define __StopWatch__

#include <reg51.h>
#include <intrins.h>

typedef unsigned int u16;
typedef unsigned char u8;
typedef signed char s8;
typedef signed int s16;

//Defining I2C pins
sbit SDA = P2^3;
sbit SCL = P2^4;


//Defining LCD PINS
sfr LCD = 0x80; //P0
sbit RS = P2^0;
sbit RW = P2^1;
sbit EN = P2^2;

//Defining StopWatch Buttons
sbit increase = P1^0;
sbit nextSetting = P1^1;

extern void delayMs(u16 ms);
extern void i2cStart(void);
extern void i2cStop(void);
extern void i2cWrite(u8 d);
extern u8 i2cRead(void);
extern bit i2cAck(void);
extern void i2cNoAck(void);
extern void i2c_byte_write_frame(u8 sa, u8 mr, u8 d);
extern u8 i2c_byte_read_frame(u8 sa, u8 mr);
extern void lcdString( char * str);
extern void lcdInit(void);
extern void lcdData( u8 d);
extern void lcdCmd( u8 cmd);
extern void setTime(void);
extern void enableInt0(void);
extern u8 hour,min,sec,date,month,year,dayofWeak;
extern char DOW[][4];
extern void setDate(void);

#endif