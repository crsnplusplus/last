#include "unary.h"
#include "factor.h"

Unary::Unary(Lexer& lex) {
  sign = 1; //initlize sign to 1
  
  char next = lex.peekNext();
  if (next == '-' || next == '+') { //while we have an operator to parse
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
