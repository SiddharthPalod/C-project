#include <stdio.h>
#include <string.h>
#include <math.h>
#include"all.h"
int checkifint(char str[])
{int c,n;
	n = 0;
	do{
	char x[20];
	
	scanf("%s", x);
	
	if(x[0] == '-')
	{
	printf("%s\n",str);	
	}
	else
	{
       	for(int i = 0; i<strlen(x); i++)
	{
		c = (int)(x[i] - '0');
		if ((int)(x[i]-'0')<10 && (int)(x[i])>=0)
		{
			n = (int)(x[i] - '0')*pow(10,(strlen(x) - 1 - i)) + n;
		}
		else
		{
			printf("%s\n",str);
			break;
			
		}
	}
	}
	}while(c>9 || c<0 );
	
return n;
}