#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int measure = 0;

    measure = atoi(argv[1]);
    float inches = measure / 2.54; // This line performs integer division

    // Corrected calculation
    float inches_corrected = measure / 2.54;

    printf("%.2f\n", inches_corrected);
    return 0;
}
