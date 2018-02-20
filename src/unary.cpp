#include "unary.h"
#include "factor.h"

Unary::Unary(Lexer& lex) {
  while (lex.peekNext() == '-' || lex.peekNext() == '+') {
    if (lex.getNext() == '-') {
        throw ParseError();
    }
  }

  value = new Factor(lex);
}

Unary::~Unary() {
  delete value;
}

int Unary::getValue() {
  return sign * value->getValue();
}
