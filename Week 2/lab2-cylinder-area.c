#include <stdio.h>
#include <stdlib.h>
#define PI 3.1415

int main(int argc, char *argv[]) {
    int radius = atoi(argv[1]);
    int height = atoi(argv[2]);
    int radius_squared = radius * radius;

    if (argc != 3) {
        if (argc == 1) {
            printf("No input given!\n");
        } else if (argc == 2) {
            printf("Two arguments needed!\n");
        } else {
            printf("Too many arguments\n");
        }
    }

    double area = (2 * PI * radius * height) + (2 * PI * radius_squared);

    if (radius < 0 || height < 0) {
        printf("The radius or height cannot be negative!\n");
    } else {
        printf("%.2f\n", area);
    }

    return 0;
}
