#ifndef __LAST_AST_NODE_H__
#define __LAST_AST_NODE_H__

#include <memory>

class LastNodeNumber;
class LastNodeBinaryOp;

class ILastNodeVisitor {
public:
  virtual void Visit(LastNodeNumber& i_node) = 0;
  virtual void Visit(LastNodeBinaryOp& i_node) = 0;
};

class LastNode {
  public:
    LastNode();
    virtual ~LastNode();
  
    virtual void Accept(ILastNodeVisitor& i_visitor) = 0;

  public:
    static LastNode* Create(char Literal); // @todo factory

  private:
    char m_Literal;
};

class LastNodeNumber : public LastNode {
  public:
    LastNodeNumber(int Value) : LastNode(), m_Value(Value) { }

    virtual void Accept(ILastNodeVisitor& i_visitor) { }

  private:
    int m_Value;
};

class LastNodeUnaryOp : public LastNode {
  public:
    virtual void Accept(ILastNodeVisitor& i_visitor) { }
};

class LastNodeBinaryOp : public LastNode {
  public:
    virtual void Accept(ILastNodeVisitor& i_visitor) { }
};

class LastNodeAddition : public LastNodeBinaryOp {
  public:
    virtual void Accept(ILastNodeVisitor& i_visitor) { }
};

class LastNodeSubtraction : public LastNodeBinaryOp {
  public:
    virtual void Accept(ILastNodeVisitor& i_visitor) { }
};

class LastNodeMultiplication : public LastNodeBinaryOp {
  public:
    virtual void Accept(ILastNodeVisitor& i_visitor) { }
};

class LastNodeDivision : public LastNodeBinaryOp {
  public:
    virtual void Accept(ILastNodeVisitor& i_visitor) { }
};

#endif // __LAST_AST_NODE_H__
