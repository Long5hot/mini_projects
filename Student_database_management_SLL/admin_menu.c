#include"header.h"

//Completed
void admin_menu() {
    int userFound;
    userFound = admin_login();

    if(!userFound) {
        printf("\n\t\tInvalid username or password\n");
        sleep(2);
        system("clear");
        exit(0);
    }
    system("clear");
    STUDENT * head = NULL;
    int choice, count;
    while (1) {
        printf("\n1.  Add record at begining in database\n");
        printf("2.  Add record at end in database\n");
        printf("3.  Add record in middle in database\n");
        printf("4.  Clear Screen\n");
        printf("5.  Display all records by ascending order in database\n");
        printf("6.  Display all records by descending order in database\n");
        printf("7.  Save all records in database to file\n");
        printf("8.  Append all records in database to file\n");
        printf("9.  Load all records in database from file\n");
        printf("10. Count all records in database\n");
        printf("11. Delete all record in database\n");
        printf("12. Delete record by id in database\n");
        printf("13. Delete record by position in database\n");
        printf("14. Sort all records in database by id\n");
        printf("15. Sort all records in database by name\n");
        printf("16. Reverse all records in database\n");
        printf("17. Sort any other csv file in present working directory\n");
        printf("18. Connect 2 CSVs\n");
        printf("19. Exit\n");
        printf("\nEnter your choice:  ");
        
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
                display_reverse_order(head);
                break;
            case 7:
                save_csv_from_scratch(head);
                break;
            case 8:
                append_csv(head);
                break;
            case 9:
                load_csv(&head);
                break;
            case 10:
                count = count_records(head);
                system("clear");
                printf("Total number of records: %d\n", count);
            case 11:
                delete_all_records(&head);
                break;
            case 12:
                delete_record_by_id(&head);
                break;
            case 13:   
                delete_record_by_position(&head);
                break;
            case 14:
                sort_records_by_id(head);
                break;
            case 15:
                sort_records_by_name(head);
                break;
            case 16:
                reverse_data(head);
                break;
            case 17:
                sort_csv_file();
                break;
            case 18:
                connect_csv_files();
                break;
            case 19:
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
}

void connect_csv_files(void) {
    char file1[20], file2[20];
    printf("Enter name of first file: ");
    scanf(" %s", file1);
    printf("Enter name of second file: ");
    scanf(" %s", file2);
    FILE * fp1 = fopen(file1, "a+");
    FILE * fp2 = fopen(file2, "r");
    if (fp1 == NULL || fp2 == NULL) {
        printf("File not found\n");
        return;
    }
    char bufftemp[55];
    fgets(bufftemp, 55, fp2);
    char line[55];
    while (fgets(line, 55, fp2)) {
        fputs(line, fp1);
    }
    fclose(fp1);
    fclose(fp2);

}


void add_student_begin(STUDENT ** head) {
    STUDENT * new_node = (STUDENT *)malloc(sizeof(STUDENT));
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
    printf("Enter student english marks: ");
    scanf("%d", &new_node->english);
    printf("Enter student computer marks: ");
    scanf("%d", &new_node->computer);
    new_node->total = new_node->physics + new_node->chemistry + new_node->maths + new_node->english + new_node->computer;
    new_node->next = *head;
    *head = new_node;
    system("clear");
}



void add_student_middle(STUDENT ** head) {

    int ret;
    STUDENT * new_node = (STUDENT *)malloc(sizeof(STUDENT));
    AGAIN:
        printf("Enter student id: ");
        scanf("%d", &new_node->id);
        ret = search_record_by_id(*head, new_node->id);
    if (ret == true) {
        printf("Student with id %d already exists\n", new_node->id);
        goto AGAIN;
    }
    printf("Enter student name: ");
    scanf(" %[^\n]", new_node->name);
    printf("Enter student physics marks: ");
    scanf("%d", &new_node->physics);
    printf("Enter student chemistry marks: ");
    scanf("%d", &new_node->chemistry);
    printf("Enter student maths marks: ");
    scanf("%d", &new_node->maths);
    printf("Enter student english marks: ");
    scanf("%d", &new_node->english);
    printf("Enter student computer marks: ");
    scanf("%d", &new_node->computer);
    new_node->total = new_node->physics + new_node->chemistry + new_node->maths + new_node->english + new_node->computer;
    new_node->next = *head;
    if(*head==NULL || new_node->id < (*head)->id) {
        new_node->next = *head;
        *head = new_node;
    }
    else {
        STUDENT * temp = *head;
        while(temp->next != NULL && temp->next->id < new_node->id) 
            temp = temp->next;
        
        new_node->next = temp->next;
        temp->next = new_node;
    }
    system("clear");
}

void add_student_end(STUDENT ** head) {
    STUDENT * new_node = (STUDENT *)malloc(sizeof(STUDENT));
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
    printf("Enter student english marks: ");
    scanf("%d", &new_node->english);
    printf("Enter student computer marks: ");
    scanf("%d", &new_node->computer);
    new_node->total = new_node->physics + new_node->chemistry + new_node->maths + new_node->english + new_node->computer;
    new_node->next = NULL;
    STUDENT * last;
    if (*head == NULL) {
        *head = new_node;
    } else {
        last = *head;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = new_node;
    }
    system("clear");
}


void display_ascending_order(STUDENT * head) {
    system("clear");
    STUDENT * temp = head;
    if(temp == NULL) {
        printf("\nNo records found\n");
        return;
    }
    float avg;
    

    printf("\n id        name     physics  chemistry  maths  english  computer  percentage\n\n");
    
    while (temp != NULL) {
        avg = temp->total / 5;
        printf("%3d %13s     %3d       %3d      %3d     %3d       %3d       %.2f\n", temp->id, temp->name, temp->physics, temp->chemistry, temp->maths, temp->english, temp->computer,avg);
        temp = temp->next;
    }
}

void display_reverse_order(STUDENT * head) {
    system("clear");
    if(head == NULL) {
        printf("\nNo records found\n");
        return;
    }
    printf("\n id        name     physics  chemistry  maths  english  computer  percentage\n\n");
    
    STUDENT * temp;
    int i, j;
    float avg;
    

    int count = count_records(head);
    for(i=0; i<count; i++) {
        temp=head;
        for(j=0; j<count-1-i; j++) {
            temp = temp->next;
        }
        avg = temp->total / 5;
        printf("%3d %13s     %3d       %3d      %3d     %3d       %3d       %.2f\n", temp->id, temp->name, temp->physics, temp->chemistry, temp->maths, temp->english, temp->computer,avg);
    }
}

void delete_all_records(STUDENT ** head) {
    if(*head == NULL) {
        printf("\nNo records found\n");
        return;
    }
    STUDENT * temp = *head;
    int count;
    while (*head) {
        *head = (*head)->next;
        free(temp);
        temp = *head;
        count++;
    }
    system("clear");
    printf("\n%d records deleted\n", count);
}

void delete_record_by_id(STUDENT ** head) {
    if(*head == NULL) {
        printf("\nNo records found\n");
        return;
    }
    STUDENT * del = *head, *ptr;
    int id;
    printf("Enter student id to delete: ");
    scanf("%d", &id);
    while (del) {
        if (del->id == id) {
            if(del==*head)
                *head = del->next;
            else {
                ptr->next = del->next;
            }
            free(del);
            break;
        }
        ptr = del;
        del = del->next;
    }
    system("clear");
    printf("\nRecord deleted\n");
}

void delete_record_by_name(STUDENT ** head) {
    if(*head == NULL) {
        printf("\nNo records found\n");
        return;
    }
    STUDENT * del = *head, *last;
    char name[20];
    printf("Enter student name to delete: ");
    scanf(" %[^\n]", name);
    while (del) {
        if (strcmp(del->name, name) == 0) {
            if(del==*head)
                *head = del->next;
            else {
                last->next = del->next;
            }
            free(del);
            break;
        }
        last = del;
        del = del->next;
    }
    system("clear");
    printf("\nRecord deleted\n");
}

void delete_record_by_position(STUDENT ** head) {
    if(*head == NULL) {
        printf("\nNo records found\n");
        return;
    }
    STUDENT * del = *head, *prev;
    int pos,count;
    printf("Enter position to delete: ");
    scanf("%d", &pos);
    count = count_records(*head);
    if(pos>=count && pos<=1) {
        printf("\nInvalid position\n");
        return;
    }
    for(int i=1; i<=count; i++) {
        if(i==pos) {
            if(del==*head)
                *head = del->next;
            else {
                prev->next = del->next;
            }
            free(del);
            break;
        }
        prev = del;
        del = del->next;
    }
    system("clear");
    printf("\nRecord deleted\n");
}

void reverse_data(STUDENT *head) {
    if(head==NULL) {
        printf("\nNo records found\n");
        return;
    }
    int count = count_records(head);
    int i,j;

    STUDENT *ptr1, *ptr2, *temp;

    for(i=0; i<count/2; i++) {
        ptr2 = ptr1;
        for(j=0; j<count-1-i; j++) {
            ptr2 = ptr2->next;
        }
        temp = ptr1;
        ptr1 = ptr2;
        ptr2 = temp;
        ptr1 = ptr1->next;
    }
    system("clear");
}

int count_records(STUDENT * head) {
    int count = 0;
    while(head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

int search_record_by_id(STUDENT * head, int id) {
    if(head==NULL) {
        return 0;
    }
    while(head) {
        if(head->id == id) {
            return 1;
        }
        head = head->next;
    }
    return false;
}

int search_record_by_name(STUDENT * head, char * name) {
    while(head != NULL) {
        if(strcmp(head->name, name) == 0) {
            return true;
        }
        head = head->next;
    }
    return false;
}

void save_csv_from_scratch(STUDENT * head) {
    if(head == NULL) {
        printf("\nNo records found\n");
        return;
    }
    STUDENT * temp = head;
    char temp_file_name[20];
    printf("Enter file name to save: ");
    scanf(" %[^\n]", temp_file_name);
    strcat(temp_file_name, ".csv");
    FILE * fp = fopen(temp_file_name, "w");
    fprintf(fp, "id,name,physics,chemistry,maths,english,computer,total\n");
    while (temp != NULL) {
        fprintf(fp, "%d , %s , %d , %d , %d , %d , %d , %d\n", temp->id, temp->name, temp->physics, temp->chemistry, temp->maths, temp->english, temp->computer, temp->total);
        temp = temp->next;
    }
    fclose(fp);
}

void append_csv(STUDENT * head) {
    if(head == NULL) {
        printf("\nNo records found\n");
        return;
    }
    STUDENT * temp = head;
    char temp_file_name[20];
    printf("Enter file name to save: ");
    scanf(" %[^\n]", temp_file_name);
    strcat(temp_file_name, ".csv");

    FILE * fp = fopen(temp_file_name, "a");
    
    while (temp != NULL) {
        fprintf(fp, "%d , %s , %d , %d , %d , %d , %d , %d\n", temp->id, temp->name, temp->physics, temp->chemistry, temp->maths, temp->english, temp->computer, temp->total);
        temp = temp->next;
    }
    
    fclose(fp);
}
void load_csv(STUDENT ** head) {
    
    if((*head) != NULL) {
        printf("\nFile already loaded\n");
        return;
    }
    char temp_file_name[20];
    printf("Enter file name to save: ");
    scanf(" %[^\n]", temp_file_name);
    strcat(temp_file_name, ".csv");
    FILE * fp = fopen(temp_file_name, "r");
    if (fp == NULL) {
        printf("\nFile not found\n");
        return;
    }
    int count = 0;
    char bufftemp[55];
    fgets(bufftemp, 55, fp);
    STUDENT * new_node;
    STUDENT * last;
    new_node = (STUDENT *)malloc(sizeof(STUDENT));
    while (fscanf(fp, "%d , %s , %d , %d , %d , %d , %d , %d\n", 
        &new_node->id, new_node->name, &new_node->physics, &new_node->chemistry, &new_node->maths, 
        &new_node->english, &new_node->computer,&new_node->total) != EOF) {
        
        new_node->next = NULL;
        if (*head == NULL) 
            *head = new_node;
        else {
            last = *head;
            while (last->next != NULL) {
                last = last->next;
            }
            last->next = new_node;
        }
        new_node = (STUDENT *)malloc(sizeof(STUDENT));
    }
    fclose(fp);
    printf("\nFile loaded\n");
}

void sort_records_by_id(STUDENT * head) {
    if(head == NULL) {
        printf("\nNo records found\n");
        return;
    }
    STUDENT temp;
    STUDENT * ptr1=head, *ptr2=NULL;
    int count = count_records(head);
    int i, j;
    printf("Processing...\n");
    for(i=0; i<count-1; i++) {
        ptr2 = ptr1->next;
        for(j=0; j<count-1-i; j++) {
            if(ptr1->id > ptr2->id) {

                // temp = *ptr1;
                // *ptr1 = *ptr2;
                // *ptr2 = temp;

                temp.id = ptr1->id;
                strcpy(temp.name, ptr1->name);
                temp.physics = ptr1->physics;
                temp.chemistry = ptr1->chemistry;
                temp.maths = ptr1->maths;
                temp.english = ptr1->english;
                temp.computer = ptr1->computer;
                temp.total = ptr1->total;

                ptr1->id = ptr2->id;
                strcpy(ptr1->name, ptr2->name);
                ptr1->physics = ptr2->physics;
                ptr1->chemistry = ptr2->chemistry;
                ptr1->maths = ptr2->maths;
                ptr1->english = ptr2->english;
                ptr1->computer = ptr2->computer;
                ptr1->total = ptr2->total;

                ptr2->id = temp.id;
                strcpy(ptr2->name, temp.name);
                ptr2->physics = temp.physics;
                ptr2->chemistry = temp.chemistry;
                ptr2->maths = temp.maths;
                ptr2->english = temp.english;
                ptr2->computer = temp.computer;
                ptr2->total = temp.total;
            }
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
        printf("%d\n", i);
    }
    printf("\nRecords sorted\n");
}

void sort_records_by_name(STUDENT * head) {
    if(head == NULL) {
        printf("\nNo records found\n");
        return;
    }
    STUDENT * ptr1 = head;
    STUDENT * ptr2 = NULL;
    STUDENT temp;
    int count = count_records(head);
    int i, j;
    for(i=0; i<count-1; count++) {
        ptr2 = ptr1->next;
        for(j=0; j<count-1-i; j++) {
            if(strcmp(ptr1->name, ptr2->name) > 0) {
                temp = *ptr1;
                *ptr1 = *ptr2;
                *ptr2 = temp;    
            }
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}

void sort_csv_file() {  
    char temp_file_name[20];
    printf("Enter file name to save: ");
    scanf(" %[^\n]", temp_file_name);
    strcat(temp_file_name, ".csv");
    FILE * fp = fopen(temp_file_name, "r");
    if (fp == NULL) {
        printf("\nFile not found\n");
        return;
    }

    STUDENT * csv_sort = NULL;

    int count = 0;
    char bufftemp[55];
    fgets(bufftemp, 55, fp);
    STUDENT * new_node;
    STUDENT * last;
    new_node = (STUDENT *)malloc(sizeof(STUDENT));
    while (fscanf(fp, "%d , %s , %d , %d , %d , %d , %d , %d\n", 
        &new_node->id, new_node->name, &new_node->physics, &new_node->chemistry, &new_node->maths, 
        &new_node->english, &new_node->computer,&new_node->total) != EOF) {
        
        new_node->next = NULL;
        if (csv_sort == NULL) 
            csv_sort = new_node;
        else {
            last = csv_sort;
            while (last->next != NULL) {
                last = last->next;
            }
            last->next = new_node;
        }
        new_node = (STUDENT *)malloc(sizeof(STUDENT));
    }
    printf("\nFile loaded\n");
    
    //Sort records by id
    sort_records_by_id(csv_sort);
    
    rewind(fp);

    fprintf(fp, "id,name,physics,chemistry,maths,english,computer,total\n");
    STUDENT *temp = csv_sort;
    while (temp != NULL) {
        fprintf(fp, "%d , %s , %d , %d , %d , %d , %d , %d\n", temp->id, temp->name, temp->physics, temp->chemistry, temp->maths, temp->english, temp->computer, temp->total);
        temp = temp->next;
    }
    fclose(fp);

    delete_all_records(&csv_sort);
}
