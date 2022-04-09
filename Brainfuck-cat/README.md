# CATBF

Brainfuck autograder.

This autograder is meant as a template for grading submissions in esoteric languages. Although it is currently a Brainfuck autograder, the autograder structure is fairly flexible and can be easily adapted for other languages.

### Assessment Language
[Brainfuck](https://en.wikipedia.org/wiki/Brainfuck)

### Autograder Language
Python 3

### Autograding Environment Packages
[Beef](https://github.com/andreabolognani/beef)

Python 3 (default libraries)

### Assessment Scenario
In this assessment, students need to implement a `cat` program in `cat.bf`. That is, their program should output exactly what it receives as input. Their final score is given by the proportion of inputs for which their program produces the correct output.

### Handin Format
The autograder expects a file by the name `cat.bf`.

A sample solution can be found in `src/cat-sol.bf`.

### autograder.tar Directory Content
```
# Autolab autograder
driver.py
# Reference solution
cat-sol.bf
# Student's solution
cat.bf
```