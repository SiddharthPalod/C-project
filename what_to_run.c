#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	printf("ENTER 1 IF YOU OWN A RESTAURANT\n");
	printf("ENTER ANY OTHER NUMBER IF YOU ARE A CUSTOMER\n");
	int n;
	scanf("%d",&n);
	if (n==1)
	{
		int k;
		printf("IF YOU ALREADY HAVE AN ACCOUNT PRESS 1\n");
		printf("IF YOU WISH TO SIGN UP PRESS ANY OTHER NUMBER\n");
		scanf("%d",&k);
		if (k==1)
		{
			system("gcc restaurant_login.c");
			system("./a.out");
		}
		else 
		{
			system("gcc restaurant_signup.c");
			system("./a.out");
		}
		}
	else
	{
		int k;
		printf("IF YOU ALREADY HAVE AN ACCOUNT PRESS 1\n");
		printf("IF YOU WISH TO SIGN UP PRESS ANY OTHER NUMBER\n");
		scanf("%d",&k);
		if (k==1)
		{
			system("gcc user_login.c");
			system("./a.out");
		}
		else
		{
			system("gcc user_signup.c");
			system("./a.out");
		}
		
	}
}
