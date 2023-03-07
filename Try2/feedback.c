//Code contributor: Shashwat Chaturvedi
#include <stdio.h>
#include <string.h>
#include "all.h"
#include "datatypes.c"
#include <stdlib.h>
void feedback()		//a function which asks the user for feedback 
{
printf("Would you like to give feedback?(enter Y for yes, N for no) \n");	//asks the user f he wants to give feedback or no with Y for yes and N for no
	char check[4];
	//scanf("%s", check);
	scanf("%s", check);
do
{
	if (strcmp(check, "Y")==0)	//shows the feedback form if the user entered Y
	{
				
	int n[4];
	char *x;
	char *feedback[31];
	FILE *fptr;
	char str2[50];
	char str3[] = "_feedback";
	strcat(str2,str3);
	system("/usr/bin/clear");

	printf("Please fill this feedback form to help us improve :)\n");	//just printing out the form stuff from here on 
	printf("(Please rate us in all questions on a scale of 1 to 5 with 1 being the worst and 5 being the best) \n");	//asks ratings on various criteia based on different parameters
	fptr = fopen(str2, "a");
	do
  	{
  	printf("Quality of food ");
	//scanf("%d", &n[0]);
  	n[0]=checkifint("Please enter a number between 1 to 5");
	printf("\n");
  }while(n[0] <1 || n[0]>5);
  
	do
  {
	printf("Delivery time ");
	//scanf("%d", &n[1]);
	n[1]=checkifint("Please enter a number between 1 to 5");
		printf("\n");
  }while(n[1] <1 || n[1]>5);
	do
  {
  printf("Condition of delivered package ");
	//scanf("%d", &n[2]);
	n[2]=checkifint("Please enter a number between 1 to 5");
		printf("\n");
  }while(n[2] <1 || n[2]>5);
  do
  {
  printf("Ease of interaction ");
  //scanf("%d", &n[3]);
	//feedback("Please enter a number between 1 to 5");
	n[3]=checkifint("Please enter a number between 1 to 5\n");
	}while(n[3] <1 || n[3]>5);
  printf("Anything else you would like to let us know?(in less than 30 words)(just put a full stop to end your message) \n");
	int count = read_strings(feedback, 30);	//reads a feeback array of strings and stops when the character entered is full stop
	printf("\n");

	fprintf(fptr, "Quality of food %d\nDelivery time %d\nCondition of delivered package %d\nEase of interaction %d \n  Anything else you would like to let us know?(in less than 30 words)\n", n[0], n[1], n[2], n[3]);
	//this sends the feedback to the restaurant and store the feedback for every restaurant in a different file
	for(int i = 0; i<count; i++)
	{
		fprintf(fptr, "%s", feedback[i]);
	}
	fprintf(fptr, "\n");
	break;
	}	
		
	else if (strcmp(check, "N")==0){
			exit(0);
		}
  else
  {
	printf("Please enter Y or N\n");
	 scanf("%s", check); 
  }
}while(1);	
	}
	
