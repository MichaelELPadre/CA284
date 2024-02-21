//author: Michael Hanley Sanchez


#include <string.h>
#include <stdlib.h>
#include <stdio.h>

float largest(float numbers[], int len) {
    float max = numbers[0];
    for (int i = 1; i < len; ++i) {
        if (max < numbers[i]) {
            max = numbers[i];
        }
    }
    return max;
}

float smallest(float numbers[], int len) {
    float min = numbers[1];
    for (int i = 1; i < len; ++i) {
        if (min > numbers[i]) {
            min = numbers[i];
        }
    }
    return min;
}

int main(int argc, char *argv[]) {
    int len = argc - 2;
    float numbers[len];
    char string[50];
    strcpy(string, argv[1]);
    for (int i = 1; i < len; ++i) {
        numbers[i] = atof(argv[i + 1]);
    }

    if (strcmp(string, "largest") == 0) {
        float result = largest(numbers, len);
        printf("%.2f\n", result);
    } else if (strcmp(string, "smallest") == 0) {
        float result = smallest(numbers, len);
        printf("%.2f\n", result);
    }

    return 0;
}
