//
// Created by  雨下的文 on 2021/2/21.
//

#include "dict.h"
#include <stdio.h>
#include <stdlib.h>

/* simple constructor */
Dictionary *create_dict(void )
{
    Dictionary *p_dic = malloc(sizeof (Dictionary));
    if(p_dic)
    {
        p_dic->number_of_elements = 0;

        // initializes the elements of the array with NULL-pointer
        for(int i = 0; i < MAXELEMENTS; i++)
        {
            p_dic->elements[i] = NULL;
        }
        return p_dic;
    } else
    {
        printf("unable to create a dictionary\n");
        return NULL;
    }
}

// utility function
// sdbm hash algorithm
// returns a hashcode for the given string 's'
int get_hash(char s[])
{
    unsigned int hash_code = 0;

    // iterates over string at each character
    for(int counter = 0; s[counter] != '\0'; counter++)
    {
        // actual computing of the hash code
        hash_code =
                s[counter] + (hash_code << 6) + (hash_code << 16) - hash_code;
    }
    // % modulo is for fitting the index in array
    return hash_code % MAXELEMENTS;
}

