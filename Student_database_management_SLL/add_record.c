#include"header.h"


void add_student_begin(struct student ** head) {
    struct student * new_node = (struct student *)malloc(sizeof(struct student));
    printf("Enter student id: ");
    scanf("%d", &new_node->id);
    printf("Enter student name: ");
    scanf(" %[^\n]", new_node->name);
    printf("Enter student physics marks: ");
    scanf("%d", &new_node->physics);
    printf("Enter student chemistry marks: ");
    scanf("%d", &new_node->chemistry);
    printf("Enter student maths marks: ");
    scanf("%d", &new_node->maths);
    new_node->total = new_node->physics + new_node->chemistry + new_node->maths;
    new_node->next = *head;
    *head = new_node;
}



void add_student_middle(struct student ** head) {
    struct student * new_node = (struct student *)malloc(sizeof(struct student));
    printf("Enter student id: ");
    scanf("%d", &new_node->id);
    printf("Enter student name: ");
    scanf(" %[^\n]", new_node->name);
    printf("Enter student physics marks: ");
    scanf("%d", &new_node->physics);
    printf("Enter student chemistry marks: ");
    scanf("%d", &new_node->chemistry);
    printf("Enter student maths marks: ");
    scanf("%d", &new_node->maths);
    new_node->total = new_node->physics + new_node->chemistry + new_node->maths;
    new_node->next = *head;
    while(new_node->id > (*head)->id) {
        *head = (*head)->next;
    }
    new_node->next = (*head)->next;
    (*head)->next = new_node;
}

void add_student_end(struct student ** head) {
    struct student * new_node = (struct student *)malloc(sizeof(struct student));
    printf("Enter student id: ");
    scanf("%d", &new_node->id);
    printf("Enter student name: ");
    scanf(" %[^\n]", new_node->name);
    printf("Enter student physics marks: ");
    scanf("%d", &new_node->physics);
    printf("Enter student chemistry marks: ");
    scanf("%d", &new_node->chemistry);
    printf("Enter student maths marks: ");
    scanf("%d", &new_node->maths);
    new_node->total = new_node->physics + new_node->chemistry + new_node->maths;
    new_node->next = NULL;
    struct student * temp = *head;
    if (temp == NULL) {
        *head = new_node;
    } else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

/*


if(*head==NULL) {
            *head = new_node;
        }
        else {
            temp = *head;
            while(temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = new_node;
        }
        new_node = (struct student *)malloc(sizeof(struct student));      
    */