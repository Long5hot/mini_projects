#include"header.h"


void display_record(struct student * head) {
    struct student * temp = head;
    if(temp == NULL) {
        printf("\nNo records found\n");
        return;
    }
    while (temp != NULL) {
        printf("%3d %15s %3d %3d %3d %3d\n", temp->id, temp->name, temp->physics, temp->chemistry, temp->maths, temp->total);
        temp = temp->next;
    }
}

