#include "lexer.h"

#include <assert.h>

Lexer::Lexer(std::string& s)
  : m_text(s), m_pos(0)
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

int Lexer::getNextAsNumber()
{
  consumeSpaces();
  char next = getNext();
  if (next > '9' || next < '0')
    return -1;

  return next - '0';
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
