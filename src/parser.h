#ifndef __LAST_PARSER_H__
#define __LAST_PARSER_H__

#include "ast_node.h"
#include <exception>

class Lexer;

class ParseException : public std::exception {
  const char* what() const throw();
};

class Parser {
  public:
    Parser(Lexer* lex);
    NodeAST* parse();

  private:
    void eat(char c);
    NodeAST* factor();
    NodeAST* term();
    NodeAST* expression();

  private:
    Lexer* m_lex;
    char m_current;
};

#endif // __LAST_PARSER_H__
