#ifndef __LAST_EXCEPTIONS_H__
#define __LAST_EXCEPTIONS_H__

#include <exception>

class ParseException : public std::exception {
  const char* what() const throw();
};

class ParseExceptionUnaryMinusNotPermitted : public ParseException {
  const char* what() const throw();
};

class ParseExceptionLiteralTooLong : public ParseException {
  const char* what() const throw();
};

#endif // __LAST_EXCEPTIONS_H__
