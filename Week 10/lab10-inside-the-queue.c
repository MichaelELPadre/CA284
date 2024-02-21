#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node Node;
struct Node {
    int value;
    Node *next;
};

Node* AddNumber(int num, int numAdd, Node *first);
Node* fill(int x[10]);
void print(Node *start);

int main(int argc, char*argv[]) {
    int x[10] = { 8, 7, 3, 4, 5, 6, 9, 2, 14, 12 };
    Node *start;
    start = fill(x);
    start = AddNumber(atoi(argv[1]), atoi(argv[2]), start);
    print(start);
    return 0;
}

Node* fill(int x[10]) {
    Node *current, *first;
    first = (Node*)calloc(1,sizeof(Node));
    current = first;
    current->value = x[0];
    for (int i = 1; i < 10; i++) {
        current->next = (Node*)calloc(1,sizeof(Node));
        current = current->next;
        current->value = x[i];
    }
    return first;
}

Node* AddNumber(int num, int numAdd, Node *first)
{
    Node *current, *start;
    start = first;
    current = first;

    for(int i = 0; i < 10; i++)
    {
        if(current->value == num)
        {
            Node *tmp = current->next;
            current->next = (Node*)calloc(1,sizeof(Node));
            current = current->next;
            current->value = numAdd;
            current->next = tmp;
        }
        current = current->next;
    }

    return start;
}

void print(Node *start)
{
    Node* p = NULL;
    for(p = start; p != NULL; p = p->next)
    {
        printf("%d\n", p->value);
    }
}
