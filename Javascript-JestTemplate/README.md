# Input Output Autograder Template with Fiblab Demo

### Assessment Language
Javascript

### Autograder Language
Javascript, using [Jest](https://jestjs.io/) testing framework

### Autograding Environment Packages
The following has to be installed in the autograding image for this assessment to work
- [NodeJS](https://nodejs.org/en/)
- [Jest](https://jestjs.io/docs/getting-started) (Do install using --global instead of --save-dev)

### Assessment Scenario
A common scenario that instructors find themselves in is that they want to compare student output with expected output and assign points accordingly. 

This autograder template modifies a popular javascript testing framework, Jest, to test the student submission. The instructor is able to utilize the wide spread of tools offered by the testing framework to grade the assignment.

This autograder also offers a concrete demonstration of a submission, functions.js, where students implements three functions `bubble-sort`, `merge-sort` and `sum`

Student's functions are imported into functions.test.js, and then the respective functions are evaluated. In each test case. With Jest testing framework, we can not only test whether the output is correct, we can also track the number of times a particular function is ran for the purpose of efficiency tracking.

### Handin Format
functions.js

### autograder.tar Directory Content
```
# make routine that runs the unit test
Makefile

# unit testing file that contains test cases
functions.test.js

# file where the calculation of the Autograder score is done
score-reporter.js

# describes the testing framework to be used
package.json
