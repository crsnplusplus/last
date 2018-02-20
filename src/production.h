#ifndef __LAST_PRODUCTION_H__
#define __LAST_PRODUCTION_H__

#include <exception>

#include "lexer.h"

class ParseError : public std::exception {
  const char* what() const throw();
};

class Production {
public:
  virtual ~Production();
  virtual int getValue() = 0;
};

#endif // __LAST_PRODUCTION_H__
