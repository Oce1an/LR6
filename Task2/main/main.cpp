#include <iostream>
#include <cctype>
#include <cstring>
#include "../src/task2.h"

int main()
{
    int columns = 40;
    int rows = 1000;

    char** text = new char* [rows];
    for (int i = 0; i < rows; i++) {
        text[i] = new char[columns];
        text[i][0] = '\0';
    }

    char ch;
    int current_row = 0;
    int current_col = 0;

    std::cout << "Input text:\n";
    while ((ch = getchar()) != '\n' && current_row < rows) {
        if (ch == ' ' && current_col == 0) {
            continue;
        }

        if (current_col >= columns - 2 && ch != ' ' && ch != '\t') {
            if (current_col > 0 && isalpha(text[current_row][current_col - 1])) {
                text[current_row][current_col] = '-';
                current_col++;
            }

            text[current_row][current_col] = '\0';
            current_row++;
            current_col = 0;

            if (current_row >= rows) {
                break;
            }
        }

        text[current_row][current_col] = ch;
        current_col++;
    }

    if (current_col > 0 && current_row < rows) {
        text[current_row][current_col] = '\0';
        current_row++;
    }

    int length;
    std::cout << "What length of words you want to delete?\n";
    std::cin >> length;

    std::cout << "\nInitial text:\n";
    for (int i = 0; i < current_row; i++) {
        std::cout << text[i] << std::endl;
    }

    char** result = new char* [rows];
    for (int i = 0; i < rows; i++) {
        result[i] = new char[columns];
        result[i][0] = '\0';
    }

    removeWordsWithLength(text, result, current_row, length);

    std::cout << "\nText after deleting words with length of " << length << ", that were starting with consonants:\n";
    for (int i = 0; i < current_row; i++) {
        if (result[i][0] != '\0') {
            std::cout << result[i] << std::endl;
        }
    }

    for (int i = 0; i < rows; i++) {
        delete[] text[i];
        delete[] result[i];
    }
    delete[] text;
    delete[] result;

    return 0;
}