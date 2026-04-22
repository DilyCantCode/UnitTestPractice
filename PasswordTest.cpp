/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, count_leading_characters_empty_string)
{
	Password my_password;
	ASSERT_EQ(0, my_password.count_leading_characters(""));
}

TEST(PasswordTest, count_leading_characters_various_runs_and_chars)
{
	Password my_password;
	ASSERT_EQ(1, my_password.count_leading_characters("Z"));
	ASSERT_EQ(4, my_password.count_leading_characters("aaaa"));
	ASSERT_EQ(5, my_password.count_leading_characters("aaaaab"));
	ASSERT_EQ(3, my_password.count_leading_characters("aaab"));
	ASSERT_EQ(1, my_password.count_leading_characters("abbb"));
	ASSERT_EQ(2, my_password.count_leading_characters("ZZz"));
	ASSERT_EQ(2, my_password.count_leading_characters("AAa"));
	ASSERT_EQ(1, my_password.count_leading_characters("aAa"));
	ASSERT_EQ(3, my_password.count_leading_characters("   a"));
	ASSERT_EQ(3, my_password.count_leading_characters("\t\t\tX"));
	ASSERT_EQ(2, my_password.count_leading_characters("\n\na"));
	ASSERT_EQ(2, my_password.count_leading_characters("!!?"));
	ASSERT_EQ(1, my_password.count_leading_characters("!?!!"));
}

TEST(PasswordTest, has_mixed_case_empty_and_single_case)
{
	Password my_password;
	ASSERT_FALSE(my_password.has_mixed_case(""));
	ASSERT_FALSE(my_password.has_mixed_case("abc"));
	ASSERT_FALSE(my_password.has_mixed_case("ABC"));
	ASSERT_FALSE(my_password.has_mixed_case("ABC123"));
	ASSERT_FALSE(my_password.has_mixed_case("abc!!!"));
	ASSERT_FALSE(my_password.has_mixed_case("123!!!"));
	ASSERT_FALSE(my_password.has_mixed_case("   \t\n"));
}

TEST(PasswordTest, has_mixed_case_true_mixed_positions_and_noise)
{
	Password my_password;
	ASSERT_TRUE(my_password.has_mixed_case("aZ"));
	ASSERT_TRUE(my_password.has_mixed_case("Z...a"));
	ASSERT_TRUE(my_password.has_mixed_case("a...Z"));
	ASSERT_TRUE(my_password.has_mixed_case("A1a"));
	ASSERT_TRUE(my_password.has_mixed_case("!aZ!"));
}

TEST(PasswordTest, unique_characters_basic_and_empty)
{
	Password my_password;
	ASSERT_EQ(0u, my_password.unique_characters(""));
	ASSERT_EQ(1u, my_password.unique_characters("a"));
	ASSERT_EQ(1u, my_password.unique_characters("aaaaa"));
	ASSERT_EQ(5u, my_password.unique_characters("abcde"));
	ASSERT_EQ(3u, my_password.unique_characters("abca"));
	ASSERT_EQ(2u, my_password.unique_characters("Aa"));
	ASSERT_EQ(2u, my_password.unique_characters("aAaa"));
	ASSERT_EQ(2u, my_password.unique_characters("a a"));   
	ASSERT_EQ(3u, my_password.unique_characters(" \t\n"));
	ASSERT_EQ(2u, my_password.unique_characters("!!?!!")); 
	ASSERT_EQ(3u, my_password.unique_characters("a1a2"));
}

TEST(PasswordTest, unique_mixed_chars_trap)
{
	Password my_password;
	ASSERT_EQ(6u, my_password.unique_characters("a A\t1!a"));
}

TEST(PasswordTest, unique_characters_more_ascii_noise)
{
	Password my_password;
	ASSERT_EQ(2u, my_password.unique_characters("11!!"));
	ASSERT_EQ(4u, my_password.unique_characters("a\tb\na"));
}