#ifndef __LAST_EXCEPTIONS_H__
#define __LAST_EXCEPTIONS_H__

#include <exception>

class LastException : public std::exception {
  public:
    const char* what() const throw();
};

class ParseException : public LastException {
  const char* what() const throw();
};

class ParseExceptionUnaryMinusNotPermitted : public LastException {
  const char* what() const throw();
};

class ParseExceptionLiteralTooLong : public LastException {
  const char* what() const throw();
};

class InterpreterExceptionDividedByZero : public LastException {
  const char* what() const throw();
};

class InterpreterOperatorNotSupported : public LastException {
  const char* what() const throw();
};

#endif // __LAST_EXCEPTIONS_H__
