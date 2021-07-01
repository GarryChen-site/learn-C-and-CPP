
#include <stdio.h>
#include <stdlib.h>

#define NULL 0

struct node
{
	int data;
	struct node *next;
};

struct node *first=NULL;
struct node *last=NULL;

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

		if(first == NULL)
		{
			first = last = pnode;
		}else
		{
			last->next = pnode;
			last = pnode; // last keeps tracks of last node
		}

		last->next = first;
	}
}

// This function will delete a node with value k from the Linked List if such a node exists
void deletenode(int k)
{
	struct node *p, *follow;

	// searching the required node
	p = first;
	follow = NULL;
	while(follow != last)
	{
		if(p->data == k)
		break;
		follow = p;
		p = p->next;
	}

	if(follow == last)
	{
		printf("Required node not found.\n");
	}
	else
	{
		// deleting the one and the only node
		if(p == first && p==last)
		{
			first = last = NULL;
		}
		// deleting the last node
		else if (p == first)
		{
			first = first->next;
			last->next = first;
		}
		// deleting the last node
		else if(p == last)
		{
			last = follow;
			last->next = first;
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

	if(first == NULL)
	{
		printf("Circulary Linked List Empty");
	}
	else
	{
		printf("Circularly Linked List is as shown: \n");

		p = first;
		follow = NULL;
		while(follow != last)
		{
			printf("%d ", p->data);
			follow = p;
			p = p->next;
		}
		printf("\n");
	}
}
