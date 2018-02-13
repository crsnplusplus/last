#include "last_utils.h"
#include <iostream>
#include <assert.h>

void LastPrintMessage(const char* Message)
{
  assert(Message != nullptr);
  std::cout << "L>" << Message << std::endl;
}
