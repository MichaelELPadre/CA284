/*
Author: Michael Hanley
Date: 14/12/2023
Input: a paragraph + argument(shortest or longest)
Output: the shortest or longest sentence in paragraph
My Approach/Description:
-->	Split paragraph for every '.' and '?'
--> Allocate each sentence to a node
-->	Iterate through nodes and find the shortest or longest
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Creating Structure for Sentence
typedef struct Sentence Sentence;
struct Sentence
{
 char words[200];
 Sentence *next;
};

Sentence *get_paragraph(char *argv);
Sentence *new_sentence();

void longest_sentence(Sentence *first, char *sentence);
void shortest_sentence(Sentence *first, char *sentence);
void checker(char *flag, Sentence *first, char *sentence);
void flagged_function(void (*pfun)(Sentence *, char *), Sentence *first, char *sentence);
void print_sentence(char *sentence);

int main(int argc, char *argv[])
{
 char flag[strlen(argv[2])];
 strcpy(flag, argv[2]);

 char *sentence = (char *)calloc(200, sizeof(char));
 Sentence *first = get_paragraph(argv[1]);
 checker(flag, first, sentence);
 return 0;
}

// Function: get_paragraph splits paragraph where there are '.' and '?'. Using Linear Search.
// Only if they are not inbetween single quotation marks.
// Return the head of the list.
Sentence *get_paragraph(char *argv)
{
 Sentence *current, *first;
 first = new_sentence();
 current = first;
 int i = 0;
 int j = i;
// Each sentence becomes a node in our linked list.
 while (argv[i])
  {
   if (argv[i] == 39)
	{
	 i += 1;
	 while (argv[i] != 39)
	  {
	   i += 1;
	  }
	}
   else if(argv[i] == '.' || argv[i] == '?')
	{
	 i += 1;
	 strncpy(current->words, argv + j, i - j);
	 if (i < strlen(argv))
	  {
	   current->next = new_sentence();
	   current = current->next;
	  }
	 else
	  {
	   current->next = NULL;
	  }
     j = i + 1;
    }
   i += 1;
  }

 return first;
}

// Function allocating new node
Sentence *new_sentence()
{
 Sentence *new = (Sentence *)calloc(1, sizeof(Sentence));
 if (!new)
  {
   printf("Error allocating memory!");
   exit(0);
  }
 return new;
}

// This function finds the longest sentence and drives the print function
void longest_sentence(Sentence *first, char *sentence)
{
 int longest_len = 0;
 Sentence *current;
 current = first;
 while (current)
  {
   if (strlen(current->words) > longest_len)
	{
	 longest_len = strlen(current->words);
	 strcpy(sentence, current->words);
	}
	current = current->next;
  }
 print_sentence(sentence);
}

// This function finds the shortest sentence and drives the print function
void shortest_sentence(Sentence *first, char *sentence)
{
 int shortest_len = strlen(first->words);
 strcpy(sentence, first->words);
 Sentence *current;
 current = first;
 while (current)
  {
   if (strlen(current->words) < shortest_len && strlen(current->words) != 0)
	 {
	  shortest_len = strlen(current->words);
	  strcpy(sentence, current->words);
	 }
   current = current->next;
  }
 print_sentence(sentence);
}

// Function: checker checks what the flag is and passes a pointer
// to correct function or prints "not valid!"
void checker(char *flag, Sentence *first, char *sentence)
{
 void (*pf)(Sentence *, char *) = NULL;
 if (strcmp(flag, "longest") == 0)
  {
   pf = longest_sentence;
   flagged_function(pf, first, sentence);
  }

 else if (strcmp(flag, "shortest") == 0)
  {
   pf = shortest_sentence;
   flagged_function(pf, first, sentence);
  }

 else
  {
   printf("Not valid!\n");
   exit(0);
  }
}
// Function: flagged_function calls the function being passed to it
void flagged_function(void (*pfun)(Sentence *, char *), Sentence *first, char *sentence)
{
 pfun(first, sentence);
}
// Print length(of sentence) and sentence.
void print_sentence(char *sentence)
{
	printf("%ld\n%s\n", strlen(sentence), sentence);
}
