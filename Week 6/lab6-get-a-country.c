#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Country {
    char *name;
    char *city;
    float pop;
    int size;
};

void statement(struct Country example) {
    printf("Country: %s\n", example.name);
    printf("Capital City: %s\n", example.city);
    printf("Population: %.2f million people\n", example.pop);
    printf("Size: %d km2\n", example.size);
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        printf("Usage: %s <country_name> <capital_city> <population> <size>\n", argv[0]);
        return 1;
    }

    struct Country random;
    random.name = strdup(argv[1]);  // Allocate memory and copy country name
    random.city = strdup(argv[2]);  // Allocate memory and copy city name
    random.pop = atof(argv[3]);      // Convert population string to float
    random.size = atoi(argv[4]);     // Convert size string to integer

    statement(random);

    // Free allocated memory
    free(random.name);
    free(random.city);

    return 0;
}
