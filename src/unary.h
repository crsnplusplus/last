#ifndef __LAST_UNARY_H__
#define __LAST_UNARY_H__

#include "production.h"

class Factor;

class Unary : public Production
{
  public:
    Unary(Lexer& in);
    virtual ~Unary();

    int getValue();

  private:
    int sign;
    Factor* value;
};

#endif // __LAST_UNARY_H__
