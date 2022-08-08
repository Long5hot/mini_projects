#include"header.h"


void display_ascending_order(struct student * head) {
    system("clear");
    struct student * temp = head;
    if(temp == NULL) {
        printf("\nNo records found\n");
        return;
    }
    
    printf("\n id             name  physics chemistry maths total\n\n");
    while (temp != NULL) {
        printf("%3d %15s    %3d      %3d      %3d   %3d\n", temp->id, temp->name, temp->physics, temp->chemistry, temp->maths, temp->total);
        temp = temp->next;
    }
}

void display_reverse_order(struct student * head) {
    system("clear");
    struct student * temp = head;
    if(temp == NULL) {
        printf("\nNo records found\n");
        return;
    }
    printf("\n id             name  physics chemistry maths total\n\n");
    int count = count_records(head);
    int i, j;
    for(i=0; i<count-1; count++) {
        for(j=0; j<count-1-i; j++) {
            temp = temp->next;
        }
        printf("%3d %15s    %3d      %3d      %3d   %3d\n", temp->id, temp->name, temp->physics, temp->chemistry, temp->maths, temp->total);
    }
}

