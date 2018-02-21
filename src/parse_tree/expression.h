#ifndef __LAST_EXPRESSION_H__
#define __LAST_EXPRESSION_H__

#include "production.h"

#include <deque>

class Term;

class Expression : public Production {
  public:
    Expression(Lexer& lex);
    virtual ~Expression();

    int getValue();

  private:
    std::deque<Term*> m_values;
    std::deque<char> m_operators;
};

#endif __LAST_EXPRESSION_H__
