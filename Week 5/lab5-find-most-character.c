#include <stdio.h>
#include <string.h>
#include <ctype.h>

int most_frequent(char letter, int array[256], int *max, char *result) {
    array[letter]++;
    if (*max < array[letter]) {
        *max = array[letter];
        *result = letter;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    char *string = argv[1];
    int array[256] = {0};
    char result;
    int max = 0;
    for (int i = 0; i < strlen(string); i++) {
        if (isgraph(string[i])) {
            most_frequent(string[i], array, &max, &result);
        }
    }
    printf("%c\n", result);
    return 0;
}
