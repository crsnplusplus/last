#ifndef __LAST_NODE_NUMBER_H__
#define __LAST_NODE_NUMBER_H__

#include "node_ast.h"

class NodeNumber : public NodeAST {
public:
  NodeNumber(char value);
  virtual ~NodeNumber();

  virtual int accept(NodeVisitor& v) override; // NodeAST

  int getValue() const;

private:
  char m_value;
};

#endif // __LAST_NODE_NUMBER_H__
