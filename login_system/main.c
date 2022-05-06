#include"header.h"

int main(int argc, char const *argv[])
{
    int option, userFound;
    USER user_a;
    char password[50];
    FILE *fp;

    printf("\n---Welcome to Authentication System-----");

    while (TRUE)
    {   
        printf("\n***-------------------------------****");
        printf("\nPlease choose your operation..\n");
        printf("1.SignUp\n");
        printf("2.Login\n");
        printf("3.Exit\n");
        printf("\nEnter your choice..\n");
        scanf("%d", &option);
        fgetc(stdin);

        switch (option)
        {
        case 1:
            printf("Enter your full name :\t");
            takeInput(user_a.fullname);
            printf("Enter your email :\t");
            takeInput(user_a.email);
            printf("Enter your contact no :\t");
            takeInput(user_a.phone);
            printf("Enter your password :\t");
            takeInput(user_a.password);
            printf("Confirm your password :\t");
            takeInput(password);
                
            if (!strcmp(user_a.password, password))
            {
                generateUsername(user_a.email, user_a.username);
                fp = fopen("User_database.txt", "a+");
                fwrite(&user_a, sizeof(USER), 1, fp);
                if (fwrite != 0)
                {
                    printf("\nUser regestration success..\n");
                    printf("Your Username : %s\n", user_a.username);
                }
                else
                {
                    printf("Something went wrong..\n");
                }
            }
            else
                printf("Password Not Matched\n");

            fclose(fp);
            break;
        case 2:
            char username[50], pword[50];
            USER user_b;

            printf("Enter your username :\t");
            takeInput(username);
            printf("Enter password :\t");
            takeInput(pword);
            fp = fopen("User_database.txt", "r");
            while (fread(&user_b, sizeof(USER), 1, fp))
            {
                if (!strcmp(user_b.username, username))
                {
                    if (!strcmp(user_b.password, pword))
                    {
                        system("clear");
                        printf("\n\t\t\tWelcome %s\n", user_b.fullname);
                        printf("\n\t\t\t|Full name : %s\n", user_b.fullname);
                        printf("\n\t\t\t|Email : %s\n", user_b.email);
                        printf("\n\t\t\t|Username : %s\n", user_b.username);
                        printf("\n\t\t\t|contact no : %s\n", user_b.phone);
                    }
                    else
                    {
                        printf("\n\nInvalid Password!\n");
                    }
                    userFound = 1;
                }
            }
            if (!userFound)
            {
                printf("\n\nUser is not registered..\n");
            }
            fclose(fp);
            return 0;

        case 3:
            printf("See yaaa..\n");
            return 0;

        default:
            printf("Wrong Option..\n");
            break;
        }
    }

    return 0;
}
