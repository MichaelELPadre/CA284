#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Country Country;
typedef struct City City;

struct City {
    char *cityName;
    float citySize;
};

struct Country {
    char *name;
    City cities[3];
};

Country addCountry(char **argv, int *index);
void print_cities(Country *c);

int main(int argc, char *argv[]) {
    int index = 1;
    int country_num = (argc - 1) / 7;
    Country countries[country_num];

    for (int i = 0; i < country_num; i++) {
        countries[i] = addCountry(argv, &index);
    }

    /* 
    for (int i = 0; i < country_num; i++) {
        print_country(countries[i]);
    }
    */

    for (int i = 0; i < country_num; i++) {
        print_cities(&countries[i]);
    }

    return 0;
}

Country addCountry(char **argv, int *index) {
    Country c;
    c.name = argv[*index];
    for (int i = 0; i < 3; i++) {
        c.cities[i].cityName = argv[*index + 1];
        c.cities[i].citySize = atoi(argv[*index + 2]);
        *index += 2;
    }
    *index += 1;
    return c;
}

void print_cities(Country *c) {
    char *first_city = c->cities[0].cityName;
    float first_size = c->cities[0].citySize;
    for (int i = 1; i < 3; i++) {
        if (first_size < c->cities[i].citySize) {
            first_size = c->cities[i].citySize;
            first_city = c->cities[i].cityName;
        }
    }
    printf("%s: %s\n", c->name, first_city);
}
