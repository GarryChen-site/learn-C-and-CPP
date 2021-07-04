
/* A priority queue is a special type of queue in which each element is
associated with a priority and is served according to its priority. If elements
with tha same priority occur, they are served according to their order in the queue.

Generally, the value of the element itself is considered for assigning the priority.

For example: The element with the highest value is considered as the highest
priority element. However, in other cases, we can assume the element with lowest value 
as highest priorities according to our needs.

In a queue, the first-in-first-out rule is implemeted whereas, in a priority
queue, the values are removed on the basis of priority. The element with 
the highest priority is removed first
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	// Lower values indicate higher priority
	int priority;

	struct node* next;
} Node;

Node* newNode(int d, int p)
{
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = d;
	temp->priority = p;
	temp->next = NULL;

	return temp;
}

// return the value at head
int peek(Node** head)
{
	return (*head)->data;
}

// removes the element with 
// the highest priority from the list
void pop(Node** head)
{
	Node* temp = *head;
	(*head) = (*head)->next;
	free(temp);
}

// function to push according to priority
void push(Node** head, int d, int p)
{
	Node* start = (*head);

	// create new node
	Node* temp = newNode(d,p);

	// Special case: the head of list has lesser
	// priotiry than new node. So insert new
	// node before head node and change head node
	if((*head)->priority > p)
	{
		// insert new node before head
		temp->next = *head;
		(*head) = temp;
	}
	else
	{
		// traverse the list and find a 
		// position to insert new node
		while(start->next != NULL &&
		start->next->priority < p)
		{
			start = start->next;
		}

		// either at the ends of the list
		// or at required position
		temp->next = start->next;
		start->next = temp;
	}
}

// function to check is list is empty
int isEmpty(Node** head)
{
	return (*head) == NULL;
}

int main()
{
	// Create a Priority Queue
	Node* pq = newNode(4,1);
	push(&pq, 5,2);
	push(&pq, 6,3);
	push(&pq, 7,0);

	while(!isEmpty(&pq))
	{
		printf("%d ",peek(&pq));
		pop(&pq);
	}

	return 0;
}