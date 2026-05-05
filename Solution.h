#pragma once
#include <string>

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
