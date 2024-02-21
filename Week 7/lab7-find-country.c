#include <stdio.h>
#include <stdlib.h>

typedef struct Find_a_country {
    char *name;
    char *capital;
    float pop;
    int size;
} Find;

void to_print(char *name, char *cap, float pop, int size) {
    printf("%-20s %-20s %-10d %.2f\n", name, cap, size, pop);
}

int size_checker(int size) {
    return (size < 100000) ? 1 : 0;
}

int main(int argc, char *argv[]) {
    if ((argc - 1) % 4 != 0) {
        printf("Invalid number of arguments.\n");
        return 1;
    }

    int numCountries = (argc - 1) / 4;
    Find country[50];
    int total = 0;

    for (int i = 1; i < argc; i += 4) {
        country[total].name = argv[i];
        country[total].capital = argv[i + 1];
        country[total].pop = atof(argv[i + 2]);
        country[total].size = atoi(argv[i + 3]);
        total += 1;
    }

    printf("%-20s %-20s %-10s %s\n", "Country", "Capital", "Size", "Population");
    for (int i = 0; i < total; ++i) {
        if (size_checker(country[i].size)) {
            to_print(country[i].name, country[i].capital, country[i].pop, country[i].size);
        }
    }

    return 0;
}
