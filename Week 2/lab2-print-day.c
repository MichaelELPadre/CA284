#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int number = atoi(argv[1]);

    if (number == 1) {
        printf("Sunday\n");
    } else if (number == 2) {
        printf("Monday\n");
    } else if (number == 3) {
        printf("Tuesday\n");
    } else if (number == 4) {
        printf("Wednesday\n");
    } else if (number == 5) {
        printf("Thursday\n");
    } else if (number == 6) {
        printf("Friday\n");
    } else if (number == 7) {
        printf("Saturday\n");
    }

    return 0;
}
