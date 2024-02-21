#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int tryy = 0;
    int conversion = 0;
    int penalty = 0;
    int dropgoal = 0;

    tryy = atoi(argv[1]);
    conversion = atoi(argv[2]);
    penalty = atoi(argv[3]);
    dropgoal = atoi(argv[4]);

    int result = (tryy * 5 + conversion * 2 + penalty * 3 + dropgoal * 3);
    printf("%d\n", result);

    return 0;
}
