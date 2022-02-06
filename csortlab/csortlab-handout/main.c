#include <stdio.h>
#include "sort.h"

void print_array(int *array, size_t size) {
    for (size_t i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// expand upon this file with your own test cases

int main() {
    int arr[] = {42, 2, 67, -3, 90, 10};
    size_t n = 6;

    printf("Before: ");
    print_array(arr, n);

    sort(arr, n);

    printf("\nAfter: ");
    print_array(arr, n);

    return 0;
}