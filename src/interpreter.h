#ifndef __LAST_INTERPRETER_H__
#define __LAST_INTERPRETER_H__

#include <assert.h>
#include "node_ast.h"

class Parser;

class Interpreter : public NodeVisitor {
  public:
    Interpreter();
    virtual int visit(NodeBinaryOperator* node);
    virtual int visit(NodeNumber* node);
    
    int evaluate(NodeAST* root);

  private:
    Parser* m_parser;
};

#endif // __LAST_INTERPRETER_H__
