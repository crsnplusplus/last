#ifndef __LAST_AST_NODE_H__
#define __LAST_AST_NODE_H__

#include <assert.h>

class NodeBinaryOperator;
class NodeNumber;

class NodeVisitor {
  public:
    virtual int visit(NodeNumber* n) = 0;
    virtual int visit(NodeBinaryOperator* n) = 0;
};

class NodeAST {
  public:
    virtual ~NodeAST() { }
    
    virtual int accept(NodeVisitor&) = 0;
};

class NodeBinaryOperator : public NodeAST {
  public:
    NodeBinaryOperator(NodeAST* left, char op, NodeAST* right) :
      m_left(left), m_op(op), m_right(right) { }

    virtual int accept(NodeVisitor& v) { return v.visit(this); }
    
    char getOperator() { return m_op; }
    NodeAST* getLeft() { return m_left; }
    NodeAST* getRight() { return m_right; }

    virtual ~NodeBinaryOperator() {
      delete m_left;
      delete m_right;

      m_left = nullptr; // debug
      m_right = nullptr;
    }

  private:
    NodeAST* m_left;
    NodeAST* m_right;
    char m_op;
};

class NodeNumber : public NodeAST {
  public:
    NodeNumber(char value) : m_value(value) { }
    virtual ~NodeNumber() { }

    virtual int accept(NodeVisitor& v) { return v.visit(this); }

    int getValue() const {
      if (m_value >= '0' && m_value < '9' )
        return m_value - '0';
      
      assert (false);
      return 0;
    }

  private:
    char m_value;
};

#endif // __LAST_AST_NODE_H__
