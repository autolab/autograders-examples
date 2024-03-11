#include "fizzbuzz.hpp"

std::string fizzbuzz(int n) {
  if (n % 15 == 0) {
    return "FizzBuzz";
  } else if (n % 4 == 0) {
    return "Buzz";
  } else if (n % 7 == 0) {
    return "Fizz";
  } else {
    return std::to_string(n);
  }
}