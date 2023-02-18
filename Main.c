#include <stdio.h>
#include<stdlib.h>
#include <string.h>

struct current_user{
        char name[20];
        char contact_no[20];
        int id;
};

int main(int argc, char* argv[]){
        char command[20];
                struct current_user cu1;
        if (strcmp(argv[1],"customer") == 0) {
                printf("Welcome customer, type help to see what u can do.\n, U can also type commands if u already know how to work!\n");
                printf(">");
                scanf("%s", command);
                if (strcmp(command, "help") == 0){
                        printf("Whatever stuff\n");
                                }
                else if(strcmp(command, "login") == 0){
                        system("/usr/bin/clear");
                        printf("Name: ");
                        scanf("%s", cu1.name);
                }

        }
        else if (strcmp(argv[1], "owner") == 0){
                printf("Welcome , type help to see what u can do.\n, U can also type commands if u already know how to work!\n");
                if (strcmp(command ,"help") == 0){
                        printf("Whatever stuff\n");
                }
        }

        else {
                printf("Please run code with command './a.out customer' or './a.out owner'");
                exit(0);
        }

        return 0;
}

