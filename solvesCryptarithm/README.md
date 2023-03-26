# Python Autograder Template with solvescryptarithm

### Assessment Language

Python

### Autograder Language

Python

### Autograding Environment Packages

The python3 environment package is not installed on the default autograding_image. To run this autograder, run the following commands in Terminal after adding python3 to the `apt-get install` in your Dockerfile (~/Tango/vmms/Dockerfile), like in the example [here](Dockerfile).
```
cd ~/Tango
docker build -t autograding_image vmms/
```

You can also just run the following command inside the solvescryptarithm directory:
```
docker build -t autograding_image .
```

### Assessment Scenario

This example offers a simple Python autograder that allows instructors to test programs that attempt the solvescryptarithm problem. Read the [problem writeup](writeup/writeup.html) for details.

### Handin Format

solvescryptarithm.py

## autograder.tar Directory Content

### Basic files created by the lab author

Makefile Builds the lab from src/
README.md
autograde-Makefile Makefile that runs the autograder
src/ Contains all src files and solutions
test-autograder/ For testing autograder offline
writeup/ Lab writeup that students view from Autolab

### Files created by running make

solvescryptarithm-handout/ The directory that is handed out to students, created
using files from src/.
solvescryptarithm-handout.tar Archive of hello-handout directory
autograde.tar File that is copied to the autograding instance
(along with autograde-Makefile and student handin file)

### Files created and managed by Autolab

handin/ All students handin files
solvescryptarithm.rb Config file
solvescryptarithm.yml Database properties that persist from semester to semester
log.txt Log of autograded submissions

## Further Notes on Autograder

/src has all the base files
- .py solution file
- driver.py which runs the test cases/autogrades and gives you a score
- student starter files with -handout at the end of the filename
running Makefile (make) will create...
- solvescryptarithm-handout folder for students
- autograde.tar & solvescryptarithm-handout.tar (copies of directories)

`make test` will reset test-autograder directory
- moves in autograde-Makefile (which runs the driver) to the test-autograder directory as Makefile
- running `make` in the test-autograder directory will run the autograder tests
