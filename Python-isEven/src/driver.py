import random
import isEven
from tests import testCases

'''
Tests that the user's answers are valid: 
1. A boolean value is returned
2. The correct boolean value is returned
'''
def isValid(input, answer):
    # check that the answer is bool
    if not isinstance(answer, bool):
        return False
    # check that the answer is correct
    res = (input%2==0)
    if res==answer:
        return True
    return False

'''
Runs a series of randomly generated numbers and checks if the
user has a correct answer
'''
def randomTest(numTests):
    score = 0
    for i in range(numTests):
        # generate random integers
        number = random.randint(0, 2 ** 30 - 1)
        res = isEven.isEven(number)
        if isValid(number, res):
            print(f"Passed test number {i + 1} of {numTests}. Input: {number}, Result: {res}")
            score += 1
        else:
            print(f"Failed test number {i + 1} of {numTests}. Input: {number}, Result: {res}")
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
        answer = isEven.isEven(integer)
        if isValid(integer, answer):
            print(f"Test Passed, number: {integer}")
            correctCount += allocatedScore
        else:
            print(f"Test failed, number: {integer}")

    return count, correctCount

customCount, customCorrectCount = customTest(testCases)
numberOfTests = 100
basicScore = randomTest(numberOfTests)
testCountPassed = basicScore + customCorrectCount
correctness = round(testCountPassed / (customCount + numberOfTests) * 100)

print("{\"scores\": {\"Correctness\": %s}}" % correctness)