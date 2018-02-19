#ifndef __LAST_LEXER_H__
#define __LAST_LEXER_H__

#include <string>

class Lexer {
  public:
    Lexer(std::string& s);
    char getNext();
    int getNextAsNumber();
    char peekNext();

  private:
    void consumeSpaces();

  private:
    std::string& m_text;
    int m_pos;
};

#endif // __LAST_LEXER_H__
