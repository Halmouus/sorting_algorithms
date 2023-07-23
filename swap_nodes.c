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

void swap_nodes(listint_t **list, listint_t **node_1, listint_t *node_2) {
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

void sswap_nodes(const listint_t *list, listint_t *node_1, listint_t *node_2) {
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
        printf("This is case 1\n--\n");
        printf("Swaping Node 1 = %d and Node 2 = %d\n", node_1->n, node_2->n);

        printf("\n---Operation---\nbackward = temp->prev\n\n");
        backward = temp->prev;
        printf("backward = %d backward->next = %d\n", backward->n, backward->next->n);
        printf("temp->prev = %d temp = %d temp->next = %d\n", temp->prev->n, temp->n, temp->next->n);
        printf("forward->prev = %d forward = %d forward->next = %d\n", forward->prev->n, forward->n, forward->next->n);
        
        printf("\n---Operation---\forward->next->prev = temp\n\n");
        printf("--before--\n");
        printf("backward = %d backward->next = %d\n", backward->n, backward->next->n);
        printf("temp->prev = %d temp = %d temp->next = %d\n", temp->prev->n, temp->n, temp->next->n);
        printf("forward->prev = %d forward = %d forward->next = %d\n", forward->prev->n, forward->n, forward->next->n);
        forward->next->prev = temp;
        printf("--after--\n");
        printf("backward = %d backward->next = %d\n", backward->n, backward->next->n);
        printf("temp->prev = %d temp = %d temp->next = %d\n", temp->prev->n, temp->n, temp->next->n);
        printf("forward->prev = %d forward = %d forward->next = %d\n", forward->prev->n, forward->n, forward->next->n);
        
        printf("\n---Operation---\nbackward->next = temp\n\n");
        printf("--before--\n");
        printf("backward = %d backward->next = %d\n", backward->n, backward->next->n);
        printf("temp->prev = %d temp = %d temp->next = %d\n", temp->prev->n, temp->n, temp->next->n);
        printf("forward->prev = %d forward = %d forward->next = %d\n", forward->prev->n, forward->n, forward->next->n);
        backward->next = temp;
        printf("--after--\n");
        printf("backward = %d backward->next = %d\n", backward->n, backward->next->n);
        printf("temp->prev = %d temp = %d temp->next = %d\n", temp->prev->n, temp->n, temp->next->n);
        printf("forward->prev = %d forward = %d forward->next = %d\n", forward->prev->n, forward->n, forward->next->n);
        
        printf("\n---Operation---\ntemp->next = forward->next\n\n");
        printf("--before--\n");
        printf("backward = %d backward->next = %d\n", backward->n, backward->next->n);
        printf("temp->prev = %d temp = %d temp->next = %d\n", temp->prev->n, temp->n, temp->next->n);
        printf("forward->prev = %d forward = %d forward->next = %d\n", forward->prev->n, forward->n, forward->next->n);
        temp->next = forward->next;
        printf("--after--\n");
        printf("backward = %d backward->next = %d\n", backward->n, backward->next->n);
        printf("temp->prev = %d temp = %d temp->next = %d\n", temp->prev->n, temp->n, temp->next->n);
        printf("forward->prev = %d forward = %d forward->next = %d\n", forward->prev->n, forward->n, forward->next->n);
        
        printf("\n---Operation---\ntemp->prev = forward\n\n");
        printf("--before--\n");
        printf("backward = %d backward->next = %d\n", backward->n, backward->next->n);
        printf("temp->prev = %d temp = %d temp->next = %d\n", temp->prev->n, temp->n, temp->next->n);
        printf("forward->prev = %d forward = %d forward->next = %d\n", forward->prev->n, forward->n, forward->next->n);
        temp->prev = forward;
        printf("--after--\n");
        printf("backward = %d backward->next = %d\n", backward->n, backward->next->n);
        printf("temp->prev = %d temp = %d temp->next = %d\n", temp->prev->n, temp->n, temp->next->n);
        printf("forward->prev = %d forward = %d forward->next = %d\n", forward->prev->n, forward->n, forward->next->n);
        
        printf("\n---Operation---\nforward->next = temp\n\n");
        printf("--before--\n");
        printf("backward = %d backward->next = %d\n", backward->n, backward->next->n);
        printf("temp->prev = %d temp = %d temp->next = %d\n", temp->prev->n, temp->n, temp->next->n);
        printf("forward->prev = %d forward = %d forward->next = %d\n", forward->prev->n, forward->n, forward->next->n);
        forward->next = temp;
        printf("--after--\n");
        printf("backward = %d backward->next = %d\n", backward->n, backward->next->n);
        printf("temp->prev = %d temp = %d temp->next = %d\n", temp->prev->n, temp->n, temp->next->n);
        printf("forward->prev = %d forward = %d forward->next = %d\n", forward->prev->n, forward->n, forward->next->n);
        
        printf("\n---Operation---\nforward->prev = backward\n\n");
        printf("--before--\n");
        printf("backward = %d backward->next = %d\n", backward->n, backward->next->n);
        printf("temp->prev = %d temp = %d temp->next = %d\n", temp->prev->n, temp->n, temp->next->n);
        printf("forward->prev = %d forward = %d forward->next = %d\n", forward->prev->n, forward->n, forward->next->n);
        forward->prev = backward;
        printf("--after--\n");
        printf("backward = %d backward->next = %d\n", backward->n, backward->next->n);
        printf("temp->prev = %d temp = %d temp->next = %d\n", temp->prev->n, temp->n, temp->next->n);
        printf("forward->prev = %d forward = %d forward->next = %d\n", forward->prev->n, forward->n, forward->next->n);
        /*
        printf("\n---Operation---\nforward->next->prev = temp\n\n");
        printf("--before--\n");
        printf("backward = %d backward->next = %d\n", backward->n, backward->next->n);
        printf("temp->prev = %d temp = %d temp->next = %d\n", temp->prev->n, temp->n, temp->next->n);
        printf("forward->prev = %d forward = %d forward->next = %d\n", forward->prev->n, forward->n, forward->next->n);
        forward->next->prev = temp;
        printf("--after--\n");
        printf("backward = %d backward->next = %d\n", backward->n, backward->next->n);
        printf("temp->prev = %d temp = %d temp->next = %d\n", temp->prev->n, temp->n, temp->next->n);
        printf("forward->prev = %d forward = %d forward->next = %d\n", forward->prev->n, forward->n, forward->next->n);
        */
        printf("\n---Operation---\nbackward->next = forward\n\n");
        printf("--before--\n");
        printf("backward = %d backward->next = %d\n", backward->n, backward->next->n);
        printf("temp->prev = %d temp = %d temp->next = %d\n", temp->prev->n, temp->n, temp->next->n);
        printf("forward->prev = %d forward = %d forward->next = %d\n", forward->prev->n, forward->n, forward->next->n);
        backward->next = forward;
        printf("--after--\n");
        printf("backward = %d backward->next = %d\n", backward->n, backward->next->n);
        printf("temp->prev = %d temp = %d temp->next = %d\n", temp->prev->n, temp->n, temp->next->n);
        printf("forward->prev = %d forward = %d forward->next = %d\n", forward->prev->n, forward->n, forward->next->n);
        
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
        printf("\n--Operation---\nbackward = temp->prev\n\n");
        printf("--before--\n");
        printf("backward = %d backward->next = %d\n", backward->n, backward->next->n);
        printf("temp->prev = %d temp = %d temp->next = %d\n", temp->prev->n, temp->n, temp->next->n);
        printf("forward->prev = %d forward = %d forward->next = %d\n", forward->prev->n, forward->n, forward->next->n);
        backward = temp->prev;
        printf("--after--\n");
        printf("backward = %d backward->next = %d\n", backward->n, backward->next->n);
        printf("temp->prev = %d temp = %d temp->next = %d\n", temp->prev->n, temp->n, temp->next->n);
        printf("forward->prev = %d forward = %d forward->next = %d\n", forward->prev->n, forward->n, forward->next->n);
        
        printf("\n--Operation---\ntemp->next = NULL\n\n");
        printf("--before--\n");
        printf("backward = %d backward->next = %d\n", backward->n, backward->next->n);
        printf("temp->prev = %d temp = %d temp->next = %d\n", temp->prev->n, temp->n, temp->next->n);
        printf("forward->prev = %d forward = %d forward->next = %d\n", forward->prev->n, forward->n, forward->next->n);
        temp->next = NULL;
        printf("--after--\n");
        printf("backward = %d backward->next = %d\n", backward->n, backward->next->n);
        printf("temp->prev = %d temp = %d temp->next = %d\n", temp->prev->n, temp->n, temp->next->n);
        printf("forward->prev = %d forward = %d forward->next = %d\n", forward->prev->n, forward->n, forward->next->n);
        
        printf("\n--Operation---\ntemp->prev = forward\n\n");
        printf("--before--\n");
        printf("backward = %d backward->next = %d\n", backward->n, backward->next->n);
        printf("temp->prev = %d temp = %d temp->next = %d\n", temp->prev->n, temp->n, temp->next->n);
        printf("forward->prev = %d forward = %d forward->next = %d\n", forward->prev->n, forward->n, forward->next->n);
        temp->prev = forward;
        printf("--after--\n");
        printf("backward = %d backward->next = %d\n", backward->n, backward->next->n);
        printf("temp->prev = %d temp = %d temp->next = %d\n", temp->prev->n, temp->n, temp->next->n);
        printf("forward->prev = %d forward = %d forward->next = %d\n", forward->prev->n, forward->n, forward->next->n);
        
        printf("\n--Operation---\nforward->prev = backward\n\n");
        printf("--before--\n");
        printf("backward = %d backward->next = %d\n", backward->n, backward->next->n);
        printf("temp->prev = %d temp = %d temp->next = %d\n", temp->prev->n, temp->n, temp->next->n);
        printf("forward->prev = %d forward = %d forward->next = %d\n", forward->prev->n, forward->n, forward->next->n);
        forward->prev = backward;
        printf("--after--\n");
        printf("backward = %d backward->next = %d\n", backward->n, backward->next->n);
        printf("temp->prev = %d temp = %d temp->next = %d\n", temp->prev->n, temp->n, temp->next->n);
        printf("forward->prev = %d forward = %d forward->next = %d\n", forward->prev->n, forward->n, forward->next->n);
        
        printf("\n--Operation---\nbackward->next = forward\n\n");
        printf("--before--\n");
        printf("backward = %d backward->next = %d\n", backward->n, backward->next->n);
        printf("temp->prev = %d temp = %d temp->next = %d\n", temp->prev->n, temp->n, temp->next->n);
        printf("forward->prev = %d forward = %d forward->next = %d\n", forward->prev->n, forward->n, forward->next->n);
        backward->next = forward;
        printf("--after--\n");
        printf("backward = %d backward->next = %d\n", backward->n, backward->next->n);
        printf("temp->prev = %d temp = %d temp->next = %d\n", temp->prev->n, temp->n, temp->next->n);
        printf("forward->prev = %d forward = %d forward->next = %d\n", forward->prev->n, forward->n, forward->next->n);
        
    }
    else if (!node_1->prev && node_2->next) {
        printf("This is case 3 (node_1 is head)\n");
        
        printf("\n--Operation---\nforward->next = temp\n\n");
        printf("--before--\n");
        //printf("temp->prev = %d temp = %d temp->next = %d\n", temp->prev->n, temp->n, temp->next->n);
        printf("forward->prev = %d forward = %d forward->next = %d\n", forward->prev->n, forward->n, forward->next->n);
        print_list(list);
        forward->next = temp;
        printf("--after--\n");
        //printf("temp->prev = %d temp = %d temp->next = %d\n", temp->prev->n, temp->n, temp->next->n);
        printf("forward->prev = %d forward = %d forward->next = %d\n", forward->prev->n, forward->n, forward->next->n);
        print_list(list);

        printf("\n--Operation---\ntemp->next = forward->next\n\n");
        printf("--before--\n");
        printf("temp = %d temp->next = %d\n", temp->n, temp->next->n);
        printf("forward->prev = %d forward = %d forward->next = %d forward->next->next = %d forward->next->prev = %d\n", forward->prev->n, forward->n, forward->next->n, forward->next->next->n, forward->next->prev->n);
        print_list(list);
        temp->next = forward->next;
        printf("--after--\n");
        printf("temp = %d temp->next = %d\n", temp->n, temp->next->n);
        printf("forward->prev = %d forward = %d forward->next = %d forward->next->next = %d forward->next->prev = %d\n", forward->prev->n, forward->n, forward->next->n, forward->next->next->n, forward->next->prev->n);
        print_list(list);
        
        printf("\n--Operation---\nforward->next->prev = temp\n\n");
        printf("--before--\n");
        printf("temp = %d temp->next = %d\n", temp->n, temp->next->n);
        printf("forward->prev = %d forward = %d forward->next = %d\n", forward->prev->n, forward->n, forward->next->n);
        print_list(list);
        forward->next->prev = temp;
        printf("--after--\n");
        printf("temp = %d temp->next = %d\n", temp->n, temp->next->n);
        printf("forward->prev = %d forward = %d forward->next = %d\n", forward->prev->n, forward->n, forward->next->n);
        print_list(list);

        printf("\n--Operation---\ntemp->prev = forward\n\n");
        printf("--before--\n");
        printf("temp = %d temp->next = %d\n", temp->n, temp->next->n);
        printf("forward->prev = %d forward = %d forward->next = %d\n", forward->prev->n, forward->n, forward->next->n);
        print_list(list);
        temp->prev = forward;
        printf("--after--\n");
        printf("temp->prev = %d temp = %d temp->next = %d\n", temp->prev->n, temp->n, temp->next->n);
        printf("forward->prev = %d forward = %d forward->next = %d\n", forward->prev->n, forward->n, forward->next->n);
        print_list(list);


        printf("\n--Operation---\nforward->prev = NULL\n\n");
        printf("--before--\n");
        printf("temp->prev = %d temp = %d temp->next = %d\n", temp->prev->n, temp->n, temp->next->n);
        printf("forward->prev = %d forward = %d forward->next = %d\n", forward->prev->n, forward->n, forward->next->n);
        print_list(list);
        forward->prev = NULL;
        printf("--after--\n");
        printf("temp->prev = %d temp = %d temp->next = %d\n", temp->prev->n, temp->n, temp->next->n);
        printf("forward = %d forward->next = %d\n", forward->n, forward->next->n);
        print_list(list);
        
    }
    else {
        printf("This is case 4 (list contains 2 elemts)\n");
        temp->next = NULL;
        temp->prev = forward;
        forward->prev = NULL;
        forward->next = temp;
    }
}