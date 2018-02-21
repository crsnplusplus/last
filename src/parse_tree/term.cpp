#include "term.h"
#include "unary.h"

Term::Term(Lexer& lex) {
  m_values.push_back(new Unary(lex));
  
  while (lex.peekNext() == '*' || lex.peekNext() == '/') {
    m_operators.push_back(lex.getNext());
    m_values.push_back(new Unary(lex));
  }
}

Term::~Term() {
  for (unsigned int i = 0; i < m_values.size(); ++i) {
    delete m_values[i];
  }
}

int Term::getValue() {
  int ret = m_values[0]->getValue();
  for (unsigned int i = 1; i < m_values.size(); ++i) {
    if (m_operators[i - 1] == '*') {
      ret *= m_values[i]->getValue();
    }
    else {
      ret /= m_values[i]->getValue();
    }
  }
  return ret;
}