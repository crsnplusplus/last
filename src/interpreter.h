#ifndef __LAST_INTERPRETER_H__
#define __LAST_INTERPRETER_H__

#include <assert.h>
#include "node_ast.h"

class Parser;

class Interpreter : public NodeVisitor {
  public:
    Interpreter();
    virtual ~Interpreter();

    virtual int visit(NodeBinaryOperator* node) override; // NodeVisitor
    virtual int visit(NodeNumber* node) override; // NodeVisitor
    
    int evaluate(NodeAST* root);

  private:
    Parser* m_parser;
};

#endif // __LAST_INTERPRETER_H__
