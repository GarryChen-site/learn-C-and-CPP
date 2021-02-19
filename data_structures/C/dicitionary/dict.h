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

/*
 * create_dict: is a simple constructor for creating
 *              a dictionary and setting up the
 *              member field 'number_of_elements'
 *              and prepares the inner array 'elements'
 */
Dictionary *create_dict(void );

/*
 * add_item_label: adds item (void*) to the dictionary at given label
 * return 0 if adding was successful otherwise -1
 */
int add_item_label(Dictionary *, char label[], void *);

/*
 * add_item_index: adds item (void*) to the dictionary at given index (int)
 * return 0 if adding was successful otherwise -1
 */
int add_item_index(Dictionary *, int index, void *);


#endif //ALGORITHMS_IN_C_DICT_H
