#include "header.h"

u8 hour=0,min=0,sec=0,date=1,month=1,year=1,dayofWeak=1;
char DOW[][4] = {"SUN","MON","TUE","WED","THU","FRI","SAT"};

main() {
	bit am_pm=0;
	enableInt0(); //Enable Externel Interrupt 0
	lcdInit();  //Initializing LCD
	setTime();
	setDate();
	//Get the time and printing on lcd
	while(1) {
		hour = i2c_byte_read_frame(0xD0,0x2);
		min  = i2c_byte_read_frame(0xD0,0x1);
		sec  = i2c_byte_read_frame(0xD0,0x0);
		dayofWeak = i2c_byte_read_frame(0xD0,0x3);
		date = i2c_byte_read_frame(0xD0,0x4);
		month = i2c_byte_read_frame(0xD0,0x5);
		year = i2c_byte_read_frame(0xD0,0x6);
		
		if(hour&(1<<6)==1)
			am_pm=1;//PM
		else
			am_pm=0;//AM
		
		lcdCmd(0x80);
		lcdData((date/10)+48);
		lcdData((date%10)+48);
		lcdData('/');
		lcdData((month/10)+48);
		lcdData((month%10)+48);
		lcdData('/');
		lcdData((year/10)+48);
		lcdData((year%10)+48);
		lcdString("    ");
		lcdString(DOW[dayofWeak-1]);
		
		
		lcdCmd(0xC0);
		lcdData((hour/10)+48);
		lcdData((hour%10)+48);
		lcdData(':');
		
		lcdData((min/10)+48);
		lcdData((min%10)+48);
		lcdData(':');
		
		lcdData((sec/10)+48);
		lcdData((sec%10)+48);
	}
	

}