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

TEST_F(ExtractFloatNumberTest, OnlyDigits) {
    const char* input = "12345";
    extractFloatNumber(input, output, MAX_LENGTH);
    EXPECT_STREQ("12345", output);
}

TEST_F(ExtractFloatNumberTest, DigitsWithSingleDot) {
    const char* input = "12.34abc56";
    extractFloatNumber(input, output, MAX_LENGTH);
    EXPECT_STREQ("12.3456", output);
}

TEST_F(ExtractFloatNumberTest, MultipleDots) {
    const char* input = "12.34.56";
    extractFloatNumber(input, output, MAX_LENGTH);
    EXPECT_STREQ("12.3456", output);
}

TEST_F(ExtractFloatNumberTest, MixedCharacters) {
    const char* input = "a1b2.c3d4!e5";
    extractFloatNumber(input, output, MAX_LENGTH);
    EXPECT_STREQ("12.345", output);
}

TEST_F(ExtractFloatNumberTest, NoDigits) {
    const char* input = "abc.def!";
    extractFloatNumber(input, output, MAX_LENGTH);
    EXPECT_STREQ("", output);
}

TEST_F(ExtractFloatNumberTest, EmptyString) {
    const char* input = "";
    extractFloatNumber(input, output, MAX_LENGTH);
    EXPECT_STREQ("", output);
}

TEST_F(ExtractFloatNumberTest, DotOnly) {
    const char* input = "....";
    extractFloatNumber(input, output, MAX_LENGTH);
    EXPECT_STREQ("", output);
}

TEST_F(ExtractFloatNumberTest, StartsWithDot) {
    const char* input = ".123";
    extractFloatNumber(input, output, MAX_LENGTH);
    EXPECT_STREQ("0.123", output);
}

TEST_F(ExtractFloatNumberTest, EndsWithDot) {
    const char* input = "123.";
    extractFloatNumber(input, output, MAX_LENGTH);
    EXPECT_STREQ("123.", output);
}