import os
import sys
import filecmp

input_files = list(filter(lambda x: (x.endswith(".in")), os.listdir("./inputs")))

tot = len(input_files)
correct = 0
max_score = 100

for input_f in input_files:
    path = "./inputs/" + input_f
    print("Running input {}".format(path))
    os.system("beef cat.bf -i {} -o output.txt".format(path))
    os.system("beef cat-sol.bf -i {} -o output-sol.txt".format(path))
    if filecmp.cmp("output.txt", "output-sol.txt"):
        print("... Correct on input {}".format(input_f))
        correct += 1
    else:
        print("... Wrong on input {}".format(input_f))

print("Total inputs: {}".format(tot))
print("Correct inputs: {}".format(correct))

print("{{\"scores\": {{\"Correctness\":{}}}}}".format(max_score * (correct // tot)))
