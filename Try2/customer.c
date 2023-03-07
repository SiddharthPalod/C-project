// Customer's code as Client's code

#include <arpa/inet.h> // inet_addr()
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h> // bzero()
#include <sys/socket.h>
#include <unistd.h> // read(), write(), close()
#include<ctype.h>
#include<math.h>
#include"all.h"
#include"datatypes.c"
#define MAX 80
#define PORT 8080
#define SA struct sockaddr
char id[23];

// MOST OF THIS CODE WAS DONE BY PRATEEK RATH IMT2022017
int main(int argc, char * argv[]){// arguments by which main is called
    int count = 0;
    struct oitem * order = (struct oitem*) malloc(1 * sizeof(struct oitem));
    order = NULL;
    
    if (argc == 1 || argc > 2 ){
        printf("Run as ./a.out owner or ./a.out customer\n");
        exit(1);
    }
    if (strcmp(argv[1], "customer") != 0 && strcmp(argv[1], "owner") != 0){//  is user is not running the code correctly correct the user
        printf("Run as ./a.out owner or ./a.out customer\n");
        exit(1);
    }
    printf("IF YOU ALREADY HAVE AN ACCOUNT PRESS 1\n");
    printf("IF YOU WISH TO DELETE AN ACCOUNT PRESS 2\n");
    printf("IF YOU WISH TO SIGN UP PRESS ANY OTHER NUMBER\n");
    char c;
    struct oitem * point = NULL;// TO BE DELETED(maybe)
    FILE * sid = fopen("databaseowner", "r");// file pointer to list of restaurant names
    FILE * prat = fopen("address", "r");// file pointer to list of addresses of restaurants
    char word[20] = "hello";
    int iter=0;
    int xcor, ycor;
    struct restaurant restaurants[100];
    while((c = fgetc(sid)) != EOF){// fill the array with the restaurants and their details
        ungetc(c, sid);
        fscanf(sid,"%s", word);
        strcpy(restaurants[iter].name, word);
        fscanf(prat, "%d %d", &xcor, &ycor);
        restaurants[iter].x = xcor;
        restaurants[iter].y = ycor;
        iter++;
        fgetc(sid);
    }
    strcpy(restaurants[iter].name, "\0");// mark the end of the array with a \n
    fclose(sid);
    fclose(prat);
    
    
    int amount = 0;// total amount
                                    int order_no = 100;// TO BE DELETED
    char command[20];
    char str[20]; char str2[20];
    int n;// number of items in a restaurant
    int q;// represents quantity
    FILE *rest, * fptr = fopen("1", "w");
    cu cu1;// the current user
    struct oitem * temp;// useful to traverse the linked list of ordered items
    ro r1;// the current restaurant owner
    int k;// checks if u want to login, signup or delete account
    scanf("%d",&k);
    if (k==1 && strcmp(argv[1], "customer") == 0)//(BY SHASHWAT CHATURVEDI IMT2022118)
        
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
    struct item * first = (struct item*) malloc(1 * sizeof(struct item));// can be changed to NULL
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
                system(word);
                printf("\n");
            }
            else{;}
            
        }while(strcmp(command,"continue") != 0);
        
        strcpy(str, menusearch());
        goto labelmenusearch;
        
        printf("Please tell us where u want to order from(Type 'list' to see all restaurants)\n>");
    label1:
        scanf("%s", str);
    labelmenusearch:
        if(strcmp(str, "list") == 0) {// look for the restaurant in the list of restaurants
            for(int i=0; strcmp(restaurants[i].name, "\0") != 0; i++){
                printf("%s ", restaurants[i].name);
            }
            printf("\n");
            goto label1;
        }
        
        strcpy(str2, str); // now str2 has the restaurant's name
        int i= 0;// iteration variable
        while( (strcmp(restaurants[i].name, "\0") != 0)   && strcmp(restaurants[i].name, str) != 0){//till u find the restaurant or find that the restaurant doesn't exist keep going through the array of structs
            i++;
        }
                        restaurants[i].head = NULL;// can be deleted, but make sure u also remove it from funcs.c
        // now get all the items of the restaurant into a linked list called first
        if(strcmp(str, "\0") == 0){
            printf("Invalid command\n");
            printf("Press and key to continue\n");
            char dummy;
            scanf("%c", &dummy);
            system("/usr/bin/clear");
            printf("Please tell us where u want to order from(Type 'list' to see all restaurants)\n>");
            goto label1;// if an invalid command is entered allow user to re-enter
        }
        else if(strcmp(str, restaurants[i].name) == 0){
            fptr = fopen(str, "r");
            first = NULL;
            first = create_ll(first, fptr);// creates a linked list containing the menu of the restaurant
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
            printf("ITEM                   | PRICE \n");
            printf("-------------------------------\n");
            printll(first, fptr);// prints the menu
            printf("-------------------------------\n");
            printf("Now u can order!\n\n");
        }
        else{
            printf("Please type start\n>");
            goto labelx;
        }
        printf("At any point when asked for item entry,\ntype 'back' to restart order\ntype 'end' to finish order\n\n");
        
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
                goto label2;
            }
            
            printf("enter the req quantity: ");
            scanf("%d", &q);
            //if (strcmp(str, "end") == 0){ break; }
            //if (strcmp(str, "back") == 0) { order = NULL ; goto label2; }
            struct oitem * temp;// SHOULD BE REMOVED < HAS BEEN DECARED TWICE
            if (strcmp(str, "end") != 0){// creates the linked list for valid ordered items
                temp = createoitem(str, q, first);
                temp = add_oitem(order ,temp);
            }
            
                order = temp;
            
        }
        // to calculate the distance (by Aaditya Gole)
        printf("Please enter your address in terms of x and y coordinates\n");
        scanf("%d %d" , &cu1.x, &cu1.y);
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
        float time =(sqrt( (pow((cx - cu1.x), 2)) + (pow((cy - cu1.y), 2)) )/5)  +5;
        
        
        
        
        if (strcmp(str,"end") != 0){// just to avoid any bad situation(although this case will never happend)
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
                count++;
                
            }
            fprintf(fptr, "--------------------------------------------\n");
            printf("--------------------------------------------\n");
            
            
        }
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        FILE* common;
        common = fopen("common.txt", "w");

        struct oitem * temp;// THIRD TIME THIS HAS BEEN DECLARED
        // useful to show owner what user has ordered during confirmation
        fprintf(common, "%d\n", count);
        temp = order;
        for(int i=0; temp != NULL; temp=temp->next){
            fprintf(common, "%15s %5d %3d %5d\n", temp->name, temp->price, temp->qty, temp->qty * temp->price);

        }
        printf("Done writing to file.");
        fclose(common);
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        for(temp = order; temp!= NULL; temp = temp->next){// calculate the total amount
            amount += temp->qty * temp->price;
        }
        
        printf("The total amount is: Rs. %d\n", amount);
        //printf("Your order no is %d\n", order_no++);
        fprintf(fptr, "The total amount is: Rs. %d\n", amount);
        //fprintf(fptr,"Your order no is %d\n\n", order_no++);
        
        printf("%s, hi Your order's estimated time of arrival is %d mins\n", cu1.name, (int)time);
        
        
        //        // Client's code
        //        int sockfd, connfd;
        //        struct sockaddr_in servaddr, cli;
        //
        //        // socket create and verification
        //        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        //        if (sockfd == -1) {
        //            printf("socket creation failed...\n");
        //            exit(0);
        //        }
        //        else
        //            printf("Socket successfully created..\n");
        //        bzero(&servaddr, sizeof(servaddr));
        //
        //        // assign IP, PORT
        //        servaddr.sin_family = AF_INET;
        //        servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
        //        servaddr.sin_port = htons(PORT);
        //
        //        // connect the client socket to server socket
        //        if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr))
        //            != 0) {
        //            printf("connection with the server failed...\n");
        //            exit(0);
        //        }
        //        else
        //            printf("h8i connected to the server..\n");
        //
        //        // function for chat
        //        char buff[MAX];
        //        int n;
        //        strcpy(buff, "start");
        //
        //        bzero(buff, sizeof(buff));
        //        write(sockfd, buff, sizeof(buff));
        //        write(sockfd, buff, sizeof(buff));
        //        printf("Enter the restaurant's name : ");
        //        n = 0;
        //        while ((buff[n++] = getchar()) != '\n')
        //            ;
        //        write(sockfd, buff, sizeof(buff));
        //        strcpy(buff, "order");
        //        write(sockfd, buff, sizeof(buff));
        //
        //        for (;;) {
        //            bzero(buff, sizeof(buff));
        //            read(sockfd, buff, sizeof(buff));
        //            printf("From Server : %s", buff);
        //
        //            if ((strncmp(buff, "confirmed", 4)) == 0) {
        //                printf("Client Exit...\n");
        //
        //                strcpy(buff, "end");
        //                write(sockfd, buff, sizeof(buff));
        //                break;
        //            }
        //        }
        //
        //        // close the socket
        //        close(sockfd);
        
        //         int sockfd, connfd;
        //     struct sockaddr_in servaddr, cli;
        //
        //     // socket create and verification
        //     sockfd = socket(AF_INET, SOCK_STREAM, 0);
        //     if (sockfd == -1) {
        //         printf("socket creation failed...\n");
        //         exit(0);
        //     }
        //     else
        //         printf("Socket successfully created..\n");
        //     bzero(&servaddr, sizeof(servaddr));
        //
        //     // assign IP, PORT
        //     servaddr.sin_family = AF_INET;
        //     servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
        //     servaddr.sin_port = htons(PORT);
        //
        //     // connect the client socket to server socket
        //     if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr))
        //         != 0) {
        //         printf("connection with the server failed...\n");
        //         exit(0);
        //     }
        //     else
        //         printf("connected to the server..\n");
        //
        //     // function for chat
        //     //func(sockfd);
        //     char buff[MAX];
        //     int n;
        //     for (;;) {
        //         bzero(buff, sizeof(buff));
        //         printf("Enter the string : ");
        //         n = 0;
        //         while ((buff[n++] = getchar()) != '\n')
        //             ;
        //         write(sockfd, buff, sizeof(buff));
        //         bzero(buff, sizeof(buff));
        //         read(sockfd, buff, sizeof(buff));
        //         printf("From Server : %s", buff);
        //         if ((strncmp(buff, "exit", 4)) == 0) {
        //             printf("Client Exit...\n");
        //             break;
        //         }
        //     }
        //
        //     // close the socket
        //     close(sockfd);
        
        //        int sockfd, connfd;
        //        struct sockaddr_in servaddr, cli;
        //
        //        // socket create and verification
        //        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        //        if (sockfd == -1) {
        //            printf("socket creation failed...\n");
        //            exit(0);
        //        }
        //        else
        //            printf("Socket successfully created..\n");
        //        bzero(&servaddr, sizeof(servaddr));
        //
        //        // assign IP, PORT
        //        servaddr.sin_family = AF_INET;
        //        servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
        //        servaddr.sin_port = htons(PORT);
        //
        //        // connect the client socket to server socket
        //        if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr))
        //            != 0) {
        //            printf("connection with the server failed...\n");
        //            exit(0);
        //        }
        //        else
        //            printf("connected to the server..\n");
        //
        //        // function for chat
        //        char buff[MAX];
        //        int n;
        //        //    for (;;) {
        //        bzero(buff, sizeof(buff));
        //        printf("start");
        //        //        printf("Enter the string : ");
        //        //        n = 0;
        //        //        while ((buff[n++] = getchar()) != '\n')
        //        //            ;
        //        strcpy(buff, "start");
        //        write(sockfd, buff, sizeof(buff));
        //
        //        bzero(buff, sizeof(buff));
        //        printf("enter restaurant name: ");
        //        n = 0;
        //        while ((buff[n++] = getchar()) != '\n');
        //        //        printf("Enter the string : ");
        //        //        n = 0;
        //        //        while ((buff[n++] = getchar()) != '\n')
        //        //            ;
        //        write(sockfd, buff, sizeof(buff));
        //
        //        for (;;){
        //            bzero(buff, sizeof(buff));
        //            read(sockfd, buff, sizeof(buff));
        //            printf("From Server : %s", buff);
        //
        //            if ((strncmp("confirmed", buff, 4)) == 0) {
        //                printf("Client Exit...\n");
        //                break;
        //            }
        //        }
        //        //    }
        //
        //        // close the socket
        //        close(sockfd);
        
        system("gcc client.c -o c.out");// DONE BY SOHAM PAWAR IMT2022127
        system("./c.out");
        
        
        
        // DONE BY SIDDHARTH PALOD IMT2022002
        
        //Happens only if order is confirmed , if order is not confirmed, code exits!!
        //Code for timer display after confirmation of order
        int minutes, seconds;
        minutes = time / 60;
        seconds = (int)time % 60;
        char final[50];
        printf("Press any key to Continue\n");
        scanf("%s", final);
        
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
    
    	feedback();

    }
        fclose(fptr);
    
    
    return 0;
    
    }
