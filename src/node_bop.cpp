#include "node_bop.h"

NodeBinaryOperator::NodeBinaryOperator(NodeAST* left, char op, NodeAST* right)
: m_left(left), m_op(op), m_right(right)
{
}

NodeBinaryOperator::~NodeBinaryOperator() {
  delete m_left;
  delete m_right;

  m_left = nullptr; // debug
  m_right = nullptr;
}

int NodeBinaryOperator::accept(NodeVisitor& v)
{
  return v.visit(this);
}

char NodeBinaryOperator::getOperator()
{
  return m_op;
}

NodeAST* NodeBinaryOperator::getLeft()
{
  return m_left;
}

NodeAST* NodeBinaryOperator::getRight()
{
  return m_right;
}