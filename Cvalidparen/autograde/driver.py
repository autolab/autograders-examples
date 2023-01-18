from ctypes import cdll
import pathlib 
import json

tests = [
    "",
    "(",
    ")",
    "()",
    "()(",
    "()()()",
    "(())",
    "(((()))",
    "((()))(()(()())()()())()",
    "((()))(()))(()())()()())()"
]

shared_object_path = pathlib.Path().absolute() / "validparen.so"
student_function = cdll.LoadLibrary(shared_object_path).validParenthesis

def solution(paren_string):
    numOpen = 0
    for char in paren_string:
        if char == "(":
            numOpen += 1
        elif char == ")":
            numOpen -= 1
        if numOpen < 0:
            return False 
    return numOpen == 0

score = 0
for test in tests:
    student_result = student_function(test.encode())
    correct_result = solution(test)
    if student_result == correct_result:
        status = "Pass"
        score += 1
    else:
        status = "Fail"
    print(f"Test \"{test}\": {status}")

autoresult = {"scores": {"Correctness": score}}
print(json.dumps(autoresult))