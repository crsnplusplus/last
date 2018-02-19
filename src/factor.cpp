#include "factor.h"
#include "expression.h"
#include "number.h"

Factor::Factor(Lexer& lex) {
  
  if (lex.peekNext() == '(') { //check to see if a paren was used
    lex.getNext();
    expr = new Expression(lex);

    if (lex.peekNext() != ')') { //make sure the paren was matched
      throw ParseError();
    }
    else {
      lex.getNext();
    }
  }
  else { //if there is no paren then we just have a number
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
