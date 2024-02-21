#include <stdio.h>
#include <stdlib.h>

#define MAX_COUNTRIES 50

struct Country {
    char name[100];
    char capital[100];
    double population;
    int size;
};

void printCountry(struct Country country) {
    printf("%-20s %-20s %-10d %.2f\n", country.name, country.capital, country.size, country.population);
}

int main(int argc, char *argv[]) {
    if ((argc - 1) % 4 != 0 || (argc - 1) / 4 > MAX_COUNTRIES) {
        printf("Invalid number of arguments or exceeds maximum number of countries.\n");
        return 1;
    }

    int numCountries = (argc - 1) / 4;
    struct Country countries[MAX_COUNTRIES];

    for (int i = 0; i < numCountries; i++) {
        int argIndex = 1 + i * 4;
        snprintf(countries[i].name, sizeof(countries[i].name), "%s", argv[argIndex]);
        snprintf(countries[i].capital, sizeof(countries[i].capital), "%s", argv[argIndex + 1]);
        countries[i].population = atof(argv[argIndex + 2]);
        countries[i].size = atoi(argv[argIndex + 3]);
    }

    printf("%-20s %-20s %-10s %s\n", "Country", "Capital", "Size", "Population");
    for (int i = 0; i < numCountries; i++) {
        printCountry(countries[i]);
    }

    return 0;
}
