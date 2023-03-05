//Code contributor: Siddharth Palod
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void main() {
    int duration;
    int minutes, seconds;
    //remove it with time calculated using distance
        printf("Enter the duration of the timer in seconds: ");
        scanf("%d", &duration);

    minutes = duration / 60;
    seconds = duration % 60;

    while (duration >= 0) {
        system("clear");
        printf("%02d:%02d\n", minutes, seconds);
        sleep(1); // wait for 1 second

        seconds--;
        if (seconds < 0) {
            minutes--;
            seconds = 59;
        }
        duration--;
        //any other thing which needs to be displayed at that time add in this loop
    }

    printf("Time's up!\a\n"); // sound alarm
}
