#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int odds = 0;
    int number = 0;

    for (int i = 1; i < argc; ++i) {
        number = atoi(argv[i]);
        if (number % 2 == 1) {
            odds += 1;
        }
    }

    printf("%d\n", odds);

    return 0;
}
