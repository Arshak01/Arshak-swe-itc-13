#include <iostream>
#include "./c/d/e/sum.hpp"
#include "./c/d/sub.hpp"
#include "./c/mult.hpp"
#include "./b/divis.hpp"



int main() {
  int number1 = 12;
  int number2 = 4;
  std::cout << number1 << " * ";
  std::cout << number2 << " = ";
  std::cout << mult(number1, number2) << std::endl;

  return 0;
}