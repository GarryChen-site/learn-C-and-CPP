//
// Created by  雨下的文 on 2021/2/23.
//

#include <assert.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

#define L List_T

// initial list
L List_init(void)
{
    L list;
    list = (L) malloc(sizeof(L));
    list->next = NULL;
    return list;
}

// push an element into top of the list
L List_push(L list, void *val)
{
    L new_elem = (L)malloc(sizeof (L));
    new_elem->val = val;
    new_elem->next = list;
    return new_elem;
}

// Length of list
int List_length(L list)
{
    int n;
    for(n = 0; list; list = list -> next)
    {
        n++;
    }
    return n;
}

// Convert list to array
void **List_toArray(L list)
{
    int i,n = List_length(list);
    // void ** is just a pointer to a pointer to memory with an unspecified type
    // can only dereference it once
    // *array -- array[0]
    void **array = (void **)malloc((n+1) * sizeof (*array));

    for(i = 0; i< n; i++)
    {
        array[i] = list->val;
        list = list->next;
    }
    array[i] = NULL;
    return array;
}

// Create and return a list
L List_list(L list, void *val,...)
{

}

