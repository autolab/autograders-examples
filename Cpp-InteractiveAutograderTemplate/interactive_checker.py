#!/usr/bin/python3
import subprocess
import os
import fcntl
from subprocess import PIPE

ORACLE_BINARY = "./oracle"
STUDENT_BINARY = "./sorter"

class bcolors:
    HEADER = '\033[95m'
    OKBLUE = '\033[94m'
    OKCYAN = '\033[96m'
    OKGREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    ENDC = '\033[0m'
    BOLD = '\033[1m'
    UNDERLINE = '\033[4m'

# Reads a line from student program
def read(proc):
    return proc.stdout.readline().decode("utf-8").strip()

# Outputs a line to student program
def write(proc, message):
    proc.stdin.write(f"{message.strip()}\n".encode("utf-8"))
    proc.stdin.flush()

def interactive_checker():
    oracle_proc = subprocess.Popen(ORACLE_BINARY, stdin=PIPE,
                            stdout=PIPE, stderr=PIPE)
    student_proc = subprocess.Popen(STUDENT_BINARY, stdin=PIPE,
                            stdout=PIPE, stderr=PIPE)

    while True:
        data = read(oracle_proc)

        if "AUTOGRADER_COMPLETE" in data:
            print(f"Oracle has judged student answer")
            autograder_result = read(oracle_proc)
            print(autograder_result)
            break

        write(student_proc, data)
        print(f"Relayed from {bcolors.OKGREEN}oracle{bcolors.ENDC} to {bcolors.OKBLUE}student{bcolors.ENDC}:\t\t{data}")
        query = read(student_proc)
        write(oracle_proc, query)
        print(f"Relayed from {bcolors.OKBLUE}student{bcolors.ENDC} to {bcolors.OKGREEN}oracle{bcolors.ENDC}:\t\t{query}")

    print(autograder_result)

if __name__ == "__main__":
    interactive_checker()
