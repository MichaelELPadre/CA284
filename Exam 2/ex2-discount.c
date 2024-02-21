/*
Author: Michael Hanley
Date: 2/11/2023
Description: Program accepts a shopping list with its items. The program calculates
the final amount to pay for all items on list. Prints 2 digits to 2 decimal
places. Including to deal with promotions like for every 3 promotional
items the customer only pays for 2.
*/

/* Relevant libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct List List;
struct List {
    // Max number of items = 100
    char *item[100];
    int amount[100];
    float price[100];
    int promotion[100];
};

struct List sale_nosale(char *arr[], int len);
void sale(char *arr[], int len);

/* Main function */
int main(int argc, char* argv[]) {
    char *arr[argc - 1];
    int count = 0;
    for (int i = 1; i < argc; ++i, ++count) {
        arr[count] = argv[i];
    }
    sale(arr, count);
    return 0;
}

void sale(char *arr[], int len) {
    // Initializing the struct
    List which_items;
    // Assigning the info to the struct
    which_items = sale_nosale(arr, len);
    float total_cost = 0;
    for (int i = 0; i < len / 4; ++i) {
        if (which_items.promotion[i] == 0) {
            total_cost += (which_items.price[i] * which_items.amount[i]);
        } else if (which_items.promotion[i] == 1) {
            int tmp_price = (which_items.price[i] * which_items.amount[i]);
            int tmp_amount = which_items.amount[i] / 3;
            int tmp_price_2 = which_items.price[i] * tmp_amount;
            total_cost += (tmp_price - tmp_price_2);
        }
    }
    printf("%.2f\n", total_cost);
}

// Function getting pointer array and length
struct List sale_nosale(char *arr[], int len) {
    List all_items;
    int index = 0;
    int count = 0;
    // Looping through all of the items on shopping list
    for (int i = 0; i < len; ++i) {
        if (count == 4) {
            all_items.item[index] = arr[i - 4];
            all_items.amount[index] = atoi(arr[i - 3]);
            all_items.price[index] = atof(arr[i - 2]);
            all_items.promotion[index] = atoi(arr[i - 1]);
            ++index;
            count = 0;
        } else if (i == len - 1) {
            all_items.item[index] = arr[i - 3];
            all_items.amount[index] = atoi(arr[i - 2]);
            all_items.price[index] = atof(arr[i - 1]);
            all_items.promotion[index] = atoi(arr[i]);
            ++index;
            count = 0;
        }
        ++count;
    }
    return all_items;
}
