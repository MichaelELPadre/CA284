#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int maximum(int numbers[], int len) {
    int i = 0;
    int max = 0;
    for (i; i < len; ++i) {
        if (max < numbers[i]) {
            max = numbers[i];
        }
    }
    return max;
}

int main(int argc, char *argv[]) {
    int len = argc - 1;
    int numbers[len];
    for (int i = 0; i < len; ++i) {
        numbers[i] = atoi(argv[i + 1]);
    }
    int result = maximum(numbers, len);
    printf("%d\n", result);
    return 0;
}
