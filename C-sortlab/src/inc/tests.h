#ifndef _TESTS_H_
#define _TESTS_H_

#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

/**
 * @brief Tests for basic sorting functionality
 * 
 * Tests the sorting implementation against 30 arbitrary arrays of length
 * [2, 20], with 1 point awarded per array correctly sorted
 * Max score: 30
 * 
 * @return an integer score, out of 30
 */
int test_basic(void);

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
int test_length_edge_cases(void);

/**
 * @brief Tests for timing of the sort implementation
 * 
 * Tests the sorting implementation against two arrays of lengths [1k, 1M],
 * measuring the time spent on each sort. Then compares the ratio between
 * the time. Checks for an O(n log n) implementation.
 * 
 * 50 points - ratio <= 10k
 * 25 points - 10k < ratio <= 1M
 * 10 points - 1M < ratio <= 10M
 * 0 points - ratio > 10M
 * 
 * @return an integer score, out of 50
 */
int test_timing(void);

#endif