#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int count(char target, char const *string) {
    int len = strlen(string);
    int count = 0;
    for (int i = 0; i < len; ++i) {
        if (string[i] == target) {
            count += 1;
        }
    }
    return count;
}

int main(int argc, char *argv[]) {
    char letter = *argv[1];
    char *string = argv[2];
    int result = count(letter, string);
    printf("%d\n", result);
    return 0;
}
