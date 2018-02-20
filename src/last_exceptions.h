#ifndef __LAST_EXCEPTIONS_H__
#define __LAST_EXCEPTIONS_H__

#include <exception>

class LastException : public std::exception {
  public:
    virtual const char* what() const throw();
};

class ParseException : public LastException {
  public:
    virtual const char* what() const throw() override;
};

class ParseExceptionUnaryMinusNotPermitted : public LastException {
  public:
    virtual const char* what() const throw() override;
};

class ParseExceptionLiteralTooLong : public LastException {
  public:
    virtual const char* what() const throw() override;
};

class InterpreterExceptionDividedByZero : public LastException {
  public:
    virtual const char* what() const throw() override;
};

class InterpreterOperatorNotSupported : public LastException {
  public:
    virtual const char* what() const throw() override;
};

#endif // __LAST_EXCEPTIONS_H__
