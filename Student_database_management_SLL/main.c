#include"header.h"

void main() {
    struct student * head = NULL;
    int choice;
    while (1) {
        printf("\n1. Add student at beginning\n");
        printf("2. Add student at end\n");
        printf("3. Display all records\n");
        printf("4. Add student at middle\n");
        printf("5. Save records to csv file\n");
        printf("6. Append records to csv file\n");
        printf("7. Load records from csv file\n");
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
                display_record(head);
                break;
            case 4:
                add_student_middle(&head);
                break;
            case 5:
                save_csv_from_scratch(head);
                break;
            case 6:
                append_csv(head);
                break;
            case 7:
                load_csv(&head);
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