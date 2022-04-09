import os
import subprocess
import sys

# -- START CONFIGS --
MAX_SCORE = 100
TASK_NAME = "Correctness"
STUDENT_FILE = "cat.bf"
SOLUTION_FILE = "cat-sol.bf"
# -- END CONFIGS --

input_files = list(filter(lambda x: (x.endswith(".in")), os.listdir("./inputs")))

tot = len(input_files)
correct = 0

for input_f in input_files:
    path = "./inputs/" + input_f
    print("Running input {}".format(path), end="")
    student_output = subprocess.check_output("beef {} -i {}".format(STUDENT_FILE, path), shell=True)
    solution_output = subprocess.check_output("beef {} -i {}".format(SOLUTION_FILE, path), shell=True)
    if student_output == solution_output:
        print("... okay.")
        correct += 1
    else:
        print("... not okay.")

final_score = MAX_SCORE * (correct // tot)

print("Correct inputs: {} / {}".format(correct, tot))

print("{{\"scores\": {{\"{}\":{}}}}}".format(TASK_NAME, final_score))
