#include "sort.h"

/**
 * quick_sort - sorts an array of integers.
 * @array: array of integers to sort.
 * @size: size of the array.
 */

void quick_sort(int *array, size_t size) {
   /*int i = -1, j = 0, pivot;
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
        strncpy(array_right, );
        quick_sort(array_right, (size_t)(n - 1));
    }*/

    quick_sort_wraper(array, size, 0, (int)(size - 1));
}

void quick_sort_wraper(int *array, size_t size, int start_idx, int end_idx) {
    printf("\n----------Start of the algorithm-------------\n");
    printf("Size = %ld, start idx = %d, end idx = %d\n", size, start_idx, end_idx);
    int n = end_idx - start_idx;
    printf("n = %d\n", n);
    int pivot_idx = end_idx;
    printf("Pivot_index = %d\n", pivot_idx);
    int pivot = array[pivot_idx];
    printf("Pivot = %d\n", array[pivot_idx]);
    int j = start_idx;
    int arr_size = n + j;
    printf("j = %d\n", j);
    int i = j - 1;
    printf("i = %d\n", i);
    if (n < 1) {
        printf("Goodbye I'm out (n = %d)\n", n);
        return;
    }
    while (j <= arr_size)
    {
        if (j == arr_size) {
            i++;
            printf("j = %d - n = %d\nfinal round! - arr[%d] = %d - arr[%d] = %d\n", j, n, i, array[i], n, pivot);
            printf("swapping array[%d] = %d with array[%d] = %d\n", i, array[i], j, array[j]);
            swap_int(&array[i], &array[j]);
            print_array(array, size);
            break;
        }
        if (array[j] >= pivot) {
            printf("array[%d] = %d >= %d. Skip, we increment j..\n", j, array[j], pivot);
            j++;
        }       
        if (array[j] < pivot) {
            printf("array[%d] = %d < %d. We increment i = %d\n", j, array[j], pivot, i);
            i++;
            printf("swapping array[%d] = %d with array[%d] = %d\n", i, array[i], j, array[j]);
            swap_int(&array[i],&array[j]);
            print_array(array, size);
            j++;
        }
    }
    if (i < n && n > 0 && i > 1) {
        printf("entering recusrion bloc\n");
        quick_sort_wraper(array, size, i + 1, end_idx);
        printf("*****************Second Part******************\n");
        quick_sort_wraper(array, size, 0, i - 1);
    }
}
