#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void Menu_generator(char Restaurant_Name[], int Restaurant_Id, char* Menu_Items[], int Prices[], int Stock[], FILE* menu, int n) {
    int no = Restaurant_Id - 100;
    if (no > 10 && no <= 20) {
        fprintf(menu, "Restaurant_Name: %s\n", Restaurant_Name);
        fprintf(menu, "Menu_Items:\n");
        for (int i = 0; i < n; i++) {
            fprintf(menu, "%d. ", i);
            fprintf(menu, "%s ", Menu_Items[i]);
            fprintf(menu, "$%d\n", Prices[i]);
        }
        fprintf(menu, "$ 1\n");
        fprintf(menu, "Restaurant_Id: %d\n", Restaurant_Id);
        fprintf(menu, "Stocks:\n");
        for (int i = 0; i < n; i++) {
            fprintf(menu, "%d\n", Stock[i]);
        }
    }
}

int main(int argc, char *argv[]) {
    //to open all files in database and search for a specific string
    //(let us assume 20 restaurants 10 are premade and max 10 can be created)
    char fileNames[20][12] = { "Burger King", "KFC", "McDonalds", "Dominoes", "Pizza Hut", "Juicy", "Onesta", "Chai Point", "Truffles", "Wow Momo", "R11", "R12", "R13", "R14", "R15", "R16", "R17", "R18", "R19", "R20" };
    char searchStr[] = "search_string";
    for (int i = 0; i < 20; i++) {
        FILE *pFile = fopen(fileNames[i], "r");
        
            fclose(pFile);
        }
    }
    return 0;
}
