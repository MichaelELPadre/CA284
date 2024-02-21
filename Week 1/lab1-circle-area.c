

/* includes*/
#include <stdio.h>
#include <stdlib.h> /* contains functions we may need*/

#define PI 3.1415 /*Defining PI as a constant*/



int main(int argc, char *argv[])
{
    /* variable initialisation */
    int radius = 0;
    float area = 0.0;
    /* all command-line arguments come in as character strings, so atoi turns them into ints*/
    radius = atoi(argv[1]);

    radius = radius*radius; /* radius squared */

    area  = radius*PI; /* calculate area of circle */

    /* print to two decimal places*/
    if (area < 1000000000){
        printf ("%.2f\n",area);
    }
    else {
        printf ("%9.2f\n",area);
    }

    return (0);
}
