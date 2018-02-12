#ifndef __LAST_TOKEN_H__
#define __LAST_TOKEN_H__

enum ETokenType
{
  token_unknown,
  token_opened_parenthesys, token_closed_parenthesys,
  token_add, token_subtract, token_multiply, token_divide,
  token_number
};

class LastToken
{
  public:
    LastToken(char LiteralValue = '#') : m_Literal(LiteralValue) { }
    virtual ~LastToken() = default;

    ETokenType GetType() const;
    int GetValue() const { return GetType() == token_number ? m_Literal - '0' : -1; }

  private:
    char m_Literal;
};

#endif // __LAST_TOKEN_H__
