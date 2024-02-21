#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int search(int target, int numbers[], int len) {
    int i = 0;
    for (i; i < len; ++i) {
        if (numbers[i] == target) {
            return i;
        }
    }
    if (i == len) {
        return 0;
    }
}

int main(int argc, char *argv[]) {
    int len = argc - 1;
    int target = atoi(argv[1]);
    int numbers[len];
    for (int i = 1; i < len; ++i) {
        numbers[i] = atoi(argv[i + 1]);
    }
    int result = search(target, numbers, len);
    if (result == 0) {
        printf("%d not found\n", target);
    } else {
        int new_result = result - 1;
        printf("Found %d at %d\n", target, new_result);
    }
    return 0;
}
