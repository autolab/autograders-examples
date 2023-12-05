import sys
import random
import twosum
from tests import test_cases
import time

'''
Tests that the indeces for a user's answer are valid:
1. Indeces are within range
2. Numbers at the indeces add up to the target
'''
def is_valid(arr, target, indeces):
  # make sure user provided 2 indeces in their answer
  if len(indeces) != 2:
    return False

  idx0 = indeces[0]
  idx1 = indeces[1]
  
  # make sure indeces are in range
  if idx0 < 0 or idx0 >= len(arr):
    return False
  if idx1 < 0 or idx1 >= len(arr):
    return False

  # make sure indeces are unique
  if idx0 == idx1:
    return False

  if arr[idx0] + arr[idx1] != target:
    return False

  return True

'''
A basic test that runs a series of randomly generated
arrays and target values and checks if the user's result
is correct.

num_tests - the number of randomly test cases to generate
'''
def test_basic(num_tests):
  print("Basic Tests:")
  score = 0

  for i in range(0, num_tests):
    # generate array of random integers
    arr_len = random.randint(2, 20)
    arr = random.sample(range(-15, 15), arr_len)

    # generate target sum
    targ_indeces = random.sample(range(0, len(arr)), 2)
    target = arr[targ_indeces[0]] + arr[targ_indeces[1]]

    res = twosum.two_sum(arr, target)

    if is_valid(arr, target, res):
      print('Test %s/%s passed!' % (i + 1, num_tests))
      score += 1
    else:
      print('Test %s/%s failed!' % (i + 1, num_tests))
      print(arr)
      print(target)
      print(res)
  print('')

  return score

'''
Tests custom test cases provided by user.

Each test case is formatted as a list of 4 elements:
0. Name of the test case (string)
1. Array of integers (list)
2. Target sum (int)
3. Points rewarded (int)
'''
def test_custom(test_cases):
  score = 0

  for case in test_cases:
    print(case[0])

    arr = case[1]
    target = case[2]
    res = twosum.two_sum(arr, target)
    if is_valid(arr, target, res):
      print('Test passed!')
      score += case[3]
      print('Points rewarded: %s/%s\n' % (case[3], case[3]))
    else:
      print('Test failed!')
      print(arr)
      print(target)
      print(res)
      print('Points rewarded: %s/%s' % (0, case[3]))
      
  return score

def test_time(arr_len):
  arr = random.sample(range(-arr_len, arr_len), arr_len)

  # generate target sum
  targ_indeces = random.sample(range(0, len(arr)), 2)
  target = arr[targ_indeces[0]] + arr[targ_indeces[1]]

  start = time.time()
  res = twosum.two_sum(arr, target)
  if not is_valid(arr, target, res):
    return -1
  end = time.time()

  time_elapsed = end - start
  return time_elapsed

def test_complex():
  for i in range(10):
    short_time = test_time(100)
    long_time = test_time(1000000)
    if short_time < 0 or long_time < 0:
      return 0
    if long_time/short_time > 20000:
      print("Program timed out!")
      return 0

  return 10

basic_score = test_basic(10)
tests_score = test_custom(test_cases)
complex_score = 0
complex_score = test_complex()

print("{\"scores\": {\"Correctness\": %s, \"Time\": %s}}" % (basic_score + tests_score, complex_score))