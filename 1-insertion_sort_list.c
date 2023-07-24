#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers.
 * @list: doubly-linked list of integers to sort
 */


void insertion_sort_list(listint_t **list) {
    
    listint_t *temp = NULL, *forward = NULL, *backward = NULL;
    int swaps;
    if (!list || !(*list) || !(*list)->next)
        return;
    temp = *list;
    forward = (*list)->next;
    while (temp && temp->next)
    {
        swaps = 0;
        forward = temp->next;
        if (temp->n > forward->n)
        {
            swap_nodes(list, &temp, forward);
            //print_list(*list);
            printf("This is an infinite loop! (1)\n");
            swaps++;
            while (forward->prev)
            {
                backward = forward->prev;
                if (backward->n > forward->n)
                {
                    printf("Before: forward->n = %d backward->n = %d\n", forward->n, backward->n);
                    swap_nodes(list, &forward, backward);
                    //print_list(*list);
                    printf("This is an infinite loop! (2)\n");
                    printf("After: forward->n = %d backward->n = %d\n", forward->n, backward->n);
                    swaps++;
                } else {
                    break;
                }
            }
        }
        if (swaps == 0)
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