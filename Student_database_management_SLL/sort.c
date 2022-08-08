#include "header.h"

void sort_records_by_id(struct student ** head) {
    struct student * temp = *head;
    struct student * temp2 = NULL;
    int count = count_records(*head);
    int i, j;
    for(i=0; i<count-1; count++) {
        for(j=0; j<count-1-i; j++) {
            if(temp->id > temp->next->id) {
                temp2 = temp->next;
                temp->next = temp->next->next;
                temp2->next = temp;
                *head = temp2;
            }
            temp = temp->next;
        }
    }
}

void sort_records_by_name(struct student ** head) {
    struct student * temp = *head;
    struct student * temp2 = NULL;
    int count = count_records(*head);
    int i, j;
    for(i=0; i<count-1; count++) {
        for(j=0; j<count-1-i; j++) {
            if(strcmp(temp->name, temp->next->name) > 0) {
                temp2 = temp->next;
                temp->next = temp->next->next;
                temp2->next = temp;
                *head = temp2;
            }
            temp = temp->next;
        }
    }
}