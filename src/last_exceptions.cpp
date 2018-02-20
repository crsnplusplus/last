#include "last_exceptions.h"

const char* ParseException::what() const throw() {
  return "Parsing error";
}

const char * ParseExceptionUnaryMinusNotPermitted::what() const throw()
{
  return "Unary minus not permitted (-)";
}

const char * ParseExceptionLiteralTooLong::what() const throw()
{
  return "Literal too long";
}
