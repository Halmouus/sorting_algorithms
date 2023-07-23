#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers.
 * @list: doubly-linked list of integers to sort
 */


void insertion_sort_list(listint_t **list) {
    
    listint_t *temp = NULL, *forward = NULL, *backward = NULL;
    int swap_n;
    if (!list)
        return;
    temp = *list;
    while (temp && temp->next)
    {
        swap_n = 0;
        forward = temp->next;
        while (temp->n > forward->n && temp->next) {
                swap_nodes(&list, &temp, forward);
                swap_n++;
                while (forward->prev && )
                    backward = forward->prev;
                    while (forward->n > backward->n) {
                        swap_nodes(&list, &forward, backward);
                        swap_n++;
                        if for
                    }
                forward = temp->next;
        }
        if (swap_n == 0)
            break;
        if (temp->next)
            temp = temp->next;
    }
    
}

/*
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
*/