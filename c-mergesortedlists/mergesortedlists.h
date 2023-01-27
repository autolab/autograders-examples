/**
 * @file mergesortedlists.h
 * @brief Header file for merging two sorted list function implementation.
 */

typedef struct list_ele {
    int val;
    struct list_ele *next;
} list_t;

list_t *mergeTwoSortedLists(list_t *list1, list_t *list2);
