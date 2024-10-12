#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void print_bar(int size, float progress, int strike_zone) {
    int i, start, end;
    
    // Calculate the start and end of the strike zone
    start = round(size / 2.0 - strike_zone / 2.0);
    end = round(size / 2.0 + strike_zone / 2.0);

    printf("start: %d, end: %d\n", start, end);

    // Print the bar
    printf("|");
    for (i = 0; i < size; i++) {
        if (i == start) {
            printf("[");
        }
        if (i == end) {
            printf("]");
        } 
        if (i < progress * size) {
            printf("=");
        } else {
            printf(" ");
        }
    }
    printf("|\n");
}

int main(int argc, char *argv[]) {
    
    

    int size = atoi(argv[1]);
    float progress = atof(argv[2]);
    int zone_width = atoi(argv[3]);

    print_bar(size, progress, zone_width);

    for (int i = 0; i < 100; i++) {
        float progress = (float)i / 100;
        print_bar(100, progress, 10);
    }
    
    return 0;
}
