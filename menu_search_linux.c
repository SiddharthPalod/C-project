//Aaditya Gole IMT2022087
//Used- pointers,file pointers,File I/O, dynamic memory allocation,array, string functions, array operations, functions
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void search(char word[]);
char *rever(char *str);


//strstr()
void main() 
{

	
	int check,choice,choice2,empty=0;
	char c,a;
    FILE* fpt;
    FILE* fpttr;
    char id[16];
	fpt = fopen("restroslist.txt", "r");	// open file
	
	FILE* fp;
	printf("Welcome !!!! \n");
	labelstart:
	printf("\n\n\nEnter 1 to see restaurant list, \n2 for key word search and \n3 for filter search \n4 to exit: \n");
	scanf("%d", &choice);
	if (choice == 2)
	{
		char wrd[256], buffer[256], buffer2[256], temp[256],rev[256],rev2[256];
		int bufflen, len, i, j, l,p,q, k, line,check;
	
		fp = fopen("restros.txt", "r");	// open file
		fgets(wrd,100,stdin);
		system("/usr/bin/clear"); 
		// this command will clear the screen in linux
		printf("\nEnter What do you want to eat : ");
		scanf("%s", wrd);
		len = strlen(wrd); // length of input word
		printf("\nRestros you might be interested in:\n");
		line = 0;
		// the following loop the file fp line by line
		// each line is stored in buffer
		while (fgets(buffer, 256, fp) != NULL) 
		{

			i = 0;
			bufflen = strlen(buffer);
			// the following loop find position of the input word in the current line and
			// print the position of the word on the screen
			// the loop basically reads each word of the file and compare it with the input word
			while (i < bufflen) 
			{

				// comparing current word with input word
				j = 0;
				
				while (i < bufflen && j < len && buffer[i] == wrd[j]) 
				{
					
					++i, ++j;
				

				}

				// the following condition implies that the current word of buffer
				// is equal to input word
				if ((i == bufflen || buffer[i] == ' ' || buffer[i] == '\n') && j == len) 
				{
					//printf("Line: %d ", line);
					for(int c= 0; c<strlen(buffer);c++)
					{
						buffer2[c]=buffer[c];
					}

					empty =1;
					l=i;
					k=0;
					q=0;
					p=i;
					while (buffer2[l] != '\n')
					{
					// going back and storing the line until we encounter a new line
					rev[k]=buffer2[l];
					k++;
					l--;
					}

					while (buffer[p] != '\n')
					{
						//going forward until we encounter a new line
					
						temp[q]=buffer[p];
						q++;
						p++;
					}
					temp[q] = '\0';	//ending the string

					printf("%s", rever(rev));
					printf("%s\n", temp); 
					//printing the combined line
					
				}

				// moving to next word
				while (i < bufflen && buffer[i] != ' ')
				{
					++i;
				}
				++i;
				
				
			}

			++line;
			check=0;

		}
		if(empty ==0)
		{
			printf("no relevant restaurants found :(\n");
		}
			


		fclose(fp);


		empty=0;

		fp = fopen("menuitems.txt", "r");	// open file


		len = strlen(wrd); // length of input word
		printf("\n\nDishes you might be interested in:\n");


		line = 0;
		// the following loop the file fp line by line
		// each line is stored in buffer
		while (fgets(buffer, 256, fp) != NULL) 
		{

			i = 0;
			bufflen = strlen(buffer);
			// the followinf loop find position of the input word in the current line and
			// print the position of the word on the screen
			// the loop basically reads each word of the file and compare it with the input word
			while (i < bufflen) 
			{

				// comparing current word with input word
				j = 0;
				
				while (i < bufflen && j < len && buffer[i] == wrd[j]) 
				{
					
					++i, ++j;
				

				}

				// the following condition implies that the current word of buffer
				// is equal to input word
				if ((i == bufflen || buffer[i] == ' ' || buffer[i] == '\n') && j == len) 
				{
					for(int c= 0; c<strlen(buffer);c++)
					{
						buffer2[c]=buffer[c];
					}
					empty=1;
					check=1;
					l=i;
					k=0;
					q=0;
					p=i;
					while (buffer2[l] != '\n')
					{
					// going back and storing the line until we encounter a new line
					rev[k]=buffer2[l];
					k++;
					l--;
					}

					while (buffer[p] != '\n')
					{
						//going forward until we encounter a new line
					
						temp[q]=buffer[p];
						q++;
						p++;
					}
					if (check ==1)
					{
						temp[q]='\0'; 		//ending the string
						printf("%s", rever(rev));
						printf("%s\n", temp); 
						//printing the combined line
						check=0;
						
					}
					check=0;
					
				}
				check=0;

				// moving to next word
				while (i < bufflen && buffer[i] != ' ')
				{
					++i;
				}
				++i;
			

			}

			++line;
			check=0;

		}
		if(empty==0)
		{
			printf("no relevant dishes found :(\n");
		}
		fclose(fp);
		goto labelstart;
	}
	else if (choice ==1)
	{
		// Read contents from file
    c = fgetc(fpt);
    while (c != EOF)		//printing until we encounter end of file
    {
        printf ("%c", c);
        c = fgetc(fpt);
    }
  
    fclose(fpt);
    label1:
    printf("Enter the NAME of the restaurant whose menu you wish to see and e if you want to go back : \n");
	
    scanf("%s", id);
	
    if(strcmp(id,"e")==0)
    {
        goto labelstart;
    }
    strcat(id,".txt");
    fpttr = fopen(id, "r");
    if (fpttr == NULL)
    {
        printf("INVALID NAME  !!!\nPlease enter correct ID\n");
        goto label1;
    }
  
    // Read contents from file
    a = fgetc(fpttr);
    while (a != EOF)
    {
        printf ("%c", a);
        a = fgetc(fpttr);
    }
    printf("\n");
    goto label1;
	}
	else if(choice == 3)
	{
		labelfilter:
		printf("Filters :\n1.Veg Only\n2.Non-Veg\n3.Spicy\n4. Beverage\n5. Desert\n6.To go Back\n");
		printf("Enter Choice ID\n");
		scanf("%d", &choice2);

		if(choice2 == 1)
		{
			printf("Dishes you want:\n");
			//running the function with the filter based in user choice
			search("veg");
		}
		else if(choice2 == 2)
		{
			printf("Dishes you want:\n");
			search("non-veg");
		}
		else if(choice2 == 3)
		{
			printf("Dishes you want:\n");
			search("spicy");
		}
		
		else if(choice2==4)
		{
			printf("Dishes you want:\n");
			search("beverage");

		}
		else if(choice2 == 5)
		{
			printf("Dishes you want:\n");
			search("desert");
		}
		else if(choice2==6)
		{
			goto labelstart;
		}
		else
		{
			printf("INVALID ID  !!!\nPlease enter correct ID\n");
			goto labelfilter;
		}
		goto labelstart;
	


	}
	else if(choice == 4)
	{
		//letting the program run out

	}
	else
	{
		printf("INVALID ID  !!!\nPlease enter correct ID\n");
		goto labelstart;	//go back to the begining
	}
	
}
void search(char word[])
{
	//function to find a string in a given text file
	FILE* fp;
	char  buffer[256],buffer2[256], temp[256],rev[256];
	int bufflen, len, i, j, l,p,q, k, line,check,choice,choice2,empty=0;
	char c,a;
	fp = fopen("menuitems.txt", "r");	// open file
	len = strlen(word); // length of input word


		line = 0;
		// the following loop the file fp line by line
		// each line is stored in buffer
		while (fgets(buffer, 256, fp) != NULL) 
		{

			i = 0;
			bufflen = strlen(buffer);
			// the following loop find position of the input word in the current line and
			// print the position of the word on the screen
			// the loop basically reads each word of the file and compare it with the input word
			while (i < bufflen) 
			{

				// comparing current word with input word
				j = 0;
				
				while (i < bufflen && j < len && buffer[i] == word[j]) 
				{
					
					++i, ++j;
				

				}

				// the following condition implies that the current word of buffer
				// is equal to input word
				if ((i == bufflen || buffer[i] == ' ' || buffer[i] == '\n') && j == len) 
				{
					//printf("Line: %d ", line);
					for(int c= 0; c<strlen(buffer);c++)
					{
						buffer2[c]=buffer[c];
					}

					empty =1;
					l=i;
					k=0;
					q=0;
					p=i;
					while (buffer2[l] != '\n')
					{
					// going back and storing the line until we encounter a new line
					rev[k]=buffer2[l];
					k++;
					l--;
					}

					while (buffer[p] != '\n')
					{
						//going forward until we encounter a new line
					
						temp[q]=buffer[p];
						q++;
						p++;
					}
					temp[q] = '\0';		//end a string

					printf("%s", rever(rev));
					printf("%s\n", temp); 
					//printing the combined line
					
				}

				// moving to next word
				while (i < bufflen && buffer[i] != ' ')
				{
					++i;
				}
				++i;
			
				
			}

			++line;
			check=0;

		}
			


		fclose(fp);
}


char *rever(char *str)
{ //function to reverse a string
    
	int i;
	char temp;
	for (i = 0; i < strlen(str) / 2; i++)
    {
        temp = str[i];
        str[i] = str[strlen(str) - i - 1];
        str[strlen(str) - i - 1] = temp;
    }

    return str;
}

		
