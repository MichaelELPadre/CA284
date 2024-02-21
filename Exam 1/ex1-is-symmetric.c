#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//Author: Michael Hanley Sanchez

int symmetric(char string[], int length) {
    for (int i = 0; string[i] == string[length - i - 1]; ++i) {
        if (i > length / 2 + 1) {
            printf("yes\n");
            return 0;
        }
    }
    printf("no\n");
}

int main(int argc, char *argv[]) {
    int length = strlen(argv[1]);
    char string[length];
    strcpy(string, argv[1]);
    symmetric(string, length);
    return 0;
}
