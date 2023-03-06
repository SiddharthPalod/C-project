// Owner's code as the server code

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#include"all.h"
#include"datatypes.c"
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h> // read(), write(), close()
#define MAX 80
#define PORT 8080
#define SA struct sockaddr

char id[23];

// Function designed for chat between client and server.
void func(int connfd, int flag)
{
    char buff[MAX];
    int n;
    // infinite loop for chat
    for (;;) {
        bzero(buff, MAX);
        
        // read the message from client and copy it in buffer
        read(connfd, buff, sizeof(buff));
        // print buffer which contains the client contents
        printf("From client: %s\t To client : ", buff);
        bzero(buff, MAX);
        n = 0;
        // copy server message in the buffer
//        while ((buff[n++] = getchar()) != '\n')
//            ;
        
        if (flag == 1) {
            strcpy(buff, "confirmed");
        }
        else {
            strcpy(buff, "some message");
        }
        
        // and send that buffer to client
        write(connfd, buff, sizeof(buff));
        
        // if msg contains "Exit" then server exit and chat ended.
        if (strncmp("confirmed", buff, 4) == 0) {
            printf("Server Exit...\n");
            break;
        }
    }
}

int main(int argc, char * argv[]){
    if (argc == 1 || argc > 2 ){
        printf("Run as ./a.out owner");
        exit(1);
    }
    if (strcmp(argv[1], "customer") != 0 && strcmp(argv[1], "owner") != 0){
        printf("Run as ./a.out owner");
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
    
    if(k==1 && strcmp(argv[1],"owner") ==0)
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
    
    if (strcmp(argv[1], "owner") == 0){
        // printf("Welcome owner, type help to see what u can do.\n, U can also type commands if u already know how to work!\n");
        if (strcmp(command ,"help") == 0){
            printf("Whatever stuff\n");
        }
        else if(strcmp(command, "continue") == 0){
            strcpy(r1.name, f2());
            printf("%s", r1.name);
            
            // Server's code:
            
            int sockfd, connfd, len;
            struct sockaddr_in servaddr, cli;
            
            // socket create and verification
            sockfd = socket(AF_INET, SOCK_STREAM, 0);
            if (sockfd == -1) {
                printf("socket creation failed...\n");
                exit(0);
            }
            else
                printf("Socket successfully created..\n");
            bzero(&servaddr, sizeof(servaddr));
            
            // assign IP, PORT
            servaddr.sin_family = AF_INET;
            servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
            servaddr.sin_port = htons(PORT);
            
            // Binding newly created socket to given IP and verification
            if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) {
                printf("socket bind failed...\n");
                exit(0);
            }
            else
                printf("Socket successfully binded..\n");
            
            // Now server is ready to listen and verification
            if ((listen(sockfd, 5)) != 0) {
                printf("Listen failed...\n");
                exit(0);
            }
            else
                printf("Server listening..\n");
            len = sizeof(cli);
            
            // Accept the data packet from client and verification
            connfd = accept(sockfd, (SA*)&cli, &len);
            if (connfd < 0) {
                printf("server accept failed...\n");
                exit(0);
            }
            else
                printf("server accept the client...\n");
            
            // Function for chatting between client and server
            func(connfd, 1);
            
            // After chatting close the socket
            close(sockfd);
            
            //
        }
    }
    
    else {
        printf("Please run code with command './a.out customer' or './a.out owner'");
        exit(0);
    }
    fclose(fptr);
    
    
    return 0;
}
