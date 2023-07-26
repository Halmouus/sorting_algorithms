#include "sort.h"

/**
 * create_listint - Creates a doubly linked list from an array of integers
 *
 * @array: Array to convert to a doubly linked list
 * @size: Size of the array
 *
 * Return: Pointer to the first element of the created list. NULL on failure
 */
listint_t *create_listint(const int *array, size_t size)
{
    listint_t *list;
    listint_t *node;
    int *tmp;

    list = NULL;
    while (size--)
    {
        node = malloc(sizeof(*node));
        if (!node)
            return (NULL);
        tmp = (int *)&node->n;
        *tmp = array[size];
        node->next = list;
        node->prev = NULL;
        list = node;
        if (list->next)
            list->next->prev = list;
    }
    return (list);
}

/**
 * swap_list - swaps 2 nodes of a doubly linked list.
 * @list: head of doubly-linked list of integers
 * @node_1: pointer to node to swap
 * @node_2: pointer to node to swap
 */
void swap_list(listint_t **list, listint_t **node_1, listint_t *node_2) {
    	(*node_1)->next = node_2->next;
        if (node_2->next != NULL)
            node_2->next->prev = *node_1;
        node_2->prev = (*node_1)->prev;
        node_2->next = *node_1;
        if ((*node_1)->prev != NULL)
            (*node_1)->prev->next = node_2;
        else
            *list = node_2;
        (*node_1)->prev = node_2;
        *node_1 = node_2->prev;
}

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
            swap_list(list, &temp, forward);
            /*infinite loop.. need to fix*/
            swaps++;
            while (forward->prev)
            {
                backward = forward->prev;
                if (backward->n > forward->n)
                {
                    printf("Before: forward->n = %d backward->n = %d\n", forward->n, backward->n);
                    swap_list(list, &forward, backward);
                    /*another infinite loop..*/
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