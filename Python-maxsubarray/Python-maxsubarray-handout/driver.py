import random
import maxsubarray
from tests import testCases

'''
Tests that the user's answers are valid"
1. The user returns a boolean value
2. The user returns the correct boolean value
'''


def isValid(input, answer):
    # check that the answer is bool
    if isinstance(answer, int):
        # check that the answer is correct
        res = 0
        nums = input
        n = len(nums)
        if n == 1:
            res = nums[0]
        else:
            lookup = [0] * n
            lookup[0] = nums[0]
            res = nums[0]
            for i in range(1, n):
                lookup[i] = max(lookup[i-1]+nums[i], nums[i])
                res = max(res, lookup[i])
        if res == answer:
            return True
    return False


'''
Runs a series of randomly generated lists and checks if the
user has a correct answer
'''

def randomTest(numTests):
    score = 0
    for i in range(numTests):
        # generate random integers
        size = random.sample(range(1, 10**6), 1)[0]
        nums = random.sample(range(-1 * (10**6), 10**6), size)
        res = maxsubarray.maxsubarray(nums)
        if isValid(nums, res):
            print(f"Passed test number {i + 1} of {numTests}. Input: {nums}, Result: {res}")
            score += 1
        else:
            print(f"Failed test number {i + 1} of {numTests}. Input: {nums}, Result: {res}")
    print('')

    return score


'''
Runs custom test cases (presented as an array)

Each test case is formatted as a list containing:
1. Name of test
2. Integer
3. Points rewarded
'''


def customTest(testCases):
    correctCount = 0
    count = 0
    # iterate through the array of testCases
    for case in testCases:
        count += 1
        integer = case[1]
        allocatedScore = case[2]
        # check if the user gets a correct answer for custom test cases
        answer = maxsubarray.maxsubarray(integer)
        if isValid(integer, answer):
            print(f"Test Passed, number: {integer}")
            correctCount += 1
        else:
            print(f"Test failed, number: {integer}")

    return count, correctCount


customCount, customCorrectCount = customTest(testCases)
numberOfTests = 10
basicScore = randomTest(numberOfTests)
testCountPassed = basicScore + customCorrectCount
correctness = round(testCountPassed / (customCount + numberOfTests) * 100)

print("{\"scores\": {\"Correctness\": %s}}" % correctness)