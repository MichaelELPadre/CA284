#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int result = 0;
    int tryy = 0;
    int conversion = 0;
    int penalty = 0;
    int dropgoal = 0;

    do {
        printf("number of tries: ");
        scanf("%d", &tryy);
        result += tryy * 5;
    } while (tryy < 0);

    do {
        printf("number of conversions: ");
        scanf("%d", &conversion);
        result += conversion * 2;
    } while (conversion < 0);

    do {
        printf("number of penalties: ");
        scanf("%d", &penalty);
        result += penalty * 3;
    } while (penalty < 0);

    do {
        printf("number of dropgoals: ");
        scanf("%d", &dropgoal);
        result += dropgoal * 3;
    } while (dropgoal < 0);

    printf("%d\n", result);
    return 0;
}
