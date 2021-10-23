#include <stdio.h>
#include "sort.h"

void print_array(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {42, 2, 67, 3, 90, 10};
    size_t n = 6;

    printf("Before: ");
    print_array(arr, n);

    sort(arr, n);

    printf("\nAfter: ");
    print_array(arr, n);

    return 0;
}