#include <iostream>
#include <cstdlib>
#include <ctime>
#include <type_traits>

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

  int test_int_1 = 30;
  static_assert(std::is_same<decltype(fizzbuzz(test_int_1)), std::string>::value, "Function fizzbuzz must return a string.");
  if (fizzbuzz(test_int_1) == fizzbuzz_ref(test_int_1)) {
    result["scores"]["Problem 1"] = 1;
  } else {
    result["scores"]["Problem 1"] = 0;
  }

  int test_int_2 = 24;
  if (fizzbuzz(test_int_2) == fizzbuzz_ref(test_int_2)) {
    result["scores"]["Problem 2"] = 1;
  } else {
    result["scores"]["Problem 2"] = 0;
  }

  int test_int_3 = 20;
  if (fizzbuzz(test_int_3) == fizzbuzz_ref(test_int_3)) {
    result["scores"]["Problem 3"] = 1;
  } else {
    result["scores"]["Problem 3"] = 0;
  }

  int test_int_4 = 16;
  if (fizzbuzz(test_int_4) == fizzbuzz_ref(test_int_4)) {
    result["scores"]["Problem 4"] = 1;
  } else {
    result["scores"]["Problem 4"] = 0;
  }

  int test_int_5 = std::rand();
  if (fizzbuzz(test_int_5) == fizzbuzz_ref(test_int_5)) {
    result["scores"]["Problem 5"] = 1;
  } else {
    result["scores"]["Problem 5"] = 0;
  }

  std::string resultString = result.dump();
  std::cout << resultString << std::endl;
  return 0;
}
