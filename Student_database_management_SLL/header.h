#ifndef __header__
#define __header__

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define true 1
struct student {
    int id;
    char name[20];
    int physics;
    int chemistry;
    int maths;
    int total;
    struct student * next;
};

void add_student_begin(struct student ** head);
void display_record(struct student * head);
void add_student_end(struct student ** head);
void add_student_middle(struct student ** head);
void save_csv_from_scratch(struct student * head);
void append_csv(struct student * head);
void load_csv(struct student ** head);



#endif // __header__