
/* Queue using Linked List - Program to creare a queue ADT using linked list.
ADT should support the following operations 1) Crearequeue 2) Insert into 
the queue 3) Delete from the queue 4) destroyqueue
*/

#include <stdio.h>
#include <stdlib.h>
#define NULL 0

struct node
{
	int data;
	struct node *next;
};

struct queue
{
	struct node *front, *rear;
};

struct queue q;

// This function initializes the queue to empty by making both front and rear as NULL
void crearequeue()
{
	q.front = q.rear = NULL;
}

int empty()
{
	if(q.front == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void insert(int x)
{
	struct node *pnode;

	pnode = (struct node *)malloc(sizeof(struct node));
	if(pnode == NULL)
	{
		printf("Memory overflow. Unable to insert.\n");
		exit(1);
	}

	pnode->data = x;
	pnode->next = NULL; // new node is always last node

	if(empty())
	{
		q.front = q.rear = pnode;
	}
	else
	{
		(q.rear)->next = pnode;
		q.rear = pnode;
	}
}

int removes()
{
	int x;
	struct node *p;

	if(empty())
	{
		printf("Queue Underflow. Unable to remove.\n");
		exit(1);
	}

	p = q.front;
	x = (q.front)->data;
	q.front = (q.front)->next;
	if(q.front == NULL) // queue contained only one node
	{
		q.rear = NULL;
	}
	free(q);
	return x;
}

void show()
{
    struct node *p;

    if (empty())
        printf("Queue empty. No data to display \n");
    else
    {
        printf("Queue from front to rear is as shown: \n");

        p = q.front;
        while (p != NULL)
        {
            printf("%d ", p->data);
            p = p->next;
        }

        printf("\n");
    }
}

void destroyqueue() { q.front = q.rear = NULL; }