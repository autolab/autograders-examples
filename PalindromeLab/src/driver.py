import random
import palindrome
import time
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
            print(f"Passed test number ${i} of ${numTests}. Input: ${number}, Result: ${res}")
            score += 1
        else:
            print(f"Failed test number ${i} of ${numTests}. Input: ${number}, Result: ${res}")
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
            print(f"Test Passed, number: ${integer}")
            score += allocatedScore
            correctCount += 1
        else:
            print(f"Test failed, number: ${integer}")
        
    return (count, score, correctCount)

'''
Test time
'''
def timeTest(lowerBound, upperBound):
    # random integer within the size boundaries
    integer = random.randint(lowerBound, upperBound)
    start = time.time()
    res = palindrome.palindrome(integer)
    # check if result is correct
    if not isValid(integer, res):
        return -1
    end = time.time()
    # calculate time
    timeTaken = end - start
    return timeTaken
    
def timeTestResult():
    for i in range(10):
        smallNumber = timeTest(0, 2**10)
        largeNumber = timeTest(2**25, 2**30-1)
        if smallNumber < 0 or largeNumber < 0:
            print("Program returned wrong answers")
            return 1
        if smallNumber > 10000 or largeNumber > 10000:
            print("Program timed out")
            return 1
    return 0

customCount, customTestScore, customCorrectCount = customTest(testCases)
numberOfTests = 100
basicScore = randomTest(numberOfTests)
testCountPassed = basicScore + customCorrectCount
testCountFailed = numberOfTests + customCount - testCountPassed - customCorrectCount
score = basicScore + customTestScore
correctness = testCountPassed / numberOfTests

print(f"""
      Test Summary\n
      Tests ran: ${numberOfTests}\n
      Passed: ${testCountPassed}\n
      Failed: ${testCountFailed}\n
      Score: ${score}\n
      Correctness: ${correctness}\n
      """)


        
        