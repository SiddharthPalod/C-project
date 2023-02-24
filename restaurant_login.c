#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct restaurant
{
        char username[100];
        char password[100];
};


int main()
{
        struct restaurant* a[100];
        int n,num;
        char* username_input;
        char* password;
        FILE * r;
        FILE * r1;
        r=fopen("restaurant_list","r");
        fscanf(r,"%d",&n);
        for(int i=0;i<n;i++)
        {
                a[i]=(struct restaurant *)malloc(sizeof(struct restaurant));
                fscanf(r,"%s %s",(*a[i]).username,(*a[i]).password);
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
        // Build a command string with the arguments
        char command[256];
        snprintf(command, 256, "./a.out %s", username_input);
        // Run the command
	system("gcc MenuOwner.c");
        system(command);

}
