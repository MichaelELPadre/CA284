#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void longest_word(char *token, char *longest, char str[]) {
    token = strtok(str, " ");
    strcpy(longest, token);
    while (token != NULL) {
        if (strlen(token) > strlen(longest)) { // Corrected the comparison
            strcpy(longest, token);
        }
        token = strtok(NULL, " ");
    }
}

int main(int argc, char *argv[]) {
    char str[strlen(argv[1])];
    char *token;
    char longest[20];
    strcpy(str, argv[1]);
    longest_word(token, longest, str);
    printf("%s\n", longest);
    return 0;
}
