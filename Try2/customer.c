#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <unistd.h>

void main(){
    float time=5;
    int minutes, seconds;
    minutes = time / 60;
    seconds = (int)time % 60;

    while (time >= 0) {
        system("clear");
        printf("%02d:%02d\n", minutes, seconds);
        //if time more than 50        
        printf("       __            \t\t\t\t\n");     
        printf("      /__|__         \t\t\t\t");     printf("        .______.                    \n");
        printf("      \\\\  /          \t\t\t\t");   printf("  ._____| _]>  |_______________.    \n");
        printf("        /|__         \t\t\t\t");     printf("  |-----|______|---------------|    \n");
        printf(" .___.  |,` T__,./   \t\t\t\t");     printf("  |  __          __________    |    \n");
        printf("/    |_-.\\\\ _    --. \t\t\t\t");   printf("  | |__|   __   |RESTAURANT|   |    \n");
        printf("\\ ____,'  `))`___,-' \t\t\t\t");    printf("  |=======|  |=================|    \n");  
        printf(" `\\_./ '--'  \\_./ _ _ _   _ _ _   _ _ _  _ _  _ _ |_______[  ]_________________|    \n");

        sleep(1); // wait for 1 second

        seconds--;
        if (seconds < 0) {
            minutes--;
            seconds = 59;
        }
        time--;
        //any other thing which needs to be displayed at that time add in this loop
    }

    printf("Time's up!\a\n"); // sound alarm
}
