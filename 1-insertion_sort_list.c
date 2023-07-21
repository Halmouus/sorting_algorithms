#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers.
 * @list: doubly-linked list of integers to sort
 */

void insertion_sort_list(listint_t **list) {
    listint_t *temp = NULL, *forward = NULL, *backward = NULL, *swap;
    temp = *list;
    while (temp->next)
    {
        forward = temp->next;
        if (temp->prev)
        backward = temp->prev;  
        if (forward->n < temp->n) {
            temp->next = forward->next;
            temp->prev = forward;
            forward->prev = backward;
            forward->next = temp;
            backward->next = forward;
            forward->next->prev = temp;
            swap = forward;
            while (swap->prev && (swap->n <))
            {
                if (swap->n)
            }
            
        }
        temp = temp->next;
    }
    
}
