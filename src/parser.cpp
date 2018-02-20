#include "parser.h"
#include "lexer.h"
#include "ast_node.h"

#include <assert.h>

const char* ParseException::what() const throw() {
  return "a parsing error occured";
}


Parser::Parser(Lexer* lex) : 
  m_lex(lex),
  m_current(m_lex->getNext())
{
}

NodeAST* Parser::parse()
{
  return expression();
}

void Parser::eat(char c)
{
  if (m_current == c)
    m_current = m_lex->getNext();
  else
    throw ParseException();
}

NodeAST* Parser::factor()
{
  assert(m_lex != nullptr);
  char current = m_current;

  if (isdigit(current)) {
    eat(current);
    return new NodeNumber(current);
  }
  else if (current == '(') {
    eat('(');
    NodeAST* node = expression();
    eat(')');
    return node;
  }

  return nullptr;
}

NodeAST * Parser::term()
{
  assert(m_lex != nullptr);
  NodeAST* node = factor();
  while (m_current == '*' || m_current == '/') {
    char current = m_current;
    if (current == '*') {
      eat('*');
    }
    else if (current == '/') {
      eat('/');
    }

    NodeAST* newNode = new NodeBinaryOperator(node, current, term());
    node = newNode;
  }

  return node;
}

NodeAST* Parser::expression()
{
  assert(m_lex != nullptr);
  NodeAST* node = term();
  while (m_current == '+' || m_current == '-') {
    char current = m_current;
    if (current == '+') {
      eat('+');
    }
    else if (current == '-') {
      eat('-');
    }

    NodeAST* newNode = new NodeBinaryOperator(node, current, term());
    node = newNode;
  }

  return node;
}
