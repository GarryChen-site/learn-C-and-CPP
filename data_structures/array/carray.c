


/*
Returen code

-1 - Array Erased
0 - Success
1 - Invalid Position
2 - Position already initialized (use update function)
3 - Position not initialized (use insert function)
4 - Position already empty
5 - Array is full

*/

#include "CArray.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



CArray *getCArray(int size){
    CArray *initArray = (CArray *)malloc(sizeof(CArray));

    initArray ->array = (int *)malloc(sizeof(int)*size);

    initArray ->size = size;

    int i;
    for ( i = 0; i < size; i++)
    {
       /* code */
       initArray ->array[i] = 0;
    }
    return initArray;
    
}

int insertValueCArray(CArray *array, int position, int value){

    if (position >= 0 && position < array ->size)
    {
        /* code */
        if (array ->array[position] == 0)
        {
            /* code */
            array ->array[position] = value;
            return SUCCESS;
        }
        else
             return POSITION_INIT;
        
    }
    return INVALID_POSITION;
    
}

int removeValueCArray(CArray *array, int position)
{
    if(position >=0 && position < array->size){
        if(array ->array[position] != 0)
        {
            array ->array[position] = 0;
        }
        else
        {
            return POSITION_EMPTY;
        }
        
    }
    return INVALID_POSITION;
}

int pushValueCArray(CArray *array, int value)
{
    int i;
    int ok = 0;
    for ( i = 0; i < array->size; i++)
    {
        if(array->array[i] == 0)
        {
            array->array[i] = value;
            ok = 1;
            break;
        }
    }
    if (ok == 1)
        return SUCCESS;
    else
        return ARRAY_FULL;
    
}

int updateValueCArray(CArray *array, int position, int value){
    if (position >= 0 && position < array->size)
    {
        if(array->array[position] != 0)
        {}
        else
        {
            return POSITION_NOT_INIT;
        }
    }
    return INVALID_POSITION;
}

int eraseCArray(CArray *array){
    int i;
    for(i = 0, i < array->size; i++)
    {
        array->array[i] = 0;
    }
    return 0;
}

