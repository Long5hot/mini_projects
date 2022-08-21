#include "header.h"


int admin_login() {
    int option, userFound=false;
    ADMIN user_a = {0};
    char password[MAX_PASSWORD_LENGTH] = {};
    FILE * fp;
    char adminFilename[25] = "adminInfos/admin.txt";
    system("clear");
    while(true) {
        printf("\n\t\tAdmin authentication menu\n");
        printf("\t\t=========================\n");
        printf("\n\n");
        printf("\n\t\tPlease choose your operation..\n");
        printf("\t\t1.SignUp\n");
        printf("\t\t2.Login\n");
        printf("\t\t3.Exit\n");
        printf("\n\t\tEnter your choice..  :   ");
        scanf("%d", &option);
        fgetc(stdin);
        switch (option) {
            case 1:
                system("clear");
                printf("\n\n\t\t\tSignUp\n");
                printf("\t\t=========================\n");
                printf("\t\tEnter your full name :\t");
                takeInput(user_a.fullname);
                printf("\t\tEnter your email :\t");
                takeInput(user_a.email);
                printf("\t\tEnter your contact no :\t");
                takeInput(user_a.phone);
                printf("\t\tEnter your password :\t");
                takeInput(user_a.password);
                printf("\t\tConfirm your password :\t");
                takeInput(password);
                
                if (!strcmp(user_a.password, password))
                {
                    generateUsername(user_a.email, user_a.username);
                    fp = fopen(adminFilename, "a+");
                    fwrite(&user_a, sizeof(ADMIN), 1, fp);
                    fprintf(fp, "\n");
                    if (fwrite != 0)
                    {
                        printf("\n\t\tUser regestration success..\n");
                        printf("\t\tYour Username : %s\n", user_a.username);
                        printf("\t\tYour Password : %s\n", user_a.password);
                        sleep(5);
                        fclose(fp);
                        continue;
                    }
                    else
                    {
                        printf("\n\t\tSomething went wrong..\n");
                        sleep(5);
                        fclose(fp);
                        continue;
                    }
                }
                else
                    printf("\n\t\tPassword Not Matched\n");

                fclose(fp);
                break;
        
            case 2:
                char username[MAX_USERNAME_LENGTH] = {}, pword[MAX_PASSWORD_LENGTH] = {0};
                ADMIN user_b = {0};
                system("clear");
                printf("\n\n\t\tEnter your username :\t");
                takeInput(username);
                printf("\t\tEnter password :\t");
                takeInput(pword);
                fp = fopen(adminFilename, "r");
                while (fread(&user_b, sizeof(ADMIN), 1, fp))
                {
                    if (!strcmp(user_b.username, username))
                    {
                        if (!strcmp(user_b.password, pword))
                        {
                            fclose(fp);
                            return true;
                        }
                        else {
                            printf("\n\t\tInvalid Password!\n");
                            sleep(2);
                        }
                    }
                }
                if (!userFound) {
                    printf("\n\n\t\tUser is not registered..\n");
                }
                fclose(fp);
                break;
            case 3: {
                system("clear");
                exit(0);
                break;
            }
            default:
                printf("Wrong Option..\n");
                break;
            }
        }
}


void takeInput(char * ch) {
	//scanf(" %[^\n]",ch);
	fgets(ch,50,stdin);
	ch[strlen(ch)-1] = '\0';
}

void generateUsername(char *email, char *username) {
	//something123@gmail.com
    for(int i=0; i<strlen(email);i++) {
		if(email[i]=='@') {
            username[i] = '\0';
            break;
        }
  		else
			username[i] =email[i];
	}
}