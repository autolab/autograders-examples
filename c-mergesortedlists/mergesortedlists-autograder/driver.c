// Autograder for Merge Two Sorted Lists Lab
#include "mergesortedlists.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

list_t *refsol(list_t *list1, list_t *list2) {
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

list_t *createRandomList() {
  list_t *head, *p;
  head = malloc(sizeof(list_t));
  p = head;

  for (int i = 0; i < 20; i++) {
    p->val = rand();
    p->next = malloc(sizeof(list_t));
    p = p->next;
  }
  p->val = rand();
  p->next = NULL;
  
  return head;
}

void swap(list_t *a, list_t *b) 
{ 
    int temp = a->val; 
    a->val = b->val; 
    b->val = temp; 
} 

void bubbleSort(list_t *start) 
{ 
    int swapped; 
    list_t *ptr1; 
    list_t *lptr = NULL; 
  
    if (start == NULL) 
        return; 
  
    do
    { 
        swapped = 0; 
        ptr1 = start; 
  
        while (ptr1->next != lptr) 
        { 
            if (ptr1->val > ptr1->next->val) 
            { 
                swap(ptr1, ptr1->next); 
                swapped = 1; 
            } 
            ptr1 = ptr1->next; 
        } 
        lptr = ptr1; 
    } 
    while (swapped); 
} 

bool listsEqual(list_t *list1, list_t *list2) {
  while (list1 != NULL && list1 != NULL) {
      if (list1->val != list2->val) {
          return false;
      } else {
          list1 = list1->next;
          list2 = list2->next;
      }
  }

  if (list1 != NULL || list2 != NULL) {
      return false;
  } else {
      return true;
  }
}

// Case: both lists are empty
int test1() {
  list_t *l1 = NULL;
  list_t *l2 = NULL;

  list_t *studentRes = mergeTwoSortedLists(l1,l2);
  list_t *refsolRes = refsol(l1, l2);

  if (listsEqual(studentRes, refsolRes)) {
    return 1;
  } else {
    return 0;
  }
}

// Case: only list2 is empty
int test2() {
  int x = rand() % 50;
  int y = x + 69;

  list_t *l1 = malloc(sizeof(list_t));
  l1->val = x;
  l1->next = malloc(sizeof(list_t));
  l1->next->val = y;
  
  list_t *l2 = NULL;

  list_t *studentRes = mergeTwoSortedLists(l1,l2);
  list_t *refsolRes = refsol(l1, l2);

  if (listsEqual(studentRes, refsolRes)) {
    return 2;
  } else {
    return 0;
  }
}

// Case: only list1 is empty
int test3() {
  int x = rand() % 50;
  int y = x + 69;

  list_t *l1 = malloc(sizeof(list_t));
  l1->val = x;
  l1->next = malloc(sizeof(list_t));
  l1->next->val = y;
  
  list_t *l2 = NULL;

  list_t *studentRes = mergeTwoSortedLists(l2,l1);
  list_t *refsolRes = refsol(l2, l1);

  if (listsEqual(studentRes, refsolRes)) {
    return 2;
  } else {
    return 0;
  }
}

// Case: both lists are not empty
int test4() {
  list_t *l1 = createRandomList();
  bubbleSort(l1);
  list_t *l2 = createRandomList();
  bubbleSort(l2);

  list_t *studentRes = mergeTwoSortedLists(l1,l2);
  list_t *refsolRes = refsol(l1,l2);

  if (listsEqual(studentRes, refsolRes)) {
    return 5;
  } else {
    return 0;
  }
}

// Run tests
int main() {
  printf("Running tests for Problem 1\n");
  int score = 0;
  int testResults[4];

  testResults[0] = test1();
  testResults[1] = test2();
  testResults[2] = test3();
  testResults[3] = test4();

  for (int i = 0; i < 4; i++) {
    score += testResults[i];
    printf("Test %d passed: %s\n", i+1, testResults[i] ? "true" : "false");
  }

  printf("{ \"scores\": { \"problem1\": %d } }", score);

  return 0;
}