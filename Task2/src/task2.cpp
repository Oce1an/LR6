#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

bool isConsonant(char c) {
    c = tolower(c);
    return (
            c != 'a' && c != 'z' && c != 'a' && c != 'e' &&
            c != 'i' && c != 'o' && c != 'u' && c != 'y'   
           );
}

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

    cout << "Input text:\n";
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
    cout << "What length of words you want to delete?\n";
    cin >> length;

    cout << "\nInitial text:\n";
    for (int i = 0; i < current_row; i++) {
        cout << text[i] << endl;
    }

    char** result = new char* [rows];
    for (int i = 0; i < rows; i++) {
        result[i] = new char[columns];
        result[i][0] = '\0';
    }

    for (int i = 0; i < current_row; i++) {

        int result_col = 0;
        int word_start = 0;
        int word_length = 0;
        bool in_word = false;
        bool first_word_in_sequence = true;

        for (int j = 0; text[i][j] != '\0'; j++) {
            if (text[i][j] != ' ' && text[i][j] != '\t') {
                if (!in_word) {
                    word_start = j;
                    in_word = true;
                    word_length = 0;
                }
                word_length++;
            }
            else {
                if (in_word) {
                    bool should_remove = (word_length == length &&
                        isConsonant(text[i][word_start]));

                    if (!should_remove) {
                        if (!first_word_in_sequence && result_col > 0) {
                            result[i][result_col++] = ' ';
                        }
                        for (int k = word_start; k < j; k++) {
                            result[i][result_col++] = text[i][k];
                        }
                        first_word_in_sequence = false;
                    }
                    else {
                        first_word_in_sequence = (result_col == 0);
                    }
                    in_word = false;
                    word_length = 0;
                }

            }
        }

        if (in_word) {
            bool should_remove = (word_length == length &&
                isConsonant(text[i][word_start]));

            if (!should_remove) {
                if (!first_word_in_sequence && result_col > 0) {
                    result[i][result_col++] = ' ';
                }
                for (int k = word_start; text[i][k] != '\0'; k++) {
                    result[i][result_col++] = text[i][k];
                }
            }
        }

        result[i][result_col] = '\0';
    }

    cout << "\nText after deleting words with length of " << length << ", that were starting with consonants:\n";
    for (int i = 0; i < current_row; i++) {
        if (result[i][0] != '\0') {
            cout << result[i] << endl;
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