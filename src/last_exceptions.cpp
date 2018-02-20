#include "last_exceptions.h"

const char* LastException::what() const throw() {
  return "Unknown LAST error";
}

const char* ParseException::what() const throw() {
  return "Parsing error";
}

const char* ParseExceptionUnaryMinusNotPermitted::what() const throw()
{
  return "Unary minus not permitted (-)";
}

const char* ParseExceptionLiteralTooLong::what() const throw()
{
  return "Literal too long";
}

const char* InterpreterExceptionDividedByZero::what() const throw()
{
  return "Division by zero";
}
