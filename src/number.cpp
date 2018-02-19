#include "number.h"

Number::Number(Lexer& lex) {
  value = lex.getNextAsNumber();
}

int Number::getValue() {
  return value;
}
