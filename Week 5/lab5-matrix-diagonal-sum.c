#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int Total(int rows, int cols, int array[rows][cols]) {
    int res = 0;
    for (int i = 0; i < rows; i++) {
        res += array[i][i];
    }
    return res;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s n [elements of matrix]\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    int pos = 2;
    if (argc != (2 + n * n)) {
        printf("Invalid number of elements for matrix of size %d\n", n);
        return 1;
    }

    int array[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            array[i][j] = atoi(argv[pos]);
            pos++;
        }
    }

    int result = Total(n, n, array);
    printf("%d\n", result);

    return 0;
}
