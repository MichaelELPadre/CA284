#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    char *string = argv[1];
    char *word = argv[2];
    char *result = strstr(string, word);
    if (result) {
        int position = result - string;
        printf("%d %lu\n", position, position + (strlen(word) - 1));
    }
    return 0;
}
