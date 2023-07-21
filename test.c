#include "sort.h"

int main(void) {
    int a = 5;
    int b = 10;
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);
    printf("a = %d b = %d\n", a, b);
    swap_int(&a, &b);
    printf("a = %d b = %d\n size of array = %ld\n", a, b, n);
    return 0;
}