/*
Author: Michael Hanley
Date: 30/11/23
Description: Creating an array of only odd numbers.
Description/Approach:
->I have created an array only of numbers from stdin.
->Then a function that returns how many odd numbers there are.
->Then I reallocated the the memory of the array with odd numbers.
*/

//necessary libraries
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int find_odd_numbers(int * pArray, int len);

void print_array(int * pArray, int len);

int main(int argc, char *argv[])
{
 //main array
 int *pArray = (int*)malloc((argc - 1)*sizeof(int));
 //temporary array
 int *tmp_array;
 //the length of odds
 int new_len;
 //assigning the numbers stdin to our array
 int count = 0;
 for (int i = 1; i < argc; ++i, ++count)
  {
   *(pArray + count) = atoi(argv[i]);
  }
 //assigning the length of odds into a variable
 new_len = find_odd_numbers(pArray, argc - 1);
 // reallocating the new memory
 tmp_array = (int*)realloc(pArray, new_len*sizeof(int));
 // assigning odd numbers to our tmp array
 count = 0;
 for (int i = 0; i <= argc - 1; ++i)
  {
   if (atoi(argv[i]) % 2 == 1)
    {
     *(tmp_array + count) = atoi(argv[i]);
     ++count;
    }
  }

 // assigning the tmp array to our original array
 pArray = tmp_array;
 //printing the array
 print_array(pArray, count);
 // free memory
 free(tmp_array);
 return 0;
}

//Function: find how many odd numbers
int find_odd_numbers(int * pArray, int len)
{
 // length of list
 int odd_length = 0;
 for (int i = 0; i < len; ++i)
  {
   if (*(pArray + i) % 2 != 0)
    {
     ++odd_length;
    }

  }
 return odd_length;
}

//Function: print array
void print_array(int * pArray, int len)
{
 // adding up the odds together
 int total = 0;
 for (int i = 0; i < len; ++i)
  {
   printf("%d\n", *(pArray + i));
   total += *(pArray + i);
  }
 // Print our total
 printf("%d\n", total);
}
