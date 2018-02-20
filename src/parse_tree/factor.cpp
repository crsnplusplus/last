#include "factor.h"
#include "expression.h"
#include "number.h"

Factor::Factor(Lexer& lex) {
  
  if (lex.peekNext() == '(') {
    lex.getNext();
    m_expr = new Expression(lex);

    if (lex.peekNext() != ')') {
      throw ParseError();
    }
    else {
      lex.getNext();
    }
  }
  else {
    m_expr = new Number(lex);
  }
}

Factor::~Factor()
{
  delete m_expr;
}

int Factor::getValue() {
  return m_expr->getValue();
}
