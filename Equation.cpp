// Headers
#include "Equation.h"

// Libraries
#include <string>
#include <set>
#include <cctype>
#include <cmath>
#include <stdexcept>
#include <print>

namespace
{
  const std::set<char> kOperators = {'+', '-', '*', '/', '^'};

  bool IsOperator(char c)
  {
    return kOperators.count(c) > 0;
  }
}

const Solution _pi("3.141592", Solution::Solution_State::SYMBOLIC);
const Solution _e("2.718281", Solution::Solution_State::SYMBOLIC);
const Solution _golden_ratio("1.618034", Solution::Solution_State::SYMBOLIC);
const Solution _gravity("9.80665", Solution::Solution_State::SYMBOLIC);

// Initializes problem
Equation::Equation(std::string problem)
  : m_Problem(std::move(problem))
{
}

// Solves the equation and returns a human-readable result or an error message.
std::string Equation::Solve()
{
  if (!Check_Validity())
  {
    return "Invalid Expression!";
  }

  double result;
  try
  {
    result = Evaluate(m_Problem);
  }
  catch (const std::exception &e)
  {
    return std::string("Invalid Expression! (") + e.what() + ")";
  }

  m_Result = Solution(std::to_string(result), Solution::Solution_State::NUMERIC);
  m_Valid = true;
  return m_Result.Text();
}

// ---- Recursive-descent expression evaluator ----
// Grammar (highest to lowest precedence):
//   primary     := NUMBER | '(' expression ')' | '-' primary
//   power       := primary ('^' power)?          (right-associative)
//   term        := power (('*' | '/') power)*
//   expression  := term (('+' | '-') term)*
namespace
{
  double ParseExpression(const std::string &s, size_t &pos);

  void SkipSpaces(const std::string &s, size_t &pos)
  {
    while (pos < s.length() && std::isspace(static_cast<unsigned char>(s[pos])))
    {
      pos++;
    }
  }

  double ParsePrimary(const std::string &s, size_t &pos)
  {
    SkipSpaces(s, pos);

    if (pos < s.length() && s[pos] == '-')
    {
      pos++;
      return -ParsePrimary(s, pos);
    }

    if (pos < s.length() && s[pos] == '(')
    {
      pos++; // consume '('
      double value = ParseExpression(s, pos);
      SkipSpaces(s, pos);
      if (pos >= s.length() || s[pos] != ')')
      {
        throw std::runtime_error("mismatched parentheses");
      }
      pos++; // consume ')'
      return value;
    }

    size_t start = pos;
    while (pos < s.length() && (std::isdigit(static_cast<unsigned char>(s[pos])) || s[pos] == '.'))
    {
      pos++;
    }

    if (start == pos)
    {
      throw std::runtime_error("expected a number");
    }

    return std::stod(s.substr(start, pos - start));
  }

  double ParsePower(const std::string &s, size_t &pos)
  {
    double base = ParsePrimary(s, pos);
    SkipSpaces(s, pos);

    if (pos < s.length() && s[pos] == '^')
    {
      pos++;
      double exponent = ParsePower(s, pos); // right-associative
      return std::pow(base, exponent);
    }

    return base;
  }

  double ParseTerm(const std::string &s, size_t &pos)
  {
    double value = ParsePower(s, pos);

    while (true)
    {
      SkipSpaces(s, pos);
      if (pos < s.length() && s[pos] == '*')
      {
        pos++;
        value *= ParsePower(s, pos);
      }
      else if (pos < s.length() && s[pos] == '/')
      {
        pos++;
        double divisor = ParsePower(s, pos);
        if (divisor == 0.0)
        {
          throw std::runtime_error("division by zero");
        }
        value /= divisor;
      }
      else
      {
        break;
      }
    }

    return value;
  }

  double ParseExpression(const std::string &s, size_t &pos)
  {
    double value = ParseTerm(s, pos);

    while (true)
    {
      SkipSpaces(s, pos);
      if (pos < s.length() && s[pos] == '+')
      {
        pos++;
        value += ParseTerm(s, pos);
      }
      else if (pos < s.length() && s[pos] == '-')
      {
        pos++;
        value -= ParseTerm(s, pos);
      }
      else
      {
        break;
      }
    }

    return value;
  }
}

double Equation::Evaluate(const std::string &Expression)
{
  size_t pos = 0;
  double result = ParseExpression(Expression, pos);

  SkipSpaces(Expression, pos);
  if (pos != Expression.length())
  {
    throw std::runtime_error("unexpected trailing characters");
  }

  return result;
}

// Checks whether the equation is structurally valid: non-empty, balanced
// parentheses, and no two binary operators sitting directly next to each other.
bool Equation::Check_Validity()
{
  if (m_Problem.empty())
  {
    return false;
  }

  int LParen = 0, RParen = 0;

  for (size_t i = 1; i < m_Problem.length(); i++)
  {
    char prev = m_Problem[i - 1];
    char buffer = m_Problem[i];

    if (IsOperator(prev) && IsOperator(buffer))
    {
      // Two binary operators found adjacent (e.g. "3+*2")
      return false;
    }

    if (buffer == '(')
    {
      LParen++;
    }
    if (buffer == ')')
    {
      RParen++;
      if (RParen > LParen)
      {
        // Closing paren with no matching open paren
        return false;
      }
    }
  }

  return LParen == RParen;
}

Equation& Equation::operator=(const Equation &Expr)
{
  if (this != &Expr)
  {
    m_Problem = Expr.m_Problem;
    m_Result = Expr.m_Result;
    m_Valid = Expr.m_Valid;
  }
  return *this;
}

bool Equation::operator==(const Equation &Expr) const
{
  return m_Problem == Expr.m_Problem;
}

void Equation::Print() const
{
  std::println("{} = {}", m_Problem, m_Result.Text());
}

void Solution::Print() const
{
  std::println("{}", m_Evaluation);
}