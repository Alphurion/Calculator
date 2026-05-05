/*
A binary tree to hold values
*/
#pragma once
#include "Equation.h"

class History
{
private:
  struct ExprNode
  {

    ExprNode(Equation problem, int Length);
    ~ExprNode();

    Equation Problem;
    int Length;
    Equation *LExpr;
    Equation *RExpr;
  };

  ExprNode *m_root;
  
  public:
History();
~History();
void Push_Back(Equation expression);

};