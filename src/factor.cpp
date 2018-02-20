#include "factor.h"
#include "expression.h"
#include "number.h"

Factor::Factor(Lexer& lex) {
  
  if (lex.peekNext() == '(') {
    lex.getNext();
    expr = new Expression(lex);

    if (lex.peekNext() != ')') {
      throw ParseError();
    }
    else {
      lex.getNext();
    }
  }
  else {
    expr = new Number(lex);
  }
}

Factor::~Factor()
{
  delete expr;
}

int Factor::getValue() {
  return expr->getValue();
}
