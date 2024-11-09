#include <stdio.h>
#include <time.h>

int main() {
    int num_seconds = 0;
    int resolution = 0;
    clock_t start = 0;
    clock_t elapsed_time = 0;
    
    printf("Enter the time limit (in seconds): ");
    scanf("%d", &num_seconds);

    printf("Enter the resolution (in fps): ");
    scanf("%d", &resolution);

    // This is the official starting point.
    start = clock();

    // Calculate the interval in clock ticks based on the desired resolution (fps).
    clock_t interval = CLOCKS_PER_SEC / resolution;
    clock_t next_print_time = interval;

    // Loop while the elapsed time has not reached the desired limit.
    while (elapsed_time < num_seconds * CLOCKS_PER_SEC) {
        elapsed_time = clock() - start;

        // Check if it's time to print the elapsed time based on the interval.
        if (elapsed_time >= next_print_time) {
            // Convert to milliseconds and print
            printf("%ld\n", elapsed_time * 1000 / CLOCKS_PER_SEC);
            next_print_time += interval;  // Set the next time to print
        }
    }

    return 0;
}
