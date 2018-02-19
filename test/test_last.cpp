#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <lexer.h>
#include <expression.h>

std::string TEST_EXPRESSION0 = "";
std::string TEST_EXPRESSION1 = "1";
std::string TEST_EXPRESSION2 = "1 + 2";
std::string TEST_EXPRESSION2b= "1 * 2";
std::string TEST_EXPRESSION3 = "(1 + 2) * 3";
std::string TEST_EXPRESSION4 = " (1  +  2)  *  3 ";
std::string TEST_EXPRESSION5 = " ((1  +  2 ) + 3  *  4)";
std::string TEST_EXPRESSION_E1 = "(4 + 5 * (7 - 3)) - 2"; // 22
std::string TEST_EXPRESSION_E2 = "4 + 5 + 7 / 2"; // 12

// runner
TEST(LastTest, Runner)
{
	EXPECT_EQ(1, 1);
}

TEST(LastTest, Production1)
{
  Lexer lex(TEST_EXPRESSION1);
  Expression expr(lex); //construct the parse tree
  int value = expr.getValue();
  EXPECT_EQ(value, 1);
}


TEST(LastTest, Production2)
{
  Lexer lex(TEST_EXPRESSION2b);
  Expression expr(lex); //construct the parse tree
  int value = expr.getValue();
  EXPECT_EQ(value, 2);
}

TEST(LastTest, Production6)
{
  Lexer lex(TEST_EXPRESSION_E1);
  Expression expr(lex); //construct the parse tree
  int value = expr.getValue();
  EXPECT_EQ(value, 22);
}

TEST(LastTest, Production7)
{
  Lexer lex(TEST_EXPRESSION_E2);
  Expression expr(lex); //construct the parse tree
  int value = expr.getValue();
  EXPECT_EQ(value, 12);
}
