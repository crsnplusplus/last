#ifndef __LAST_NODE_AST_H__
#define __LAST_NODE_AST_H__

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

#endif // __LAST_NODE_AST_H__
