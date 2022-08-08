#include"header.h"

void main() {
    struct student * head = NULL;
    int choice;
    while (1) {
        printf("\n1. Add student at beginning\n");
        printf("2. Add student at end\n");
        printf("3. Add student at middle\n");
        printf("4. Clear Screen\n");
        printf("5. Display all records in ascending order\n");
        printf("6. Save records to csv file\n");
        printf("7. Append records to csv file\n");
        printf("8. Load records from csv file\n");
        printf("18. Exit\n");
        printf("Enter your choice: ");
        scanf(" %d", &choice);
        switch (choice) {
            case 1:
                add_student_begin(&head);
                break;
            case 2:
                add_student_end(&head);
                break;
            case 3:
                add_student_middle(&head);
                break;
            case 4: 
                system("clear");
                break;
            case 5:
                display_ascending_order(head);
                break;
            case 6:
                save_csv_from_scratch(head);
                break;
            case 7:
                append_csv(head);
                break;
            case 8:
                load_csv(&head);
                break;
            case 9:
                delete_all_records(&head);
                break;
            case 10: 
                delete_record_by_id(&head);
                break;
            case 11:
                sort_csv_file();
                break;
            case 18:
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
}


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
            //break;
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
    
    if((*head) != NULL) {
        printf("\nFile already loaded\n");
        return;
    }
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

void sort_csv_file(void) {
    struct student * my_csv = NULL;
    load_csv(&my_csv);
    sort_records_by_id(&my_csv);
    save_csv_from_scratch(my_csv);
    delete_all_records(&my_csv);
}
