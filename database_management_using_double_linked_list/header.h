#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<ctype.h>

typedef struct Student {
    struct Student *prev;
    int no;
    char name[15];
    float marks;
    struct Student *next;
}DLL;

void read_file(void);
void add_begin(void);
void add_end(void);
void add_middle(void);
void print_records(void);
int count_nodes(void);
void reverse_print_loop(void);
void save_file(void);
void delete_all(void);
void print_recursion(DLL *ptr);
void delete_node();
void delete_pos();
int search_node(int num);
void sort_data();
void reverse_data();
void reverse_links();
void reverse_print_recursion(DLL *ptr);

