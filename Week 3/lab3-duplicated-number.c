#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int duplicate(int numbers[], int length) {
    for (int i = 0; i < length - 1; ++i) {
        for (int j = i + 1; j < length; ++j) {
            if (numbers[i] == numbers[j])
                return numbers[i];
        }
    }
    return 0;
}

int main(int argc, char *argv[]) {
    int len = argc - 1;
    int numbers[len];
    for (int i = 0; i < len; ++i) {
        numbers[i] = atoi(argv[i + 1]);
    }
    int dup = duplicate(numbers, len);

    if (dup == 0) {
        printf("no duplicated number\n");
    } else {
        printf("%d\n", dup);
    }

    return 0;
}
