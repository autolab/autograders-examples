# Name of your autograder

C++ Interactive Autograder.

This autograder is meant as a template for writing interactive autograders. An interactive autograder is one where a student program
makes specific queries to an oracle, which will respond. After several queries, the student program
is expected to output an answer. This approach allows lab authors to measure the Big-O complexity of student programs
more carefully, as they can measure the exact number of queries made instead of having to infer that from
the running time of the program. This can be very useful in an algorithms and data structure class.

### Assessment Language

Agnostic, although in this particular example both the oracle and student program are written in C++.

### Autograder Language

Python 3

### Autograding Environment Packages

Only default Python 3 libraries are used.

### Assessment Scenario

Students need to implement a sorting algorithm in `sorter.cpp`. Their final score scales inversely based
on the number of queries made to the oracle, so having a O(n log n) complexity solution
will give a better score than one with O(n^2).

The student program should expect the following interface:

- The autograder will first output N on a single line, where N is the total number of elements in the array `A` to be sorted
- The student will then make any number queries of the following form on a single line:

  ```
  i j
  ```

  which upon receiving them, the autograder will
  output `-1` if i < j, `0` if i = j, and 1 if i > j.

- The student program should output DONE on a single line when it has enough information to output the original array in sorted order
- The student program should then output their answer of the indices in sorted order on a single line

#### Example Trace

In this example, let `A = [2,1,3]`.

We look at an example trace from both the oracle and student:

```
oracle->student:  3
student->oracle:  0 1
oracle->student:  1
student->oracle:  0 2
oracle->student:  -1
student->oracle:  DONE
student->oracle:  1 0 2
```

### Handin Format

The autograder expects a file by the name `sorter.c`.

You can find a sample non-optimal solution in `src/sorter.c`.

### autograder.tar Directory Content

```
# Interactive autograder
interactive_checker.py
# Oracle program that generates/runs test cases
# and allow student programs to query it
oracle.cpp
```

The sample `interactive_checker.py` is very verbose and logs all interactions between the oracle and student program. To suppress these
outputs, set `VERBOSE = False` at the top of the file.

### Limitations

All IO from both the oracle and student program must only be 1 line, including the final score.
This is because otherwise the interactive checker will not be able to discern when the
oracle or student program has completed writing.