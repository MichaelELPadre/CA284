#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float sum(int a, int b) {
    return a + b;
}

float diff(int a, int b) {
    return a - b;
}

float prod(int a, int b) {
    return a * b;
}

float dev(int a, int b) {
    if (b != 0) {
        return (float)a / b;
    } else {
        return INFINITY; // Return infinity for division by zero
    }
}

float power(int a, int b) {
    return pow(a, b);
}

float logarth(int a, int b) {
    if (a > 0 && b > 0) {
        return log10(a) + log10(b);
    } else {
        return NAN; // Return NaN for negative values
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <number1> <number2>\n", argv[0]);
        return 1;
    }

    int number1 = atoi(argv[1]);
    int number2 = atoi(argv[2]);

    float (*functions[])(int, int) = {sum, diff, prod, dev, power, logarth};
    const char *operations[] = {"sum", "difference", "product", "quotient", "power", "logarithm"};

    for (int i = 0; i < sizeof(functions) / sizeof(functions[0]); ++i) {
        printf("%s: %.2f\n", operations[i], functions[i](number1, number2));
    }

    return 0;
}
