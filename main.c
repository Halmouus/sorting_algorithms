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
    int array[] = {14, -5, 99, 5, 14, 34, 105, 1024, -2005, 19, -5, -5, 0, 0};
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("****************\n");
    quick_sort(array, n);
    printf("****************\n");
    print_array(array, n);
    return (0);
}