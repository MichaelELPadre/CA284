/*
Author: Michael Hanley
Date: 30/11/23
Description: Reading numbers and printing a number if it appears(frequency) > 3
Description/Approach:
-> I assigned all numbers from argv to an array;
-> Then made a frequency function where
-> I take a number using a for loop and check how many times it repeats with a second for loop.
-> If the frequency > 3, then it passes to adding it to array (its size it constantly updated with realloc).
-> Then I pass it to printing function which also sorts it for me using insertion sort
*/

// necessary libraries
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void find_freq(int * pArray, int len);

void print_array(int * pArray, int len);

int main(int argc, char *argv[])
{
 // assigning all numbers to new array
 int *pArray = (int*)malloc((argc - 1)*sizeof(int));
 int count = 0;
 // getting numbers from stdin and adding them to array as integers
 for (int i = 1; i < argc; ++i, ++count)
  {
   *(pArray + count) = atoi(argv[i]);
  }
 find_freq(pArray, count);
 return 0;
}

// finding the freqency of each number
void find_freq(int * pArray, int len)
 {
  int size_freq = 1;
  int *freq_nr = (int*)malloc(size_freq*sizeof(int));
  int *temp_ptr; // temporary array for realloc
  int position = 0; // position in the new temporaty array
  int count = 0; // counting instances (freqency)
  for (int i = 0; i < len; ++i)
   {
    count = 0; // reseting count
    for (int j = 0; j < len; ++j)
     {
      if (*(pArray + i) == *(pArray + j))
       {
        // checking
        ++count; // counting, using a count variable
       }
     }
    if (count > 3)
     {// checking if count has right value
      if (position < 1)
       {// assigning the first position
        *(freq_nr + position) = *(pArray + i);
        ++position;
       }
      else
       {// after the first position was assigned we can assign the rest
        ++size_freq;
        temp_ptr = (int*)realloc(freq_nr, (size_freq)*sizeof(int)); // reallocating one number at a time
        *(temp_ptr + position) = *(pArray + i);
        freq_nr = temp_ptr; // submitting to the original array
        ++position; //updating next position
       }
     }

   }
 // printing array
 print_array(freq_nr, size_freq);
}


// Function: print array
void print_array(int *arr, int len_arr)
{
 // sorting using insertion sort to sort array
 int i, j, min_idx;
 for (i = 0; i < len_arr; ++i)
  {
   min_idx = i;
   for (j = i + 1; j < len_arr; ++j)
    {
     if (*(arr + j) < *(arr + min_idx))
     min_idx = j;
    }
   if(min_idx != i)
    {
     // swapping temp
     int temp = *(arr + min_idx);
     *(arr + min_idx) = *(arr + i);
     *(arr + i) = temp;
    }
  }
 // printing numbers linearly
 for (int i = 0; i < len_arr; ++i)
  {
   printf("%d\n", *(arr + i));
  }
}
