#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include"all.h"
//#include"user_login.h"
//#include"restaurant_login.h"
#include<math.h>
typedef struct ro{
	char name[20];
	int phno;
}ro;

typedef struct {
        char name[20];
        int phno;
        int id;
	int x;
	int y;
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

struct restaurant{// done by Aaditya Gole IMT2022087
        char name[20];
        char location[50];
        struct item * head;
	int x;
	int y;
};
struct restaurant restaurants[100];
/*struct restaurant restaurants[21] = {{"Burger_King", "Bg rd", NULL}, {"ChaiPoint", "rd", NULL}, {"Dominoz", "rd", NULL},{"Juicy", "rd", NULL},{"KFC", "rd", NULL},{"McDonalds", "rd", NULL},{"Onesta", "rd", NULL},{"Pizza_Hut", "rd", NULL},{"Truffles", "rd", NULL},{"Wow_Momo", "rd", NULL},{"\0", "", NULL}};// has a list of all restaurants with a '\0' terminating it*/

/*FILE *d=fopen("KFC","w");
//FILE * sid = fopen("restaurant_list", "r");
//FILE * prat = fopen("address", "r");
char word[20] = "hello";
int iter=0;
int xcor, ycor;
while(word != EOF){
	fscanf(sid,"%s", word);
	strcpy(restaurants[i].name, word);
	fscanf(prat, "%d %d", &xcor, &ycor);
	restaurants[iter].x = xcor;
	restaurants[iter].y = ycor;
	iter++;
}
fclose(sid);
fclose(prat);
*/

int no_of_restaurants = 10;

int find_rest_index(char *str){
	int i= 0;
	while (strcmp(str, restaurants[i].name) != 0){
		i++;
	}
	return i;
}

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
                printf("%-23s| $%-5d\n", start->name, start->price);
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
	char f[] = ".";
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

int converter(char * str)
{
    int num = 0;
  
    // converting string to number
    for (int i = 0; str[i] != '\0'; i++) {
        num = num * 10 + (str[i] - 48);
    }
  
    // at this point num contains the converted number
    return num;
}
