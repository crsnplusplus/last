#include "term.h"
#include "unary.h"

Term::Term(Lexer& lex) {
  values.push_back(new Unary(lex));
  
  while (lex.peekNext() == '*' || lex.peekNext() == '/') {
    ops.push_back(lex.getNext());
    values.push_back(new Unary(lex));
  }
}

Term::~Term() {
  for (unsigned int i = 0; i<values.size(); ++i) {
    delete values[i];
  }
}

int Term::getValue() {
  int ret = values[0]->getValue();
  for (unsigned int i = 1; i<values.size(); ++i) {
    if (ops[i - 1] == '*') {
      ret *= values[i]->getValue();
    }
    else {
      ret /= values[i]->getValue();
    }
  }
  return ret;
}