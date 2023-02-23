#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Menu_generator(char* Menu_Items[], int Prices[], FILE* menu, int no) {
    for (int i = 0; i < no; i++) {
        fprintf(menu, "%s ", Menu_Items[i]);
        fprintf(menu, "$%d\n", Prices[i]);
    }
}

void menu_file_maker(char* name) {
    FILE* abc = fopen(name, "w");
    int n;
    printf("\nEnter no of menu items: ");
    scanf("%d", &n);
    char* Menu_Items[n];
    int Prices[n];
    printf("\nEnter names and prices of menu items as shown");
    for(int i=0; i<n; i++) {
        Menu_Items[i] = malloc(100 * sizeof(char)); // Allocate memory for Menu_Items[i]
        printf("\nMenu Item=\t");
        scanf("%s", Menu_Items[i]);
        printf("Prices=\t");
        scanf("%d", &Prices[i]);
    }
    Menu_generator(Menu_Items, Prices, abc, n);    
    fclose(abc);
}

void menu_file_editor(char* name) {
    int command;
    printf("Press 1 to add items\nPress 2 to delete items\nPress 3 to create new\n");
    scanf("%d",&command);
    if (command == 1) {
        FILE* abc = fopen(name, "a");
        int n;
        printf("\nEnter no of menu items to add: ");
        scanf("%d",&n);
        char* Menu_Items[n];
        int Prices[n];
        printf("\nEnter names and prices of menu items as shown");
        for(int i=0; i<n; i++) {
            Menu_Items[i] = malloc(100 * sizeof(char)); // Allocate memory for Menu_Items[i]
            printf("\nMenu Item=\t");
            scanf("%s", Menu_Items[i]);
            printf("Prices=\t");
            scanf("%d", &Prices[i]);
        }
        Menu_generator(Menu_Items, Prices, abc, n);    
        fclose(abc);
    }
    else if (command == 2) {
        FILE* abc = fopen(name, "r");
        printf("\n\n\n Menu \n");
        char str1[20] = "cat ";
        strcat(str1, name);
        system(str1);
        char word[100];
        while(1){
        printf("\n\n\nEnter the name of menu item to delete: ");
        scanf("%s",word);
        // Create a temporary output file
        FILE *temp_file = fopen("temp.txt", "w");
        if (temp_file == NULL) {
            printf("Could not create temporary file\n");
            return;
        }
        char buffer[1000];
        // Read each line from the input file and write it to the output file
        while (fgets(buffer, sizeof(buffer), abc) != NULL) {
            // If the line does not contain the word, write it to the output file
            if (strstr(buffer, word) == NULL) {
                fputs(buffer, temp_file);
            }
        }
        // Close the input and output files
        fclose(abc);
        fclose(temp_file);
        // Rename the temporary file to the original file
        remove(name);
        rename("temp.txt", name);
        printf("\nTo stop deleting press 1: ");
        int temp;
        scanf("%d",&temp);
        if(temp)
            break;
        }
    }
    else if (command == 3)
        menu_file_maker(name);
    else {
        printf("You pressed the wrong button.\nTo continue press 1, to exit press anything else: ");
        scanf("%d",&command);
        if(command==1) {
            menu_file_editor(name);
        }
        else
            return;
    }
}

void menu_file(char* name) {
    FILE* abc = fopen(name, "a");
    // TODO: Implement menu file editor
    fclose(abc);
}

int main() {
    
    char name[100]; //replace it with the owner name variable given by shiven
    printf("Enter name of menu file: ");
    fgets(name, 100, stdin);
    name[strcspn(name, "\n")] = '\0'; // Remove trailing newline character
    FILE* databaseowner = fopen("databaseowner", "r"); //Name for owner database
    if (databaseowner == NULL) {
        printf("Error opening databaseowner file\n");
        return 1;
    }
    char line[202];
    int file_found = 0;
    int flag=0;
    char c;
    menu_file(name);
    while (fgets(line, sizeof(line), databaseowner) != NULL) {
        if (strstr(line, name) != NULL){
            flag=1;
            FILE* abc = fopen(name, "r");
            char temp[1111];
            c = fgetc(abc);
            if(c==EOF) {
                menu_file_maker(name);
                return 1;
            }
            fseek(abc, -1, SEEK_SET);
            fscanf(abc,"%s",temp);
            int command;
            printf("Do you want to edit the menu?\nPress 1 for Yes otherwise Press anything else to exit: ");
            scanf("%d", &command);
            if (command == 1) {
                menu_file_editor(name);}
            else
                    break;
        fclose(databaseowner);
        }
    }
    
    if (flag)
        return 1;
    else
    {printf("%s was found in the database\n", name); 
    return 1;}
}



