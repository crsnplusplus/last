#ifndef __LAST_TERM_H__
#define __LAST_TERM_H__

#include "production.h"
#include "lexer.h"

#include <deque>

class Unary;

class Term : public Production
{
  public:
    Term(Lexer& in);
    virtual ~Term();

    int getValue();

  private:
    std::deque<Unary*> values;
    std::deque<char> ops;
};

#endif // __LAST_TERM_H__
