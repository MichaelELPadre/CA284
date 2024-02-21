#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int sorted(int numbers[], int len) {
    int temp;
    int sort;
    do {
        sort = 0;
        for (int i = 0; i < len - 1; i++) {
            if (numbers[i] > numbers[i + 1]) {
                sort = 1;
                temp = numbers[i];
                numbers[i] = numbers[i + 1];
                numbers[i + 1] = temp;
            }
        }
    } while (sort == 1);
}

int main(int argc, char *argv[]) {
    int len = argc - 1;
    int numbers[len];
    for (int i = 0; i < len; i++) {
        numbers[i] = atoi(argv[i + 1]);
    }

    sorted(numbers, len);

    for (int i = 0; i < len; i++) {
        printf("%d\n", numbers[i]);
    }
    
    return 0;
}
