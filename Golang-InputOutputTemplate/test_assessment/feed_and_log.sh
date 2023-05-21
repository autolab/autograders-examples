#!/bin/bash

input="test_input"
output="student_output"
while IFS= read -r line
do
  # It is assumed that:
  # 1. The executed program prints the relevant output
  #    to standard out
  # 2. The executable program outputs some wildcard character when
  #    the program crashes.
  # 3. A unique line in the format of PROBLEM:<problem name> denotes
  #    the input test suite for a particular problem
  if [[ $line =~ PROBLEM:(.*) ]]
  then
    echo Start testing for ${BASH_REMATCH[1]}
    echo $line >> $output
  else
    echo $line | ./main >> $output
  fi
done < $input
echo $line | ./main >> $output
echo Finished running the tests.

