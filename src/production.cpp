#include "production.h"

#include <istream>

const char* ParseError::what() const throw() {
  return "a parsing error occured";
}

Production::~Production()
{
}
