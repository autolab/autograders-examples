# Input Output Autograder Template with Fiblab Demo

### Assessment Language
Javascript

### Autograder Language
Javascript, using [Jest](https://jestjs.io/) testing framework

### Assessment Scenario
A common scenario that instructors find themselves in is that they want to compare student output with expected output and assign points accordingly. 

This autograder template modifies a popular javascript testing framework, Jest, to test the student submission. The instructor is able to utilize the wide spread of tools offered by the testing framework to grade the assignment.

This autograder also offers a concrete demonstration of a submission, functions.tgz, where students implements three functions in three separate file, `bubble-sort.js`, `merge-sort.js` and `sum.js`

Student's functions are improted into functions.test.js, and then the respective functions are evaluated. In each test case. With Jest testing framework, we can not only test whether the output is correct, we can also track the number of times a particular function is ran for the purpose of efficiency tracking.

### Handin Format
handin.tgz

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
