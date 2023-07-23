#include "sort.h"

/**
 * selection_sort - sorts an array of integers.
 * @array: array of integers to sort.
 * @size: size of the array.
 */

void selection_sort(int *array, size_t size) {
    int i = 0, min_index;
    if (!array || size < 2)
        return;
    while (i < (int)size)  
    {   
        min_index = min_arr(array, i, size);
        if (min_index == -1)
            return;
        if (array[i] > array[min_index]) {
            swap_int(&array[i], &array[min_index]);
            print_array(array, size);
        }
        i++;
    }
}
