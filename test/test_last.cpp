#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <last_parser.h>

std::string TEST_EXPRESSION0 = "";
std::string TEST_EXPRESSION1 = "1";
std::string TEST_EXPRESSION2 = "1 + 2";
std::string TEST_EXPRESSION3 = "(1 + 2) * 3";
std::string TEST_EXPRESSION4 = " (1  +  2)  *  3 ";

// runner
TEST(LastTest, Runner)
{
	EXPECT_EQ(1, 1);
}

// parser ctor/dtor
TEST(LastTest, ParserCtorDtor)
{
	LastParser* Parser = new LastParser;
	delete Parser;
}

// parser ctor/dtor
TEST(LastTest, ParserCtorDtor2)
{
  LastParser Parser;
  LastParser ParserWithArgs(TEST_EXPRESSION2);
}

// parser - set/get expression
TEST(LastTest, ParserGetSetExpression)
{
	LastParser Parser;
  Parser.SetLiteralExpression(TEST_EXPRESSION1);
  EXPECT_STRCASEEQ(Parser.GetLiteralExpression().c_str(), TEST_EXPRESSION1.c_str());

  LastParser Parser2(TEST_EXPRESSION1);
  EXPECT_STRCASEEQ(Parser2.GetLiteralExpression().c_str(), TEST_EXPRESSION1.c_str());
}

TEST(LastTest, ParserParse)
{
  LastParser Parser;
  Parser.SetLiteralExpression(TEST_EXPRESSION0);
  EXPECT_FALSE(Parser.Parse());
  Parser.SetLiteralExpression(TEST_EXPRESSION1);
  EXPECT_TRUE(Parser.Parse());
  Parser.SetLiteralExpression(TEST_EXPRESSION2);
  EXPECT_TRUE(Parser.Parse());
  Parser.SetLiteralExpression(TEST_EXPRESSION3);
  EXPECT_TRUE(Parser.Parse());
  Parser.SetLiteralExpression(TEST_EXPRESSION4);
  EXPECT_TRUE(Parser.Parse());
}


