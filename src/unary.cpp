#include "unary.h"
#include "factor.h"

Unary::Unary(Lexer& lex) {
  sign = 1;
  
  while (lex.peekNext() == '-' || lex.peekNext() == '+') { //while we have an operator to parse // @todo change if to while
    if (lex.getNext() == '-') { //if the operator actully has an effect
      sign = -sign;
    }
  }
  value = new Factor(lex); //parse the factor following the unary operators
}

Unary::~Unary() {
  delete value;
}

int Unary::getValue() {
  return sign * value->getValue();
}
