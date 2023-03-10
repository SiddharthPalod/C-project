#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h> // read(), write(), close()
#define MAX 80
#define PORT 8080
#define SA struct sockaddr

// Function designed for chat between client and server.
//void func(int connfd)
//{
//    char buff[MAX];
//    int n;
//    // infinite loop for chat
//    for (;;) {
//        bzero(buff, MAX);
//
//        // read the message from client and copy it in buffer
//        read(connfd, buff, sizeof(buff));
//        // print buffer which contains the client contents
//        printf("From client: %s\t To client : ", buff);
//        bzero(buff, MAX);
//        n = 0;
//        // copy server message in the buffer
//        while ((buff[n++] = getchar()) != '\n')
//            ;
//
//        // and send that buffer to client
//        write(connfd, buff, sizeof(buff));
//
//        // if msg contains "Exit" then server exit and chat ended.
//        if (strncmp("exit", buff, 4) == 0) {
//            printf("Server Exit...\n");
//            break;
//        }
//    }
//}

// Driver function
int main(int argc, char* argv[])
{
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
        printf("server accepted the client...\n");
    
    // Function for chatting between client and server
    char buff[MAX];
    int n;
    // infinite loop for chat
    //    for (;;) {
    bzero(buff, MAX);
    
    // read the message from client and copy it in buffer
    read(connfd, buff, sizeof(buff));
    // print buffer which contains the client contents
    printf("From client: %s\t", buff);
    
    bzero(buff, MAX);
    
    // read the message from client and copy it in buffer
    read(connfd, buff, sizeof(buff));
    // print buffer which contains the client contents
    printf("From client : %s\t", buff);
    //printf("\n %s\n", argv[1]);

    
    if (strncmp(buff, argv[1], 3) == 0) {
        printf("New Order recieved : \n");
        system("cat common.txt");
    
        //        printf("\nFile will be opened here...\n");
        //        printf("%s\n", buff);
        
        // FILE* common;
        // common = fopen("common.txt", "r");
        
        // int count = 0;
        // fscanf(common, "%d", &count);
        
        // printf("count: %d\n", count);
        
        // printf("%15s %5s %3s %5s\n", "item", "price", "qty", "Total");
        
        // for (int i = 0; i < count; i++) {
        //     char name[20];
        //     char price[1000];
        //     char qty[1000];
        //     char total[5000];
            
        //     fscanf(common, "%15s %5s %3s %5s\n", name, price, qty, total);
        //     printf("%15s %5s %3s %5s\n", name, price, qty, total);
        // }
        // fclose(common);
        
    
    
    bzero(buff, MAX);
    //        n = 0;
    //        // copy server message in the buffer
    //        while ((buff[n++] = getchar()) != '\n')
    //            ;
    
    // and send that buffer to client
    
    char response;
    
    printf("\nDo you confirm the order? Enter 'Y' for yes and 'N' for no: ");
    scanf("%s", &response);
    
    if (response == 'Y') {
        printf("Yes chosen.");
        
        //                resend.flag = '2';
        //                resend.mesg_type = 1;
        
        strcpy(buff, "Y");
        
    } else if (response == 'N') {
        printf("No chosen.");
        
        //                resend.flag = '3';
        //                resend.mesg_type = 1;
        
        strcpy(buff, "N");
        
    } else {
        printf("Invalid input!!");
    }
    write(connfd, buff, sizeof(buff));
    }
    
    // if msg contains "Exit" then server exit and chat ended.
    //        if (strncmp("exit", buff, 4) == 0) {
    //            printf("Server Exit...\n");
    //        }
    //    }
    
    // After chatting close the socket
    close(sockfd);
}