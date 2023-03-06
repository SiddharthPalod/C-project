#include <stdio.h>
#include <string.h>
#include <math.h>
int f()
{int c,n;
	n = 0;
	do{
	char x[20];
	
	scanf("%s", x);
	
	if(x[0] == '-')
	{
	printf("Invalid input\n");	
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
			printf("Invalid input\n");
			break;
			
		}
	}
	}
	}while(c>9 || c<0 );
	
return n;
}

}

