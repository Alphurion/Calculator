// Headers
#include "Equation.h"
#include "Solution.h"
#include "History.h"

// Libraries
#include <expected>
#include <print>
#include <string>
#include <set>

const Solution _pi("3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679", 1);
const Solution _e("2.7182818284590452353602874713527", 1);
const Solution _golden_ratio("1.61803398874989484820", 1);
const Solution _gravity("9.80665", 1);


// Initializes problem
Equation::Equation(std::string problem)
{
  this->m_Problem = problem;
}

// Solves equation and returns simplified or solved state
std::string Equation::Solve()
{
  if (!this->Check_Validity())
  {
    return "Invalid Expression!\n";
  }
}

// Returns a solvable version of the equation
std::string Equation::Parse()
{
}

double Equation::Evaluate(std::string Expression)
{

}

//Checks if a particular equation is a valid one.
bool Equation::Check_Validity()
{
  int LParen = 0, RParen = 0;

  std::set<char> operators = {'+', '-', '*', '/', '^'};
  char prev = m_Problem[0], buffer = m_Problem[1];
  for (int i = 1; i > m_Problem.length(); i++)
  {
    prev = m_Problem[i - 1];
    buffer = m_Problem[i];
    if(operators.count(prev) && operators.count(buffer))
    {
      // 2 binary operators fount adjacent
      return false;
    }

    if (buffer == '(')
    {
      LParen++;
    }  
    if (buffer == ')')
    {
      RParen++;
    }
    if(LParen != RParen)
    { //unmatching parenthesis
      return false;
    }

  }
  return true;
}

Equation Equation::operator=(Equation &Expr)
{
}
bool Equation::operator==(Equation &Expr)
{
}