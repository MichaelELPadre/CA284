#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void leap_years(int start, int end) {
    int year = start;
    while (year <= end) {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            printf("%d\n", year);
        }
        year++;
    }
}

int main(int argc, char *argv[]) {
    int start = atoi(argv[1]);
    int end = atoi(argv[2]);
    leap_years(start, end);
    return 0;
}
