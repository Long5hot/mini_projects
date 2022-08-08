#include"header.h"

void delete_all_records(struct student ** head) {
    struct student * temp = *head;
    while (temp != NULL) {
        *head = (*head)->next;
        free(temp);
        temp = *head;
    }
}

void delete_record_by_id(struct student ** head) {
    struct student * temp = *head;
    int id;
    printf("Enter student id to delete: ");
    scanf("%d", &id);
    while (temp != NULL) {
        if (temp->id == id) {
            *head = (*head)->next;
            free(temp);
            break;
        }
        temp = temp->next;
    }
}

void delete_record_by_name(struct student ** head) {
    struct student * temp = *head;
    char name[20];
    printf("Enter student name to delete: ");
    scanf(" %[^\n]", name);
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            *head = (*head)->next;
            free(temp);
            break;
        }
        temp = temp->next;
    }
}

