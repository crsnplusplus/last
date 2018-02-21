#include "expression.h"
#include "term.h"

#include <assert.h>

Expression::Expression(Lexer& lex) {
  m_values.push_back(new Term(lex));

  while (lex.peekNext() == '+' || lex.peekNext() == '-') {
      m_operators.push_back(lex.getNext());
      m_values.push_back(new Term(lex));
  }
}

Expression::~Expression() {
  for (size_t i = 0; i < m_values.size(); ++i) {
    delete m_values[i];
  }
}

int Expression::getValue() {
  int ret = m_values[0]->getValue();
  for (size_t i = 1; i < m_values.size(); ++i) {
    if (m_operators[i - 1] == '+') {
      ret += m_values[i]->getValue();
    }
    else {
      ret -= m_values[i]->getValue();
    }
  }
  return ret;
}
