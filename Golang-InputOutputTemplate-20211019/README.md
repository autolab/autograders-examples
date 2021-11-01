# Input Output Autograder Template with Fiblab Demo

### Assessment Language
Golang

### Autograder Language
Shell

### Autograding Environment Packages
Golang is required for this autograder. Consult their [official documentation](https://golang.org/doc/install).

### Assessment Scenario
A common scenario that instructors find themselves in is that they want to compare student output with expected output and assign points accordingly. This autograder template offers a very simple template with strong assumptions for input output comparison. It is up to the instructors’ discretion to decide the language of their assignment and the necessary supplementary files to compile a submission.

This autograder also offers a concrete demo of the template with a simple Golang assessment fiblab, where students implement a method in Golang that calculates the nth Fibonacci number. Students' handin is compiled with main.go which invokes student implementation and output a single line result. The autograder feeds predefined test input into this compiled executable program, writes student output, and compares student output with expected output.

Makefile.template is a template for autograde-Makefile with pseudocode that executes the autograding job. Build your own Makefile and autograde.tar by replacing the supplementary files and the pseudocode in the relevant template files!

### Handin Format
fib.go

### autograder.tar Directory Content
```
# make routine that compiles fib.go into a program
Makefile

# test input to student program; test case per line
test_input

# expected output from student program; test case per line
test_output

# feed test_input to student program and writes output to student_output;
# test case per line
# this script assumes that the compiled program from student's handin file
# reads test case input one at a time
feed_and_log.sh

# compare student_output and test_output line by line and echo the actual
# autograding result
compare_and_grade.sh

# dependency files needed to compile fib.go
# depending on the specific needs, instructors should replace these two files
# with their own supplementary files
main.go
go.mod

# autograder template files with pseudocode;
# this offers a simple starting point for those who want to write
# their own input output autograder
# replace the feed_and_log.sh and Makefile with your own
Makefile.template
feed_and_log.sh.template
```
