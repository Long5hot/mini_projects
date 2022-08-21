#ifndef __header__
#define __header__

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define true 1
#define false 0
#define ENTER 13
#define TAB 9
#define BACKSPACE 8
#define MAX_PASSWORD_LENGTH 20
#define MAX_USERNAME_LENGTH 20
#define MAX_FULLNAME_LENGTH 25
#define MAX_EMAIL_LENGTH 25
#define MAX_PHONE_LENGTH 15

typedef struct student {
    int id;
    char name[20];
    int physics;
    int chemistry;
    int maths;
    int english;
    int computer;
    int total;
    struct student * next;
} STUDENT;

typedef struct user {
    int id;
	char fullname[MAX_FULLNAME_LENGTH];
	char email[MAX_EMAIL_LENGTH];
	char password[MAX_PASSWORD_LENGTH];
	char username[MAX_USERNAME_LENGTH];
	char phone[MAX_PHONE_LENGTH];
} USER;

typedef struct admin {
    char fullname[MAX_FULLNAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    char username[MAX_USERNAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} ADMIN;

// Login system
extern void admin_menu();
extern void student_menu();
extern int admin_login();
void generateUsername(char *email, char *username);
void takeInput(char * ch);

//Add record in database
void add_student_begin(STUDENT ** head);
void add_student_end(STUDENT ** head);
void add_student_middle(STUDENT ** head);

//Display all records in database
void display_ascending_order(STUDENT * head);
void display_reverse_order(STUDENT * head);

//Save all records in database to file
void save_csv_from_scratch(STUDENT * head);
void append_csv(STUDENT * head);
void load_csv(STUDENT ** head);

//Miscellaneous functions
int count_records(STUDENT * head);
int search_record_by_name(STUDENT * head, char * name);
int search_record_by_id(STUDENT * head, int id);

//Delete record from database
void delete_all_records(STUDENT ** head);
void delete_record_by_id(STUDENT ** head);
void delete_record_by_name(STUDENT ** head);
void delete_record_by_position(STUDENT ** head);

//Sort records in database
void sort_records_by_id(STUDENT * head);
void sort_records_by_name(STUDENT * head);
void sort_csv_file(void);

//Connect 2 CSV files
void connect_csv_files(void);

//Reverse records in database
void reverse_data(STUDENT * head);


//User Authentication


#endif // __header__