#ifndef __LAST_FACTOR_H__
#define __LAST_FACTOR_H__

#include "production.h"

class Factor : public Production
{
  public:
    Factor(Lexer& lex);
    virtual ~Factor();

    int getValue();

  private:
    Production* expr;
};

#endif // __LAST_FACTOR_H__
