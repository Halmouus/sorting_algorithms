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
 * get_gap - returns the gap using the Knuth sequence
 * @size: size of a given array
 * Return: the gap
*/
int get_gap(size_t size) {
    int h = 1, n = (int)size;
    while (h < n)
        h = 3 * h + 1;
    h = (h - 1) / 3;
    return h;
}

/**
 * shell_sort - sorts an array of integers.
 * @array: array of integers to sort.
 * @size: size of the array.
 */

void shell_sort(int *array, size_t size) {
    int gap = get_gap(size), n = (int)size;
    int i = 0, j, temp, end;
    for (int i = 0; i < n; i++)
    {
        continue;
    }
    while (i + gap < n)
    {
        j = (n - 1) / (gap + i);
        if (array[i] > array[gap]){
            swap_int(&array[i], &array[gap]);
            /*incomplete program*/


        }
        i++;
    }
    
    
}
