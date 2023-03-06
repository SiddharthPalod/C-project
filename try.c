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
if (strcmp(argv[1], "customer") != 0 && strcmp(argv[1], "owner") != 0){
	printf("Run as ./a.out owner or ./a.out customer\n");
	exit(1);
}  
printf("IF YOU ALREADY HAVE AN ACCOUNT PRESS 1\n");
printf("IF YOU WISH TO DELETE AN ACCOUNT PRESS 2\n");
printf("IF YOU WISH TO SIGN UP PRESS ANY OTHER NUMBER\n");
char c;
struct oitem * point = NULL;
FILE * sid = fopen("databaseowner", "r");
FILE * prat = fopen("address", "r");
char word[20] = "hello";
int iter=0;
int xcor, ycor;
struct restaurant restaurants[100];
while((c = fgetc(sid)) != EOF){
	ungetc(c, sid);
	fscanf(sid,"%s", word);
	strcpy(restaurants[iter].name, word);
	fscanf(prat, "%d %d", &xcor, &ycor);
	restaurants[iter].x = xcor;
	restaurants[iter].y = ycor;
	iter++;
	fgetc(sid);
}
strcpy(restaurants[iter].name, "\0");
fclose(sid);
fclose(prat);


	int amount = 0;	
	int order_no = 100;
	char command[20];
	char str[20]; char str2[20];
	int n;// number of items in a restaurant
	int q;// represents quantity
	FILE *rest, * fptr = fopen("1", "w");
    cu cu1;
	struct oitem * temp;
	ro r1;
	int k;
	scanf("%d",&k);
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
	struct item * first = (struct item*) malloc(1 * sizeof(struct item));
	struct oitem * order = (struct oitem*) malloc(1 * sizeof(struct oitem));
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
			strcpy(word, "vim ");
			strcat(word, cu1.name);
			system(word);		
		}
		else{;}

		}while(strcmp(command,"continue") != 0);
		
                       /* printf("Name: ");
                        scanf("%s", cu1.name);
                        printf("Phno: ");
			scanf("%d", &cu1.phno);*/
			//system("gcc menu_search_linux.c");
			//system("./a.out");
			strcpy(str, menusearch());
			goto labelmenusearch;
			
		//	scanf("%s", str2);
		//	if (strcmp(str2, "history") == 0){
		//		strcpy(str ,cu1.name);
		//		char vim[20] = "vim";
		//		strcat(vim, " ");
		//		strcat(vim, str);
		//		system(vim);
		//	}
		//	else{
		//		printf("error");
		//	}
			printf("Please tell us where u want to order from(Type 'list' to see all restaurants)\n>");
label1:
			scanf("%s", str);
labelmenusearch:	
			if(strcmp(str, "list") == 0) {
				for(int i=0; strcmp(restaurants[i].name, "\0") != 0; i++){
					printf("%s ", restaurants[i].name);
				}
				printf("\n");
				goto label1;
			}
					
					strcpy(str2, str);
					//strcat(str, ".f");
					//fptr = fopen(str, "r");
					int i= 0;
					while( (strcmp(restaurants[i].name, "\0") != 0)   && strcmp(restaurants[i].name, str) != 0){//till u find the restaurant or find that the restaurant doesn't exist keep going through the array of structs
						i++;	
					}
					restaurants[i].head = NULL;
					// now get all the items of the restaurant into a linked list called first
					if(strcmp(str, "\0") == 0){
						printf("Invalid command\n");
						printf("Press and key to continue\n");
						char dummy;
						scanf("%c", &dummy);
						system("/usr/bin/clear");
						printf("Please tell us where u want to order from(Type 'list' to see all restaurants)\n>");
						goto label1;
					}
					else if(strcmp(str, restaurants[i].name) == 0){
						fptr = fopen(str, "r");
						first = NULL;
						first = create_ll(first, fptr);
						system("/usr/bin/clear");
						printf("Welcome to %s, type 'start' to start ordering\n>", str2);				
					}
					
					else{
						printf("No match found, try again\n>");
						system("/usr/bin/clear");
						printf("Please tell us where u want to order from(Type 'list' to see all restaurants)\n>");
						goto label1;
					}
labelx:
					scanf("%s", str);
					if(strcmp(str, "start") == 0){
						printf("Here is the menu\n");
						printf("-------------------------------\n");
						printf("item                   | price \n");
						printf("-------------------------------\n");
						printll(first, fptr);
						printf("-------------------------------\n");	
						printf("Now u can order!\n\n");
					}
					else{
						printf("Please type start\n>");
						goto labelx;
					}
					printf("At any point wheen asked for item entry type 'back' to restart order\ntype 'end' to finish order\n");
						
					strcpy(str, "hello");
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
						int flag = 0;// if item exists flag becomes 1
						while(temp1 != NULL){
							if (strcmp(temp1->name, str) == 0) { flag = 1; break; }
							else temp1 = temp1->next;
						}
						if (flag == 0){
							printf("Invalid item, please continue your order from where u left\n");
							/*point = order;
							while(point->next != NULL){
								point = point->next;
							}
							point = NULL;
							//order = NULL;*/
							goto label2;
						}

						printf("enter the req quantity: ");
						scanf("%d", &q);
						//if (strcmp(str, "end") == 0){ break; }
						//if (strcmp(str, "back") == 0) { order = NULL ; goto label2; }
						struct oitem * temp;		
						if (strcmp(str, "end") != 0){	
							temp = createoitem(str, q, first);
							temp = add_oitem(order ,temp);
						}				
						if (temp == NULL){
							free(temp);
							//printf("Invalid item, please continue your order from where u left\n");
							/*point = order;
							while(point->next != NULL){
								point = point->next;
							}
							point = NULL;
							//order = NULL;
							goto label2;*/
						}
						else {
							order = temp;
						}
					}
					// to caluculate the distance by gole
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
					int cy = converter(ry);
					float time = (sqrt( (pow((cx - cu1.x), 2)) + (pow((cy - cu1.y), 2)) ) / 20.0) + 5;
					

					
					
					
					if (strcmp(str,"end") != 0){
						printf("order error\n"); exit(0);
					}
					else {
						system("/usr/bin/clear");		
						printf("Your order is:\n");
						fptr = fopen(cu1.name, "a");

						fprintf(fptr, "%s\n", str2);
						fprintf(fptr, "--------------------------------------------\n");
						printf("--------------------------------------------\n");

						printf("%-23s |%-6s |%-3s |%-5s\n", "item", "price", "qty", "Total");
						fprintf(fptr, "%-23s |%-6s |%-3s |%-5s\n", "item", "price", "qty", "Total");
						fprintf(fptr, "--------------------------------------------\n");
						printf("--------------------------------------------\n");
						temp = order;
						for(int i=0; temp != NULL; temp=temp->next){
							printf("%-23s |$%-5d |%-3d |%-5d\n", temp->name, temp->price, temp->qty, temp->qty * temp->price);
														

							fprintf(fptr, "%-23s |$%-5d |%-3d |%-5d\n", temp->name, temp->price, temp->qty, temp->qty * temp->price);

						}
						fprintf(fptr, "--------------------------------------------\n");
						printf("--------------------------------------------\n");


					}
					for(temp = order; temp!= NULL; temp = temp->next){
						amount += temp->qty * temp->price;
					}	
					printf("The total amount is: Rs. %d\n", amount);
					//printf("Your order no is %d\n", order_no++);       		
					fprintf(fptr, "The total amount is: Rs. %d\n", amount);
					//fprintf(fptr,"Your order no is %d\n\n", order_no++);
					printf("%s, Your order's estimated time of arrival is %d mins\n", cu1.name, (int)time);

	//Code for timer display after confirmation of order
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
		
        else if (strcmp(argv[1], "owner") == 0){
               // printf("Welcome owner, type help to see what u can do.\n, U can also type commands if u already know how to work!\n");
                if (strcmp(command ,"help") == 0){
                        printf("Whatever stuff\n");
                }
		else if(strcmp(command, "continue") == 0){
		strcpy(r1.name, f2());
		printf("%s", r1.name);	
		}		
        }

        else {
                printf("Please run code with command './a.out customer' or './a.out owner'");
                exit(0);
        }
	fclose(fptr);	
	
	
	return 0;

//	printf("Confirm order?(enter Y for yes, N for no) \n");
//	char check;
//	scanf("%c", &check);
//	if (check == 'N')
//		return 0;
//	else if (check == 'Y')
		
	}
