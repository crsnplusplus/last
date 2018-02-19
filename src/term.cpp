#include "term.h"
#include "unary.h"

Term::Term(Lexer& lex) {
  values.push_back(new Unary(lex)); //construct the first value
  
  char next = lex.peekNext();
  if (next == '*' || next == '/') {
    ops.push_back(lex.getNext()); //push back the operator
    values.push_back(new Unary(lex)); //push back the left operand
  }
}

Term::~Term() {
  for (unsigned int i = 0; i<values.size(); ++i) {
    delete values[i];
  }
}

int Term::getValue() {
  int ret = values[0]->getValue(); //get the first value
  for (unsigned int i = 1; i<values.size(); ++i) { //loop though the rest of the values
    if (ops[i - 1] == '*') { //check to see which operator it is and preform the acoridng action
      ret *= values[i]->getValue();
    }
    else {
      ret /= values[i]->getValue();
    }
  }
  return ret;
}