
/**
 * @details
 * A doubly linked list is a data structure with a sequence
 * of components called nodes. Within that nodes there are
 * there elements: a value recorded, a pointer to the next
 * node, and a pointer to the previous node.
 * 
 * In this implementation, the functions of creating the list,
 * inserting by position, deleting by position, searching 
 * for value, printing the list, and an example of how the 
 * list works were coded.
 * 
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    double value;
    struct list *next, *prev;
} List;

List *create(double value);

List *insert(List *list, double value, int pos);

List *delete(List *list, int pos);

int search(List *list, double value);


List *create(double value)
{
    List *new_list = (List *)malloc(sizeof(List));
    new_list->value = value;
    new_list->next = NULL;
    new_list->prev = NULL;
    return new_list;
}

/**
 * insertion by position into the list function
 *  
 * 
 */
List *insert(List *list, double value, int pos)
{
    // list NULL case
    if(list == NULL)
    {
        list = create(value);
        return list;
    }

    // position existing case
    if(pos > 0)
    {
        List *cpy = list, *tmp = cpy;

        int flag = 1, index = 1, size = 0;

        // need to know size
        while (tmp != NULL)
        {
            size++;
            tmp = tmp->next;
        }
        
        // first position case
        if(pos == 1)
        {
            List *new_node = create(value);
            new_node->next = cpy;
            cpy->prev = new_node;
            list = new_node;
            return list;
        }

        // position existing in list range case
        if(size + 2 > pos)
        {
            while(index < pos && cpy->next != NULL)
            {
                index++;
                cpy = cpy -> next;
                flag++;
            }

            List *new_node = (List *)malloc(sizeof(List));
            new_node->value = value;

            // position into list with no poiting for NULL -> index == pos
            if(flag == pos)
            {
                cpy->prev->next = new_node;
                new_node->next = cpy;
                new_node->prev = cpy->prev;
                cpy->prev = new_node;
            }

            // last position case
            if(flag < pos)
            {
                new_node->next = cpy->next;
                new_node->prev = cpy;
                cpy->next = new_node;
            }
        }
        return list;
    }
}