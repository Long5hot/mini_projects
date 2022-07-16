/*LCD_Driver*/

#include "header.h"

void lcdData( u8 d) {
	LCD = d;
	RS = 1;
	RW = 0;
	EN = 1;
		delayMs(2);
	EN =0;
}

void lcdCmd( u8 cmd) {
	LCD = cmd;
	RS = 0;
	RW = 0;
	EN =1;
		delayMs(2);
	EN =0;
}	

void lcdInit(void) {
	lcdCmd(0x01);
	lcdCmd(0x02);
	lcdCmd(0x38);
	lcdCmd(0x80);
	lcdCmd(0x0C);// Cursor OFF
}

void lcdString( char * str) {
	while(*str)
		lcdData(*str++);
}