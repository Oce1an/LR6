#include <iostream>
#include "../src/task3.h"

using namespace std;

int main() {
    char buffer1[50];
    int testInt = -12345;

    intToString(testInt, buffer1);
    cout << "Integer " << testInt << " to string: " << buffer1 << endl;

    const char* intStr = "6789";
    int convertedInt = stringToInt(intStr);
    cout << "String \"" << intStr << "\" to integer: " << convertedInt << endl;

    char buffer2[50];
    double testDouble = -123.456789;

    doubleToString(testDouble, buffer2, 4);
    cout << "Double " << testDouble << " to string: " << buffer2 << endl;

    const char* doubleStr = "78.9012";
    double convertedDouble = stringToDouble(doubleStr);
    cout << "String \"" << doubleStr << "\" to double: " << convertedDouble << endl;

    return 0;
}
