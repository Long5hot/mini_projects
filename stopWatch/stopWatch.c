/*StopWatch driver.c*/
#include "header.h"

void setTime(void) {
	hour=0;
	min =0;
	sec =0;
	
	//Set hour in hour variable
	lcdCmd(0x01);
	lcdCmd(0x80);
	lcdString("Set hour");
	do{
		lcdCmd(0xC0);
		lcdData((hour/10)+48);
		lcdData((hour%(10))+48);
		while((nextSetting!=0)&&(increase!=0));
		hour++;
		while(increase==0);
	}while(nextSetting!=0) ;
	hour--;
	while(nextSetting==0); //Waiting for Switch release
	
	//Set minute in Minute Variable
	lcdCmd(0x01);
	lcdCmd(0x80);
	lcdString("Set Minute");
	do{
		lcdCmd(0xC0);
		lcdData((min/10)+48);
		lcdData((min%10)+48);
		while((nextSetting!=0)&&(increase!=0));
		min++;
		while(increase==0);
	}while(nextSetting!=0) ;
	min--;
	while(nextSetting==0); //Waiting for Switch release
	lcdCmd(0x01);
	
	i2c_byte_write_frame(0xD0,0x2,hour|(1<<5)|(1<<6));
	i2c_byte_write_frame(0xD0,0x1,min);
	i2c_byte_write_frame(0xD0,0x0,sec);
}

void setDate(void) {
	date=1;
	month=1;
	year=1;
	dayofWeak=1;
	
	//Day of the weak
	lcdCmd(0x01);
	lcdCmd(0x80);
	lcdString("Which day is it??");
	do {
		AGAIN:
		lcdCmd(0xC0);
		lcdString(DOW[dayofWeak-1]);
		while((nextSetting!=0)&&(increase!=0));
		dayofWeak++;
		while(increase==0);
		if(dayofWeak>7) {
			dayofWeak=1;
			goto AGAIN;
		}	
	}while(nextSetting!=0);
		dayofWeak--;
	while(nextSetting==0);
	
	//set Date
	lcdCmd(0x01);
	lcdCmd(0x80);
	lcdString("Set Date");
	do {
		lcdCmd(0xC0);
		lcdData((date/10)+48);
		lcdData((date%10)+48);
		while((nextSetting!=0)&&(increase!=0)); //Wait hear if none of the buttons are pressed
		date++;
		while(increase==0); //Wait till unpressed
	} while(nextSetting!=0);
	date--;
	while(nextSetting==0); //Wait till unpressed

	//set month
	lcdCmd(0x01);
	lcdCmd(0x80);
	lcdString("Set Month");
	do {
		lcdCmd(0xC0);
		lcdData((month/10)+48);
		lcdData((month%10)+48);
		while((nextSetting!=0)&&(increase!=0)); //Wait hear if none of the buttons are pressed
		month++;
		while(increase==0); //Wait till unpressed
	} while(nextSetting!=0);
	month--;
	while(nextSetting==0); //Wait till unpressed

	//set year
	lcdCmd(0x01);
	lcdCmd(0x80);
	lcdString("Set Year");
	do {
		lcdCmd(0xC0);
		lcdData((year/10)+48);
		lcdData((year%10)+48);
		while((nextSetting!=0)&&(increase!=0)); //Wait hear if none of the buttons are pressed
		year++;
		while(increase==0); //Wait till unpressed
	} while(nextSetting!=0);
	year--;
	while(nextSetting==0); //Wait till unpressed
	
	i2c_byte_write_frame(0xD0,0x3,dayofWeak);
	i2c_byte_write_frame(0xD0,0x4,date);
	i2c_byte_write_frame(0xD0,0x5,month);
	i2c_byte_write_frame(0xD0,0x6,year);
	
}