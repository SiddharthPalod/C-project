#include<stdio.h>			//shiven contribution
#include<stdlib.h>
#include<string.h>

struct user				//a struct to hold the information about user 
{
        char username[100];
        char password[100];
	char number[20];
	char email[100];
};


int usrdelete()			//function to delete a user 
{
        struct user* a[100];		//an array of struct user
        int n,num;			//n is a variable to hold number of records ,num is a variable to hold the index of input username
        char* username_input;
        char* password;
        FILE * r;			//file pointers to databaseuser and user_list
        FILE * r1;
        r=fopen("user_list","r");
        fscanf(r,"%d",&n);
        for(int i=0;i<n;i++)
        {
                a[i]=(struct user *)malloc(sizeof(struct user));
                fscanf(r,"%s %s %s %s",(*a[i]).username,(*a[i]).password,(*a[i]).number,(*a[i]).email);		//reading input for user 
        }
        fclose(r);
	usernamelabel:
        while(1)
        {
                int count=0;				//variable to count number of occurences of username_input in array of struct user
                username_input=(char*)malloc(100*sizeof(char));
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
		else
		{
			printf("USERNAME NOT FOUND!\n \nRETRY GIVING USERNAME INPUT\n\n");
		}
        }
        printf("ENTER YOUR PASSWORD\n");
        while(1)
        {
		num=0;
		password=(char*)malloc(100*sizeof(char));
                scanf("%s",password);			
		for(int i=0;i<n;i++)
                {
                        if (strcmp(a[i]->username,username_input)==0)			//finiding index of first occurence of username_input
                        {
                                num=i;
				break;
                        }
                }
		if (strcmp(a[num]->password,password)!=0)				//checking if password is correct
		{
			printf("INCORRECT PASSWORD OR USERNAME KINDLY TRY AGAIN\n");
			goto usernamelabel;
		}
		else
		{
			break;
		}  
        }
	r=fopen("user_list","w");
	r1=fopen("databaseuser","w");
	fprintf(r,"%d\n",(n-1));
	for (int i=0;i<n;i++)
	{
		if (strcmp((*a[i]).username,username_input) != 0)
		{
			fprintf(r,"%s %s %s %s\n",(*a[i]).username,(*a[i]).password,(*a[i]).number,(*a[i]).email);		//deleting element(by not adding it again)in list 
			fprintf(r1,"%s \n",a[i]->username);
		}
	}
	fclose(r);
	fclose(r1);
	printf("YOU HAVE SUCCESSFULLY DELETED ACCOUNT!\n");
	printf("%s\n",username_input);
        exit(0);			//exiting program
	
}
