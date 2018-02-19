#ifndef __LAST_TOKEN_H__
#define __LAST_TOKEN_H__

class CToken {
  CToken() {}
};

class CTokenNumber : public CToken {
};

class CTokenOperation: public CToken {
};

class CTokenPlus : public CToken {
};

class CTokenStar : public CToken {
};

class CParenthesys : public CToken {
};

#endif // __LAST_TOKEN_H__
