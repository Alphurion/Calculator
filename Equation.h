
#pragma once
//Headers
#include "Token.h"
// Libraries
#include <string>
#include <memory>

class Solution
{

private:
  enum class Solution_State
  {
    NUMERIC,
    SYMBOLIC,
    ERROR
  };
  std::string m_Evaluation;
  Solution_State m_State;

public:
  Solution();
  Solution(std::string digits, int state)
  {
    m_Evaluation = digits;
  };
  ~Solution();
  void Print();
};

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
  Token problem;
  std::string Solve();
  void Print();
};

class History
{
private:
  struct ExprNode
  {

    ExprNode(Equation problem, int Length);
    ~ExprNode();

    Equation Problem;
    int Length;
  };
  ExprNode *m_root;

  public:
History();
~History();
void Push_Back(Equation expression);

};
