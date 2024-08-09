source("calculator.R")
source("tests.R")

run_testcases <- function(test_cases) {
  is_passed <- 0
  for (case in test_cases) {
    print(case$description)
    a <- case$inputs[1]
    b <- case$inputs[1]
    
    if ((a + b == add(a, b)) &&
        (a - b == subtract(a, b)) &&
        (a * b == multiplication(a, b)) &&
        (a / b == division(a, b))) {
      is_passed <- is_passed + 1
      print('---Passed!---')
    } else {
      print('---Failed!---')
    }
  }
  return(is_passed)
}

# Calculate the score
test_score <- (run_testcases(test_cases) / length(test_cases)) * 100
cat(sprintf('{"scores": {"Correctness": %f}}', test_score))