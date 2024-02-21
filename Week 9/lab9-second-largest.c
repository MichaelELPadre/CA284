#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void second_largest(int length, float *list, float *sec);

int main(int argc, char* argv[]) {
    int len = argc - 1;
    float *list = calloc(len, sizeof(float));
    for (int i = 0; i < len; i++) {
        *(list + i) = atof(argv[i + 1]);
    }
    float second_largest_number = 0;
    second_largest(len, list, &second_largest_number);
    printf("%.1f\n", second_largest_number);
    free(list); // Free dynamically allocated memory
    return 0;
}

void second_largest(int len, float *list, float *sec) {
    float largest = list[0];
    float secondLargest = list[1];
    if (secondLargest > largest) {
        float temp = largest;
        largest = secondLargest;
        secondLargest = temp;
    }
    for (int i = 2; i < len; i++) {
        if (list[i] > largest) {
            secondLargest = largest;
            largest = list[i];
        } else if (list[i] > secondLargest) {
            secondLargest = list[i];
        }
    }
    *sec = secondLargest;
}
