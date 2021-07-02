
#include <stdio.h>
#include <stdlib.h>

#define NULL 0

struct node
{
	int data;
	struct node *next;
};

struct node *head=NULL;
struct node *tail=NULL;

void create()
{
	int i,n;
	struct node *pnode, *p;

	printf("Enter the number of nodes required:\n");
	scanf("%d",&n);

	printf("Enter the data value of each node:\n");
	for(i=1; i<=n; i++)
	{
		pnode = (struct node*)malloc(sizeof(struct node));
		if(pnode == NULL)
		{
			printf("Memory overflow. Unable to create.\n");
			return;
		}
		scanf("%d", &pnode->data);

		if(head == NULL)
		{
			head = tail = pnode;
		}else
		{
			tail->next = pnode;
			tail = pnode; // last keeps tracks of last node
		}

		tail->next = head;
	}
}

// This function will delete a node with value k from the Linked List if such a node exists
void deletenode(int k)
{
	struct node *p, *follow;

	// searching the required node
	p = head;
	follow = NULL;
	while(follow != tail)
	{
		if(p->data == k)
		break;
		follow = p;
		p = p->next;
	}

	if(follow == tail)
	{
		printf("Required node not found.\n");
	}
	else
	{
		// deleting the one and the only node
		if(p == head && p==tail)
		{
			head = tail = NULL;
		}
		// deleting the tail node
		else if (p == head)
		{
			head = first->next;
			tail->next = head;
		}
		// deleting the tail node
		else if(p == tail)
		{
			tail = follow;
			tail->next = head;
		}
		// deleting any other node
		else
		{
			follow ->next = p ->next;
		}

		free(p);
	}
}

// This function will go through all the nodes of Linked List exactly once and will display data value of each node
void traverse()
{
	struct node *p, *follow;

	if(head == NULL)
	{
		printf("Circulary Linked List Empty");
	}
	else
	{
		printf("Circularly Linked List is as shown: \n");

		p = head;
		follow = NULL;
		while(follow != tail)
		{
			printf("%d ", p->data);
			follow = p;
			p = p->next;
		}
		printf("\n");
	}
}
