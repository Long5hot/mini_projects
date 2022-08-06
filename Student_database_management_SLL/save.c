#include"header.h"

void save_csv_from_scratch(struct student * head) {
    struct student * temp = head;
    if(temp == NULL) {
        printf("\nNo records found\n");
        return;
    }
    FILE * fp = fopen("student.csv", "w");
    while (temp != NULL) {
        fprintf(fp, "%d,%s,%d,%d,%d,%d\n", temp->id, temp->name, temp->physics, temp->chemistry, temp->maths, temp->total);
        temp = temp->next;
    }
    fclose(fp);
}

void append_csv(struct student * head) {
    struct student * temp = head;
    if(temp == NULL) {
        printf("\nNo records found\n");
        return;
    }
    FILE * fp = fopen("student.csv", "a");
    while (temp != NULL) {
        fprintf(fp, "%d,%s,%d,%d,%d,%d\n", temp->id, temp->name, temp->physics, temp->chemistry, temp->maths, temp->total);
        temp = temp->next;
    }
    fclose(fp);
}
