#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
void main() 
{
	int hour,min,sec;
	

	
	printf("Enter the a time in format of HH:MM::SS\n");
	scanf("%d%d",&hour,&min);
	system("clear");
	while(1) 
	{
		for(;min<60;min++) 
		{
			for(sec=0;sec<60;sec++) 
			{
				printf("%d : %d : %d ",hour,min,sec);
				if(hour<12) {
					printf("AM \n");
				}
				else { 
					printf("PM \n");
				}
				sleep(1);
				system("clear");
			}
		}
		min = 0;
		hour++;
		if(hour>12) hour = 1;
	}


}
