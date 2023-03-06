#include <stdio.h>
#include <string.h>
#include <math.h>
#include"all.h"
int checkifint(char str[])	//function which asks for input again and again unitl user enters a positive integer  
{int c,n;	//str is a string which has to be shown if the user input is not a positive integer
	n = 0;
	do{
	char x[20];
	
	scanf("%s", x);
	negati
	if(x[0] == '-')		//checking if the first character is negtaive
	{
	printf("%s\n",str);	
	}
	else
	{
       	for(int i = 0; i<strlen(x); i++)	//loop which uses the ASCII values of the characters to return an integer and a prompt showing whatever string the user wants to be shown otherwise
	{
		c = (int)(x[i] - '0');
		if ((int)(x[i]-'0')<10 && (int)(x[i])>=0)
		{
			n = (int)(x[i] - '0')*pow(10,(strlen(x) - 1 - i)) + n;
		}
		else
		{
			printf("%s\n",str);	//breaking out of the loop as soon as the first non int character is entered
			break;
			
		}
	}
	}
	}while(c>9 || c<0 );	//loop keeps running as long as number entered is invalid
	
return n;	//returns the number entered if the number is valid
}



