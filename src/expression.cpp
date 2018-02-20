#include "expression.h"
#include "term.h"

Expression::Expression(Lexer& lex) {
  values.push_back(new Term(lex));

  while (lex.peekNext() == '+' || lex.peekNext() == '-') {
      ops.push_back(lex.getNext());
      values.push_back(new Term(lex));
  }
}

Expression::~Expression() {
  for (unsigned int i = 0; i<values.size(); ++i) {
    delete values[i];
  }
}

int Expression::getValue() {
  int ret = values[0]->getValue();
  for (unsigned int i = 1; i<values.size(); ++i) {
    if (ops[i - 1] == '+') {
      ret += values[i]->getValue();
    }
    else {
      ret -= values[i]->getValue();
    }
  }
  return ret;
}
