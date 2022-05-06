#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <unistd.h>
#define ENTER 13
#define TAB 9
#define BACKSPACE 8
#define TRUE 1

typedef struct user {
	char fullname[50];
	char email[50];
	char password[50];
	char username[50];
	char phone[50];
} USER;

void takeInput(char * ch) {
	//scanf(" %[^\n]",ch);
	fgets(ch,50,stdin);
	ch[strlen(ch)-1] = '\0';
}

void generateUsername(char *email, char *username) {
	//something123@gmail.com
	for(int i=0; i<strlen(email);i++) {
		if(email[i]=='@')
			break;
  		else
			username[i] =email[i];
	}
}


/*Only works in Windows With getch function...*/
/*
void takePassword(char pwd[50]) {
	int index;
	char ch;
	while(TRUE) {
		ch = getch();
		if(ch==ENTER || ch==TAB){
			pwd[index] ='\0';
			break;
		}
		else if(ch==BACKSPACE) {
			if(index>0) {
				index--;
				printf("\b \b");  //abc| --> ab | -->ab|
			}
		}
		else {
			pwd[index++] = ch;
			printf("* \b");
		}
	}

}*/