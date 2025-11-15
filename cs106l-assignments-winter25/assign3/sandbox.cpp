/*
 * CS106L Assignment 3: Make a Class
 * Created by Fabio Ibanez with modifications by Jacob Roberts-Baca.
 */
#include "class.h"
#include <iostream>

void sandbox() {
  Stack<int> stack = {1, 2, 3, 4, 5};
  std::cout << stack.getTop() << std::endl;
  stack.push(114);
  stack.push(514);
  stack.push(1);
  stack.push(2);
  stack.push(3);
  stack.push(1919810);

  std::cout << stack.getTop() << std::endl;
  stack.pop();
  stack.setTop(1);
  std::cout << stack.getTop() << std::endl;
}