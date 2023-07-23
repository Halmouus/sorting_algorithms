#include "sort.h"

/**
 * quick_sort - sorts an array of integers.
 * @array: array of integers to sort.
 * @size: size of the array.
 */

void quick_sort(int *array, size_t size) {
    int i = -1, j = 0, pivot;
    int n = (int)size;
    int *array_left, *array_right;
    size_t size_left, size_right;
    pivot = array[n - 1];
    if (size < 2) {
        return;
    }
    while (j < n)
    {
        if (j == n - 1) {
            i++;
            //printf("j = %d - n = %d\nfinal round! - arr[%d] = %d - arr[%d] = %d\n", j, n, i, array[i], n-1, pivot);
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
    if (i > -1 && i < n)
    {
        array_left = malloc(sizeof(int) * (i + 1));
        strncpy(array_left, array, i);
        quick_sort(array_left, (size_t)(i + 1));
        array_right = malloc(sizeof(int) * (n - i));
        strncpy(array_right, )
        quick_sort(array_right, (size_t)(n - 1));
    }

}
