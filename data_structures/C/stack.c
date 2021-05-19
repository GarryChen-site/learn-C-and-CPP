
#include <stdio.h>
#include <stdlib.h>

// head is a sentinel node ???
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

/**
 * push data onto the stack
 */
void push(int x)
{
    if(head == NULL)
    {
        head = (struct node *)malloc(1 * sizeof(struct node));
        head->next = NULL;
        head->pre = NULL;
        head->data = x;
    }
    else
    {
        tmp = (struct node *)malloc(1 * sizeof(struct node));
        tmp->data = x;
        tmp->next = NULL;
        tmp->pre = head;
        head->next = tmp;
        head = tmp;
    }
    ++count;
}

/**
 * pop datafro m the stack
 * 6
 * 5     5
 * 4  6  4
 * 3 --> 3
 * 2     2
 * 1     1
 * last in first out
 */
int pop()
{
    int returnData;

    if(head == NULL)
    {
        printf("ERROR: Pop from empty stack.\n");
        exit(1);
    }
    else
    {
        returnData = head->data;

        // because head is a sentinel node
        if(head->pre == NULL)
        {
            free(head);
            head = NULL;
        }
        else
        {
            head = head->pre;
            free(head->next);
        }
    }
    --count;
    return returnData;
}

/**
 * return the top element
 */
int peek()
{
    if(head != NULL)
    {
        return head->data;
    }
    else
    {
        printf("ERROR: Peeking from empty stack.");
        exit(1);
    }
}

/**
 * Returns the size of the stack
 */
int size()
{
    return count;
}

/**
 * Return 1 if stack is empty, returns 0 if not empty
 */
int isEmpty()
{
    if(count == 0)
    {
        return 1;
    }
    return 0;
}


