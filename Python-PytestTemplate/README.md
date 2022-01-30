# Pytest Template Example Autograder

### Special Credit
Based on the pull request [#969](https://github.com/autolab/Autolab/pull/969) by BrianKolowitz on Mar 7 2018. A very neat example of python autograder that uses pytest.

### Assessment Language
Python

### Autograder Language
Python

### Autograding Environment Packages
pip and python3 are needed for the autograding environment.

### Assessment Scenario
Students are required to implement two methods: get_name() which returns "Batman" and get_age() which returns 30. Instructors are encouraged to add methods to test and implement the additional tests accordingly.

### Handin Format
main.py

### autograder.tar Directory Content
```
# Python file that runs the unit tests
autograde/project/driver.py
# Configuration file that maps problems to unit tests
autograde/project/problems.yml
# Package requirements for the autograder
autograde/project/requirements.txt
# Python file that contains the actual test for the problems specified in problems.yml
autograde/project/test/test_main.py
```
