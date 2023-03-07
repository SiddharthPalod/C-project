#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct user
{
	char username[100];			//struct variable to hold username
	char password[100];			//struct variable to hold password
	char number[20];			//struct variable to hold phone number of user
	char email[100];			//struct variable to hold email of user
};


int main()
{
	struct user* a[100];			//an array to read the values from the file
	int n;					
	char* new_username;			//variables to take inputs for the credentials of new login
	char* password;
	char* ph_no;
	char* email;
	FILE * r;				//file pointers to databaseuser and user_list
	FILE * r1;
	r=fopen("user_list","r");
	fscanf(r,"%d",&n);
	for(int i=0;i<n;i++)
	{
		a[i]=(struct user *)malloc(sizeof(struct user));			//copying data from file to array 
		fscanf(r,"%s %s %s %s",(*a[i]).username,(*a[i]).password,(*a[i]).number,(*a[i]).email);
	}
	fclose(r);
	printf("ENTER YOUR USERNAME\n");
	while(1)
	{
		int count=0;					//variable to keep track of how many times the username occurs
		new_username=(char*)malloc(100*sizeof(char));
		scanf("%s",new_username); 
		for(int i=0;i<n;i++)
		{
			if (strcmp(a[i]->username,new_username)==0)			//check statement to see if username is repeating or not
			{
				printf("ENTER ANOTHER USERNAME THIS USERNAME IS ALREADY TAKEN\n");
				count++;
			}
		}
		if (count==0)				//if it does not repeat break
		{
			break;
		}
	}
	printf("ENTER THE NEW PASSWORD[BETWEEN 6 TO 20 CHARACTERS]\n");
	while(1)
	{
		password=(char*)malloc(100*sizeof(char));
		scanf("%s",password);			//taking input of new password	
		if (strlen(password)<6)			//checkinng if length of password is appropriate	
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
		if(strlen(ph_no) != 10)				//checking if phone number is of appropritate length
		{
			printf("INVALID PHONE NUMBER ,REENTER PHONE NUMBER\n");
			continue;
		}
		int c1=0;
                for(int i=0;i<strlen(ph_no);i++)		//checking for number of characters that are not digits
                {
                        if (ph_no[i]>'9' || ph_no[i]<'0')
                        {
                                c1++;
                        }
                }
                if (c1>0)				//if there is any character that is not a digit
                {
                        printf("INVALID PHONE NUMBER ,REENTER PHONE NUMBER\n");
                        continue;
                }
		int count=0;				//variable to hold number of times the phone number is repeating
                for(int i=0;i<n;i++)
                {
                        if (strcmp(a[i]->number,ph_no)==0)		//checking if phone number already exists
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
		int count=0;					//variable to count number of occurences of email in array
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
	a[n]=(struct user*)malloc(sizeof(struct user));			//putting new user credentials into array
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
		fprintf(r1,"%s\n",a[i]->username);			//putting array elements in array
		fprintf(r,"%s %s %s %s\n",a[i]->username,a[i]->password,a[i]->number,a[i]->email);
	}
	fclose(r);
	fclose(r1);
	printf("CONGRATS! YOU HAVE SUCCESSFULLY REGISTERED.\n");
}
