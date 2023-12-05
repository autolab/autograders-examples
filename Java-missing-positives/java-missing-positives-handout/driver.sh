#!/bin/bash

# Usage: ./driver.sh

# Compile the code
echo "Compiling Missing.java"
(make clean; make)
status=$?
if [ ${status} -ne 0 ]; then
    echo "Failure: Unable to compile Missing.java (return status = ${status})"
    echo "{\"scores\": {\"Correctness\": 0}}"
    exit
fi

# Run the code
echo "Testing java Missing"
java -ea TestMissing
status=$?
if [ ${status} -eq 0 ]; then
    echo "Success: java Missing runs with an exit status of 0"
    echo "{\"scores\": {\"Correctness\": 100}}"
else
    echo "Failure: java Missing fails or returns nonzero exit status of ${status}"
    echo "{\"scores\": {\"Correctness\": 0}}"
fi

exit