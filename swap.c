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
 * return: index of min value of the array
*/
int min_arr(int *array, int start, size_t n) {
int min;
int i = start, min_index;
if (!array || n == 0) {
printf("Shit happened bro\n!");
return -1;
}
min_index = start;
min = array[start];
while (i < (int)n)
{
if (array[i] < min) {
min = array[i];
min_index = i;
}
i++;
}
return min_index;
}