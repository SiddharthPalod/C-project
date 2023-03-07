#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"all.h"
#include"datatypes.c"

/*struct restaurant1
{
        char username[100];
        char password[100];
};*/


char * f2()				//defining a function f2 which is used to check for login
{
        struct restaurant1* a[100];		//a struct containing an array of restauarants
        int n,num;				//n is an integer to hold the number of values in file,num is an integer to hold index of username in  array
        char* username_input;
        char* password;
        FILE * r;
        FILE * r1;
        r=fopen("restaurant_list","r");
        fscanf(r,"%d",&n);
        for(int i=0;i<n;i++)
        {
                a[i]=(struct restaurant1 *)malloc(sizeof(struct restaurant1));		//copying file contents into an array
                fscanf(r,"%s %s",(*a[i]).username,(*a[i]).password);
        }
        fclose(r);
	usernamelabel:
        while(1)
        {
                int count=0;						//variable to count number of occurences of given input
                username_input=(char*)malloc(100*sizeof(char));			//username to be checked if exists
        	printf("ENTER YOUR USERNAME\n");
                scanf("%s",username_input);
                for(int i=0;i<n;i++)
                {
                        if (strcmp(a[i]->username,username_input)==0)
                        {
                                count++;
                        }
                }
                if (count>0)
                {
                        break;
                }
		else			//condition if username not found
		{
			printf("USERNAME NOT FOUND!\n \nWOULD YOU LIKE TO RETRY GIVING USERNAME INPUT?\n\n(PRESS 1 FOR GOING TO SIGNUP PAGE)\n\nPRESS ANY OTHER NUMBER FOR RETRYING INPUT USERNAME\n\n");
			int x;
			scanf("%d",&x);
			if(x==1)
			{
				system("gcc restaurant_signup.c");
				system("./a.out");
			}
		}
        }
        printf("ENTER YOUR PASSWORD\n");
        while(1)
        {
		num=0;
		password=(char*)malloc(100*sizeof(char));
                scanf("%s",password);				//passwordgiven by user on login page
		for(int i=0;i<n;i++)
                {
                        if (strcmp(a[i]->username,username_input)==0)
                        {
                                num=i;				//storing value of index at which we find username mathchin username input
				break;
                        }
                }
		if (strcmp(a[num]->password,password)!=0)		//if pasword does not match
		{
			printf("INCORRECT PASSWORD OR USERNAME KINDLY TRY AGAIN\n");
			goto usernamelabel;
		}
		else
		{
			break;
		}  
        }
	system("/usr/bin/clear"); 

	printf("YOU HAVE SUCCESSFULLY LOGGED IN!\n");		//user logged in 
        // Build a command string with the arguments
        char command[256];
        snprintf(command, 256, "./a.out %s", username_input);
        // Run the command
	system("gcc MenuOwner.c -lm");			//going to next program
        system(command);
	return username_input;
}