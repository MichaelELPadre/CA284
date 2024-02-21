#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node Node;

struct Node {
    float value;
    Node *next;
};

Node* fill(char *argv[], int length);
void print(Node *start);

int main(int argc, char*argv[]) {
    int length = atoi(argv[1]);
    Node *LinkedList = NULL;
    LinkedList = fill(argv, length);
    print(LinkedList);
    return 0;
}

Node* fill(char *argv[], int length) {
	Node *current, *first;
    first = (Node*)calloc(1,sizeof(Node)); /*create the first node */
	current = first;
    current->value = atof(argv[length + 1]);
    for (int i = length - 1; i > 0; i--) {
        current->next = (Node*)calloc(1,sizeof(Node));
	    current = current->next;
        current->value = atof(argv[i + 1]);
    }

    return first;
}

void print(Node *start)
{
	Node* p = NULL;
	for(p = start; p != NULL; p = p->next)
	{
		printf("%.2f\n", p->value);
	}
}