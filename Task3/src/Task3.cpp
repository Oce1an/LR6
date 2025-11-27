#include <iostream>
using namespace std;

int strLength(const char* str);
void strCopy(char* dest, const char* src);
void intToString(int num, char* buffer);
int stringToInt(const char* str);
void doubleToString(double num, char* buffer, int precision = 6);
double stringToDouble(const char* str);

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

void intToString(int num, char* buffer) {
    char* ptr = buffer;

    if (num == 0) {
        *ptr = '0';
        *(ptr + 1) = '\0';
        return;
    }

    if (num < 0) {
        *ptr = '-';
        ptr++;
        num = -num;
    }

    int temp = num;
    int length = 0;
    do {
        length++;
        temp /= 10;
    } while (temp > 0);

    char* end = ptr + length;
    *end = '\0';
    end--;

    do {
        *end = '0' + (num % 10);
        end--;
        num /= 10;
    } while (num > 0);
}

int stringToInt(const char* str) {
    const char* ptr = str;
    int result = 0;
    int sign = 1;

    if (*ptr == '-') {
        sign = -1;
        ptr++;
    }
    else if (*ptr == '+') {
        ptr++;
    }

    while (*ptr >= '0' && *ptr <= '9') {
        result = result * 10 + (*ptr - '0');
        ptr++;
    }

    return result * sign;
}

void doubleToString(double num, char* buffer, int precision) {
    char* ptr = buffer;

    if (num < 0) {
        *ptr = '-';
        ptr++;
        num = -num;
    }

    int intPart = static_cast<int>(num);
    double fractional = num - intPart;

    char intBuffer[20];
    intToString(intPart, intBuffer);

    const char* intPtr = intBuffer;
    while (*intPtr != '\0') {
        *ptr = *intPtr;
        ptr++;
        intPtr++;
    }

    *ptr = '.';
    ptr++;

    for (int i = 0; i < precision; i++) {
        fractional *= 10;
        int digit = static_cast<int>(fractional);
        *ptr = '0' + digit;
        ptr++;
        fractional -= digit;

        if (fractional < 0) {
            fractional = 0;
        }
    }

    *ptr = '\0';
}

double stringToDouble(const char* str) {
    const char* ptr = str;
    double result = 0.0;
    double sign = 1.0;

    if (*ptr == '-') {
        sign = -1.0;
        ptr++;
    }
    else if (*ptr == '+') {
        ptr++;
    }

    while (*ptr >= '0' && *ptr <= '9') {
        result = result * 10.0 + (*ptr - '0');
        ptr++;
    }

    if (*ptr == '.') {
        ptr++;
        double fraction = 0.0;
        double divisor = 10.0;

        while (*ptr >= '0' && *ptr <= '9') {
            fraction += (*ptr - '0') / divisor;
            divisor *= 10.0;
            ptr++;
        }

        result += fraction;
    }

    return result * sign;
}

int strLength(const char* str) {
    const char* ptr = str;
    while (*ptr != '\0') {
        ptr++;
    }
    return ptr - str;
}

void strCopy(char* dest, const char* src) {
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}