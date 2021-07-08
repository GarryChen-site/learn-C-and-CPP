
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

/*
*         7
*      5     6
*    4   2 1
* 
*   7 5 6 4 2 1 
* 0 1 2 3 4 5 6
* 
* 数组中下标为i的节点的左子节点，就是下标为i*2的节点，
* 右子节点就是下标为i*2+1的节点，父节点就是下标为i/2的节点
*/
Heap *create_heap(Heap *heap)
{
    heap = (Heap *)malloc(sizeof(Heap));
    heap->size = 1;
    // p是啥？？？
    heap->p = (int *)malloc(heap->size * sizeof(int));
    heap->count = 0;
    return heap;
}

void down_heapify(Heap *heap, int index)
{
    if(index >= heap->count)
    {
        return;
    }
    int left = index * 2 + 1;
    int right = index * 2 + 2;
    int leftflag = 0, rightflag = 0;

    int maximum = *((heap->p) + index);
    if(left < heap->count && maximum < *((heap->p) + left))
    {
        maximum = *((heap->p) + left);
        leftflag = 1;
    }
    if(right < heap->count && maximum < *((heap->p) + right))
    {
        maximum = *((heap->p) + right);
        leftflag = 0;
        rightflag = 1;
    }

    if(leftflag)
    {
        *((heap->p) + left) = *((heap->p) + index);
        *((heap->p) + index) = maximum;
        down_heapify(heap, left);
    }
    if(rightflag)
    {
        *((heap->p) + right) = *((heap->p) + index);
        *((heap->p) + index) = maximum;
        down_heapify(heap, right);
    }
}

void up_heapify(Heap *heap, int index)
{
    int parent = (index - 1) / 2;
    if(parent < 0)
    {
        return;
    }
    if(*((heap->p) + index) > *((heap->p) + parent))
    {
        int temp = *((heap->p) + index);
        *((heap->p) + index) = *((heap->p) + parent);
        *((heap->p) + parent) = temp;
        up_heapify(heap, parent);
    }
}

void push(Heap *heap; int x)
{
    if(heap->count >= heap->size)
    {
        return;
    }
    *((heap->p) + heap->count) = x;
    heap->count++;
    if(4 * heap->count >= 3 * heap ->size)
    {
        heap->size *= 2;
        (heap->p) = (int *)realloc((heap->p), (heap->size) * sizedof(int));
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
    down_heapify(heap, 0);
    if(4 * heap->count <= heap->size)
    {
        heap->size /= 2;
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