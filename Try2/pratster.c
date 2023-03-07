#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct user
{
        char username[100];
        char password[100];
	char number[20];
	char email[100];
};


int f()
{
        struct user* a[100];
        int n,num;
        char* username_input;
        char* password;
        FILE * r;
        FILE * r1;
        r=fopen("user_list","r");
        fscanf(r,"%d",&n);
        for(int i=0;i<n;i++)
        {
                a[i]=(struct user *)malloc(sizeof(struct user));
                fscanf(r,"%s %s %s %s",(*a[i]).username,(*a[i]).password,(*a[i]).number,(*a[i]).email);
        }
        fclose(r);
	usernamelabel:
        while(1)
        {
                int count=0;
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
			printf("USERNAME NOT FOUND!\n \nWOULD YOU LIKE TO RETRY GIVING USERNAME INPUT?\n\n(PRESS 1 FOR GOING TO SIGNUP PAGE)\n\nPRESS ANY OTHER NUMBER FOR RETRYING INPUT USERNAME\n\n");
			int x;
			scanf("%d",&x);
			if(x==1)
			{
				system("gcc user_signup.c");
				system("./a.out");
				r=fopen("user_list","r");
        			fscanf(r,"%d",&n);
        			for(int i=0;i<n;i++)
        			{
                			a[i]=(struct user *)malloc(sizeof(struct user));
                			fscanf(r,"%s %s %s %s",(*a[i]).username,(*a[i]).password,(*a[i]).number,(*a[i]).email);
        			}
        			fclose(r);
			}
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
                        if (strcmp(a[i]->username,username_input)==0)
                        {
                                num=i;
				break;
                        }
                }
		if (strcmp(a[num]->password,password)!=0)
		{
			printf("INCORRECT PASSWORD OR USERNAME KINDLY TRY AGAIN\n");
			goto usernamelabel;
		}
		else
		{
			break;
		}  
        }
	printf("YOU HAVE SUCCESSFULLY LOGGED IN!\n");
}
