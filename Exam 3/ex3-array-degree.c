/*
Author: Michael Hanley
Date: 30/11/23
Description: Printing the degree from given list with a number of integers(Frequncy of most frequent number in list).
Description/Approach:
-> Initiated a struct with the necesarry data including a reference to the next value.
-> Took argv and made a linked list based on the data from the struct made.
-> I then passed the start to my function that prints, to print our linked list with necesarry the necessary data.
-> I used a second loop to compare and find the highest frequency using a temp variable.
*/

// necessary libraries

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
// struct class Number
typedef struct Number Number;
struct Number
{
 int number;
 Number *next;
};

Number * link(char * arr[], int len);
void print_highest_freq(Number *start, char* arr[], int len);


int main(int argc, char *argv[])
{
 Number* start = NULL;
 start = link(argv, argc - 1);
 print_highest_freq(start, argv, argc - 1);
 return 0;
}

// Linked List
Number * link(char * arr[], int len)
{
 // making current and first to be the first node
 Number *current, *first;
 first = (Number*)malloc(sizeof(Number));
 current = first;

 // filling out first node
 current->number = atoi(arr[1]);

 // assigning the rest based on first node
 for (int i = 2; i <= len; ++i)
  {
   current->next = (Number*)malloc(sizeof(Number));
   current = current->next;
   current->number = atoi(arr[i]);
  }

 // ending linked list making last node next reference NULL
 current->next = NULL;

 // returning head of linked list
 return first;
}

// Function: prints our linked list
void print_highest_freq(Number *start, char * arr[], int len)
{
 int count = 0;
 Number *p = NULL;
 int highest = 0;
 // tmp value compared to highest value
 int tmp = 0;
 for (p = start; p != NULL; p = p -> next)
  {
   ++count;
   // looking for frequency of p -> next
   for (int i = 1; i <= len; ++i)
    {
     if (p->number == atoi(arr[i]))
      {
       ++tmp;
      }
    }
   // comparing tmp to highest to see which one stays
   if (highest < tmp)
    {
     highest = tmp;
    }
   // emptying the tmp
   tmp = 0;
  }
 // printing highest numbers
 printf("%d\n", highest);
}
