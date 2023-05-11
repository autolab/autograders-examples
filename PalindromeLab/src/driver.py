import random
import palindrome
from tests import testCases

'''
Tests that the user's answers are valid"
1. The user returns a boolean value
2. The user returns the correct boolean value
'''
def isValid(input, answer):
    # check that the answer is bool
    if isinstance(answer, bool):
        # check that the answer is correct
        strNum = str(input)
        strNumOpp = strNum[::-1]
        if strNumOpp == strNum:
            if not answer:
                return False
            return True
        else:
            if not answer:
                return True
            return False
    return False


'''
Runs a series of randomly generated numbers and checks if the
user has a correct answer
'''
def randomTest(numTests):
    score = 0
    for i in range(numTests):
        # generate random integers
        number = random.randint(0, 2**30-1)
        res = palindrome.palindrome(number)
        if isValid(number, res):
            print(f"Passed test number {i} of {numTests}. Input: {number}, Result: {res}")
            score += 1
        else:
            print(f"Failed test number {i} of {numTests}. Input: {number}, Result: {res}")
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
    score = 0
    correctCount = 0
    count = 0
    # iterate through the array of testCases
    for case in testCases:
        count += 1
        integer = case[1]
        allocatedScore = case[2]
        # check if the user gets a correct answer for custom test cases
        answer = palindrome.palindrome(integer)
        if isValid(integer, answer):
            print(f"Test Passed, number: {integer}")
            score += allocatedScore
            correctCount += 1
        else:
            print(f"Test failed, number: {integer}")
        
    return (count, score, correctCount)


customCount, customTestScore, customCorrectCount = customTest(testCases)
numberOfTests = 100
basicScore = randomTest(numberOfTests)
testCountPassed = basicScore + customCorrectCount
testCountFailed = numberOfTests + customCount - testCountPassed - customCorrectCount
score = basicScore + customTestScore
correctness = round(testCountPassed / (customCount + numberOfTests) * 100)


print("{\"scores\": {\"Correctness\": %s}}" % correctness)
