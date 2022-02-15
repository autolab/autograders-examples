#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

#include "json.hpp"
#include "fib.h"

using json = nlohmann::json;

int fib_ref(int n)
{
  int a = 0, b = 1, c, i;
  if( n == 0)
    return a;
  for (i = 2; i <= n; i++)
  {
     c = a + b;
     a = b;
     b = c;
  }
  return b;
}

int main ()
{
  json result;
  srand (time(NULL));

  int num1 = rand() % 100;
  if (fib_ref(num1) == fib(num1)){
    result["scores"]["problem 1"] = 10;
  } else {
    result["scores"]["problem 1"] = 0;
  }

  int num2 = rand() % 100;
  if (fib_ref(num2) == fib(num2)){
    result["scores"]["problem 2"] = 10;
  } else {
    result["scores"]["problem 2"] = 0;
  }

  std::string resultString = result.dump();   
  std::cout << resultString << std::endl;
  return 0;
}
