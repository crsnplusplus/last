#include "node_number.h"

NodeNumber::NodeNumber(char value)
  : m_value(value)
{
}

NodeNumber::~NodeNumber()
{
}

int NodeNumber::accept(NodeVisitor& v)
{
  return v.visit(this);
}

int NodeNumber::getValue() const {
  if (m_value >= '0' && m_value < '9')
    return m_value - '0';

  assert(false);
  return 0;
}