#ifndef __LAST_PRODUCTION_H__
#define __LAST_PRODUCTION_H__

#include <exception>

#include "lexer.h"

// a simple class to handle parsing errors
class ParseError : public std::exception {
  const char* what() const throw();
};

// base class for all of our productions
class Production {
public:
  virtual ~Production();
  virtual int getValue() = 0;
};


#endif // __LAST_PRODUCTION_H__
