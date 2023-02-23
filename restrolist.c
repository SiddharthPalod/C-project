//Aaditya Gole IMT2022087

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main() 
{
    char c,a;
    FILE* fp;
    FILE* fptr;
    char id[16];
	fp = fopen("restroslist.txt", "r");	// open file+
  
    // Read contents from file
    c = fgetc(fp);
    while (c != EOF)
    {
        printf ("%c", c);
        c = fgetc(fp);
    }
  
    fclose(fp);
    label1:
    printf("Enter the ID of the restaurant whose menu you wish to see : \n");
    scanf("%s", id);
    if(strcmp(id,"e")==0)
    {
        exit(0);
    }
    strcat(id,".txt");
    fptr = fopen(id, "r");
    if (fptr == NULL)
    {
        printf("INVALID ID  !!!\nPlease enter correct ID\n");
        goto label1;
    }
  
    // Read contents from file
    a = fgetc(fptr);
    while (a != EOF)
    {
        printf ("%c", a);
        a = fgetc(fptr);
    }
    printf("\n");
    goto label1;
    fclose(fptr);

}