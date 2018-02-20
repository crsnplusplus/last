#include "parser.h"
#include "lexer.h"
#include "ast_node.h"
#include <last_exceptions.h>

#include <assert.h>

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
    if (isdigit(m_lex->peekNext())) {
      // next is digit too, throwing exception
      // (only single digit is supporte)
      throw ParseExceptionLiteralTooLong();
    }

    eat(current);

    return new NodeNumber(current);
  }
  else if (current == '(') {
    eat('(');
    NodeAST* node = expression();
    eat(')');
    return node;
  }
  else if (current == '-') {
    // unary operator not supported
    throw ParseExceptionUnaryMinusNotPermitted();
  }

  return nullptr;
}

NodeAST* Parser::term()
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
