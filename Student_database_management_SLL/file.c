#include"header.h"

void save_csv_from_scratch(struct student * head) {
    struct student * temp = head;
    if(temp == NULL) {
        printf("\nNo records found\n");
        return;
    }
    FILE * fp = fopen("student.csv", "w");
    fprintf(fp, "id,name,physics,chemistry,maths,total\n");
    while (temp != NULL) {
        fprintf(fp, "%d , %s , %d , %d , %d , %d\n", temp->id, temp->name, temp->physics, temp->chemistry, temp->maths, temp->total);
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
        fprintf(fp, "%d , %s , %d , %d , %d , %d\n", temp->id, temp->name, temp->physics, temp->chemistry, temp->maths, temp->total);
        temp = temp->next;
    }
    fclose(fp);
}


void load_csv(struct student ** head) {
    FILE * fp = fopen("student.csv", "r");
    if (fp == NULL) {
        printf("\nFile not found\n");
        return;
    }
    char bufftemp[38];
    fgets(bufftemp, 38, fp);
    struct student * new_node = (struct student *)malloc(sizeof(struct student));
    struct student * temp=NULL;
    while (fscanf(fp, "%d , %s , %d , %d , %d , %d\n", &new_node->id, new_node->name, &new_node->physics, &new_node->chemistry, &new_node->maths, &new_node->total) != EOF) {
    new_node->next = NULL;
        if (*head == NULL) {
            *head = new_node;
            temp = new_node;
        } else {
            temp->next = new_node;
            temp = new_node;
        }
        new_node = (struct student *)malloc(sizeof(struct student));  
    }
    fclose(fp);
}


/*
fprintf(fp, "%d , %[^\n] , %d , %d , %d , %d\n", temp->id, temp->name, temp->physics, temp->chemistry, temp->maths, temp->total);
        temp = temp->next;
        */