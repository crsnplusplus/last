#include "interpreter.h"
#include "ast_node.h"
#include "parser.h"

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
    case '/':
      return (left->accept(*this)) / (right->accept(*this));
  }

  assert(false);
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
