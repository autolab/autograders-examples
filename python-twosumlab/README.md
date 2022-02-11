# Python Autograder Template with Twosum Demo

### Assessment Language

Python

### Autograder Language

Python

### Autograding Environment Packages

pip and python3 are needed for the autograding environment.

### Assessment Scenario

This example offers a simple Python autograder that allows instructors to test programs with randomly generated test cases, custom-written test cases, and checks for time bounds.

In this lab, students implement a solution for twosumlab, where the goal is to determine the indeces of the two elements of an array that add up to a target sum. The autograder generates a series of random test cases and can also take in custom test cases. It also checks that the submission is approximately in O(n) time bounds.

### Handin Format

twosum.py

### autograder.tar Directory Content

# Basic files created by the lab author

Makefile Builds the lab from src/
README.md
autograde-Makefile Makefile that runs the autograder
src/ Contains all src files and solutions  
test-autograder/ For testing autograder offline
writeup/ Lab writeup that students view from Autolab

# Files created by running make

twosum-handout/ The directory that is handed out to students, created
using files from src/.
twosum-handout.tar Archive of hello-handout directory
autograde.tar File that is copied to the autograding instance
(along with autograde-Makefile and student handin file)

# Files created and managed by Autolab

handin/ All students handin files
twosumlab.rb Config file
twosumlab.yml Database properties that persist from semester to semester
log.txt Log of autograded submissions
