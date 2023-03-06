// delarations of all functions are present in this file


#include<stdio.h>                                       //this is a file that contains all the function declarations and struct declarations
int find_rest_index(char * str);
struct item * obtain_item(FILE * fptr);
struct item * insert_item(struct item * head, struct item * new);
struct item * create_ll(struct item * head, FILE * fptr);
void printll(struct item * start, FILE * fptr);
char* getitem1(FILE * fptr, int n);
char* find(char str[], FILE *fptr);
struct oitem * createoitem(char str[], int qty, struct item * first);
struct oitem * add_oitem(struct oitem * order, struct oitem * new);
int read_strings(char *a[], int n);
int converter(char * str);

struct user;
char * f1();
void search(char word[], char file2open[]);
char *rever(char *str);
char * menusearch();

struct restaurant1;
char * f2();

int checkifint(char str[]);
