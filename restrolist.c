//Aaditya Gole IMT2022087

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main() 
{
    char c,a;
    FILE* fpt;
    FILE* fpttr;
    char id[16];
	fpt = fopen("restroslist.txt", "r");	// open file+
  
    // Read contents from file
    c = fgetc(fpt);
    while (c != EOF)
    {
        printf ("%c", c);
        c = fgetc(fpt);
    }
  
    fclose(fpt);
    label1:
    printf("Enter the ID of the restaurant whose menu you wish to see : \n");
    scanf("%s", id);
    if(strcmp(id,"e")==0)
    {
        exit(0);
    }
    strcat(id,".txt");
    fpttr = fopen(id, "r");
    if (fpttr == NULL)
    {
        printf("INVALID ID  !!!\nPlease enter correct ID\n");
        goto label1;
    }
  
    // Read contents from file
    a = fgetc(fpttr);
    while (a != EOF)
    {
        printf ("%c", a);
        a = fgetc(fpttr);
    }
    printf("\n");
    goto label1;
    fclose(fpttr);

}