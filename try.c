#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#include"all.h"
#include"datatypes.c"
#include <unistd.h>


char id[23];

int main(int argc, char * argv[]){
if (argc == 1 || argc > 2 ){
	printf("Run as ./a.out owner or ./a.out customer\n");
	exit(1);
}
if (strcmp(argv[1], "customer") != 0 && strcmp(argv[1], "owner") != 0){// if user doesn't run code properly just tell them how to
	printf("Run as ./a.out owner or ./a.out customer\n");
	exit(1);
}  
printf("IF YOU ALREADY HAVE AN ACCOUNT PRESS 1\n");//provide options to user
printf("IF YOU WISH TO DELETE AN ACCOUNT PRESS 2\n");
printf("IF YOU WISH TO SIGN UP PRESS ANY OTHER NUMBER\n");
char c;
struct oitem * point = NULL;// later points to different ordered items
FILE * sid = fopen("databaseowner", "r");//opens the file containing all the owner's names
FILE * prat = fopen("address", "r");// opens the file containing all restaurants addresses
char word[20] = "hello";
int iter=0;
int xcor, ycor;
struct restaurant restaurants[100];
while((c = fgetc(sid)) != EOF){// fill required data into the array of structures
	ungetc(c, sid);
	fscanf(sid,"%s", word);
	strcpy(restaurants[iter].name, word);
	fscanf(prat, "%d %d", &xcor, &ycor);
	restaurants[iter].x = xcor;
	restaurants[iter].y = ycor;
	iter++;
	fgetc(sid);
}
strcpy(restaurants[iter].name, "\0");// end with a "\0"
fclose(sid);
fclose(prat);


	int amount = 0;	// total amount to be paid
	int order_no = 100;//discard
	char command[20];// stores commands entered by the user
	char str[20]; char str2[20];// store commands as well at different stages
	int n;// number of items in a restaurant
	int q;// represents quantity
	FILE *rest, * fptr = fopen("1", "w");// open a random file
    cu cu1;
	struct oitem * temp;// later points to different ordered items
	ro r1;// r1 is the restaurant r1.name is the current restaurant u are ordering from
	int k;// helps to select the option 
	scanf("%d",&k);//Done by shashwat (putting shiven's code into prateek's code)
	if (k==1 && strcmp(argv[1], "customer") == 0)

	{
		strcpy(cu1.name, f1());
	}
	
	else if(k != 1 && k != 2 && strcmp(argv[1], "customer") == 0)

	{
		system("gcc user_signup.c");
		system("./a.out");
		strcpy(cu1.name , f1());
	}
	
	else if ( k == 2 && strcmp(argv[1], "customer") == 0){
		system("gcc user_delete.c");
		system("./a.out");
		exit(0);
	}
	
	else if(k==1 && strcmp(argv[1],"owner") ==0)
	{
		strcpy(r1.name,f2());
	}
	else if(k != 1 && strcmp(argv[1],"owner")==0)
	{
		system("gcc restaurant_signup.c");
		system("./a.out");
		strcpy(r1.name ,f2());
	}
	//printf("%s", cu1.name);
	struct item * first = NULL;// contains a ptr to linked list of all the menu items
	struct oitem * order = NULL;// contains a ptr to a linked list of all ordered items
        if (strcmp(argv[1],"customer") == 0) {
                printf("Type continue to proceed Type order history to see your history\n");
                printf(">");
		do{
                scanf("%s", command);
                if (strcmp(command, "continue") != 0 && strcmp(command, "history")!=0){
                        printf("Type 'continue' to proceed\n");
                }
                else if(strcmp(command, "continue") == 0){
                        system("/usr/bin/clear");
		}
		else if(strcmp(command, "history") == 0){
			strcpy(word, "cat ");
			strcat(word, cu1.name);
			system("/usr/bin/clear");
			system(word);		
		}
		else{;}

		}while(strcmp(command,"continue") != 0);
		
			strcpy(str, menusearch());
			goto labelmenusearch;
		
			printf("Please tell us where u want to order from(Type 'list' to see all restaurants)\n>");
label1:
			scanf("%s", str);
labelmenusearch:	
			if(strcmp(str, "list") == 0) {// just print the list of restaurants 
				for(int i=0; strcmp(restaurants[i].name, "\0") != 0; i++){
					printf("%s ", restaurants[i].name);
				}
				printf("\n");
				goto label1;// if restaurant is present allow him to type where he wants to order
			}
					strcpy(str2, str);// now str2 holds the restaurant's name
					int i= 0;// helps store the index of array that has the desired restaurant
					while( (strcmp(restaurants[i].name, "\0") != 0)   && strcmp(restaurants[i].name, str) != 0){//till u find the restaurant or find that the restaurant doesn't exist keep going through the array of structs
						i++;	
					}
					restaurants[i].head = NULL;
				// if the restaurant name (entered by user) doesn't exist
					if(strcmp(str, "\0") == 0){
						printf("Invalid command\n");
						printf("Press and key to continue\n");
						char dummy;
						scanf("%c", &dummy);
						system("/usr/bin/clear");
						printf("Please tell us where u want to order from(Type 'list' to see all restaurants)\n>");
						goto label1;// ask user to re-enter restaurant name
					}
		// now get all the items of the restaurant into a linked list called first
					else if(strcmp(str, restaurants[i].name) == 0){
						fptr = fopen(str, "r");
						first = NULL;
						first = create_ll(first, fptr);
						system("/usr/bin/clear");
						printf("Welcome to %s, type 'start' to start ordering\n>", str2);				
					}
					//just incase some unknown error turns up(can be treated same as else if)
					else{
						printf("No match found, try again\n>");
						system("/usr/bin/clear");
						printf("Please tell us where u want to order from(Type 'list' to see all restaurants)\n>");
						goto label1;
					}
labelx:
					scanf("%s", str);
					if(strcmp(str, "start") == 0){// if he enters start show him the menu 
						printf("Here is the menu\n");
						printf("-------------------------------\n");
						printf("item                   | price \n");
						printf("-------------------------------\n");
						printll(first, fptr);
						printf("-------------------------------\n");	
						printf("Now u can order!\n\n");
					}
					else{// if user doesn't input start
						printf("Please type start\n>");
						goto labelx;
					}
					printf("At any point when asked for item entry type 'back' to restart order\ntype 'end' to finish order\n");
						
					strcpy(str, "hello");// put a random string in str
					order = NULL;
					while(strcmp(str, "end") != 0){
label2:
						printf("Enter the item name: ");
						scanf("%s", str);
						if (strcmp(str, "end") == 0){ break; }
						if (strcmp(str, "back") == 0) { 
							order = NULL ; 
							goto label2;
						        	
						}
						struct item * temp1 = first;// temp1 is used to check if user has entered a valid item or not
						int flag = 0;// if item exists(is valid) flag becomes 1
						while(temp1 != NULL){
							if (strcmp(temp1->name, str) == 0) { flag = 1; break; }
							else temp1 = temp1->next;
						}
						if (flag == 0){
							printf("Invalid item, please continue your order from where u left\n");
							goto label2;
						}
						//if the item is valid, add it to cart
						printf("enter the req quantity: ");
						scanf("%d", &q);
						//if (strcmp(str, "end") == 0){ break; }
						//if (strcmp(str, "back") == 0) { order = NULL ; goto label2; }
						struct oitem * temp;		
						if (strcmp(str, "end") != 0){	
							temp = createoitem(str, q, first);
							temp = add_oitem(order ,temp);
							printf("%d %s added to cart!\n", temp->qty, temp->name);
						}				
						{// after adding the item make order point to the start of the list of ordered items
							order = temp;
						}
					}
					// to calculate the distance (by Aaditya Gole)
					printf("Please enter your address in terms of x and y coordinates\n");
					scanf("%d, %d" , &cu1.x, &cu1.y);
					FILE * gole;
					gole = fopen("address", "r");			
					char rx[10];
					char ry[10];
					char ch;
					int next =0, counter = 0, iterable = 0;
					ch = fgetc(gole);
					while (ch != EOF){
						if(counter == i){
							if(ch == ' '){
								rx[iterable] = '\0';
								next = 1;
								iterable = 0;
								goto labelend;
							}
							if (ch == '\n'){
								ry[iterable] = '\0';
								break;
							}
							if (next == 0){
								rx[iterable] = ch;
							}
							else if(next == 1){
								ry[iterable] = ch;
							}
							iterable++;
						}
labelend:
						if (ch == '\n') counter++;
						ch = fgetc(gole);
					}

					fclose(gole);
					int cx = converter(rx);
					int cy = converter(ry);//use formula of distance between two points
					float time = (sqrt( (pow((cx - cu1.x), 2)) + (pow((cy - cu1.y), 2)) ) / 20.0) + 5;
					
					
					if (strcmp(str,"end") != 0){// just to ensure nothing went wrong
						printf("order error\n"); exit(0);
					}
					else {
						system("/usr/bin/clear");		
						printf("Your order is:\n");
						fptr = fopen(cu1.name, "a");// points to the order history file of that particular customer
					// str2 contains the name of the restaurant
						fprintf(fptr, "%s\n", str2);// just some decoration
						fprintf(fptr, "--------------------------------------------\n");
						printf("--------------------------------------------\n");

						printf("%-23s |%-6s |%-3s |%-5s\n", "ITEM", "PRICE", "QTY", "TOTAL");
						fprintf(fptr, "%-23s |%-6s |%-3s |%-5s\n", "ITEM", "PRICE", "QTY", "TOTAL");
						fprintf(fptr, "--------------------------------------------\n");
						printf("--------------------------------------------\n");
						temp = order;
						for(int i=0; temp != NULL; temp=temp->next){
							printf("%-23s |$%-5d |%-3d |%-5d\n", temp->name, temp->price, temp->qty, temp->qty * temp->price);// calculate subprices
							fprintf(fptr, "%-23s |$%-5d |%-3d |%-5d\n", temp->name, temp->price, temp->qty, temp->qty * temp->price);
						}
						fprintf(fptr, "--------------------------------------------\n");
						printf("--------------------------------------------\n");


					}
		// calculate total price
					for(temp = order; temp!= NULL; temp = temp->next){
						amount += temp->qty * temp->price;
					}	
					printf("The total amount is: Rs. %d\n", amount);
					fprintf(fptr, "The total amount is: Rs. %d\n\n", amount);
					printf("%s, Your order's estimated time of arrival is %d mins\n", cu1.name, (int)time);

	//Code for timer display after confirmation of order done by siddharth palod and soham
	int minutes, seconds;
	minutes = time / 60;
	seconds = (int)time % 60;

	while (time >= 0) {
	system("clear");
	printf("\t\t\t%02d  :   %02d\n", minutes, seconds);
	if(minutes>=1){
	printf("       __            \t\t\t\t\n");     
	printf("      /__|__         \t\t\t\t");     printf("        .______.                    \n");
	printf("      \\\\  /          \t\t\t\t");   printf("  ._____| _]>  |_______________.    \n");
	printf("        /|__         \t\t\t\t");     printf("  |-----|______|---------------|    \n");
	printf(" .___.  |,` T__,./   \t\t\t\t");     printf("  |  __          __________    |    \n");
	printf("/    |_-.\\\\ _    --. \t\t\t\t");   printf("  | |__|   __   |RESTAURANT|   |    \n");
	printf("\\ ____,'  `))`___,-' \t\t\t\t");    printf("  |=======|  |=================|    \n");  
	printf(" `\\_./ '--'  \\_./ _ _ _   _ _ _   _ _ _  _ _  _ _ |_______[  ]_________________|    \n");
	if(minutes>1)
	printf("\n\t\t Order is being prepared !\n");
	else
	printf("\n\t\t Driver is picking up your order\n");
	}
	else{
	printf("       __            \t\t\t       \n");
	printf("      /__|__         \t\t\t");         printf("      ___                      \n");
	printf("      \\\\  /          \t\t\t");       printf("     /   \\                    \n");
	printf("        /|__         \t\t\t");         printf("    /VVVVV\\______________     \n");
	printf(" .___.  |,` T__,./   \t\t\t");         printf("   /   _   \\nnnnnnnnnnnnn\\   \n");
	printf("/    |_-.\\\\ _    --. \t\t\t");       printf("   |  /_\\  |\\_____________\\ \n");
	printf("\\ ____,'  `))`___,-' \t\t\t");        printf("   |  __   |  Arriving   |     \n");
	printf(" `\\_./ '--'  \\_./_-_  _-_  _-_  _-_  _ _   ");    printf("|_|o |__|_____Soon____|     \n");
	if(seconds>30)
	printf("\n\t\t Driver is on the way\n");
	else if(seconds>5)
	printf("\n\t    Driver has arrived to your location\n");
	else    
	printf("\n\t\t\t ORDER  RECIEVED \n");
	}
	sleep(1); // wait for 1 second

	seconds--;
	if (seconds < 0) {
	minutes--;
	seconds = 59;
	}
	time--;
	//any other thing which needs to be displayed at that time add in this loop
	}

	printf("\n\t T H A N K S for Ordering from SASTA SWIGGY\n"); //After timer is 0 prints end message

	
	printf("Would you like to give feedback?(enter Y for yes, N for no) \n");
	char check[4];
	scanf("%s", check);
	scanf("%s", check);

	if (strcmp(check, "Y")==0)
	{
				
	int n[4];
	char *x;
	char *feedback[31];
	FILE *fptr;
	char str3[] = "_feedback";
	strcat(str2,str3);
	system("/usr/bin/clear");

	printf("Please fill this feedback form to help us improve :)\n");
	printf("(Please rate us in all questions on a scale of 1 to 5 with 1 being the worst and 5 being the best) \n");
	fptr = fopen(str2, "a");
	printf("Quality of food ");
	scanf("%d", &n[0]);
	printf("\n");
	printf("Delivery time ");
	scanf("%d", &n[1]);
	printf("\n");
	printf("Condition of delivered package ");
	scanf("%d", &n[2]);
	printf("\n");
	printf("Ease of interaction ");
	scanf("%d", &n[3]);
	printf("\n");
	printf("Anything else you would like to let us know?(in less than 30 words)(just put a full stop to end your message) \n");
	int count = read_strings(feedback, 30);
	printf("\n");

	fprintf(fptr, "Quality of food %d\nDelivery time %d\nCondition of delivered package %d\nEase of interaction %d \n  Anything else you would like to let us know?(in less than 30 words)\n", n[0], n[1], n[2], n[3]);
	for(int i = 0; i<count; i++)
	{
		fprintf(fptr, "%s", feedback[i]);
	}
	fprintf(fptr, "\n");
	}	
		
	else if (strcmp(check, "N")==0){
			exit(0);
		}	
		
		
		else{
			printf("Invalid command\n");
		}
		
	}
		
       
	fclose(fptr);	
	
	
	return 0;

}
