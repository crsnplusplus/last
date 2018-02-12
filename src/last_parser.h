#ifndef __LAST_PARSER_H__
#define __LAST_PARSER_H__

#include <string>

class LastParser
{
	public:
		LastParser();
    LastParser(const std::string& literal_expression);
		virtual ~LastParser();

		void SetLiteralExpression(const std::string& literal_expression);
		std::string GetLiteralExpression() const;

    bool Parse();
    
  private:
	  std::string m_Expression;
};

#endif // __LAST_PARSER_H__
