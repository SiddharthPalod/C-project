#include<stdio.h>
#include<stdlib.h>

void Menu_generator(char Restaurant_Name[],int Restaurant_Id,char* Menu_Items[n],int Prices[n],int Stock[n],FILE* menu){
    no=Restaurant_Id-100
    for(10<no<=20){
//        menu= fopen("R11.txt", "w") (has been put in main function)
        fprintf(menu,"Restaurant_Name: %s\n",Restaurant_Name);
        fprintf(menu,"Menu_Items:\n");
        for(int i=0;i<n;i++){
            fprintf(menu,"%s\n".Menu_Items[i]);
        };
        fprintf(menu,"Restaurant_Id: %d\n",Restaurant_Id);
        fprintf(menu,"Prices:\n");
        for(int i=0;i<n;i++){
            fprintf(menu,"%d\n".Price[i]);
        };
        fprintf(menu,"Stocks:\n");
        for(int i=0;i<n;i++){
            fprintf(menu,"%d\n".Stock[i]);
        };     
        }
}

int main(int argc, char *argv[]){
    //to open all files in database and search for a specific string
    //(let us assume 20 restaurants 10 are premade and max 10 can be created)
    char fileNames[20][8] = { "Burger King", "KFC", "McDonalds", "Dominoes","Pizza Hut","Juicy","Onesta","Chai Point"."Truffles","Wow Momo","R11", "R12", "R13", "R14","R15","R16","R17","R18"."R19","R20"};
    for (int i = 0; i < 20; i++) {
        FILE *pFile = fopen(fileNames[i], "r");
        bool bExists = searchInFile(pFile, searchStr);
        if (bExists) {
            printf("%s contains %s\n", fileNames[i], searchStr);
        }
        fclose(pFile);
    }
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
  }
