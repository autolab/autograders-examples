/* Refsol for Merge Two Sorted Lists Lab */
#include "mergesortedlists.h"

#include <stdlib.h>

/**
 * @brief Merges two sorted lists into one sorted list
 *
 * This function takes the heads of two ascending sorted lists 
 * and splices them together into one sorted singly-linked list
 * in ascending order.
 * 
 * Do not allocate any additional memory with malloc/calloc!
 *
 * @pre The input lists are sorted
 * 
 * @param[in] list1 The head of the first list
 * @param[in] list2 The head of the second list
 *
 * @return A pointer to the head of the merged list
 * @return NULL if both lists are empty
 */

list_t *mergeTwoSortedLists(list_t *list1, list_t *list2) {
  if (list1 == NULL) {
    return list2;
  } else if (list2 == NULL) {
    return list1;
  }

  list_t *head, *p, *curr1, *curr2;
  if (list1->val < list2->val) {
    head = p = list1;
    curr1 = list1->next;
    curr2 = list2;
  } else {
    head = p = list2;
    curr2 = list2->next;
    curr1 = list1;
  }
  
  while (curr1 != NULL && curr2 != NULL) {
    if (curr1->val > curr2->val) {
      p->next = curr2;
      p = curr2;
      curr2 = curr2->next;
    } else {
      p->next = curr1;
      p = curr1;
      curr1 = curr1->next;
    }
  }

  if (curr1 != NULL) {
    p->next = curr1;
  }

  if (curr2 != NULL) {
    p->next = curr2;
  }

  return head;
}
