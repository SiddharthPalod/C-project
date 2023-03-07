#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include"user_login.h"

typedef struct {
        char name[20];
        int phno;
        int id;
}cu;// current user
struct item{ 
        char name[20];
        int no;
        int price;
        struct item * next;
};

struct oitem{
	char name[20];
	int qty;
	int price;
	struct oitem * next;
};

struct restaurant{
        char name[20];
        char location[50];
        struct item * head;
};

struct restaurant restaurants[21] = {{"Burger_King", "Bg rd", NULL}, {"ChaiPoint", "rd", NULL}, {"Dominoz", "rd", NULL},{"Juicy", "rd", NULL},{"KFC", "rd", NULL},{"McDonald", "rd", NULL},{"Onesta", "rd", NULL},{"Pizza_Hut", "rd", NULL},{"Truffles", "rd", NULL},{"Wow_Momo", "rd", NULL},{"\0", "", NULL}};// has a list of all restaurants with a '\0' terminating it
int no_of_restaurants = 10;
struct item* obtain_item(FILE *fptr){//gets a line from page and returns a pointer to struct item holding that data, should be assigned to struct item* new
        char str[20];
	int i; char c;
        int price;
        struct item *new = NULL;
        fscanf(fptr, "%s $%d", str, &price);
        new = (struct item*)malloc(1 * sizeof(struct item));
        strcpy(new->name, str);
        new->price = price;
        new->next = NULL;
        return new;
}

struct item * insert_item(struct item *head, struct item * new){
        struct item * present = head;
        struct item * prev = NULL;

        if (head == NULL){
                return new;
        }
        else {
                while(present != NULL){
                        prev = present;
                        present = present->next;
                }
                prev->next = new;
                new->next = present;
                return head;
        }// return value should be given to a pointer to first item, something like item*
}

struct item * create_ll(struct item *head, FILE * fptr){
        char str[20] = "Hello";
        int price;
        struct item * new  = (struct item*)malloc(1 * sizeof(struct item));
        strcpy(new->name, str);// random value so that it is not equal to str
        head = NULL;// insert_item requires head to be initialized to NULL
        do{
                new = obtain_item(fptr);
                if (strcmp(new->name, "~") == 0) break;
                head = insert_item(head, new);
        }while(strcmp(new->name, "~") != 0);
        return head;
}

void printll(struct item * start, FILE * fptr){// pass &restaurant[i]
        while(start != NULL){
                printf("%s $%d\n", start->name, start->price);
                start = start->next;
        }
}



char* getitem1(FILE * fptr, int n){// n is the number of the line to get
	int price;
	char *line = (char*) malloc(sizeof(char) * 20);
	for(int i=1; i<=n; i++){
	fscanf(fptr , "%s %d", line, &price);
	}
	line = (char*)realloc(line, sizeof(char)*(strlen(line)+1));
	return 	line;
}

char* find(char str[], FILE *fptr){// finds occurence of str in file and returns 0 if not found
	char temp[20]; int price; int i = 0;// line number
	while(1){
		fscanf(fptr, "%s %d", temp, &price);
	       	if(strcmp(str, temp)==0){
			return getitem1(fptr, i);	
		}
		else if (temp != "~"){ i++; continue;}
		else break;
	}
	return "absent";// indicates item not found
}

struct oitem * createoitem(char str[], int qty, struct item * first){
	int found = 0;
	for(int i=0; first != NULL; first= first->next){
		if (strcmp(first->name, str) == 0){
			found = 1;
			break;
		}	
	}
	if (found==1){
		struct oitem * it = (struct oitem*)malloc(1 * sizeof(struct oitem));
		strcpy(it->name, str);
		it->price = first->price;
		it->qty = qty;
		it->next = NULL;
		//printf("%s %d %d", it->name,it->price, it->qty);
		return it;
	}
	else {
		return NULL;// item doesn't exist
	}
			
}

struct oitem * add_oitem(struct oitem * order, struct oitem * new){
	if(new == NULL) return NULL;
	struct oitem* present = order;
	struct oitem* prev  = NULL;
	if (present == NULL){
		return new;
	}
	else{
		while(present != NULL){
			prev = present;
			present =  present->next;
		}
		prev->next = new;
		new->next = present;
	}
	return order;
}

int read_strings(char *a[], int n)		//function to read n strings into an array of character pointers allocating exactly enough space to store the  string
{
	int count = 0;
	char *x;
	char *f = ".";
	do
	{
		x = (char*)malloc(20*sizeof(char));	//initializing an array of 20 characters cuz max char size is 20
		scanf("%s", x);
		a[count] = (char*)malloc(strlen(x)*sizeof(char));	//allocating element of just the exact size in the character pointer array 
		if (strcmp(x,f) != 0)
		{
			strcpy(a[count], x);
			count++;
		}
		
	}
	while((strcmp(x,f) != 0) && (count < n));

	return count;
}



int main(int argc, char * argv[]){
	int amount = 0;	
	int order_no = 100;
	char command[20];
	char str[20]; char str2[20];
	int n;// number of items in a restaurant
	int q;// represents quantity
	FILE *rest, * fptr = fopen("1", "w");
        cu cu1;
	strcpy(cu1.name, f1());
	//printf("%s", cu1.name);
	struct item * first = (struct item*) malloc(1 * sizeof(struct item));
	struct oitem * order = (struct oitem*) malloc(1 * sizeof(struct oitem));
	if(argc < 2) { printf("Usage: ./a.exe customer / ./a.exe owner\n"); exit(0); }
        if (strcmp(argv[1],"customer") == 0) {
                printf("Welcome customer, type help to see what u can do.\n, U can also type commands if u already know how to work!\n");
                printf(">");
                scanf("%s", command);
                if (strcmp(command, "help") == 0){
                        printf("Type 'continue' to proceed\n");
                }
                else if(strcmp(command, "continue") == 0){
                        system("/usr/bin/clear");
		
                       /* printf("Name: ");
                        scanf("%s", cu1.name);
                        printf("Phno: ");
			scanf("%d", &cu1.phno);*/
			system("gcc menu_search_linux.c");
			system("./a.exe");
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
			printf("%s\n", str);
			if(strcmp(str, "list") == 0) {
				for(int i=0; strcmp(restaurants[i].name, "\0") != 0; i++){
					printf("%s ", restaurants[i].name);
				}
				printf("\n");
				goto label1;
			}
						
					strcpy(str2, str);
					//strcat(str, ".f");
					fptr = fopen(str, "r");
					int i= 0;
					while( (strcmp(restaurants[i].name, "\0") != 0)   && strcmp(restaurants[i].name, str) != 0){
						i++;	
					}
					restaurants[i].head = NULL;
					// now get all the items of the restaurant into a linked list.
					first = NULL;
					first = create_ll(first, fptr);
					
					if(strcmp(str, restaurants[i].name) == 0){
						printf("Welcome to %s, type 'start' to start ordering\n>", str2);
									
					}
					
					else{
						printf("No match found, try again\n>");
						goto label1;
					}
labelx:
					scanf("%s", str);
					if(strcmp(str, "start") == 0){
						printf("Here is the menu\n");
						printll(first, fptr);	
					}
					else{
						printf("Please type start\n");
						goto labelx;
					}
					printf("Enter <item> <qty> and then hit enter to add item to cart\n type 'back 1' to restart\ntype 'end 1' to finish order\n");
						
					strcpy(str, "hello");
					order = NULL;
					while(strcmp(str, "end") != 0){
label2:
						scanf("%s %d", str, &q);
						if (strcmp(str, "end") == 0){ break; }
						if (strcmp(str, "back") == 0) { order = NULL ; goto label2; }
						struct oitem * temp;		
						if (strcmp(str, "end") != 0){	
							temp = createoitem(str, q, first);
							temp = add_oitem( order ,temp);
						}				
						if (temp == NULL){
							free(temp);
							printf("Invalid item, please restart your oerder and don't make that mistake again!!\n");
							order = NULL;
							goto label2;
						}
						else {
							order = temp;
						}
					}
					if (strcmp(str,"end") != 0){
						printf("order error\n"); exit(0);
					}
					else {
						system("/usr/bin/clear");
						struct oitem * temp;		
						printf("Your order is:\n");
						fptr = fopen(cu1.name, "a");

						fprintf(fptr, "%s\n", str2); 
						printf("%15s %5s %3s %5s\n", "item", "price", "qty", "Total");
						fprintf(fptr, "%15s %5s %3s %5s\n", "item", "price", "qty", "Total");

						temp = order;
						for(int i=0; temp != NULL; temp=temp->next){
							printf("%15s %5d %3d %5d\n", temp->name, temp->price, temp->qty, temp->qty * temp->price);
														

							fprintf(fptr, "%15s %5d %3d %5d\n", temp->name, temp->price, temp->qty, temp->qty * temp->price);

						}

					}
					for(struct oitem *temp = order; temp!= NULL; temp = temp->next){
						amount += temp->qty * temp->price;
					}	
					printf("The total amount is: Rs. %d\n", amount);
					printf("Your order no is %d\n", order_no++);       		
					fprintf(fptr, "The total amount is: Rs. %d\n", amount);
					fprintf(fptr,"Your order no is %d\n\n", order_no++); 		
	
	printf("Would you like to give feedback?(enter Y for yes, N for no) \n");
	char check[4];
	scanf("%s", check);
	if (strcmp(check, "Y\n"))
	{
				
	int n[4];
	char *x;
	char *feedback[31];
	FILE *fptr;
	char str3[] = "_feedback";
	strcat(str2,str3);
	system("/usr/bin/clear");

	printf("Please fill this feedback form to help us improve :)\n");
	printf("(Please rate us in all questions on a scale of 1 to 5 with 1 being the worst and 5 being the best \n");
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
	printf("Anything else you would like to let us know?(in less than 30 words) \n");
	int count = read_strings(feedback, 30);
	printf("\n");

	fprintf(fptr, "Quality of food %d\nDelivery time %d\nCondition of delivered package %d\nEase of interaction %d \n  Anything else you would like to let us know?(in less than 30 words)\n", n[0], n[1], n[2], n[3]);
	for(int i = 0; i<count; i++)
	{
		fprintf(fptr, "%s", feedback[i]);
	}
	fprintf(fptr, "\n");	
		}
		
		}
		
		else{
			printf("Invalid command\n");
		}
		
	}
        else if (strcmp(argv[1], "owner") == 0){
                printf("Welcome , type help to see what u can do.\n, U can also type commands if u already know how to work!\n");
                if (strcmp(command ,"help") == 0){
                        printf("Whatever stuff\n");
                }
        }

        else {
                printf("Please run code with command './a.exe customer' or './a.exe owner'");
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
