#pragma once
// Libraries
#include <string>
#include <memory>

// Represents the result of solving an equation — either a concrete numeric
// value, an unevaluated symbolic expression, or an error state.
class Solution
{
public:
  enum class Solution_State
  {
    NUMERIC,
    SYMBOLIC,
    ERROR
  };

  Solution() = default;
  Solution(std::string digits, Solution_State state)
    : m_Evaluation(std::move(digits)), m_State(state)
  {
  }
  ~Solution() = default;

  void Print() const;
  const std::string& Text() const { return m_Evaluation; }
  Solution_State State() const { return m_State; }

private:
  std::string m_Evaluation;
  Solution_State m_State = Solution_State::ERROR;
};

class Equation
{
  /*
  Problem: This is the user's input string
  Valid: For returning whether or not this equation is valid or invalid
  Check_Validity: Finds if an equation is valid, sets m_Valid to true
  Operator =: sets one side of problem equal to the other
  Operator ==: Checks if problem sides are equal
  */
public:
  explicit Equation(std::string problem);
  std::string Solve();

  void Print() const;

  Equation& operator=(const Equation &Expr);
  bool operator==(const Equation &Expr) const;

private:
  bool Check_Validity();
  double Evaluate(const std::string &Expression);

  std::string m_Problem;
  Solution m_Result;
  bool m_Valid = false;
};

class History
{
  // NOTE: linked-list storage/traversal isn't wired in yet — this is a stub
  // for future equation history tracking, not currently used anywhere.
private:
  struct ExprNode
  {
    ExprNode(Equation problem, int Length);
    ~ExprNode();

    Equation Problem;
    int Length;
  };
  ExprNode *m_root = nullptr;

public:
  History();
  ~History();
  void Push_Back(Equation expression);
};