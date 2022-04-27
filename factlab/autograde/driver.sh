#!/bin/bash

# driver.sh - Compiles student submissions then checks score using Autograder.sml
# Usage: ./driver.sh

# Compile the code
echo "Compiling factorial.sml"
(rm -rf autograde; mlton -output autograde autograde.mlb)
status=$?
if [ ${status} -ne 0 ]; then
    echo "Failure: Unable to compile factorial.sml (return status = ${status})"
    echo "{\"scores\": {\"Correctness\": 0}}"
    exit
fi

# Run the code
echo "Running ./autograde"
(./autograde; rm -rf autograde)

exit
