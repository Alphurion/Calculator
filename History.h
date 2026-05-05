#pragma once
// Headers
#include "Equation.h"

//Libraries
#include <memory>

class History
{
private:
  struct ExprNode
  {

    ExprNode(Equation problem, int Length);
    ~ExprNode();

    Equation Problem;
    int Length;
    std::unique_ptr<Equation> LExpr;
    std::unique_ptr<Equation> RExpr;
  };

  ExprNode *m_root;

  public:
History();
~History();
void Push_Back(Equation expression);

};
