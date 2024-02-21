#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int evens = 0;
    
    for (int i = 1; i < argc; i++) {
        if (atoi(argv[i]) % 2 == 0) {
            int j = i - 1;
            printf("%d - %d\n", j, atoi(argv[i]));
            evens = evens + 1;
        }
    }
    
    if (evens == 0) {
        printf("Not found!\n");
    }
    
    return 0;
}
