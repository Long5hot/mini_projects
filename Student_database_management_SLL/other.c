#include"header.h"

int count_records(struct student * head) {
    int count = 0;
    while(head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

int search_record_by_id(struct student * head, int id) {
    while(head != NULL) {
        if(head->id == id) {
            return true;
        }
        head = head->next;
    }
    return false;
}

int search_record_by_name(struct student * head, char * name) {
    while(head != NULL) {
        if(strcmp(head->name, name) == 0) {
            return true;
        }
        head = head->next;
    }
    return false;
}