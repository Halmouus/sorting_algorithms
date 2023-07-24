#include "sort.h"

/**
 * quick_sort - sorts an array of integers.
 * @array: array of integers to sort.
 * @size: size of the array.
 */

void quick_sort(int *array, size_t size) {
    quick_sort_wraper(array, size, 0, (int)(size - 1));
}

void quick_sort_wraper(int *array, size_t size, int start_idx, int end_idx) {
    int n = end_idx - start_idx;
    int pivot_idx = end_idx;
    int pivot = array[pivot_idx];
    int j = start_idx;
    int arr_size = n + j;
    int i = j - 1;
    if (n < 1) {
        return;
    }
    while (j <= arr_size)
    {
        if (j == arr_size) {
            i++;
            swap_int(&array[i], &array[j]);
            print_array(array, size);
            break;
        }
        if (array[j] >= pivot) {
            j++;
        }       
        if (array[j] < pivot) {
            i++;
            swap_int(&array[i],&array[j]);
            print_array(array, size);
            j++;
        }
    }
    if (n > 0 && i > 1) {
        quick_sort_wraper(array, size, i + 1, end_idx);
        quick_sort_wraper(array, size, 0, i - 1);
    }
}
