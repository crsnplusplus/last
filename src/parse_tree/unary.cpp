#include "unary.h"
#include "factor.h"

Unary::Unary(Lexer& lex) {
  while (lex.peekNext() == '-' || lex.peekNext() == '+') {
    if (lex.getNext() == '-') {
        throw ParseError();
    }
  }

  m_value = new Factor(lex);
}

Unary::~Unary() {
  delete m_value;
}

int Unary::getValue() {
  return m_value->getValue();
}
