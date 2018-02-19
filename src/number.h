#ifndef __LAST_NUMBER_H__
#define __LAST_NUMBER_H__

#include "production.h"

class Number : public Production
{
public:
  Number(Lexer& lex);
  int getValue();

private:
  int value;
};

#endif // __LAST_NUMBER_H__
