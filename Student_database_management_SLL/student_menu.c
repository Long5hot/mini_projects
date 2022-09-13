#include "header.h"

//For student login purpose

void student_menu() {
    int userFound = false;
    USER user_a = {};
    char username[MAX_USERNAME_LENGTH] = {};
    char password[MAX_PASSWORD_LENGTH] = {};
    FILE * fp;
    char userFilename[25] = "userInfos/user.txt";
    system("clear");
    fgetc(stdin);
    printf("\n\t\tStudent authentication \n");
    printf("\t\t=========================\n");
    printf("\n\n");
    printf("\t\tEnter your username :\t");
    takeInput(username);
    printf("\t\tEnter password :\t");
    takeInput(password);
    fp = fopen(userFilename, "r");
    while(fread(&user_a, sizeof(USER), 1, fp)) {
        if (!strcmp(user_a.username, username) && !strcmp(user_a.password, password)) {
            userFound = true;
            break;
        }
    }
    if(userFound) {
        printf("\n\t\tLogin Successful\n");
        sleep(2);
        fclose(fp);
        system("clear");
        fp = fopen("student.csv", "r");
        STUDENT student = {};
        while (fscanf(fp, "%d , %s , %d , %d , %d , %d , %d , %d\n", 
        &student.id, student.name, &student.physics, &student.chemistry, &student.maths, 
        &student.english, &student.computer,&student.total) != EOF) {
                if(strcmp(student.name, user_a.fullname) == 0) {

                    printf("\n\t\tStudent Details\n");
                    printf("\t\t=========================\n");
                    printf("\t\tID : %d\n", student.id);
                    printf("\t\tName : %s\n", student.name);
                    printf("\t\tPhysics : %d\n", student.physics);
                    printf("\t\tChemistry : %d\n", student.chemistry);
                    printf("\t\tMaths : %d\n", student.maths);
                    printf("\t\tEnglish : %d\n", student.english);
                    printf("\t\tComputer : %d\n", student.computer);
                    printf("\t\tTotal : %d\n", student.total);
                    break;
                }
        }
    }
    else {
        printf("\n\t\tInvalid Username or Password\n");
        sleep(2);
        fclose(fp);
        system("clear");
    }
}