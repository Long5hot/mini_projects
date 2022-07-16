/*External Interrupt Driver*/

#include "header.h"

void enableInt0(void) {
	EA = EX0 =1; //enable externel interupt 
	IT0 = 1; // INT0 edge triggered  
}

void externelInterrupt_Handler(void) interrupt 0 {
	setTime();
	setDate();
}