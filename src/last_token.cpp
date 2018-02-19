/*
#include "last_token.h"

ETokenType LastToken::GetType() const
{
  ETokenType tokenType = token_unknown;

  switch (m_Literal)
  {
    case '(': tokenType = token_opened_parenthesys; break;
    case ')': tokenType = token_closed_parenthesys; break;
    case '+': tokenType = token_add; break;
    case '-': tokenType = token_subtract; break;
    case '*': tokenType = token_multiply; break;
    case '/': tokenType = token_divide; break;
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
      tokenType = token_number;
      break;
    default:
      break;
  }

  return tokenType;
}
*/