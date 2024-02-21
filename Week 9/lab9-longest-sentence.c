#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void findLongest(char **strings, int numStrings);

int main(int argc, char *argv[])
{
    char **strings = (char **)malloc(argc * sizeof(char *));
    for (int i = 1; i < argc; i++)
    {
        strings[i - 1] = (char *)malloc((strlen(argv[i]) + 1) * sizeof(char));
        if (strings[i - 1] == NULL)
        {
            for (int j = 0; j < i - 1; j++)
            {
                free(strings[j]);
            }
            free(strings);
            return 1;
        }
        strcpy(strings[i - 1], argv[i]);
    }
    findLongest(strings, argc - 1);

    for (int i = 0; i < argc - 1; i++)
    {
        free(strings[i]);
    }
    free(strings);
    return 0;
}

void findLongest(char **strings, int numStrings)
{
    int maxLength = 0;
    for (int i = 0; i < numStrings; i++)
    {
        int currentLength = strlen(strings[i]);
        if (currentLength > maxLength)
        {
            maxLength = currentLength;
        }
    }
    for (int i = 0; i < numStrings; i++)
    {
        if (strlen(strings[i]) == maxLength)
        {
            printf("%s\n", strings[i]);
        }
    }
}
