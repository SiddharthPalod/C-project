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
    char fileNames[20][8] = { "R1.txt", "R2.txt", "R3.txt", "R4.txt","R5.txt","R6.txt","R7.txt","R8.txt"."R9.txt","R10.txt","R11.txt", "R12.txt", "R13.txt", "R14.txt","R15.txt","R16.txt","R17.txt","R18.txt"."R19.txt","R20.txt"};
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
