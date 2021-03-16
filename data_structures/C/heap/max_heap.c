
#include <stdio.h>
#include <stdlib.h>

typedef struct max_heap
{
    int *p;
    int size;
    int count;
} Heap;

Heap *create_heap(Heap *heap);// creates a max_heap structure and returns a pointer to the struct

void down_heapify(Heap *heap, int index); // pushes an element downwards int the heap to find its correct position

void up_heapify(Heap *heap, int index); // pushed an element upwards in the heap to find its correct position

void push(Heap *heap, int x); // inserts an element in the heap

void pop(Heap *heap); // removes the top element from the heap

int top(Heap *heap); // returns the top element of the heap or returns INT_MIN if heap is empty

int empty(Heap *heap); // checks if heap is empty

int size(Heap *heap); // returns the size of heap

int main()
{
    //todo ??? 递归？
    Heap *head = create_heap(head);
    push(head,10);
    printf("Pushing element : 10\n");
    push(head, 3);
    printf("Pushing element : 3\n");
    push(head, 2);
    printf("Pushing element : 2\n");
    push(head, 8);
    printf("Pushing element : 8\n");
    printf("Top element = %d \n", top(head));
    push(head, 1);
    printf("Pushing element : 1\n");
    push(head, 7);
    printf("Pushing element : 7\n");
    printf("Top element = %d \n", top(head));
    pop(head);
    printf("Popping an element.\n");
    printf("Top element = %d \n", top(head));
    pop(head);
    printf("Popping an element.\n");
    printf("Top element = %d \n", top(head));
    printf("\n");
    return 0;
}

Heap *create_heap(Heap *heap)
{
    heap = (Heap *)malloc(sizeof(Heap));
    heap->size = 1;
    // p是啥？？？
    heap->p = (int *)malloc(heap->size * sizeof(int));
    heap->count = 0;
    return heap;
}

int seize(Heap *heap)
{
    return heap->count;
}

int empty(Heap *heap)
{
    if(heap->count !=0)
    {
        return 0;
    }else
    {
        return 1;
    }
}