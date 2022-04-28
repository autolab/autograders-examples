# FactLab

Example SML autograder, to be used as a template for creating autograded assignments in SML.

### Assessment Language
[SML](https://en.wikipedia.org/wiki/Standard_ML)

### Autograder Language
[SML](https://en.wikipedia.org/wiki/Standard_ML)

### Autograding Environment Packages
[MLton](http://mlton.org/)

Note: For ease of installation, a Dockerfile has been included, with installation instructions inside.

### Assessment Scenario
In this assessment, students need to implement a `fact` program in `factorial.sml`. This function should return the i'th factorial when `fact i` is called. Their final score is based on the student function's performance on test cases defined in `autograde/Tests.sml`.

### Handin Format
The autograder expects a file by the name `factorial.sml`.

A sample solution can be found in `src/factorial.sml`.

### autograde.tar Directory Content
```
# Details about the autograde directory
README
# ML Basis file containing the dependencies for the autograding executable
autograde.mlb
# SML Autograder to test a student's submission
Autograder.sml
# Script for compiling and running autograding executable
driver.sh
# SML file containing the autograded test cases
Tests.sml
```

### factlab-handout.tar Directory Content
```
# Lab instructions
README
# Starter code
factorial.sml
```