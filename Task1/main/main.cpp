#include <iostream>
#include <cstdio>
#include <cctype>
#include "../src/task1.h"

int main() {
    const int maxLength = 81;

    char* string = new char[maxLength];
    char* floatNum = new char[maxLength];

    std::cout << "Input string:\n";

    int length = 0;
    char ch;
    while ((ch = std::getchar()) != '\n' && length < maxLength - 1) {
        string[length] = ch;
        length++;
    }
    string[length] = '\0';

    extractFloatNumber(string, floatNum, maxLength);

    std::cout << "Initial input: " << string << std::endl;
    std::cout << "Double number = " << floatNum << std::endl;

    delete[] string;
    delete[] floatNum;
    return 0;
}