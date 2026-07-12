#include "Equation.h"
#include <string>
#include <iostream>

int main()
{
  std::string problem;
  std::cout << "Enter an equation to solve: ";
  std::cin >> problem;
  Equation equation(problem);
  std::cout << equation.Solve() << std::endl;
  return 0;
}
