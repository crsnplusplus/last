#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <lexer.h>
#include <parser.h>
#include <interpreter.h>
#include <last_exceptions.h>

std::string TEST_EXPRESSION_EMPTY = "";
std::string TEST_EXPRESSION_FAIL1 = "-1";
std::string TEST_EXPRESSION_FAIL2 = "-10";
std::string TEST_EXPRESSION_FAIL3 = "42";
std::string TEST_EXPRESSION_FAIL4 = "(4 + 2";
std::string TEST_EXPRESSION_0DIV = "0/4";
std::string TEST_EXPRESSION_DIV0 = "2/0";

struct TestData {
  std::string expression;
  int result;
};

TestData tests[] = {
    { "1", 1 }, // 0
    { "4 + 2", 6 }, // 1
    { "4 * 2", 8 }, // 2
    { "(1 + 2) * 3", 9 }, // 3
    { " (1  +  2)  *  3 ", 9 }, // 4
    { " ((1  +  2 ) + 3  *  4)", 15 }, // 5
    { "(4 + 5 * (7 - 3)) - 2", 22 }, // 6
    { "4 + 5 + 7 / 2", 12 } // 7
};


// runner
TEST(LastTest, Runner)
{
	EXPECT_EQ(true, true);
}

TEST(LastTest, Interpreter1)
{
  int testNumber = 0;
  TestData test = tests[testNumber];
  Lexer lex(test.expression);
  Parser parser(&lex);
  Interpreter interpreter;

  NodeAST* root = parser.parse();
  int value = interpreter.evaluate(root);

  EXPECT_EQ(value, test.result);
}


TEST(LastTest, Interpreter2)
{
  int testNumber = 1;
  TestData test = tests[testNumber];
  Lexer lex(test.expression);
  Parser parser(&lex);
  Interpreter interpreter;

  NodeAST* root = parser.parse();
  int value = interpreter.evaluate(root);

  EXPECT_EQ(value, test.result);
}


TEST(LastTest, Interpreter3)
{
  int testNumber = 2;
  TestData test = tests[testNumber];
  Lexer lex(test.expression);
  Parser parser(&lex);
  Interpreter interpreter;

  NodeAST* root = parser.parse();
  int value = interpreter.evaluate(root);

  EXPECT_EQ(value, test.result);
}

TEST(LastTest, Interpreter4)
{
  int testNumber = 3;
  TestData test = tests[testNumber];
  Lexer lex(test.expression);
  Parser parser(&lex);
  Interpreter interpreter;

  NodeAST* root = parser.parse();
  int value = interpreter.evaluate(root);

  EXPECT_EQ(value, test.result);
}

TEST(LastTest, Interpreter5)
{
  int testNumber = 4;
  TestData test = tests[testNumber];
  Lexer lex(test.expression);
  Parser parser(&lex);
  Interpreter interpreter;

  NodeAST* root = parser.parse();
  int value = interpreter.evaluate(root);

  EXPECT_EQ(value, test.result);
}

TEST(LastTest, Interpreter6)
{
  int testNumber = 5;
  TestData test = tests[testNumber];
  Lexer lex(test.expression);
  Parser parser(&lex);
  Interpreter interpreter;

  NodeAST* root = parser.parse();
  int value = interpreter.evaluate(root);

  EXPECT_EQ(value, test.result);
}

TEST(LastTest, Interpreter7)
{
  int testNumber = 6;
  TestData test = tests[testNumber];
  Lexer lex(test.expression);
  Parser parser(&lex);
  Interpreter interpreter;

  NodeAST* root = parser.parse();
  int value = interpreter.evaluate(root);

  EXPECT_EQ(value, test.result);
}

TEST(LastTest, InterpreterEmpty)
{
  Lexer lex(TEST_EXPRESSION_EMPTY);
  Parser parser(&lex);
  Interpreter interpreter;

  NodeAST* root = parser.parse();
  int value = interpreter.evaluate(root);

  EXPECT_EQ(value, 0);
}

TEST(LastTest, InterpreterFail1)
{
  Lexer lex(TEST_EXPRESSION_FAIL1);
  Parser parser(&lex);

  EXPECT_THROW({
    parser.parse();
  }, ParseExceptionUnaryMinusNotPermitted);
}

TEST(LastTest, InterpreterFail2)
{
  Lexer lex(TEST_EXPRESSION_FAIL2);
  Parser parser(&lex);

  EXPECT_THROW({
    parser.parse();
  }, ParseExceptionUnaryMinusNotPermitted);
}

TEST(LastTest, InterpreterFail3)
{
  Lexer lex(TEST_EXPRESSION_FAIL3);
  Parser parser(&lex);

  EXPECT_THROW({
    parser.parse();
  }, ParseExceptionLiteralTooLong);
}

TEST(LastTest, InterpreterFail0Div)
{
  Lexer lex(TEST_EXPRESSION_0DIV);
  Parser parser(&lex);
  Interpreter interpreter;

  NodeAST* root = parser.parse();
  int value = interpreter.evaluate(root);

  EXPECT_EQ(value, 0);
}

TEST(LastTest, InterpreterFailDiv0)
{
  Lexer lex(TEST_EXPRESSION_DIV0);
  Parser parser(&lex);
  Interpreter interpreter;

  NodeAST* root = parser.parse();

  EXPECT_THROW({
    interpreter.evaluate(root);
  }, InterpreterExceptionDividedByZero);
}
