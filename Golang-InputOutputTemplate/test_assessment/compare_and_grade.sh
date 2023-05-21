#!/bin/bash

student_output="student_output"
expected_output="test_output"

score=0
problem=""
result=""

while IFS= read -r line1 && IFS= read -r line2 <&3
do
  if [[ $line2 =~ PROBLEM:(.*) && $line1 =~ PROBLEM:(.*) &&
        $line1 == $line2 ]]
  then
    [[ $problem != "" ]] && result="$result\"$problem\":\"$score\","
    problem=${BASH_REMATCH[1]}
    total=0
    score=0
    echo Grading $problem.
  else
    [[ $line1 == $line2 ]] && ((score+=1))
  fi
done < $student_output 3< $expected_output

result="$result\"$problem\":\"$score\""
echo "{\"scores\": {$result} }"
