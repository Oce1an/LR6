#include <gtest/gtest.h>
#include <cstring>
#include "../src/task1.h"

class ExtractFloatNumberTest : public ::testing::Test {
protected:
    static const int MAX_LENGTH = 81;
    char output[MAX_LENGTH];

    void SetUp() override {
        std::memset(output, 0, MAX_LENGTH);
    }
};

TEST_F(ExtractFloatNumberTest, NegativeNumber) {
    const char* input = "-123.45";
    extractFloatNumber(input, output, MAX_LENGTH);
    EXPECT_STREQ("123.45", output);
}

TEST_F(ExtractFloatNumberTest, PositiveSign) {
    const char* input = "+67.89";
    extractFloatNumber(input, output, MAX_LENGTH);
    EXPECT_STREQ("67.89", output);
}

TEST_F(ExtractFloatNumberTest, MultipleSigns) {
    const char* input = "-+12.34";
    extractFloatNumber(input, output, MAX_LENGTH);
    EXPECT_STREQ("12.34", output);
}

TEST_F(ExtractFloatNumberTest, OnlySignsAndDots) {
    const char* input = "-+.-+.";
    extractFloatNumber(input, output, MAX_LENGTH);
    EXPECT_STREQ("", output);
}

TEST_F(ExtractFloatNumberTest, DotBetweenDigits) {
    const char* input = "1.2.3.4.5";
    extractFloatNumber(input, output, MAX_LENGTH);
    EXPECT_STREQ("1.2345", output);
}

TEST_F(ExtractFloatNumberTest, LongNumberWithMultipleDots) {
    const char* input = "1.2.3.4.5.6.7.8.9.0";
    extractFloatNumber(input, output, MAX_LENGTH);
    EXPECT_STREQ("1.234567890", output);
}

TEST_F(ExtractFloatNumberTest, MixedWithSpaces) {
    const char* input = " 12 . 34 56 ";
    extractFloatNumber(input, output, MAX_LENGTH);
    EXPECT_STREQ("12.3456", output);
}

TEST_F(ExtractFloatNumberTest, SingleDigitWithDot) {
    const char* input = "5.";
    extractFloatNumber(input, output, MAX_LENGTH);
    EXPECT_STREQ("5", output);
}

TEST_F(ExtractFloatNumberTest, DotThenDigit) {
    const char* input = ".5";
    extractFloatNumber(input, output, MAX_LENGTH);
    EXPECT_STREQ("0.5", output);
}

TEST_F(ExtractFloatNumberTest, MultipleLeadingDots) {
    const char* input = "...123";
    extractFloatNumber(input, output, MAX_LENGTH);
    EXPECT_STREQ("0.123", output);
}