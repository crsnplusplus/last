#include "number.h"

Number::Number(Lexer& lex) {
  m_value = lex.getNextAsNumber();
}

int Number::getValue() {
  return m_value;
}
