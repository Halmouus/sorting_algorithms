#include "sort.h"

/**
 * swap_int - function that swaps the values of two integers
 * @a: pointer to the first integer to be swapped
 * @b: pointer to the second integer to be swapped
 */
void swap_int(int *a, int *b)
{
int c;
c = *a;
*a = *b;
*b = c;
}

/**
 * bubble_sort - sorts an array of integers.
 * @array: array of integers to sort.
 * @size: size of the array.
 */

void bubble_sort(int *array, size_t size)
{
unsigned long int i, j, swap = 1;
for (i = 0; i < size - 1; i++)
{
swap = 0;
for (j = 0; j < size - i - 1; j++)
{
if (array[j] > array[j + 1])
{
swap_int(&array[j], &array[j + 1]);
swap = 1;
}
print_array(array, size);
}
if (swap == 0)
{
break;
}
}
}
