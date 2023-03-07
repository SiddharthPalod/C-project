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


int main()
{
	struct user* a[100];
	int n;
	char* new_username;
	char* password;
	char* ph_no;
	char* email;
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
	printf("ENTER YOUR USERNAME\n");
	while(1)
	{
		int count=0;
		new_username=(char*)malloc(100*sizeof(char));
		scanf("%s",new_username); 
		for(int i=0;i<n;i++)
		{
			if (strcmp(a[i]->username,new_username)==0)
			{
				printf("ENTER ANOTHER USERNAME THIS USERNAME IS ALREADY TAKEN\n");
				count++;
			}
		}
		if (count==0)
		{
			break;
		}
	}
	printf("ENTER THE NEW PASSWORD[BETWEEN 6 TO 20 CHARACTERS]\n");
	while(1)
	{
		password=(char*)malloc(100*sizeof(char));
		scanf("%s",password);
		if (strlen(password)<6)
		{
			printf("PASSWORD TOO SHORT,ENTER A LONGER PASSWORD\n");
		}
		else if(strlen(password)>20)
		{
			printf("PASSWORD TOO LONG ,ENTER A SHORTER PASSWORD\n");
		}
		else
		{
			break;
		}
	}
	printf("ENTER YOUR PHONE NUMBER\n");
	while(1)
	{
		ph_no=(char*)malloc(20*sizeof(char));
		scanf("%s",ph_no);
		if(strlen(ph_no) != 10)
		{
			printf("INVALID PHONE NUMBER ,REENTER PHONE NUMBER\n");
			continue;
		}
		int count=0;
                for(int i=0;i<n;i++)
                {
                        if (strcmp(a[i]->number,ph_no)==0)
                        {
                                printf("ENTER ANOTHER PHONE NUMBER THIS PHONE NUMBER IS ALREADY TAKEN\n");
                                count++;
                        }
                }
		if(count==0)
		{
			break;
		}
	}
	printf("ENTER YOUR EMAIL ID\n");
	while(1)
	{
		email=(char *)malloc(100*sizeof(char));
		scanf("%s",email);
		int count=0;
                for(int i=0;i<n;i++)
                {
                        if (strcmp(a[i]->email,email)==0)
                        {
                                printf("ENTER ANOTHER EMAIL THIS EMAIL IS ALREADY TAKEN\n");
                                count++;
                        }
                }
		if(count==0)
		{
			break;
		}
	}
	a[n]=(struct user*)malloc(sizeof(struct user));
	strcpy(a[n]->username,new_username);
	strcpy(a[n]->password,password);
	strcpy(a[n]->number,ph_no);
	strcpy(a[n]->email,email);
	n++;
	r=fopen("user_list","w");
	r1=fopen("databaseuser","w");
	fprintf(r,"%d\n",n);
	for(int i=0;i<n;i++)
	{
		fprintf(r1,"%s\n",a[i]->username);
		fprintf(r,"%s %s %s %s\n",a[i]->username,a[i]->password,a[i]->number,a[i]->email);
	}
	fclose(r);
	fclose(r1);
	printf("CONGRATS! YOU HAVE SUCCESSFULLY REGISTERED.\n");
}
