/*
 * Credit to Sarah McCarthy '23 for this example
 */

//compile with: g++ -std=c++20 practice.cpp -o practice
//run with: ./practice (on mac)

#include <iostream>
#include <optional>

std::optional<int> divide(int a, int b) {
    if (b != 0) {
      return a / b;
    } else {
      return std::nullopt;
    }
}

int main() {
  /* CALL HERE WITH (10, 2)*/
  auto call = divide(10, 2);
  if (call.has_value()) {
    std::cout << call.value() << std::endl;
  } else {
    std::cout << "Divided by 0!!!" << std::endl;
  }
  /* CALL HERE WITH (10, 0)*/
  auto call2 = divide(10, 0);
  if (call2.has_value()) {
    std::cout << call2.value() << std::endl;
  } else {
    std::cout << "Divided by 0!!!" << std::endl;
  }
  return 0;
}
