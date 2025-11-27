#include <string>
#include <cctype>

bool startsWithConsonant(const char* word) {
    if (word == nullptr || word[0] == '\0') return false;

    char firstChar = tolower(static_cast<unsigned char>(word[0]));

    if (!isalpha(static_cast<unsigned char>(firstChar))) {
        return false;
    }

    const char* vowels = "aeiou";

    return strchr(vowels, firstChar) == nullptr;
}

void removeWordsWithLength(char** text, char** result, int rows, int length) {
    for (int i = 0; i < rows; i++) {
        if (text[i][0] == '\0') {
            result[i][0] = '\0';
            continue;
        }

        char* line = text[i];
        char* resLine = result[i];
        int resIndex = 0;

        char word[100];
        int wordIndex = 0;
        bool inWord = false;

        for (int j = 0; line[j] != '\0'; j++) {
            if (isalpha(static_cast<unsigned char>(line[j]))) {
                word[wordIndex++] = line[j];
                inWord = true;
            }
            else {
                if (inWord) {
                    word[wordIndex] = '\0';

                    if (!(strlen(word) == length && startsWithConsonant(word))) {
                        for (int k = 0; k < wordIndex; k++) {
                            resLine[resIndex++] = word[k];
                        }
                    }
                    wordIndex = 0;
                    inWord = false;
                }
                resLine[resIndex++] = line[j];
            }
        }

        if (inWord) {
            word[wordIndex] = '\0';
            if (!(strlen(word) == length && startsWithConsonant(word))) {
                for (int k = 0; k < wordIndex; k++) {
                    resLine[resIndex++] = word[k];
                }
            }
        }

        resLine[resIndex] = '\0';
    }
}