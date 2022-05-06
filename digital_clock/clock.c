#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	int hour,min,sec;
	
	int delay = 1000;

	printf("Set time..:\n");
	scanf("%d%d%d",&hour,&min,&sec);
	if(hour > 12 || min>60 || sec>60) {
		printf("Error..!\n");
		exit(0);
	}

	while(1) {
		
		sec++;
		if(sec>59) {
			min++;
			sec=0;
		}
		if(min>59) {
			hour++;
			min=0;
		}
		if(hour>12) {
			hour=1;
		}
		printf("\nclock : ");
		printf("%2d : %2d : %2d",hour,min,sec);
		sleep(1);
		system("clear");
	
	}

}
