#include "sort.h"

/**
 * bubble_sort - sorts an array of integers.
 * @array: array of integers to sort.
 * @size: size of the array.
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	int swap = 0;

	if (array == NULL || size < 2)
		return;

	while (swap == 0)
	{
		swap = 1;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_int(array + i, array + i + 1);
				print_array(array, size);
				swap = 0;
			}
		}
		len--;
	}
}
