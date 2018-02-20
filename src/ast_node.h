#ifndef __LAST_AST_NODE_H__
#define __LAST_AST_NODE_H__

class NodeAST {
  public:
    virtual ~NodeAST() { }
};

class NodeBinaryOperator : public NodeAST {
  public:
    NodeBinaryOperator(NodeAST* left, char op, NodeAST* right) :
      m_left(left), m_op(op), m_right(right) { }

  private:
    NodeAST * m_left;
    NodeAST* m_right;
    char m_op;
};

class NodeNumber : public NodeAST {
  public:
    NodeNumber(int value) : m_value(value) { }
  private:
    int m_value;
};

#endif // __LAST_AST_NODE_H__
