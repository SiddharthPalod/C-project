//Code contributor: Shashwat Chaturvedi
#include <stdio.h>
#include <string.h>
#include <math.h>
#include"all.h"
int checkifint(char str[]);
int check_str(char x[], char str[], int n, int c);
int check_char(char x[], char str[], int n, int a1, int a2);

int checkifint(char str[])	//function to handle user error test cases, displays str for all invalid inputs
{	int c,n;
	int a1,a2;
	char x[20];
	
	

	do	//keeps asking for new input till either of the above functions give false values
	{
		scanf("%s", x);	
	}while(!check_str(x, str, n, c) || !check_char(x, str, n, a1, a2));
	n = check_str(x, str, n, c);
	return n;	//finally returns the integer value entered 
}

	int check_str(char x[], char str[], int n, int c)	//function to return the integer if the user has entered a decimal, str2 is the user input string
	{		//returns 0 if str2 is any string and returns the number if str2 is any number
		do
		{
		n = 0;
    		for(int i = 0; i<strlen(x); i++)
		{
			c = (int)(x[i] - '0');
			if ((int)(x[i]-'0')<10 && (int)(x[i])>=0)
			{
				n = (int)(x[i] - '0')*pow(10,(strlen(x) - 1 - i)) + n;
			}
			else		//prints error message if it is any other string
			{
				printf("%s\n",str);
				return 0;
			}
		}
	return n;
		}while(c>9 || c<0);
	}


	int check_char(char x[], char str[], int n, int a1, int a2)	//function to check if user has entered a negative number or a decimal number, str1 is the user input string 
	{	// returns 0 if str1 is a decimal or a negative number and 1 otherwise
		do{
			a1 = 1;		//these are flags
			a2 = 1;
			if(x[0] == '-')		//checking for negative
			{
				printf("%s\n",str);
				a1 = 0;
				return 0;	
			}
			else
			{
			for(int i =0;i<strlen(x); i++)		//checking for decimal
			{
            			if(x[i]=='.')
				{
                			printf("%s\n",str);
					a2 = 0;
					return 0;
           			}				
			}
			}
		}while(!a1 || !a2);	//running till both conditions aren't false
	return 1;
	}
	
