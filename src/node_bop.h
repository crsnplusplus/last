#ifndef __LAST_NODE_BOP_H__
#define __LAST_NODE_BOP_H__

#include "node_ast.h"

class NodeBinaryOperator : public NodeAST {
public:
  NodeBinaryOperator(NodeAST* left, char op, NodeAST* right);
  virtual ~NodeBinaryOperator();

  virtual int accept(NodeVisitor& v) override; // NodeAST

  char getOperator();
  NodeAST* getLeft();
  NodeAST* getRight();

private:
  NodeAST * m_left;
  NodeAST* m_right;
  char m_op;
};

#endif // __LAST_NODE_BOP_H__
