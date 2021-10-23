This is a repo for example autograders. They are more complicated than hello lab in the documentation but simpler than real life scenario ones. They serve to offer instructors a better starting point with autograder writing in a variety of languages. For a detailed walkthrough of how autograders work, see [documentation](https://docs.autolabproject.com/lab/#writing-autograders).

---

For those who are interested in example autograders: We encourage you to download the folder of the autograder that you are interested in and run make to get a sense of how the autograder works and examine the content of autograder.tar.

---

For devs: Upload your autograder as a folder in this repository and copy the template below to README.md in your folder to document your autograder. Name your folder with the following format: Assessment Language-Functionality or lab name-Date Uploaded (YYYYMMDD), e.g. Golang-sortlab-20211018
Your folder should contain autograde.tar, autograde-Makefile, a reference student submission file, an uncompressed autograde.tar directory, and NOTHING ELSE.
Thoroughly comment your autograde-Makefile.

---
# Name of your autograder

### Assessment Language
Put your assessment's languages here, e.g. Python, C++, Ruby.

### Autograder Language
Put your autograder's languages here, e.g. Shell, Python.

### Assessment Scenario
Briefly explain your assessment, e.g. Students are required to implement mergesort and quicksort.

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
