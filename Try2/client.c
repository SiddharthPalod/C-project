#include <arpa/inet.h> // inet_addr()
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h> // bzero()
#include <sys/socket.h>
#include <unistd.h> // read(), write(), close()
#define MAX 80
#define PORT 8080
#define SA struct sockaddr
//void func(int sockfd)
//{
//    char buff[MAX];
//    int n;
//    for (;;) {
//        bzero(buff, sizeof(buff));
//        printf("Enter the string : ");
//        n = 0;
//        while ((buff[n++] = getchar()) != '\n')
//            ;
//        write(sockfd, buff, sizeof(buff));
//        bzero(buff, sizeof(buff));
//        read(sockfd, buff, sizeof(buff));
//        printf("From Server : %s", buff);
//        if ((strncmp(buff, "exit", 4)) == 0) {
//            printf("Client Exit...\n");
//            break;
//        }
//    }
//}

struct oitem{
    char name[20];
    int qty;
    int price;
    struct oitem * next;
};

struct item{
    char name[20];
    int no;
    int price;
    struct item * next;
};

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

int main()
{
    int sockfd, connfd;
    int count = 0;
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
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_port = htons(PORT);
    
    struct oitem * order = (struct oitem*) malloc(1 * sizeof(struct oitem));
    
    // connect the client socket to server socket
    if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr))
        != 0) {
        printf("connection with the server failed...\n");
        exit(0);
    }
    else
        printf("connected to the server..\n");
    
    // function for chat
    char buff[MAX];
    int n;
    //    for (;;) {
    bzero(buff, sizeof(buff));
    printf("start");
    //        printf("Enter the string : ");
    //        n = 0;
    //        while ((buff[n++] = getchar()) != '\n')
    //            ;
    strcpy(buff, "start");
    write(sockfd, buff, sizeof(buff));
    
    bzero(buff, sizeof(buff));
    printf("enter restaurant name: ");
    n = 0;
    while ((buff[n++] = getchar()) != '\n');
    //        printf("Enter the string : ");
    //        n = 0;
    //        while ((buff[n++] = getchar()) != '\n')
    //            ;
    write(sockfd, buff, sizeof(buff));
    
    FILE* common;
    common = fopen("common.txt", "w");
    
    struct oitem * temp;
    
    fprintf(common, "%d\n", count);
    temp = order;
    for(int i=0; temp != NULL; temp=temp->next){
        fprintf(common, "%15s %5d %3d %5d\n", temp->name, temp->price, temp->qty, temp->qty * temp->price);
        
    }
    printf("Done writing to file.");
    fclose(common);
    
    for (;;){
        bzero(buff, sizeof(buff));
        read(sockfd, buff, sizeof(buff));
        printf("From Server : %s", buff);
        
        if ((strncmp("Y", buff, 4)) == 0) {
            printf("Confirmed from owner.");
            break;
        }
        
        if ((strncmp("N", buff, 4)) == 0) {
            printf("Order confirmation denied!!");
            break;
        }
        
    }
    //    }
    
    // close the socket
    close(sockfd);
}
