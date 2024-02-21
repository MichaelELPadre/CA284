#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reverse(char string[]) {
    int len = strlen(string);
    int i, j;
    char temp;
    for (i = 0, j = len - 1; i < j; ++i, --j) {
        temp = string[i];
        string[i] = string[j];
        string[j] = temp;
    }
}

int main(int argc, char *argv[]) {
    char String[50];
    strcpy(String, argv[1]);
    reverse(String);
    printf("%s\n", String);
    return 0;
}
