#include <gtest/gtest.h>
#include "../src/task2.h"

TEST(StartsWithConsonantTest, EmptyString) {
    EXPECT_FALSE(startsWithConsonant(""));
}

TEST(StartsWithConsonantTest, StartsWithVowel) {
    EXPECT_FALSE(startsWithConsonant("apple"));
}

TEST(StartsWithConsonantTest, StartsWithConsonant) {
    EXPECT_TRUE(startsWithConsonant("banana"));
}

TEST(StartsWithConsonantTest, NonAlphaFirstChar) {
    EXPECT_FALSE(startsWithConsonant("123hello"));
}

TEST(RemoveWordsTest, RemoveConsonantWordsOfLength3) {
    const char* inputText[] = { "cat dog elephant" };
    char* input[1];
    char* output[1];

    input[0] = new char[40];
    strcpy(input[0], "cat dog elephant");
    output[0] = new char[40];

    removeWordsWithLength(input, output, 1, 3);
    EXPECT_STREQ(output[0], "  elephant");

    delete[] input[0];
    delete[] output[0];
}

TEST(RemoveWordsTest, KeepVowelStartWords) {
    const char* inputText[] = { "apple bear cat" };
    char* input[1];
    char* output[1];

    input[0] = new char[40];
    strcpy(input[0], "apple bear cat");
    output[0] = new char[40];

    removeWordsWithLength(input, output, 1, 5);
    EXPECT_STREQ(output[0], "apple bear cat");

    delete[] input[0];
    delete[] output[0];
}

TEST(RemoveWordsTest, EmptyLine) {
    char* input[1];
    char* output[1];

    input[0] = new char[40];
    input[0][0] = '\0';
    output[0] = new char[40];

    removeWordsWithLength(input, output, 1, 3);
    EXPECT_STREQ(output[0], "");

    delete[] input[0];
    delete[] output[0];
}

TEST(RemoveWordsTest, MultipleWordsSameLength) {
    const char* inputText[] = { "bat cat rat sat" };
    char* input[1];
    char* output[1];

    input[0] = new char[40];
    strcpy(input[0], "bat cat rat sat");
    output[0] = new char[40];

    removeWordsWithLength(input, output, 1, 3);
    EXPECT_STREQ(output[0], "   ");

    delete[] input[0];
    delete[] output[0];
}

TEST(RemoveWordsTest, MixedCaseConsonant) {
    const char* inputText[] = { "Cat Dog" };
    char* input[1];
    char* output[1];

    input[0] = new char[40];
    strcpy(input[0], "Cat Dog");
    output[0] = new char[40];

    removeWordsWithLength(input, output, 1, 3);
    EXPECT_STREQ(output[0], " ");

    delete[] input[0];
    delete[] output[0];
}

TEST(RemoveWordsTest, NoWordsToRemove) {
    const char* inputText[] = { "hello world test" };
    char* input[1];
    char* output[1];

    input[0] = new char[40];
    strcpy(input[0], "hello world test");
    output[0] = new char[40];

    removeWordsWithLength(input, output, 1, 10);
    EXPECT_STREQ(output[0], "hello world test");

    delete[] input[0];
    delete[] output[0];
}