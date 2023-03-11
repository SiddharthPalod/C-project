//Aaditya Gole IMT2022087
//Used- pointers,file pointers,File I/O, dynamic memory allocation,array, string functions, array operations, functions
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"all.h"
#include"datatypes.c"
void search(char word[],char file2open[]);
char *rever(char *str);
extern char id[23];
char * menusearch() {
	char choice[20];
	char choice2[20];
	char reply,c,a;
    FILE* fpt;
    //FILE* fpttr;
	printf("\tWelcome to the EXPLORE SECTION!!!! \n");
	labelstart:
	printf("\n\tEnter 1 to see restaurant list, \n\t2 for key word search and \n\t3 for filter search \n\t4 to start ordering: \n");
	scanf("%s", choice);
	if (strcmp(choice,"2")==0){
		char wrd[256], buffer[256], buffer2[256], temp[256],rev[256],rev2[256];
		int bufflen, len, i, j, l,p,q, k, line,check,empty=0;
		//fp = fopen("restros", "r");	// open file
		fgets(wrd,100,stdin);
		system("/usr/bin/clear"); 
		// this command will clear the screen in linux
		printf("\nEnter What do you want to eat : ");
		scanf("%s", wrd);
		printf("\nRestaurants you might be interested in:\n");		//first we search a restaurantlist to find if the user entered a restaurant name
		search(wrd,"restros");				//function to find restaurant name in restaurant list
		printf("\n\nDishes you might be interested in:\n");				//then we check if they have entered a dish
		search(wrd, "menuitems");				//function to check all the dishes
		goto labelstart;
	}
	else if (strcmp(choice,"1")==0){
		system("/usr/bin/clear");  //clearing screen for clarity
		fpt = fopen("databaseowner", "r");	// open file
	label1:

	c = fgetc(fpt);
    while (c != EOF){		// Read contents from file and printing until we encounter end of file
        printf ("%c", c);
        c = fgetc(fpt);
    }

    printf("\n\nEnter the NAME of the restaurant whose menu you wish to see and e if you want to go back : \n");
    scanf("%s", id);
    if(strcmp(id,"e")==0){
		system("/usr/bin/clear");
        goto labelstart;
    }
    fpt = fopen(id, "r");
    if (fpt == NULL){
        printf("\nINVALID NAME  !!!\nPlease enter correct NAME\n"); //nif the entered word matches no existing file
		fpt=fopen("databaseowner","r");
		fseek(fpt,0,SEEK_SET);
        goto label1;
    }
    a = fgetc(fpt);		// Read contents from file
    while (a != EOF){
	    if(a=='~'){
			break;
		}
        printf ("%c", a);
        a = fgetc(fpt);
    }
    printf("\n");
    printf("Would you like to order from this restaurant? 'y' for yes and 'n' for no\n");	//this lets you skip a few steps and directly order from the restaurant of your choice
	reply = fgetc(stdin);
	reply = fgetc(stdin);
	//printf("\n");
	if (reply == 'y'){
	   fclose(fpt);
	   return id;
	}
	else{
	   	fclose(fpt);
		goto label1;
	}
    }
	else if(strcmp(choice,"3")==0){
		system("/usr/bin/clear"); 
		labelfilter:
		printf("Filters :\n1.Veg Only\n2.Non-Veg\n3. Beverage\n4. Dessert\n5.To go Back\n");
		printf("Enter Choice ID\n");
		scanf("%s", choice2);
		if(strcmp(choice2,"1")==0){
			printf("Dishes you want:\n");
			search("(veg)", "menuitems"); //running the function with the filter based in user choice
			goto labelfilter;
		}
		else if(strcmp(choice2,"2")==0){
			printf("Dishes you want:\n");
			search("(non-veg)", "menuitems"); //running the function with the filter based in user choice
			goto labelfilter;
		}
		
		else if(strcmp(choice2,"3")==0){
			printf("Dishes you want:\n");
			search("(beverage)", "menuitems"); //running the function with the filter based in user choice
			goto labelfilter;
		}
		else if(strcmp(choice2,"4")==0){
			printf("Dishes you want:\n");
			search("(desert)", "menuitems"); //running the function with the filter based in user choice
			goto labelfilter;
		}
		else if(strcmp(choice2,"5")==0){
			goto labelstart;
		}
		else{
			printf("\nINVALID ID  !!!\nPlease enter correct ID\n");
			goto labelfilter;
		}
		goto labelstart;
	}
	else if(strcmp(choice,"4")==0){
		system("/usr/bin/clear"); 
		return "done";		//letting the program run out
	}
	else{
		printf("INVALID ID  !!!\nPlease enter correct ID\n");
		goto labelstart;	//go back to the begining
	}
}
void search(char word[], char file2open[])
{
	//function to find a string in a given text file
	FILE* fp;
	char  buffer[256],buffer2[256], temp[256],rev[256];
	int bufflen, len, i, j, l,p,q, k, line,empty=0;
	char c,a;
	fp = fopen(file2open, "r");	// open file
	len = strlen(word); // length of input word
		line = 0;
		// the following loop the file fp line by line
		// each line is stored in buffer
		while (fgets(buffer, 256, fp) != NULL) {
			i = 0;
			bufflen = strlen(buffer);
			// the following loop find position of the input word in the current line and
			// print the position of the word on the screen
			// the loop basically reads each word of the file and compare it with the input word
			while (i < bufflen) 
			{ // comparing current word with input word
				
				j = 0;
				while (i < bufflen && j < len && buffer[i] == word[j]) {
					++i, ++j;
				} // the following condition implies that the current word of buffer is equal to input word
				if ((i == bufflen || buffer[i] == ' ' || buffer[i] == '\n') && j == len) { //we have found the word
					for(int c= 0; c<strlen(buffer);c++){
						buffer2[c]=buffer[c];
					}
					empty =1;l=i,k=0,p=i,q=0;
					while (buffer2[l] != '\n'){
					// going back and storing the line until we encounter a new line
					rev[k]=buffer2[l];
					k++;
					l--;
					}
					while (buffer[p] != '\n'){
						//going forward until we encounter a new line
						temp[q]=buffer[p];
						q++;
						p++;
					}
					temp[q] = '\0';		//end a string
					printf("%s", rever(rev));
					printf("%s\n", temp); 		//printing the combined line
				}
				// moving to next word
				while (i < bufflen && buffer[i] != ' ')
					++i;
				++i;
			}
			++line;
		}
			if(empty==0){
			printf("no relevant searches found :(\n"); //if no words match
		}
		fclose(fp);
}
char *rever(char *str){ 		//function to reverse a string
	int i;
	char temp;
	for (i = 0; i < strlen(str) / 2; i++){		//swapping ith and ith from last index of a string using temp variable
        temp = str[i];
        str[i] = str[strlen(str) - i - 1];
        str[strlen(str) - i - 1] = temp;
    }
    return str;
}

