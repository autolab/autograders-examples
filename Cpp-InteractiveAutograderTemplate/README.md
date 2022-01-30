# Name of your autograder

C++ Interactive Autograder.

This autograder is meant as a template for writing interactive autograders. An interactive autograder is one where a student program
makes specific queries to an oracle, which will respond. After several queries, the student program
is expected to output an answer. This approach allows lab authors to measure the Big-O complexity of student programs
more carefully, as they can measure the exact number of queries made instead of having to infer that from
the running time of the program.

### Assessment Language

Agnostic, although in this particular example both the oracle and student program are written in C++.

### Autograder Language

Python 3

### Autograding Environment Packages

Only default Python 3 libraries are used.

### Assessment Scenario

Students need to implement a sorting algorithm in `sorter.cpp`. Their final score depends on the number of queries made
to the oracle, so having a O(n log n) complexity will give a better score than one with O(n^2).

The student program should expect the following interface:

- The autograder will first output N on a single line, where N is the total number of elements in the array to be sorted
- The student program should output DONE on a single line when it has enough

### Handin Format

The expected format/name of your student handin, e.g. handin.tar, hello.c.

### autograder.tar Directory Content

List your autograder.tar content here and briefly explain what each file does.
e.g.

```
# Compiles hello.c
Makefile
# Autolab autograder
driver.sh
# Empty C file that you will edit
hello.c
```

### Limitations

All IO from both the oracle and student program must only be 1 line, including the final score.
