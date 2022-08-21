#include "header.h"

void main() {
    int choice;
    TRY_AGAIN:
    system("clear");
    printf("\n\t\tWelcome to the Student Database\n");
    printf("\t\t================================\n");
    printf("\n\n");
    printf("\t\tSign in as:\n");
    printf("\t\t1. Admin\n");
    printf("\t\t2. Student\n");
    printf("\t\t3. Exit\n");
    printf("\n\t\tEnter your choice: ");
    scanf("%d", &choice);
    if(choice < 1 || choice > 3) {
        printf("\n\n\t\tInvalid choice.\n");
        goto TRY_AGAIN;
    }
    switch(choice) {
        case 1:
            admin_menu();
            break;
        case 2:
            student_menu();
            break;
        case 3:
            exit(0);
            break;
    }
}