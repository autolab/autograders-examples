import os
import sys
import filecmp

# CONFIGS
MAX_SCORE = 100
STUDENT_FILE = "cat.bf"
SOLUTION_FILE = "cat-sol.bf"
STUDENT_OUTPUT = "output.txt"
SOLUTION_OUTPUT = "output-sol.txt"

# CODE
input_files = list(filter(lambda x: (x.endswith(".in")), os.listdir("./inputs")))

tot = len(input_files)
correct = 0

for input_f in input_files:
    path = "./inputs/" + input_f
    print("Running input {}".format(path))
    os.system("beef {} -i {} -o {}".format(STUDENT_FILE, path, STUDENT_OUTPUT))
    os.system("beef {} -i {} -o {}".format(SOLUTION_FILE, path, SOLUTION_OUTPUT))
    if filecmp.cmp(STUDENT_FILE, SOLUTION_FILE):
        print("... Correct on {}".format(input_f))
        correct += 1
    else:
        print("... Wrong on {}".format(input_f))

os.remove(STUDENT_FILE)
os.remove(SOLUTION_FILE)
print("Cleaned up files")

print("Correct inputs: {} / {}".format(correct, tot))

print("{{\"scores\": {{\"Correctness\":{}}}}}".format(MAX_SCORE * (correct // tot)))
