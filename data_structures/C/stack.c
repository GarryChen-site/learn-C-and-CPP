
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *pre;
} *head, *tmp;

// GLOBAL VARIABLES
int count = 0;

// FUNCTION PROTOTYPES
void create();
void push(int x);
int pop();
int peek();
int size();
int isEmpty();

void create()
{
    head = NULL;
}



