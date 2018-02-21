#include "lexer.h"

#include <assert.h>

Lexer::Lexer(std::string& s)
  : m_text(s), m_pos(0)
{
}

Lexer::~Lexer()
{
}

char Lexer::getNext()
{
  consumeSpaces();
  char val = m_text[m_pos];
  ++m_pos;
  consumeSpaces();
  return val;
}

char Lexer::peekNext()
{
  int maxSize = m_text.size();

  for (int i = m_pos; i < maxSize; ++i) {
    if (m_text[i] == ' ')
      continue;

    return m_text[i];
  }

  return 0;
}

void Lexer::consumeSpaces()
{
  int maxSize = m_text.size();
  
  for (int i = m_pos; i < maxSize; ++i) {
    if (m_text[i] == ' ')
      ++m_pos;
    else
      break;
  }
}
