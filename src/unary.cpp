#include "unary.h"
#include "factor.h"

Unary::Unary(Lexer& lex) {
  sign = 1;
  
  while (lex.peekNext() == '-' || lex.peekNext() == '+') {
    if (lex.getNext() == '-') {
      sign = -sign;
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
