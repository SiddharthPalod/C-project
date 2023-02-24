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
	int n;
	char* new_username;
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
	a[n]=(struct restaurant*)malloc(sizeof(struct restaurant));
	strcpy(a[n]->username,new_username);
	strcpy(a[n]->password,password);
	n++;
	r=fopen("restaurant_list","w");
	r1=fopen("databaseowner","w");
	fprintf(r,"%d\n",n);
	for(int i=0;i<n;i++)
	{
		fprintf(r1,"%s\n",a[i]->username);
		fprintf(r,"%s %s\n",a[i]->username,a[i]->password);
	}
	fclose(r);
	fclose(r1);
	printf("CONGRATS! YOU HAVE SUCCESSFULLY REGISTERED.\n");
	system("gcc MenuOwner.c");
        system("./a.out username_input");
}
