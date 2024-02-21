/*
Author: Michael Hanley
Date: 14/12/2023
Input: n number of attendance records for n students.
Output: attendance status of every student printed line by line
My Approach/Description:
--> I created a struct(Record) that holds the students attenendance.
-->	I then made an array to store attendance status each student.
-->	I update the element of the array associated with each student
	with a 1 or 0 according to the question guidelines.
-->	Then print the attendance status.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Record Record;
struct Record
{
 char record[20];
};

void print_record(int *length, int *absent_checker);
void get_attendance(char *argv[], Record *attendance);
void new_record(int *length, Record *attendance, int *absent_checker);

int main(int argc, char *argv[])
{
 int length = argc - 1;

 // allocating memory for Record with the size of the attendance
 Record *attendance = calloc(length, sizeof(*attendance));
 int *absent_checker = (int *)calloc(length, sizeof(int));

 // getting attendance
 get_attendance(argv, attendance);
 new_record(&length, attendance, absent_checker);
 free(attendance);
 attendance = NULL;
 print_record(&length, absent_checker);

 // freeing memory after
 free(absent_checker);
 absent_checker = NULL;
 return 0;
}

// Function: get_attendance stores data from command line into the array of structures
void get_attendance(char *argv[], Record *attendance)
{
 int i = 0;
 Record *cptr;
 while (argv[i + 1])
  {
   cptr = &attendance[i];
   strcpy(cptr->record, argv[i + 1]);
   ++i;
  }
}

// Function: new_record processes each attendance record and keeps a record of total absent counts(absent_counter).
// If absent_counter for a student is greater than or equal to
// 3 then status is 1, else status is 0.
void new_record(int *length, Record *attendance, int *absent_checker)
{
 Record *cptr;
 int absent_counter = 0;
 // Forlooping through all attendances and setting counter to 0 before starting
 for (int i = 0; i < *length; ++i)
  {
   cptr = &attendance[i];
   absent_counter = 0;
 // Checking Absent status with a counter
 for (int j = 0; j < strlen(cptr->record); ++j)
  {
	if (cptr->record[j] == 'A')
	 {
	  absent_counter += 1;
	 }
	else if (cptr->record[j] == 'L')
	 {
	  if (cptr->record[j + 1] == 'L' && cptr->record[j + 2] == 'L')
		{
		 absent_counter += 1;
		 j = j + 2;
	    }
	 }
  }
  if (absent_counter >= 3)
   {
	*(absent_checker + i) = 1;
   }
  else
   {
	*(absent_checker + i) = 0;
   }
  }
}
// Function: print_record prints the status array line by line
void print_record(int *length, int *absent_checker)
{
 for (int i = 0; i < *length; ++i)
  {
   printf("%d\n", *(absent_checker + i));
  }
}
