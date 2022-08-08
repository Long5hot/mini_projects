#ifndef __header__
#define __header__

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define true 1
#define false 0
struct student {
    int id;
    char name[20];
    int physics;
    int chemistry;
    int maths;
    //int english;
    //int computer;
    int total;
    struct student * next;
};
//Add record in database
void add_student_begin(struct student ** head);
void add_student_end(struct student ** head);
void add_student_middle(struct student ** head);

//Display all records in database
void display_ascending_order(struct student * head);
void display_reverse_order(struct student * head);

//Save all records in database to file
void save_csv_from_scratch(struct student * head);
void append_csv(struct student * head);
void load_csv(struct student ** head);

//Miscellaneous functions
int count_records(struct student * head);
int search_record_by_name(struct student * head, char * name);
int search_record_by_id(struct student * head, int id);

//Delete record from database
void delete_all_records(struct student ** head);
void delete_record_by_id(struct student ** head);
void delete_record_by_name(struct student ** head);
int delete_record_by_position(struct student ** head);

//Sort records in database
void sort_records_by_id(struct student ** head);
void sort_records_by_name(struct student ** head);
void sort_csv_file(void);

#endif // __header__