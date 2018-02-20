#ifndef __LAST_LEXER_H__
#define __LAST_LEXER_H__

#include <string>

class Lexer {
  public:
    Lexer(std::string& s);
    virtual ~Lexer();

    char getNext();
    char peekNext();

  private:
    void consumeSpaces();

  private:
    std::string& m_text;
    int m_pos;
};

#endif // __LAST_LEXER_H__
