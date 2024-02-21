#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int number = 0;
    number = atoi(argv[1]);

    for (int j = 0; j < number; ++j) {
        printf("*");
    }
    printf("\n");

    for (int i = 0; i < (number - 2); ++i) {
        for (int j = 0; j < number; ++j) {
            if ((j == 0) || (j == number - 1))
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }

    for (int j = 0; j < number; ++j) {
        printf("*");
    }
    printf("\n");

    return 0;
}
