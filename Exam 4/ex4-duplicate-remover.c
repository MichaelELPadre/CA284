/*
Author: Michael Hanley
Date: 14/12/2023
Input: n number of numbers
Output: remove all the duplicate numbers
My Approach/Description:
-->	Store all elements from command line into an array.
-->	Sort elements that are not duplicates at the beggining of our array.
-->	Length of array after removal of duplicates will be the number of non-duplicates
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void get_array(int *len, char *argv[], int *array);
void del_duplicates(int *len, int *array);
void print_array(int *len, int *array);
void swap(int *element_a, int *element_b);

int main(int argc, char *argv[])
{
 int len = argc - 1;
 int *array = (int *)calloc(len, sizeof(int));
 get_array(&len, argv, array);
 del_duplicates(&len, array);
 print_array(&len, array);
 return 0;
}

// Function: get_array stores elements in array
void get_array(int *len, char *argv[], int *array)
{
 for (int i = 0; i < *len; ++i)
  {
   *(array + i) = atoi(argv[i + 1]);
  }
}

// Function: del_duplicates deletes duplicate values by swapping duplicates to the end of array, then reducing the array size
void del_duplicates(int *len, int *array)
{
 int new_len = 0;
 int counter = 0;
 for (int i = 0; i < *len; ++i)
  {
   counter = 0;
   for (int j = 0; j < *len; ++j)
	{
	 if (*(array + i) == *(array + j))
	  {
	   counter++;
	  }
	}
   if (counter == 1)
	{// swapping elements
	 swap(array + new_len, array + i);
	 new_len++;
	}
  }
	// all duplicates are at the end of the array and are now removed by reducing the arrays length
 *len = new_len;
}

// Function: swap, swaps elements element_a and element_b
void swap(int *element_a, int *element_b)
{
 // temporary variable
 int tmp = *element_a;
 *element_a = *element_b;
 *element_b = tmp;
}

// Function: print_array prints our array with its new shortened length
void print_array(int *len, int *array)
{
 for (int i = 0; i < *len; ++i)
  {
   printf("%d\n", *(array + i));
  }
}
