#include <gtest/gtest.h>
#include <cstring>
#include "../src/task3.h"

TEST(ConversionTest, IntToStringPositive) {
    char buffer[50];
    intToString(123, buffer);
    EXPECT_STREQ(buffer, "123");
}

TEST(ConversionTest, IntToStringNegative) {
    char buffer[50];
    intToString(-456, buffer);
    EXPECT_STREQ(buffer, "-456");
}

TEST(ConversionTest, IntToStringZero) {
    char buffer[50];
    intToString(0, buffer);
    EXPECT_STREQ(buffer, "0");
}

TEST(ConversionTest, StringToIntPositive) {
    EXPECT_EQ(stringToInt("789"), 789);
}

TEST(ConversionTest, StringToIntNegative) {
    EXPECT_EQ(stringToInt("-123"), -123);
}

TEST(ConversionTest, StringToIntWithPlus) {
    EXPECT_EQ(stringToInt("+456"), 456);
}

TEST(ConversionTest, DoubleToStringPositive) {
    char buffer[50];
    doubleToString(123.456, buffer, 2);
    EXPECT_STREQ(buffer, "123.45");
}

TEST(ConversionTest, DoubleToStringNegative) {
    char buffer[50];
    doubleToString(-78.9, buffer, 1);
    EXPECT_STREQ(buffer, "-78.9");
}

TEST(ConversionTest, StringToDoublePositive) {
    EXPECT_DOUBLE_EQ(stringToDouble("12.34"), 12.34);
}

TEST(ConversionTest, StringToDoubleNegative) {
    EXPECT_DOUBLE_EQ(stringToDouble("-56.78"), -56.78);
}