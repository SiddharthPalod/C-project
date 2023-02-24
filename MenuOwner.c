//Code contributor: Siddharth Palod
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Initialising all functions
void Menu_generator(char* Menu_Items[], int Prices[],FILE* menu, int no);
void Menu_generator2(char* Menu_Items[],char* Category[],FILE* gole,char* name,int n);
void menu_file_maker(char* name);
void menu_file_editor(char* name);
void menu_file(char* name);

//Main function
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

//FUNCTION DEFINATIONS
void Menu_generator(char* Menu_Items[], int Prices[],FILE* menu, int no) {
    for (int i = 0; i < no; i++) {
        fprintf(menu, "%s ", Menu_Items[i]);
        fprintf(menu, "$%d\n", Prices[i]);
    }
        fputs("~ 1",menu);
        
}

void Menu_generator2(char* Menu_Items[],char* Category[],FILE* gole,char* name,int n){
    for (int i = 0; i < n; i++) {
        char* wrd=Menu_Items[i];
        for(int i =0; i<strlen(wrd); i++){
            if (wrd[i]=='_') wrd[i]=' ';
        }
        for(int i =0; i<strlen(wrd); i++){
            if (wrd[i]=='_') wrd[i]=' ';
        }
        fprintf(gole,"%s (%s) - %s\n", wrd, Category[i],name);
    }
}

void menu_file_maker(char* name) {
    FILE* abc = fopen(name, "w");
    FILE* gole= fopen("menuitems","w");
        printf("\nEnter no of menu items to add: ");
        int n;
        scanf("%d",&n);
        char* Menu_Items[n];
        char* Category[n]; //stores user choosen category
        int Prices[n];
        char *category_array[] = {"veg", "non-veg", "beverage", "desert"};
        printf("\nEnter names and prices of menu items as shown");
        for(int i=0; i<n; i++) {
            Menu_Items[i] = malloc(100 * sizeof(char)); // Allocate memory for Menu_Items[i]
            Category[i] = malloc(100 * sizeof(char)); // Allocate memory for Category[i]
            printf("\nMenu Item= ");
            scanf("%s", Menu_Items[i]);
            printf("Prices= ");
            scanf("%d", &Prices[i]);
            printf("Choose Category from:\n");
            for(int i=0;i<5;i++) //To add n more categories change value of 5 to then 5+n
            {
            printf("%d. %s\t",i+1,category_array[i]);}
            printf("\nEnter choice: ");

            int k;
            scanf("%d", &k);
            strcpy(Category[i],category_array[k-1]);            
        }
        Menu_generator(Menu_Items, Prices, abc, n);
        Menu_generator2(Menu_Items, Category, gole,name, n);  
        fclose(abc);
        fclose(gole);

}

void menu_file_editor(char* name) {
    int command;
    printf("Press 1 to add items\nPress 2 to delete items\nPress 3 to create new\n");
    scanf("%d",&command);
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
        FILE* gole= fopen("menuitems","a");
        printf("\nEnter no of menu items to add: ");
        scanf("%d",&n);
        char* Menu_Items[n];
        char* Category[n]; //stores user choosen category
        int Prices[n];
        char *category_array[] = {"veg", "non-veg", "beverage", "desert"};
        printf("\nEnter names and prices of menu items as shown");
        for(int i=0; i<n; i++) {
            Menu_Items[i] = malloc(100 * sizeof(char)); // Allocate memory for Menu_Items[i]
            Category[i] = malloc(100 * sizeof(char)); // Allocate memory for Category[i]
            printf("\nMenu Item= ");
            scanf("%s", Menu_Items[i]);
            while(1){
                printf("Prices= ");
                int k;
                scanf("%d",&k);
                if(k>=0){
                    k=Prices[i];
                    break;}
                else
                    printf("\nthis is not valid Price please try again\n");
            }
            printf("Choose Category from:\n");
            for(int i=0;i<5;i++) //To add n more categories change value of 5 to then 5+n
            {
            printf("%d. %s\t",i+1,category_array[i]);}
            printf("\nEnter choice: ");

            int k;
            scanf("%d", &k);
            strcpy(Category[i],category_array[k-1]);
        }
        Menu_generator(Menu_Items, Prices, abcd, n);
        Menu_generator2(Menu_Items, Category, gole,name, n);  
        fclose(abcd);
        fclose(gole);
        menu_file_editor(name);
    }
    else if (command == 2) {
        while(1){
        FILE* abc = fopen(name, "r");
        FILE* gole= fopen("menuitems","r");
        //Menu display remove ~ 1 from it
        printf("\n\n Menu \n");
        /*char str1[20] = "cat ";
        strcat(str1, name);
        system(str1);*/
        //use fprintf instead
        char dw[20];
        while(fgets(dw, 100, abc) != NULL){
            if (strstr(dw,"~") == NULL){
                printf("%s", dw);
            }
            else{
                break;
            }
        }

        char word[100];
        printf("\nEnter the name of menu item to delete: ");
        scanf("%s",word); //word to delete line
        // Create a temporary output file
        FILE *temp_file = fopen("temp.txt", "w");
        FILE *temp_file1 = fopen("temp1.txt", "w");

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

        while (fgets(buffer, sizeof(buffer), gole) != NULL) {
            // If the line does not contain the word, write it to the output file
            if (strstr(buffer, word) == NULL) {
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

        printf("\nDeleted: To stop further deleting press 1: ");
        int temp;
        scanf("%d",&temp);
        if(temp==1){
            menu_file_editor(name);
            break;  }          
        else {
            continue;
        }
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


