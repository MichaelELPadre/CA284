#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void calculateTotal(int *pTotal, int *pV1, int *pV2, int n);

int main(int argc, char*argv[])
{
    int number = atoi(argv[1]);
    int *vector1 = calloc(number, sizeof(int));
    int *vector2 = calloc(number, sizeof(int));
    for (int i = 0; i < number; i++)
    {
        *(vector1 + i) = atoi(argv[2 + i]);
        *(vector2 + i) = atoi(argv[2 + i + number]);
    }
    int total = 0;
    calculateTotal(&total, vector1, vector2, number);
    printf("%d\n", total);
    return 0;
}

void calculateTotal(int *total, int *vector1, int *vector2, int n)
{
    for (int i = 0; i < n; i++)
    {
        *total += (vector1[i]) * (vector2[i]);
    }
}
