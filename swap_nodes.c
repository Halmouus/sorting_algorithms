#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

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

void swap_nodes(listint_t *node_1, listint_t *node_2) {
    listint_t *temp = NULL, *forward = NULL, *backward = NULL;
    if (!node_1 || !node_2 || node_1 == node_2) {
        printf("Nodes are null!\n");
        return;
        }
    if (node_1->next != node_2 || node_2->prev != node_1) {
        printf("Nodes 1 = %d and Node 2 = %d are not linked!\n", node_1->n, node_2->n);
        printf("Nodes 1 -> next = %d and Node 2 -> next = %d are not linked!\n", node_1->next->n, node_2->next->n);
        printf("Nodes 1 -> prev = %d and Node 2 -> prev = %d are not linked!\n", node_1->prev->n, node_2->prev->n);
        return;
        }
    temp = node_1;
    forward = node_2;
    if (node_1->prev && node_2->next) {
        printf("This is case 1\n");
        printf("Swaping Node 1 = %d and Node 2 = %d\n", node_1->n, node_2->n);
        backward = temp->prev;
        backward->next = temp;
        temp->next = forward->next;
        temp->prev = forward;
        forward->next = temp;
        forward->prev = backward;
        forward->next->prev = temp;
        backward->next = forward;
        /*
        backward = temp->prev;
        temp->next = forward->next;
        forward->prev = backward;
        forward->next = temp;
        backward->next = forward;
        forward->next->prev = forward;
        temp->prev = forward;*/
        printf("Now Node 1 = %d and Node 2 = %d\n", temp->n, forward->n);
        printf("Node 1->next = %d Node 1->prev = %d\n", temp->next->n, temp->prev->n);
        printf("Node2->next = %d Node2->prev= %d\n", forward->next->n, forward->prev->n);
    }
    else if (node_1->prev && !node_2->next) {
        printf("This is case 2 (node_2 is tail)\n");
        backward = node_1->prev;
        temp->next = NULL;
        temp->prev = forward;
        forward->prev = backward;
        backward->next = forward;
    }
    else if (!node_1->prev && node_2->next) {
        printf("This is case 3 (node_1 is head)\n");
        temp->next = forward->next;
        temp->prev = forward;
        forward->next = temp;
        forward->next->prev = temp;
        forward->prev = NULL;
    }
    else {
        printf("This is case 4 (list contains 2 elemts)\n");
        temp->next = NULL;
        temp->prev = forward;
        forward->prev = NULL;
        forward->next = temp;
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