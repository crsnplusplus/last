#include "interpreter.h"
#include "node_ast.h"
#include "node_bop.h"
#include "node_number.h"
#include "parser.h"

#include "last_exceptions.h"

#include <assert.h>

Interpreter::Interpreter()
{
}

int Interpreter::visit(NodeBinaryOperator* node)
{
  assert(node != nullptr);
  char op = node->getOperator();
  NodeAST* left = node->getLeft();
  NodeAST* right = node->getRight();
  
  switch (op) {
    case '+':
      return (left->accept(*this)) + (right->accept(*this));
    case '-':
      return (left->accept(*this)) - (right->accept(*this));
    case '*':
      return (left->accept(*this)) * (right->accept(*this));
    case '/': {
      int lhs = left->accept(*this);
      int rhs = right->accept(*this);
      if (rhs == 0) {
        // nice to have :)
        throw InterpreterExceptionDividedByZero();
      }
      return lhs / rhs;
    }
    default:
      throw InterpreterOperatorNotSupported();
  }

  return 0;
}

int Interpreter::visit(NodeNumber* node)
{
  assert(node != nullptr);
  return node->getValue();
}

int Interpreter::evaluate(NodeAST* root)
{
  if (root == nullptr) // empty string?
    return 0;

  int value = root->accept(*this);
  return value;
}
