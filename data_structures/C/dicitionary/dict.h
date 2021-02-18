//
// Created by  雨下的文 on 2021/2/18.
//

#ifndef ALGORITHMS_IN_C_DICT_H
#define ALGORITHMS_IN_C_DICT_H

#define MAXELEMENTS 1000

/*
 * special data type called 'Dictionary'
 * for generic use
 */
typedef struct Dict
{
    /*
     * void* array for generic use of the dictionary.
     * there actual saves the entries.
     */
    void *elements[MAXELEMENTS];

    /*
     * contains the number of elements in this dictionary
     */
    int number_of_elements;
}Dictionary;

#endif //ALGORITHMS_IN_C_DICT_H
