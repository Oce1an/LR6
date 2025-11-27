#pragma once 

int strLength(const char* str);
void strCopy(char* dest, const char* src);
void intToString(int num, char* buffer);
int stringToInt(const char* str);
void doubleToString(double num, char* buffer, int precision = 6);
double stringToDouble(const char* str);