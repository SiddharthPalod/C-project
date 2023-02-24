//Code contributor: Siddharth Palod
#include <stdio.h>
#include <time.h>

int main() {
    int duration = 15; // in seconds
    time_t start_time;
    time_t end_time;
    int order_placed = 0;
    int order_delivered = 0;

    // Simulated event: order is placed
    order_placed = 1;

    if (order_placed) {
        start_time = time(NULL);
        end_time = start_time + duration;

        while (!order_delivered && time(NULL) < end_time) {
            // Check for event: order delivered
            // If order delivered, set order_delivered = 1 to exit loop
        }
    }
    while (time(NULL) < end_time) {
        // wait for the timer to finish
    }
    printf("Timer has finished!\n");
    //Prints 
    return 0;
}

