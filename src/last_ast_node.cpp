#include "last_ast_node.h"

LastNode::LastNode()
{
}

LastNode::~LastNode()
{
}

LastNode* LastNode::Create(char Literal)
{
  LastNode* Node = nullptr;
  switch (Literal) {
    case '(':
      break;

    case ')':
      break;

    case '+':
      break;

    case '-':
      break;

    case '*':
      break;

    case '/':
      break;

    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
      break;
  
    default:
      break;
  }

  return nullptr;
}
