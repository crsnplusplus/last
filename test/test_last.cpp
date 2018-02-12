#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <last_parser.h>

// runner
TEST(LastTest, Runner)
{
	EXPECT_EQ(1, 1);
}

// creator
TEST(LastTest, Creator)
{
	LastParser* p = new LastParser;
	EXPECT_NE(p, nullptr);
	delete p;
}
