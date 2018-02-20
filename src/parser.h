#ifndef __LAST_PARSER_H__
#define __LAST_PARSER_H__

#include "ast_node.h"

class Lexer;

class Parser {
  public:
    Parser(Lexer* lex);
    NodeAST* parse();

  private:
    void consume(char c);
    NodeAST* factor();
    NodeAST* term();
    NodeAST* expression();

  private:
    Lexer* m_lex;
    char m_current;
};

#endif // __LAST_PARSER_H__
