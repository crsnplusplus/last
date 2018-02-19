#ifndef __LAST_PARSER_H__
#define __LAST_PARSER_H__

#include <string>

class LastParser
{
	public:
		LastParser();
    LastParser(const std::string& LiteralExpression);
		virtual ~LastParser();

		void SetLiteralExpression(const std::string& LiteralExpression);
		std::string GetLiteralExpression() const;

    bool Parse();
    
  private:
    bool Scan();
    bool CreateAST();
    bool ParseExpression(std::string Expression);

  private:
	  std::string m_Expression;
};

#endif // __LAST_PARSER_H__
