
#include <stdio.h>
#include <stdlib.h>
#include <limits.h> 

typedef struct min_heap
{
	int *p;
	int size;
	int count;
} Heap;


// creates a min_heap structure and returns a pointer to the strcut
Heap *create_heap(Heap *heap);

// pushes an element downwards in the heap to find its correct position
void down_heapify(Heap *heap, int index);

// pushes an element upwards in the heap to find its correct position
void up_heapify(Heap *heap, int index);

// inserts an element int the heap
void push(Heap *heap, int x);

// removes the top element from the heap
void pop(Heap *heap);

// returns the top element of the heap or returns INI_MIN if heap is empty
int top(Heap *heap);

// checks if heap is empty
int empty(Heap *heap);

// returns the size of heap
int size(Heap *heap);

Heap *create_heap(Heap *heap)
{
	heap = (Heap *)malloc(sizeof(Heap));
	heap->size = 1;
	heap->p = (int *)malloc(heap->size * sizeof(int));
	heap->count = 0;
	return heap;
}

void down_heapif(Heap *heap, int index)
{
	if(index >= heap->count)
	{
		return;
	}
	int left = index * 2 + 1;
	int right = index * 2 + 2;
	int leftflag = 0, rightflag = 0;

	int minimum = *((heap->p) + index);
	if(left <heap->count && minimum > *((heap->p) + left))
	{
		minimum = *((heap->p) + left);
		leftflag = 1;
	}

	if(right <heap->count && minimum > *((heap->p) + right))
	{
		minimum = *((heap->p) + right);
		leftflag = 0;
		rightflag = 1;
	}

	if(leftflag)
	{
		*((heap->p) + left) = *((heap->p) + index);
		*((heap->p) + index) = minimum;
		down_heapif(heap, left);
	}

	if(rightflag)
	{
		*((heap->p) + right) = *((heap->p) + index);
		*((heap->p) + index) = minimum;
		down_heapif(heap, right);
	}
}

void up_heapify(Heap *heap, int index)
{
	int parent = (index - 1)/2;
	if(parent < 0)
	{
		return;
	}
	if(*((heap->p) + index) < * ((heap->p) + parent))
	{
		int temp = *((heap->p) + index);
		*((heap->p) + index) = *((heap->p) + parent);
		*((heap->p) + parent) = temp;
		up_heapify(heap, parent);
	}
}

void push(Heap *heap, int x)
{
	if(heap->count >= heap->size)
	{
		return;
	}
	*((heap->p) + heap->count) = x;
	heap->count++;
	if(4 * heap->count >= 3 * heap->size)
	{
		heap->size *= 2;
		(heap->p) = (int *)realloc((heap->p), (heap->size) * sizeof(int));
	}
	up_heapify(heap, heap->count - 1);
}

void pop(Heap *heap)
{
	if(heap->count == 0)
	{
		return;
	}
	heap->count--;
	int temp = *((heap->p) + heap->count);
	*((heap->p) + heap->count) = *(heap->p);
	*(heap->p) = temp;
	down_heapif(heap, 0);
	if(4 * heap->count <= heap->size)
	{
		heap->size /=2;
		(heap->p) = (int *)realloc((heap->p), (heap->size) * sizeof(int));
	}
}

int top(Heap *heap)
{
	if(heap->count != 0)
	{
		return *(heap->p);
	}
	else
	{
		return INT_MIN;
	}
}

int empty(Heap *heap)
{
    if (heap->count != 0)
        return 0;
    else
        return 1;
}
int size(Heap *heap) 
{ 
	return heap->count; 
}