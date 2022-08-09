#ifndef __header__
#define __header__

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define true 1
#define false 0
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

//Reverse records in database
void reverse_data(STUDENT * head);

#endif // __header__