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

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, unique_single_character)
{
	Password my_password;
	ASSERT_EQ(1u, my_password.unique_characters("a"));
}

TEST(PasswordTest, unique_all_same)
{
	Password my_password;
	ASSERT_EQ(1u, my_password.unique_characters("aaaaa"));
}

TEST(PasswordTest, unique_all_different)
{
	Password my_password;
	ASSERT_EQ(5u, my_password.unique_characters("abcde"));
}

TEST(PasswordTest, unique_emtpty_string)
{
	Password my_password;
	ASSERT_EQ(0u, my_password.unique_characters(""));
}

TEST(PasswordTest, unique_non_adjacent_repeats)
{
	Password my_password;
	ASSERT_EQ(3u, my_password.unique_characters("abca"));
}

TEST(PasswordTest, unique_case_sensitive)
{
	Password my_password;
	ASSERT_EQ(2u, my_password.unique_characters("Aa"));
	ASSERT_EQ(2u, my_password.unique_characters("aAaa"));
}

TEST(PasswordTest, unique_counts_spaces_and_punctuation)
{
	Password my_password;
	ASSERT_EQ(2u, my_password.unique_characters("a a"));   
	ASSERT_EQ(2u, my_password.unique_characters("!!?!!")); 
}

TEST(PasswordTest, unique_counts_digits)
{
	Password my_password;
	ASSERT_EQ(3u, my_password.unique_characters("a1a2"));
}