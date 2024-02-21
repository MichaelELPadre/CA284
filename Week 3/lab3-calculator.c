#include <string.h>
#include <stdlib.h>
#include <stdio.h>

float multi(float number1, float number2) {
    float result = number1 * number2;
    return result;
}

float divide(float number1, float number2) {
    float result = number1 / number2;
    return result;
}

int main(int argc, char *argv[]) {
    char *string = argv[1];
    float number1 = atof(argv[2]);
    float number2 = atof(argv[3]);
    float result;

    if (number2 == 0) {
        printf("invalid\n");
    } else {
        if (strcmp(string, "multiply") == 0) {
            result = multi(number1, number2);
            printf("%f\n", result);
        } else {
            result = divide(number1, number2);
            printf("%f\n", result);
        }
    }

    return 0;
}
