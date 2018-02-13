#include "last_parser.h"
#include "last_token.h"
#include "last_utils.h"
#include <vector>

LastParser::LastParser()
{
}

LastParser::LastParser(const std::string & LiteralExpression) :
  m_Expression(LiteralExpression)
{
}

LastParser::~LastParser()
{
}

void LastParser::SetLiteralExpression(const std::string & Expression)
{
  m_Expression = Expression;
}

std::string LastParser::GetLiteralExpression() const
{
  return m_Expression;
}

bool LastParser::Parse()
{
  bool Result = Scan();
  
  if (Result == false)
  {
    LastPrintMessage("Parser: scan failed");
    return false;
  }

  
  return true;
}

bool LastParser::Scan()
{
  std::vector<LastToken> Tokens;
  // in this way, scanner result is false, for m_Expression.size() == 0
  bool ScanningResult = m_Expression.size() > 0 ? true : false;

  for (char CurrentChar : m_Expression)
  {
    if (CurrentChar == ' ')
      // just skipping spaces
      continue;

    LastToken Token(CurrentChar);
    // and creating tokens, both valid and invalid ones
    Tokens.push_back(Token);
    // memorizing the result
    ScanningResult &= (Token.GetType() != token_unknown);
  }

  return ScanningResult;
}
