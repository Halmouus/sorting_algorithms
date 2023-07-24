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
 * min_arr - function that returns the minimum value of an int array
 * @array: array to be scanned
 * @start: starting index of the scan
 * @n: size of the array
 * Return: index of min value of the array
*/
int min_arr(int *array, int start, size_t n)
{
int min;
int i = start, min_index;
if (!array || n == 0)
return (-1);
min_index = start;
min = array[start];
while (i < (int)n)
{
if (array[i] < min)
{
min = array[i];
min_index = i;
}
i++;
}
return (min_index);
}

/**
 * selection_sort - sorts an array of integers.
 * @array: array of integers to sort.
 * @size: size of the array.
 */

void selection_sort(int *array, size_t size)
{
int i = 0, min_index;
if (!array || size < 2)
return;
while (i < (int)size)
{
min_index = min_arr(array, i, size);
if (min_index == -1)
return;
if (array[i] > array[min_index])
{
swap_int(&array[i], &array[min_index]);
print_array(array, size);
}
i++;
}
}
