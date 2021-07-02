
#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
}

struct node *head1 = NULL;
struct node *head2 = NULL;

// main algorithmic function to merge the two input linked list

void merge()
{
	struct node *temp1 = head1;
	struct node *temp2 = head2;

	// temporary pointer variables to store the address of next node of the 
	// two input linked list
	struct node *holder1 = NULL;
	struct node *holder2 = NULL;



	while(temp1 != NULL && temp2 != NULL)
	{
		holder1 = temp1->next;
		// storing the address of next node of first linked list
		temp1->next = temp2;
		// making the first node of first linked list point to first node of
		// second linked list

		if(holder1 != NULL)
		{
			// Making the first node of second linked list point to second node
			// of first linked list
			holder2 = temp2->next;
			temp2->next = holder1;
		}
		// updating the address location of two pointer variables temp1 and temp2
		temp1 = holder1;
		temp2 = holder2;
	}
}

void printlist(struct node *temp)
{
	printf("%d",temp->data);
	temp = temp->data;
	while(temp != NULL)
	{
		printf("->%d", temp->data);
		temp = temp->next;
	}
	printf("\n");
}