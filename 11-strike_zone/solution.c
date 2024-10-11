#include <stdio.h>
#include <math.h>

void print_bar(int size, float progress, int strike_zone) {
    int i, start, end;
    
    // Calculate the start and end of the strike zone
    start = round(size / 2.0 - strike_zone / 2.0);
    end = round(size / 2.0 + strike_zone / 2.0);

    // Print the bar
    printf("|");
    for (i = 0; i < size; i++) {
        if (i == start) {
            printf("[");
        }
        if (i >= progress * size && i < end) {
            printf(" ");
        } else if (i < progress * size) {
            printf("=");
        } else {
            printf(" ");
        }
        if (i == end - 1) {
            printf("]");
        }
    }
    printf("|\n");
}

int main(int argc, char *argv[]) {
    print_bar(10, 0.5, 1);
    print_bar(10, 0.5, 2);
    print_bar(10, 0.5, 4);
    print_bar(15, 0.3, 4);
    return 0;
}
