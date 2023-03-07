//Code contributor: Siddharth Palod
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Menu_generator(char* Menu_Items[], int Prices[],FILE* menu, int no) {
    for (int i = 0; i < no; i++) {
        fprintf(menu, "%s ", Menu_Items[i]);
        fprintf(menu, "$%d\n", Prices[i]);
    }
        fputs("~ 1",menu);
        
}

void Menu_generator2(char* Menu_Items[], char* Category[], FILE* gole, char* name, int n) {
    // Make a copy of the Menu_Items array to avoid modifying the string literals
    char* Menu_Items_copy[n];
    for (int i = 0; i < n; i++) {
        Menu_Items_copy[i] = strdup(Menu_Items[i]);
    }

    for (int i = 0; i < n; i++) {
        char* wrd = Menu_Items_copy[i];
        for (int j = 0; j < strlen(wrd); j++) {
            if (wrd[j] == '_') {
                wrd[j] = ' ';
            }
        }
        fprintf(gole, "%s (%s) - %s\n", wrd, Category[i], name);
    }

    // Free the memory allocated for the copy of the Menu_Items array
    for (int i = 0; i < n; i++) {
        free(Menu_Items_copy[i]);
    }
}

void menu_file_maker(char* name) {
    FILE* abc = fopen(name, "w");
    FILE* gole = fopen("menuitems", "a");
    printf("\nEnter no of menu items to add: ");
    int n;
    //scanf("%d", &n);
    n = checkifint("Enter a number");
    while (n > 100) {
        printf("Invalid no of menu items\nplease enter again: ");
        //scanf("%d", &n);
        n = checkifint("Enter a number between 0 to 100");
    }
    char* Menu_Items[n];
    char* Category[n]; //stores user chosen category
    int Prices[n];
    char* category_array[] = {"veg", "non-veg", "beverage", "desert"};
    printf("\nEnter names and prices of menu items as shown");
    for (int i = 0; i < n; i++) {
        Menu_Items[i] = malloc(100 * sizeof(char)); // Allocate memory for Menu_Items[i]
        Category[i] = malloc(100 * sizeof(char)); // Allocate memory for Category[i]
        printf("\nMenu Item= ");
        scanf("%s", Menu_Items[i]);
        printf("Prices= ");
        int k;
        //scanf("%d", &k);
        k = checkifint("Invalid price please enter again:");
        //while (k < 0) {
          //  printf("Invalid price please enter again: ");
            //k = checkifint("Invalid price please enter again:");
            //scanf("%d", &k);
        //}
        Prices[i] = k;

        printf("Choose Category from:\n");
        for (int j = 0; j < 4; j++) //no of categories change value of 4 to the desired no of category 
        {
            printf("%d. %s\t", j + 1, category_array[j]);
        }
        printf("\nEnter choice using number: ");
        k = checkifint("Invalid choice please enter a number in list ");
        //scanf("%d", &k);
        while (k > 4) {
            printf("Invalid choice please enter a number in list ");
            k = checkifint("Invalid choice please enter a number in list ");
            //scanf("%d", &k);
        }
        strcpy(Category[i], category_array[k - 1]);
    }
    Menu_generator(Menu_Items, Prices, abc, n);
    Menu_generator2(Menu_Items, Category, gole, name, n);
    fclose(abc);
    fclose(gole);
}

void menu_file_editor(char* name) {
    int command;
    system("clear");
    printf("------------------------Sasta SWIGGY MENU EDITOR------------------------\n");    
    printf("Restaurant Name: %s\n",name);
    printf("\t\t\tPress 1 to add items\n\t\t\tPress 2 to delete items\n\t\t\tPress 3 to create new\n\t\t\tPress 4 to see menu\n\t\t\tPress anything else to quit\n");
    command = checkifint("Please enter a valid command ")
    //scanf("%d",&command);

//To add items
    if (command == 1) {
        FILE* abc = fopen(name, "r");
        int n;
        //code to delete ~ 1
        char word[]="~ 1";
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

        //Command code:
        FILE* abcd = fopen(name, "a");
        FILE* gole = fopen("menuitems", "a");
        printf("\nEnter no of menu items to add: ");
        a = checkifint("Please enter a valid number ");
        //scanf("%d", &n);
        while (n > 100) {
            printf("Invalid no of menu items\nplease enter again: ");
            a = checkifint("Invalid no of menu items\nplease enter again: ");
            //scanf("%d", &n);
        }
        char* Menu_Items[n];
        char* Category[n]; //stores user choosen category
        int Prices[n];
        char *category_array[] = {"veg", "non-veg", "beverage", "desert"};
        printf("\nEnter names and prices of menu items as shown");
        for (int i = 0; i < n; i++) {
            Menu_Items[i] = malloc(100 * sizeof(char)); // Allocate memory for Menu_Items[i]
            Category[i] = malloc(100 * sizeof(char)); // Allocate memory for Category[i]
            printf("\nMenu Item= ");
            scanf("%s", Menu_Items[i]);
            printf("Prices= ");
            int k;
            k = checkifint("Please enter a valid price:");
            //scanf("%d", &k);
            //while (k < 0) {
              //  printf("Invalid price please enter again: ");
                
                //scanf("%d", &k);
            //}
            Prices[i] = k;
            printf("Choose Category from:\n");
            for (int i = 0; i < 4; i++) //no of categories change value of 4 to the desired no of category 
            {
                printf("%d. %s\t", i+1, category_array[i]);
            }
            printf("\nEnter choice using number: ");
            k = checkifint("Please enter a valid number");
            //scanf("%d", &k);
            while (k > 4) {
                printf("Invalid choice please select a number in list ");
                k = checkifint("Invalid choice please select a number in list ");
                //scanf("%d", &k);
            }
            strcpy(Category[i], category_array[k-1]);
        }
        Menu_generator(Menu_Items, Prices, abcd, n);
        Menu_generator2(Menu_Items, Category, gole, name, n);
        fclose(abcd);
        fclose(gole);
        printf("\n\t\t\t Great Success\n\n");
        menu_file_editor(name);

    }

//To delete items  
    else if (command == 2) {
        while(1){
        FILE* abc = fopen(name, "r");
        FILE* gole= fopen("menuitems","r");
        if (abc == NULL) {
            printf("Could not open %s file\n",name);
            return;
        }
        if (gole == NULL) {
            printf("Could not open menuitems file\n");
            return;
        }
        
        //Menu display remove ~ 1 from it
        printf("\n\n|---Menu---|\n");

        char dw[100];
        while(fgets(dw, 100, abc) != NULL){
            if (strstr(dw,"~") == NULL){
                printf("%s", dw);
            }
            else{
                break;
            }
        }
        rewind(abc);
        //--------Deletion code--------
        char word[100],wrd[100];
        printf("\nEnter the name of menu item to delete: ");
        scanf("%s",word); //word to delete line
        
        // Create a temporary output file
        FILE *temp_file = fopen("temp.txt", "w");
        FILE *temp_file1 = fopen("temp1.txt", "w");

        if (temp_file == NULL) {
            printf("Could not create temporary file\n");
            return;
        }
        if (temp_file1 == NULL) {
            printf("Could not create temporary file\n");
            return;
        }


        char buffer[1000];
        // Read each line from the input file and write it to the output file
        while (fgets(buffer, sizeof(buffer), abc) != NULL) {
            // If the line does not contain the word, write it to the output file
            if (strstr(buffer, word) == 0) {
                fputs(buffer, temp_file);
            }
        }

            strcpy(wrd,word);
            for(int i =0; i<strlen(wrd); i++){
                if (wrd[i]=='_') wrd[i]=' ';
            }

        while (fgets(buffer, sizeof(buffer), gole) != NULL) {
            // If the line does not contain the word, write it to the output file
            if ( ( (strstr(buffer, wrd) != NULL) && (strstr(buffer,name) != NULL) )==0 ) {
                fputs(buffer, temp_file1);
            }
        }

        // Close the input and output files
        fclose(abc);
        fclose(temp_file);
        fclose(gole);
        fclose(temp_file1);
        // Rename the temporary file to the original file
        remove(name);
        remove("menuitems");
        rename("temp.txt", name);
        rename("temp1.txt", "menuitems");

        printf("\n\t\tDeleted\nTo stop further deleting press 1: ");
        int temp;
        temp = checkifint("Enter a valid number: ");
            //scanf("%d",&temp);
        if(temp==1){
            menu_file_editor(name);
            break;  }          
        else {
            continue;
        }
        }
        
    }

//To create a new menu    
    else if (command == 3){
        
        FILE *gole = fopen("menuitems", "r");
        if (gole == NULL) {
            printf("Could not open menuitems file\n");
            return;
        }
        FILE *temp_file = fopen("temp.txt", "w");
        if (temp_file == NULL) {
            printf("Could not create temporary file\n");
            return;
        }

        char buffer[1000];
        while (fgets(buffer, sizeof(buffer), gole) != NULL) {
            // If the line does not contain the word, write it to the output file
            if (strstr(buffer, name) == NULL) {
                fputs(buffer, temp_file);
            }
        }
        fclose(gole);
        fclose(temp_file);
        rename("temp.txt", "menuitems");

        menu_file_maker(name);
        printf("\n\t\t\t Great Success\n\n");

        menu_file_editor(name);}

//To display menu
    else if (command ==4){
        FILE* abc = fopen(name, "r");
        printf("\n|---Menu---|\n");
        char dw[100];
        while(fgets(dw, 100, abc) != NULL){
            if (strstr(dw,"~") == NULL){
                printf("%s", dw);
            }
            else{
                break;
            }
        }
        fclose(abc);
        printf("\n\tPress 1 to return\n\tPress anything else to exit\n");
        command = checkifint("Enter a valid command: ");
        //scanf("%d",&command);
        if(command==1)
            menu_file_editor(name);
        else
            return;
    }

//Any other case
    else {
        printf("\n\n\tAre you sure you want to quit?\n\tIf yes press 1: ");
        command = checkifint("Enter a valid command: ");
        //scanf("%d",&command);
        if(command ==1){
            return;}
        else{
            menu_file_editor(name);}
    }
}

void menu_file(char* name) {
    FILE* abc = fopen(name, "a");
    // TODO: Implement menu file editor
    fclose(abc);
}


int main(int argc,char* argv[]) {
    char name[100];//replace it with the owner name variable given by shiven
    strcpy(name,argv[1]);
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
        if (strstr(line, name) == NULL){
            flag=1;
            FILE* abc = fopen(name, "r");
            char temp[1111];
            c = fgetc(abc);
            ungetc(c, abc);
            if(c==EOF) {
                system("clear");
                printf("------------------------Sasta SWIGGY Create MENU------------------------\n");    
                menu_file_maker(name);
                printf("\n\t\t\tDo you want to open menu editor?\nPress 1 for yes\t\t\t Press anything else to exit\n");
                int command;
                command = checkifint("Enter a valid command: ");
                //scanf("%d",&command);
                if(command==1){
                    menu_file_editor(name);
                    return 1;}
                else{
                    return 1;}
            }
            fseek(abc, -1, SEEK_SET);
            fscanf(abc,"%s",temp);
            int command;
            printf("Do you want to edit the menu?\nPress 1 for Yes otherwise Press anything else to exit: ");
            command = checkifint("Enter a valid command: ");
            //scanf("%d", &command);
            if (command == 1) {
                menu_file_editor(name);
                break;}
            else{
                    break;}
        fclose(databaseowner);
        }
    }
    
    if (flag)
        return 1;
    else
    {printf("%s was found in the database\n", name); 
    return 1;}
}
