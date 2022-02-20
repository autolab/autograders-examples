#include "tests.h"
#include "sort.h"

#define LONG_ARR_LEN 10000
#define SHORT_ARR_LEN 100

int cmp(const void *a, const void *b) {
   return ( *(int*)a - *(int*)b );
}

bool arrays_identical(int *arr1, int *arr2, size_t n) {
    for (size_t i = 0; i < n; i++) {
        if (arr1[i] != arr2[i]) {
            return false;
        }
    }
    return true;
}

/**
 * @brief Tests for basic sorting functionality
 * 
 * Tests the sorting implementation against 30 arbitrary arrays of length
 * [2, 20], with 1 point awarded per array correctly sorted
 * Max score: 30
 * 
 * @return an integer score, out of 30
 */
int test_basic(void) {
    int score = 0;

    srand(31415926); // fixed seed for reproducibility

    int arr[20];
    int sorted[20];
    
    for (int i = 0; i < 30; i++) {
        size_t len = rand() % 19 + 2;

        for (size_t j = 0; j < len; j++) {
            arr[j] = rand();
            sorted[j] = arr[j];
        }

        qsort(sorted, len, sizeof(int), cmp);

        sort(arr, len);

        if (arrays_identical(arr, sorted, len)) {
            score++;
        }
    }

    return score;
}

/**
 * @brief Tests for edge cases related to length
 * 
 * Tests the sorting implementation against the following possible edge cases:
 * - length 0 (2 points)
 * - length 1 (8 points)
 * - very large length (10 points)
 * 
 * @return an integer score, out of 20
 */
int test_length_edge_cases(void) {
    int score = 0;

    srand(271828); // fixed seed for reproducibility

    int empty_arr[0] = {};
    sort(empty_arr, 0);
    // test case passes if the implementation does not segfault
    score += 2;

    int arr_len_1[8];
    int sorted_len_1[8];
    for (int i = 0; i < 8; i++) {
        arr_len_1[i] = rand();
        sorted_len_1[i] = arr_len_1[i];
    }

    // sort for each element as a check for any array out of bound writes
    for (int i = 0; i < 8; i++) {
        sort(arr_len_1, 1);
    }

    for (int i = 0; i < 8; i++) {
        if (arr_len_1[i] == sorted_len_1[i]) {
            score++;
        }
    }

    int arr_long[LONG_ARR_LEN];
    int sorted_long[LONG_ARR_LEN];
    for (int i = 0; i < LONG_ARR_LEN; i++) {
        arr_long[i] = rand();
        sorted_long[i] = arr_long[i];
    }

    sort(arr_long, LONG_ARR_LEN);
    qsort(sorted_long, LONG_ARR_LEN, sizeof(int), cmp);

    if (arrays_identical(arr_long, sorted_long, LONG_ARR_LEN)) {
        score += 10;
    }

    return score;
}

/**
 * @brief Tests for timing of the sort implementation
 * 
 * Tests the sorting implementation against two arrays of lengths [100, 10k],
 * measuring the time spent on each sort. Then compares the ratio between
 * the time. Checks for an O(n log n) implementation.
 * 
 * 50 points - ratio <= 500 (O(n log n))
 * 25 points - 500 < ratio <= 1.5k
 * 10 points - 1.5k < ratio <= 15k (approx 0(n^2))
 * 0 points - ratio > 15k
 * 
 * @return an integer score, out of 50
 */
int test_timing(void) {
    clock_t start, end;
    double short_time, long_time, ratio;

    srand(31415926); // fixed seed for reproducibility

    int arr_short[SHORT_ARR_LEN];
    int sorted_short[SHORT_ARR_LEN];

    for (int i = 0; i < SHORT_ARR_LEN; i++) {
        arr_short[i] = rand();
        sorted_short[i] = arr_short[i];
    }

    start = clock();
    sort(arr_short, SHORT_ARR_LEN);
    end = clock();
    short_time = (double)(end - start) / CLOCKS_PER_SEC;

    qsort(sorted_short, SHORT_ARR_LEN, sizeof(int), cmp);

    if (!arrays_identical(arr_short, sorted_short, SHORT_ARR_LEN)) {
        return 0;
    }

    int arr_long[LONG_ARR_LEN];
    int sorted_long[LONG_ARR_LEN];

    for (int i = 0; i < LONG_ARR_LEN; i++) {
        arr_long[i] = rand();
        sorted_long[i] = arr_long[i];
    }

    start = clock();
    sort(arr_long, LONG_ARR_LEN);
    end = clock();
    long_time = (double)(end - start) / CLOCKS_PER_SEC;

    qsort(sorted_long, LONG_ARR_LEN, sizeof(int), cmp);

    if (!arrays_identical(arr_long, sorted_long, LONG_ARR_LEN)) {
        return 0;
    }

    ratio = long_time / short_time;

    if (ratio <= 500) {
        return 50;
    } else if (ratio <= 1500) {
        return 25;
    } else if (ratio <= 15e3) {
        return 10;
    } else {
        return 0;
    }
}
