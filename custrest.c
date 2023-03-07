//Aaditya Gole IMT2022087


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main() 
{
    char ch;
    printf("Welcome to sasta swiggy/zomato\n");
    
    start:  
        printf("Enter r for resto owner \n Enter c for customer\n e to exit\n");
        scanf("%c", &ch);

    if(ch=='e')
    {
        exit(0);
    
    }
    else if (ch=='r')
    {
        //resto owner stuff
        printf("change inventory");
    }
    else if (ch=='c')
    {
        printf("menu: \n");
        // go to menu
    }
    else
    {
        printf("Please enter valid option\n");
        goto start;
    }
}