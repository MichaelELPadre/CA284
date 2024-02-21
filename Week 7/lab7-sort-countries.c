#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct Location Location;

struct Location
{
    char *country;
    char *capital;
    float population;
    int size;
};

void location_print(char *country, char *cap, float pop, int s)
{
    printf("%s\t\t\t%s\t\t\t%d\t\t\t%.2f\n", country, cap, s, pop);
}

void bub_sort(Location location[50], int size)
{
    int i = 0;
    int j = 0;
    Location temp;
    for(i = 0; i < size; i++)
    {
        for(j = 0; j < (size - 1); j++)
        {
            if(location[j].population < location[j + 1].population)
            {
                temp = location[j];
                location[j] = location[j + 1];
                location[j + 1] = temp;
            }
        }
    }
}

int main(int argc, char * argv[])
{
    Location location[50];
    int lcount = 0;
    for(int i = 1; i < argc; i += 4)
    {
        location[lcount].country = argv[i];
        location[lcount].capital = argv[i + 1];
        location[lcount].population = atof(argv[i + 2]);
        location[lcount].size = atoi(argv[i + 3]);
        lcount++;
    }
    bub_sort(location, lcount);
    printf("Country\t\t\tCapital\t\t\tSize\t\t\tPopulation\n");
    int count = 0;
    for(int i = 0; i < lcount; i++)
    {
        location_print(location[count].country, location[count].capital, location[count].population, location[count].size); // calling function to print each country
        count++;
    }

    return 0;
}
