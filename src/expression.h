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
  std::deque<Term*> values;
  std::deque<char> ops;
};

#endif __LAST_EXPRESSION_H__
