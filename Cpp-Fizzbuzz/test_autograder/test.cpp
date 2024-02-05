#include <iostream>
#include <cstdlib>
#include <ctime>

#include "fizzbuzz.hpp"
#include "json.hpp"

using json = nlohmann::json;

std::string fizzbuzz_ref(int n) {
  if (n % 15 == 0) {
    return "FizzBuzz";
  } else if (n % 5 == 0) {
    return "Buzz";
  } else if (n % 3 == 0) {
    return "Fizz";
  } else {
    return std::to_string(n);
  }
}

int main() {
  json result;
  std::srand(std::time(nullptr));
  for (int i = 1; i <= 5; i++) {
    int random_int = std::rand();
    std::string problem_id = "Problem " + std::to_string(i);
    if (fizzbuzz(random_int) == fizzbuzz_ref(random_int)) {
      result["scores"][problem_id] = 1;
    } else {
      result["scores"][problem_id] = 0;
    }
  }

  std::string resultString = result.dump();
  std::cout << resultString << std::endl;
  return 0;
}
