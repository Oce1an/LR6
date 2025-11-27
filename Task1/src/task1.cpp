#include "task1.h"
#include <cctype>

void extractFloatNumber(const char* input, char* output, int maxLength) {
    int count = 0;
    int dotCount = 0;
    bool hasDigits = false;

    for (int i = 0; input[i] != '\0'; i++) {
        if (std::isdigit(static_cast<unsigned char>(input[i]))) {
            hasDigits = true;
            break;
        }
    }

    if (!hasDigits) {
        output[0] = '\0';
        return;
    }

    for (int i = 0; input[i] != '\0' && count < maxLength - 1; i++) {
        if (std::isdigit(static_cast<unsigned char>(input[i]))) {
            output[count++] = input[i];
        }
        else if (input[i] == '.' && dotCount == 0) {
            output[count++] = input[i];
            dotCount++;
        }
    }
    output[count] = '\0';

    if (output[0] == '.' && count < maxLength - 1) {
        for (int i = count; i > 0; i--) {
            output[i] = output[i - 1];
        }
        output[0] = '0';
        output[count + 1] = '\0';
    }
}