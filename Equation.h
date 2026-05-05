
#pragma once
//Headers
#include "Solution.h"
#include "Token.h"
// Libraries
#include <string>

class Equation
{
  /*
Problem: This is the user's input string
Valid: For returning whether or not this function is valid or invalid
Check Validity: Finds if an equation is valid, sets valid to true
Operator =: sets one side of problem equal to the other
Operator ==: Checks if problem sides are equal (recursive call)
*/
private:
  bool Check_Validity();
  std::string Parse();
  double Evaluate(std::string Expression);
  Equation operator=(Equation &Expr);
  bool operator==(Equation &Expr);
  std::string m_Problem;
  Solution m_Result;
  bool m_Valid;

  /*
  Solve: solves a problem, the only public function besides constructors
  */
public:
  Equation(std::string problem);
  std::string Solve();
  void Print();
};
