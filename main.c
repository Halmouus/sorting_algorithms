#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int array[] = {1, 2, 3, 4, 5, 6};
    listint_t *list;
    size_t n = sizeof(array) / sizeof(array[0]);
    list = create_listint(array, n);
    //print_array(array, n);
    print_list(list);
    printf("list = %d, list->next = %d\n", list->n, list->next->n);
    printf("list = %d, list->next->prev = %d\n", list->n, list->next->prev->n);
    swap_nodes(list->next, list->next->next);
    print_list(list);
    printf("list = %d, list->next = %d\n", list->n, list->next->n);
    printf("list = %d, list->next->prev = %d\n", list->n, list->next->prev->n);
    swap_nodes(list->next->next, list->next->next->next);
    //swap_nodes(list->next, list->next->next);
    print_list(list);
    //swap_nodes(list->next->next, list->next->next->next);
    print_list(list);
}