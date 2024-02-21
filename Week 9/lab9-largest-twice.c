#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void sort(int *list, int len);
int large_times(int *list, int len);

int main(int argc, char *argv[]) {
    int len = argc - 1;
    int *list = calloc(len, sizeof(int));
    for (int i = 0; i < len; ++i) {
        list[i] = atoi(argv[i + 1]);
    }
    sort(list, len);
    int result = large_times(list, len);
    printf("%d\n", result);
    free(list);
    return 0;
}

int large_times(int *list, int len) {
    if (len >= 2 && list[0] >= list[1] * 2) {
        return list[0];
    }
    return 0;
}

void sort(int *list, int len) {
    // Using quicksort for more efficient sorting
    qsort(list, len, sizeof(int), compare);
}

// Comparison function for qsort
int compare(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}
