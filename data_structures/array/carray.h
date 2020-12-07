
/*
 * Header for Array in C
 * 
 */

// 预编译一次
#pragma once
// 如果是cpp代码，那么加入 extern “C”{ 和 } 并处理其中代码
#ifdef __cplusplus
extern "C"
{
#endif

#define ARRAY_ERASED -1
#define SUCCESS 0
#define INVALID_POSITION 1
#define POSITION_INIT 2
#define POSITION_NOT_INIT 3
#define POSITION_EMPTY 4
#define ARRAY_FULL 

typedef struct CArray
{
    /* data */
    int *array;
    int size;
}CArray;

//Returns array
CArray *getCArray(int size);
CArray *getCopyCArray(CArray *array);

// input / output
int insertValueCArray(CArray *array, int position, int value);
int removeValueCArray(CArray *array, int position);
int pushValueCArray(CArray *array, int value);
int updateValueCArray(CArray *array, int position, int value);

// earse
int earseCArray(CArray *array);

// switch 换位
int switchValuesCArray(CArray *array, int position1, int position2);
int reverseCArrary(CArray *array);

// sort
int bubbleSortCArray(CArray *array);
int selectionSortCArray(CArray *array);
int insertionSortCArray(CArray *array);
// 搅拌？？？
int blenderCArray(CArray *array);

// search
int valueOcurranceCArray(CArray *array, int value);
CArray *valuePositionsCArray(CArray *array, int value);
int findMaxCArray(CArray *array);
int findMinCArray(CArray *array);

// display
int displayCArray(CArray *array);

#ifdef __cplusplus
}
#endif

